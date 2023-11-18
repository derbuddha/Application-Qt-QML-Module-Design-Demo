cmake_minimum_required(VERSION 3.16)

project(QMLModuleApplicationDemo VERSION 1.0 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(DATA_FILE
    ${PROJECT_SOURCE_DIR}/README.md
    ${PROJECT_SOURCE_DIR}/LICENSE)

find_package(Qt6 6.2 COMPONENTS Quick Gui REQUIRED)

qt_add_executable(demo_app
    main.cpp
    ${DATA_FILE}
)

qt_add_qml_module(demo_app
    URI hello
    VERSION 1.0
    QML_FILES
        main.qml
        Logo.qml
    RESOURCES
        images/Invisto-Logo.svg
)

target_link_libraries(demo_app PRIVATE Qt6::Gui Qt6::Quick)
