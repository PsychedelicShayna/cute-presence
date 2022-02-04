# Qt Creator DRPC (Discord Rich Presence) Plugin
This plugin adds Discord Rich Presence support to Qt Creator, with a growing list of recognized file types, and complete with icons!

## Preview

## Recognized File Types
| Category    | Extensions |
|-------------|------------|
| Qt/QMake    | `.pro` `.pri` `.ui` `.qrc` `.qml` `.qss` 
| C/C++       | `.cpp` `.hpp` `.cxx` `.hxx` `.cc` `.hh` `.c` `.h` `.i`
| Other Langs | `.py` `.rb` `.rs` `.js` `.css` `.html` `.lua` `.java` `.asm`
| Data & Text | `.json` `.xml` `.yaml` `.ini` `.txt` `.md`
| Misc        | `.gitignore` `Makefile` `CMakeLists.txt`

## Building
The official precompiled versions of Qt Creator don't come complete with the `.lib` files and headers required to build plugins for it, as such, you will have to [download the source code](https://github.com/qt-creator/qt-creator/releases) of the Qt Creator version that you intend to build this plugin for, and then build that version of Qt Creator to generate the needed `.lib` files inside of the `<build-output>/lib/qtcreator/plugins` folder. 

(Optional) You can merge the `<build-output>/lib/` folder with the `/lib` folder of your existing Qt Creator build (skipping existing files, not replacing, if prompted), and do the same with the `<build-output>/src` folder, and any `.pri` and `.pro` files located at the root of `<build-output>` so that you can delete the duplicate build and avoid having to do this again.

Once you've downloaded and built the source code, make sure to modify these two variables located in `QtCreatorDRPC.pro` accordingly.
```qmake
# Qt Plugin Configuration ------------------------------
IDE_SOURCE_TREE = C:/Qt/Tools/QtCreator/    # Ensure that this points to the root of the Qt Creator build containing the 
                                            # source code folder (/src) and .pri files.
                                            
IDE_BUILD_TREE  = C:/Qt/Tools/QtCreator/    # Ensure that this points to the root of the Qt Creator build whose 
                                            # /lib/qtcreator/plugins folder contains the built .lib files.
```
