
cmake_minimum_required(VERSION 3.16)

project(arraylib VERSION 1.0.0 LANGUAGES CXX)

# Используем C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Создание динамической библиотеки
add_library(arraylib SHARED src/arraylib.cpp)

# Указываем расположение заголовочных файлов
target_include_directories(arraylib
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Макрос экспорта функций для Windows
target_compile_definitions(arraylib PRIVATE ARRAYLIB_BUILD)

# Предупреждения компилятора
if(MSVC)
    target_compile_options(arraylib PRIVATE /W4)
else()
    target_compile_options(arraylib PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Создание исполняемого файла
add_executable(app main.cpp)

# Подключение динамической библиотеки к app
target_link_libraries(app PRIVATE arraylib)

# Каталог для результатов сборки
set_target_properties(arraylib app PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)

# Тестирование — подключим тесты на этапе 6
include(CTest)

if(BUILD_TESTING)

    # Модульные тесты
    add_executable(test_unit tests/test_unit.cpp)
    target_link_libraries(test_unit PRIVATE arraylib)
    add_test(NAME unit COMMAND test_unit)

    # Интеграционные тесты
    add_executable(test_integration tests/test_integration.cpp)
    target_link_libraries(test_integration PRIVATE arraylib)
    add_test(NAME integration COMMAND test_integration)

    # Включаем assert даже для Release-сборки
    if(MSVC)
        target_compile_options(test_unit PRIVATE /UNDEBUG)
        target_compile_options(test_integration PRIVATE /UNDEBUG)
    else()
        target_compile_options(test_unit PRIVATE -UNDEBUG)
        target_compile_options(test_integration PRIVATE -UNDEBUG)
    endif()

endif()

