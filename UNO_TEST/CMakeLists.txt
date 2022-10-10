cmake_minimum_required(VERSION 3.5)

project(TEST LANGUAGES CXX)

find_package(QT NAMES Qt5 Qt6 COMPONENTS Test Widgets Network REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Test REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Network REQUIRED)

include_directories(libraries/include/SDL2)
link_directories(libraries/lib)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_testing()

set(PROJECT_SOURCES
        main.cpp
        greeting.cpp
        greeting.h
        greeting.ui
        rules.h
        rules.cpp
        rules.ui
        inputs.cpp
        inputs.h
        inputs.ui
        card.cpp
        card.h
        users.cpp
        users.h
        server_greeting.cpp
        server_greeting.h
        server_greeting.ui
        client_greeting.cpp
        client_greeting.h
        client_greeting.ui
        game.cpp
        game.h
        profiledata.txt
        profilemanager.cpp
        profilemanager.h
        profilemanager.ui
        bot_player.cpp
        bot_player.h
        soundclass.cpp
        soundclass.h
        test_card.cpp
        test_card.h
        test_users.h
        test_users.cpp
        test_game.h
        test_game.cpp

        test_sound.h
        test_sound.cpp
)

add_executable(TEST ${PROJECT_SOURCES})
add_test(NAME TEST COMMAND TEST)

target_link_libraries(TEST PRIVATE Qt${QT_VERSION_MAJOR}::Test Qt${QT_VERSION_MAJOR}::Network Qt${QT_VERSION_MAJOR}::Widgets -mwindows  mingw32 SDL2main  SDL2  SDL2_mixer)


add_custom_command(TARGET TEST POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${PROJECT_SOURCE_DIR}/libraries/bin"
        $<TARGET_FILE_DIR:TEST>)

add_custom_command(TARGET TEST POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${PROJECT_SOURCE_DIR}/sounds1"
        $<TARGET_FILE_DIR:TEST>)

    add_custom_command(TARGET TEST POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${PROJECT_SOURCE_DIR}/sounds1"
            $<TARGET_FILE_DIR:TEST>/sounds1)
