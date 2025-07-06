#include "ContactRepository.hpp"
#include <algorithm>
#include <cctype>

ContactRepository::ContactRepository() : currentId(1) {
}

Contact ContactRepository::adicionarContato(const Contact &contato) {
    Contact novo = contato;
    novo.setId(currentId++);
    contacts[novo.getId()] = novo;
    return novo;
}

bool ContactRepository::removerContato(int id) {
    return contacts.erase(id) > 0;
}

Contact *ContactRepository::buscarPorId(int id) {
    auto it = contacts.find(id);
    if (it != contacts.end()) {
        return &(it->second);
    }
    return nullptr;
}

std::vector<Contact> ContactRepository::buscarPorNome(const std::string &nome) {
    std::vector<Contact> encontrados;
    for (const auto &par: contacts) {
        std::string nomeContato = par.second.getName();
        std::string nomeLower = nome;
        std::transform(nomeContato.begin(), nomeContato.end(), nomeContato.begin(), ::tolower);
        std::transform(nomeLower.begin(), nomeLower.end(), nomeLower.begin(), ::tolower);
        if (nomeContato.find(nomeLower) != std::string::npos) {
            encontrados.push_back(par.second);
        }
    }
    return encontrados;
}

std::vector<Contact> ContactRepository::listarContatos() {
    std::vector<Contact> todos;
    for (const auto &par: contacts) {
        todos.push_back(par.second);
    }
    return todos;
}

bool ContactRepository::atualizarContato(const Contact &contatoAtualizado) {
    int id = contatoAtualizado.getId();
    auto it = contacts.find(id);
    if (it != contacts.end()) {
        it->second = contatoAtualizado;
        return true;
    }
    return false;
}
