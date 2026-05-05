project(Race_library VERSION 1.0.0)

# Собираем исходники
file(GLOB_RECURSE RACE_SRC "src/*.cpp")
file(GLOB_RECURSE RACE_HEADERS "include/*.h")

# Создаём DLL
add_library(Race_library SHARED ${RACE_SRC} ${RACE_HEADERS})

# Указываем пути для include
target_include_directories(Race_library
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Для Windows определяем макрос для экспорта/импорта
target_compile_definitions(Race_library 
    PRIVATE RACE_LIBRARY_EXPORTS    
)

# Настройки для Windows DLL
set_target_properties(Race_library PROPERTIES
    WINDOWS_EXPORT_ALL_SYMBOLS FALSE  # ручной контроль
)
