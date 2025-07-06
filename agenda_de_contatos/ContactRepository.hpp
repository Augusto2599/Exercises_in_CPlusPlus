#ifndef CONTACTREPOSITORY_HPP
#define CONTACTREPOSITORY_HPP

#include <map>
#include <vector>
#include "Contact.hpp"

class ContactRepository {
private:
    std::map<int, Contact> contacts;
    int currentId;

public:
    ContactRepository();

    Contact adicionarContato(const Contact &contato);

    bool removerContato(int id);

    Contact *buscarPorId(int id);

    std::vector<Contact> buscarPorNome(const std::string &nome);

    std::vector<Contact> listarContatos();

    bool atualizarContato(const Contact &contatoAtualizado);
};

#endif
