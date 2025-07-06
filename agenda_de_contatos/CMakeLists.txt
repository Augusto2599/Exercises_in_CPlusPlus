cmake_minimum_required(VERSION 3.31)
project(agenda_de_contatos)

set(CMAKE_CXX_STANDARD 20)

add_executable(agenda_de_contatos main.cpp
        ContactType.hpp
        MenuOption.hpp
        Contact.hpp
        ContactRepository.hpp
        ContactService.hpp
        InputReader.hpp
        ContactMenu.hpp
        ContactController.hpp
        Contact.cpp
        ContactRepository.cpp
        ContactService.cpp
        InputReader.cpp
        ContactMenu.cpp
        ContactController.cpp
)
