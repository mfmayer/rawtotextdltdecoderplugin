/**
 * @licence app begin@
 * Author 2022 Matthias Mayer
 * derived from dummydecoderplugin (part of GENIVI Project Dlt Viewer) - Copyright (C) 2011-2012  BMW AG
 *
 * Contributions are licensed to the GENIVI Alliance under one or more
 * Contribution License Agreements.
 *
 * \copyright
 * This Source Code Form is subject to the terms of the
 * Mozilla Public License, v. 2.0. If a  copy of the MPL was not distributed with
 * this file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * \file rawtotextdltdecoderplugin.cpp
 * For further information see http://www.genivi.org/.
 * @licence end@
 */

#include <QtGui>

#include "rawtotextdltdecoderplugin.h"

RawToTextDltDecoderPlugin::RawToTextDltDecoderPlugin()
{
}

RawToTextDltDecoderPlugin::~RawToTextDltDecoderPlugin()
{
}

QString RawToTextDltDecoderPlugin::name()
{
    return QString("Raw To Text DLT Decoder Plugin");
}

QString RawToTextDltDecoderPlugin::pluginVersion()
{
    return RAW_TO_TEXT_DLT_DECODER_PLUGIN_VERSION;
}

QString RawToTextDltDecoderPlugin::pluginInterfaceVersion()
{
    return PLUGIN_INTERFACE_VERSION;
}

QString RawToTextDltDecoderPlugin::description()
{
    return QString("Decoder plugin to make raw dlt messages readable in trace view.");
}

QString RawToTextDltDecoderPlugin::error()
{
    return QString();
}

bool RawToTextDltDecoderPlugin::loadConfig(QString /* filename */)
{
    return true;
}

bool RawToTextDltDecoderPlugin::saveConfig(QString /* filename */)
{
    return true;
}

QStringList RawToTextDltDecoderPlugin::infoConfig()
{
    return QStringList();
}

bool RawToTextDltDecoderPlugin::isMsg(QDltMsg &msg, int triggeredByUser)
{
    Q_UNUSED(msg);
    Q_UNUSED(triggeredByUser);
    if (msg.getNumberOfArguments() > 0)
    {
        for (int i = 0; i < msg.getNumberOfArguments(); ++i)
        {
            QDltArgument arg;
            msg.getArgument(i, arg);
            if (arg.getTypeInfo() == QDltArgument::DltTypeInfoRawd)
            {
                return true;
            }
        }
    }
    return false;
}

bool RawToTextDltDecoderPlugin::decodeMsg(QDltMsg &msg, int triggeredByUser)
{
    Q_UNUSED(msg);
    Q_UNUSED(triggeredByUser);
    QList<QDltArgument> arguments;
    if (msg.getNumberOfArguments() > 0)
    {
        for (int i = 0; i < msg.getNumberOfArguments(); ++i)
        {
            QDltArgument arg;
            msg.getArgument(i, arg);
            if (arg.getTypeInfo() == QDltArgument::DltTypeInfoRawd)
            {
                QByteArray data = arg.getData();
                int length = 0, pos = 0;
                for (int i = data.length() - 1; i >= 0; --i)
                {
                    char ch = data[i];
                    if (i == data.length() - 1 && ch == '\0')
                    {
                        continue;
                    }
                    if (ch >= 32 && ch < 127)
                    {
                        length++;
                        pos = i;
                    }
                    else
                    {
                        break;
                    }
                }
                if (pos >= 0 && length > 0)
                {
                    arg.setValue(QString(data.mid(pos, length)));
                }
            }
            arguments.append(arg);
        }
    }
    if (arguments.length() > 0)
    {
        msg.clearArguments();
        for (QDltArgument &arg : arguments)
        {
            msg.addArgument(arg);
        }
        msg.genMsg();
        return true;
    }
    return false;
}

#ifndef QT5
Q_EXPORT_PLUGIN2(RawToTextDltDecoderPlugin, RawToTextDecoderPlugin);
#endif
