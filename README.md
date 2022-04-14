# Raw To Text DLT Decoder Plugin

DLT-Viewer (Diagnostic Log and Trace Viewer) decoder plugin to make raw dlt messages readable in DLT-Viewer's trace view. For more information regarding DLT-Viewer see: <https://github.com/COVESA/dlt-viewer>

## How-To compile

Compilation has been successfully tried with DLT-Viewer v22.2.0 and Qt 5.15.2 (Community)

1. Clone this repository into the DLT-Viewers plugin source folder.
2. Adapt the .pro or CMakeLists.txt file (depending on how you want to build it) within DLT-Viewer's plugin subdirecotry and include rawtotextdltdecoderplugin analogous to how the accompanying plugins are included there.
3. Generate and compile DLT-Viewer together with rawtotextdltdecoderplugin
