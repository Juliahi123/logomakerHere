cmake_minimum_required(VERSION 3.17)
project(FirstDraft)

set(CMAKE_CXX_STANDARD 14)

add_executable(FirstDraft saveFile.cpp saveFile.h windowOne.cpp windowOne.h ColorPicker.cpp ColorPicker.h FontBox.cpp
        FontBox.h randomGenerator.cpp randomGenerator.h Cursor.cpp Cursor.h SliderMenu.cpp SliderMenu.h BackGround.cpp
        BackGround.h LogoScreen.cpp LogoScreen.h Slider.cpp Slider.h Typer.cpp Typer.h Label.cpp Label.h State.h State.cpp
        TextInput.cpp TextInput.h Node.h LinkedList.h LinkedList.cpp Box.cpp Box.h Item.h Item.cpp SetUpFormate.cpp
        SetUpFormate.h FileTree.h FileTree.cpp FileNode.h FileNode.cpp FileItem.h
        FileItem.cpp Menu.cpp Menu.h MenuBar.cpp MenuBar.h ItemList.cpp ItemList.h main.cpp asset.cpp asset.h MouseEvent.cpp MouseEvent.h )


target_link_libraries(FirstDraft sfml-graphics sfml-audio)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)