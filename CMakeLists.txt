cmake_minimum_required(VERSION 3.5)

project(Inventario VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql)

# Define PROJECT_SOURCES (que faltaba en tu versión)
set(PROJECT_SOURCES
    main.cpp
    inventario.cpp
    inventario.h
    inventario.ui
)

set(COMPONENT_SOURCES
    Component/ComponentDialog.h
    Component/ComponentDialog.cpp
    Component/ComponentDialog.ui
)

set(DATABASE_SOURCES
    Database/DatabaseManager.h
    Database/DatabaseManager.cpp
)
set(MODEL_SOURCES
    Models/ComponentModel.h
    Models/ComponentModel.cpp
)
set(FILTER_SOURCES
    Models/CustomFilterProxyModel.h
    Models/CustomFilterProxyModel.cpp
)

set(ALL_SOURCES
    ${PROJECT_SOURCES}
    ${COMPONENT_SOURCES}
    ${DATABASE_SOURCES}
    ${MODEL_SOURCES}
    ${FILTER_SOURCES}
)
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Inventario
        MANUAL_FINALIZATION
        ${ALL_SOURCES}
    )
else()
    if(ANDROID)
        add_library(Inventario SHARED
            ${ALL_SOURCES}
        )
    else()
        add_executable(Inventario
            ${ALL_SOURCES}
        )
    endif()
endif()

target_link_libraries(Inventario PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Sql
)

# Configuración para macOS/iOS
if(${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Inventario)
endif()

set_target_properties(Inventario PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Inventario
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Inventario)
endif()
