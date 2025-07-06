#ifndef CONTACTSERVICE_HPP
#define CONTACTSERVICE_HPP

#include "ContactRepository.hpp"
#include <regex>

class ContactService {
private:
    ContactRepository &repository;

    bool validarContato(const Contact &contato);

public:
    ContactService(ContactRepository &repo);

    Contact adicionarContato(const Contact &contato);

    bool removerContato(int id);

    Contact *buscarPorId(int id);

    std::vector<Contact> buscarPorNome(const std::string &nome);

    std::vector<Contact> listarContatos();

    bool atualizarContato(const Contact &contato);
};

#endif
