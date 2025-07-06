#include "ContactMenu.hpp"
#include <iostream>
#include <sstream>

MenuOption ContactMenu::showMenu() {
    std::cout << "\n=== MENU AGENDA ===\n"
            << "1 - Adicionar contato\n"
            << "2 - Listar contatos\n"
            << "3 - Editar contato\n"
            << "4 - Remover contato\n"
            << "5 - Buscar contato por nome\n"
            << "6 - Sair\n";

    int option = input.readInt("Escolha uma opção: ", 1, 6);
    return static_cast<MenuOption>(option - 1);
}

std::vector<std::string> ContactMenu::requestContactData() {
    std::vector<std::string> dados;
    dados.push_back(input.readString("Nome: "));
    dados.push_back(input.readString("Telefone (formato (XX) XXXXX-XXXX): "));
    dados.push_back(input.readOptionalString("Email (opcional): "));
    dados.push_back(input.readString("Tipo (PESSOAL, PROFISSIONAL, FAMILIAR, OUTRO): "));
    return dados;
}

int ContactMenu::requestContactId() {
    return input.readInt("Digite o ID do contato: ");
}

void ContactMenu::showMessage(const std::string &message) {
    std::cout << message << std::endl;
}

void ContactMenu::showContacts(const std::vector<Contact> &contatos) {
    if (contatos.empty()) {
        std::cout << "Nenhum contato encontrado.\n";
        return;
    }
    for (const auto &contato: contatos) {
        std::cout << "ID: " << contato.getId()
                << " | Nome: " << contato.getName()
                << " | Telefone: " << contato.getPhoneNumber()
                << " | Email: " << (contato.getEmail().empty() ? "N/A" : contato.getEmail())
                << " | Tipo: " << tipoParaString(contato.getType()) << std::endl;
    }
}

std::string ContactMenu::readString(const std::string &prompt) {
    return input.readString(prompt);
}

std::string ContactMenu::tipoParaString(ContactType tipo) {
    switch (tipo) {
        case ContactType::PESSOAL: return "PESSOAL";
        case ContactType::PROFISSIONAL: return "PROFISSIONAL";
        case ContactType::FAMILIAR: return "FAMILIAR";
        case ContactType::OUTRO: return "OUTRO";
        default: return "DESCONHECIDO";
    }
}
