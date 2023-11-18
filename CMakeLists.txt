cmake_minimum_required(VERSION 3.22)

project(QMLModuleApplicationDemo VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_OBJECT_PATH_MAX 256)

set(DATA_FILE
    ${PROJECT_SOURCE_DIR}/README.md
    ${PROJECT_SOURCE_DIR}/LICENSE)

option(LINK_INSIGHT "Link Qt Insight Tracker library" ON)
option(BUILD_QDS_COMPONENTS "Build design studio components" ON)

find_package(Qt6 6.5 COMPONENTS Core Widgets Gui Qml Quick QuickWidgets QuickControls2 REQUIRED)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(${CMAKE_PROJECT_NAME}
    src/main.cpp
    src/mainwindow.cpp
    src/mainwindow.h
    src/mainwindow.ui

    ${DATA_FILE}
)

qt_add_resources(${CMAKE_PROJECT_NAME} roboto_font
    PREFIX font
    BASE font
    FILES
        font/Roboto-Bold.ttf
        font/Roboto-Regular.ttf)

qt_add_qml_module(${CMAKE_PROJECT_NAME}
    URI first
    VERSION 1.0
    QML_FILES
        main.qml
)

qt_add_resources(${CMAKE_PROJECT_NAME} "configuration"
    PREFIX "/"
    FILES
        qtquickcontrols2.conf
)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
    Qt6::Widgets
    Qt6::QuickWidgets
    Qt6::QuickControls2

    Test::TestDisplayPlugin)

if (LINK_INSIGHT)
    include(${CMAKE_CURRENT_SOURCE_DIR}/insight)
endif ()

add_subdirectory(qml)
