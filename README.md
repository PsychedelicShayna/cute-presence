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
You will need a build of Qt Creator complete with the project include `.pri` files at the root of the build, the source code `/src` folder, the `.pri` files inside of the `/src` folder, and the `.lib` files inside of `/lib/qtcreator/plugins` and `/bin` that correspond to the Qt Creator DLLs stored in the same folders (e.g. `Core.lib`:`Core.dll`). If you've installed Qt Creator using the official installer, then you're most likely lacking the `/src` folder and `.pri` files, and might or might not have the `.lib` files depending on whether or not you selected "Qt Creator Plugin Development" as one of the features during the installation process.

You can get a copy of the `/src` folder and the `.pri` files by downloading the source code of the Qt Creator version you intend to build this plugin for from the [official repository](https://github.com/qt-creator/qt-creator/releases). Copy the `/src` folder and `.pri` files from the root of the repository into the root of your existing build. 

If you need the `.lib` files, you can either re-run the installer and select the "Qt Creator Plugin Development" feature, or build the source code of your Qt Creator version.

**Qt Creator 6 NOTE**: In previous Qt Creator versions, the `.lib` filenames had the version number as a suffix, e.g. `Core5.lib` whereas in Qt Creator 6 - at least when using the "Qt Creator Plugin Development" feature to acquire the `.lib` files - that suffix is omitted, but the `.pri` files do not account for that omission. Also, the `.lib` files within the `/bin` folder are expected to be within the `/lib/qtcreator/plugins` folder, but they aren't. If you run into this problem when building, rather than renaming everything, I suggest you create a second `/lib` folder, e.g. `/symlib/lib/qtcreator/plugins` and then create symlinks to all of the `.lib` files from both `/lib/qtcreator/plugins` and `/bin` inside of `/symlib/lib/qtcreator/plugins`, including the version number suffix in the filenames for the symlinks. Doing this by hand is obviously quite tedious, but it should not be difficult to automate.

Once you have all of the required files, edit `QtCreatorDRPC.pro` and ensure that these two variables point to the right locations.
```qmake
# Qt Plugin Configuration ------------------------------
IDE_SOURCE_TREE = C:/Qt/Tools/QtCreator/    # Ensure that this points to the root of the Qt Creator build containing the 
                                            # source code folder (/src) and .pri files.
                                            
IDE_BUILD_TREE  = C:/Qt/Tools/QtCreator/symlib    # Ensure that this points to the root of the Qt Creator build whose 
                                                  # /lib/qtcreator/plugins folder contains the needed .lib files. If
                                                  # using symlinks, point to that folder instead.
```
