/**
 * @licence app begin@
 * Author 2022 Matthias Mayer
 * derived from dummydecoderplugin (part of GENIVI Project Dlt Viewer - Copyright (C) 2011-2012  BMW AG)
 *
 * \copyright
 * This Source Code Form is subject to the terms of the
 * Mozilla Public License, v. 2.0. If a  copy of the MPL was not distributed with
 * this file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * \file rawtotextdltdecoderplugin.h
 * For further information see http://www.genivi.org/.
 * @licence end@
 */

#ifndef RAWTOTEXTDLTDECODERPLUGIN_H
#define RAWTOTEXTDLTDECODERPLUGIN_H

#include <QObject>
#include "plugininterface.h"

#define RAW_TO_TEXT_DLT_DECODER_PLUGIN_VERSION "1.0.0"

class RawToTextDltDecoderPlugin : public QObject, QDLTPluginInterface, QDLTPluginDecoderInterface
{
    Q_OBJECT
    Q_INTERFACES(QDLTPluginInterface)
    Q_INTERFACES(QDLTPluginDecoderInterface)
#ifdef QT5
    Q_PLUGIN_METADATA(IID "de.mfmayer.DLT.RawToTextDltDecoderPlugin")
#endif

public:
    RawToTextDltDecoderPlugin();
    ~RawToTextDltDecoderPlugin();

    /* QDLTPluginInterface interface */
    QString name();
    QString pluginVersion();
    QString pluginInterfaceVersion();
    QString description();
    QString error();
    bool loadConfig(QString filename);
    bool saveConfig(QString filename);
    QStringList infoConfig();

    /* QDltPluginDecoderInterface */
    bool isMsg(QDltMsg &msg, int triggeredByUser);
    bool decodeMsg(QDltMsg &msg, int triggeredByUser);

private:
    QString errorText;
};

#endif // RAWTOTEXTDLTDECODERPLUGIN_H
