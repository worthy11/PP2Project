set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
qt_add_executable(PJMRecognizer
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        main.cpp mainwindow.cpp mainwindow.h mainwindow.ui
        functions.cpp functions.h model.cpp model.h pylandmarkrecognizer.cpp pylandmarkrecognizer.h capturewidget.cpp capturewidget.h
        generatorwidget.h generatorwidget.cpp

    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET PJMRecognizer APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(PJMRecognizer SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(PJMRecognizer
            ${PROJECT_SOURCES}
            capturewidget.cpp capturewidget.h
            CMakeLists.txt
            functions.cpp functions.h
            generatorwidget.cpp generatorwidget.h
            main.cpp
            mainwindow.cpp mainwindow.h mainwindow.ui
            model.cpp model.h
            pylandmarkrecognizer.cpp pylandmarkrecognizer.h

        )
    endif()
endif()

target_link_libraries(PJMRecognizer PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(PJMRecognizer PRIVATE ${OpenCV_LIBS})
target_link_libraries(PJMRecognizer PRIVATE ${PYTHON_LIBRARIES})

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.PJMRecognizer)
endif()
set_target_properties(PJMRecognizer PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS PJMRecognizer
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
