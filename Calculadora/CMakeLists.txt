cmake_minimum_required(VERSION 3.16)
project(Calculadora)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adiciona flags para desenvolvimento (warnings e debug)
if (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -Wextra -pedantic -g)
endif ()

add_executable(Calculadora
        main.cpp
        Calculator.cpp
        Menu.cpp
)

# Headers são incluídos automaticamente via #include
target_include_directories(Calculadora PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
