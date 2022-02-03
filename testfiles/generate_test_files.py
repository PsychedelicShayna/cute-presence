import os

output_folder:str = "generated-files"

if not os.path.isdir(output_folder):
    os.mkdir(output_folder)

extensions:list = [
    ".pro",   ".pri",  ".ui",    ".qrc",
    ".qml",   ".qss",  ".cpp",   ".hpp",
    ".cxx",   ".hxx",  ".cc",    ".hh",
    ".c",     ".h",    ".i",     ".py",
    ".rb",    ".rs",   ".js",    ".css",
    ".html",  ".lua",  ".java",  ".asm",
    ".json",  ".xml",  ".yaml",  ".ini",
    ".txt",   ".md"
]

filenames:list = [
    ".gitignore",
    "Makefile",
    "CMakeLists.txt"
]

data:dict = {
    ".ui": b'<ui version="4.0"><author></author><comment></comment><exportmacro></exportmacro><class>MainWindow</class> <widget class="QMainWindow" name="MainWindow"><property name="geometry"><rect><x>0</x><y>0</y><width>800</width><height>600</height></rect></property><property name="windowTitle"><string>MainWindow</string></property><widget class="QMenuBar" name="menubar" /><widget class="QWidget" name="centralwidget"/><widget class="QStatusBar" name="statusbar"/></widget><pixmapfunction></pixmapfunction><connections/></ui>'
}

for extension in extensions:
    with open("{0}/File{1}".format(output_folder, extension), "wb+") as io:
        if extension in data:
            io.write(data[extension])
        else:
            io.write(b"")

        io.close()

for filename in filenames:
    with open("{0}/{1}".format(output_folder, filename), "wb+") as io:
        if filename in data:
            io.write(data[filename])
        else:
            io.write(b"")

        io.close()
