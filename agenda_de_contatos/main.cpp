#include <windows.h>
#include <iostream>

#include "ContactRepository.hpp"
#include "ContactService.hpp"
#include "ContactMenu.hpp"
#include "ContactController.hpp"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    std::cout << "========================\n";
    std::cout << "  Agenda de Contatos\n";
    std::cout << "========================\n\n";

    // Instanciando dependências
    ContactRepository repository;
    ContactService service(repository);
    ContactMenu menu{};
    ContactController controller(service, menu);

    // Iniciando o sistema
    controller.iniciar();

    return 0;
}
