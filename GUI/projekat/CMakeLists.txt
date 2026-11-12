
cmake_minimum_required(VERSION 3.5)

project(projekat VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt 5 biblioteke
find_package(Qt5 REQUIRED COMPONENTS
    Widgets
    3DCore
    3DRender
    3DInput
    3DExtras
)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    resources.qrc
    settingsprozor.ui
    settingsprozor.h
    settingsprozor.cpp
    general.cpp
    general.h
    general.ui
)

add_executable(projekat
    ${PROJECT_SOURCES}
)

# Povezivanje biblioteka
target_link_libraries(projekat PRIVATE
    Qt5::Widgets
    Qt5::3DCore
    Qt5::3DRender
    Qt5::3DInput
    Qt5::3DExtras
)
