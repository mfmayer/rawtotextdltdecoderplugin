# This Source Code Form is subject to the terms of the
# Mozilla Public License (MPL), v. 2.0.
# If a copy of the MPL was not distributed with this file,
# You can obtain one at http://mozilla.org/MPL/2.0/.
#
# For further information see http://www.genivi.org/.
#
# List of changes:
# 01.Oct.2016, Jack Smith <jack.smith@elektrobit.com>, Original Author
# 14.Apr.2022, Matthias Mayer <github.com/mfmayer>, adaptions regarding rawtotextdltdecoderplugin

add_library(rawtotextdltdecoderplugin MODULE
    rawtotextdltdecoderplugin.cpp
    ${UI_HEADERS})

target_link_libraries(rawtotextdltdecoderplugin qdlt Qt5::Widgets )

add_plugin(rawtotextdltdecoderplugin)
