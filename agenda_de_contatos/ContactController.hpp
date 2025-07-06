#ifndef CONTACTCONTROLLER_HPP
#define CONTACTCONTROLLER_HPP

#include "ContactService.hpp"
#include "ContactMenu.hpp"

class ContactController {
private:
    ContactService &service;
    ContactMenu menu;

    void adicionarContato();

    void listarContatos();

    void editarContato();

    void removerContato();

    void buscarPorNome();

    std::string formatarContato(const Contact &contato);

public:
    ContactController(ContactService &service, ContactMenu menu);

    void iniciar();
};

#endif
