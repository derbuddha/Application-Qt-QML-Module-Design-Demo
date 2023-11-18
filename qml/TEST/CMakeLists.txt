project(TestDisp VERSION 1.0 LANGUAGES C CXX)
set(LIBRARY_NAME ${PROJECT_NAME})

qt_add_qml_module(${PROJECT_NAME}
    URI qml.TEST
    VERSION ${PROJECT_VERSION}
    STATIC
    QML_FILES
        TestDisplay.qml
        Screen01.ui.qml
        Logo.qml
    RESOURCES
       images/sailor-1424820_640.png
   )

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Gui)

add_library(Test::TestDisplayPlugin ALIAS ${LIBRARY_NAME}plugin)

# enable compiler warnings
target_compile_options(${PROJECT_NAME} PRIVATE
    $<$<CXX_COMPILER_ID:MSVC>:/W4>
    $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic>)
