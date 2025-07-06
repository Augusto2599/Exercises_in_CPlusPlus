#include "ContactService.hpp"
#include <iostream>

ContactService::ContactService(ContactRepository &repo) : repository(repo) {
}

bool ContactService::validarContato(const Contact &contato) {
    if (contato.getName().empty()) {
        std::cout << "Nome não pode ser vazio.\n";
        return false;
    }

    std::regex telefonePattern("^\\(\\d{2}\\) \\d{4,5}-\\d{4}$");
    if (!std::regex_match(contato.getPhoneNumber(), telefonePattern)) {
        std::cout << "Telefone inválido. Use (XX) XXXXX-XXXX\n";
        return false;
    }

    if (!contato.getEmail().empty()) {
        std::regex emailPattern("^[\\w.-]+@[\\w.-]+\\.\\w{2,}$");
        if (!std::regex_match(contato.getEmail(), emailPattern)) {
            std::cout << "Email inválido.\n";
            return false;
        }
    }

    return true;
}

Contact ContactService::adicionarContato(const Contact &contato) {
    if (validarContato(contato)) {
        return repository.adicionarContato(contato);
    }
    return Contact();
}

bool ContactService::removerContato(int id) {
    return repository.removerContato(id);
}

Contact *ContactService::buscarPorId(int id) {
    return repository.buscarPorId(id);
}

std::vector<Contact> ContactService::buscarPorNome(const std::string &nome) {
    return repository.buscarPorNome(nome);
}

std::vector<Contact> ContactService::listarContatos() {
    return repository.listarContatos();
}

bool ContactService::atualizarContato(const Contact &contato) {
    if (validarContato(contato)) {
        return repository.atualizarContato(contato);
    }
    return false;
}
