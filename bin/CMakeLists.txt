project(RacingSimulator_App)

# Исходник программы - Source.cpp
set(APP_SOURCES Source.cpp)

add_executable(racing_simulator ${APP_SOURCES})

# Линкуем библиотеки
target_link_libraries(racing_simulator
    PRIVATE
        Race_library
        Transport_library
)

# Пути к заголовкам библиотек
target_include_directories(racing_simulator
    PRIVATE
        ${CMAKE_SOURCE_DIR}/lib/Race_library/include
        ${CMAKE_SOURCE_DIR}/lib/Transport_library/include
)

# Копируем DLL в папку с exe (на Windows)
add_custom_command(TARGET racing_simulator POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:Race_library>
        $<TARGET_FILE_DIR:racing_simulator>
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:Transport_library>
        $<TARGET_FILE_DIR:racing_simulator>
)