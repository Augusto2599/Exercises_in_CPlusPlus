#include "ContactController.hpp"
#include <iostream>

ContactController::ContactController(ContactService &service, ContactMenu menu)
    : service(service), menu(menu) {
}

void ContactController::iniciar() {
    bool executando = true;
    while (executando) {
        MenuOption opcao = menu.showMenu();

        switch (opcao) {
            case MenuOption::ADICIONAR: adicionarContato();
                break;
            case MenuOption::LISTAR: listarContatos();
                break;
            case MenuOption::EDITAR: editarContato();
                break;
            case MenuOption::REMOVER: removerContato();
                break;
            case MenuOption::BUSCAR_POR_NOME: buscarPorNome();
                break;
            case MenuOption::SAIR:
                menu.showMessage("Encerrando...");
                executando = false;
                break;
        }
    }
}

void ContactController::adicionarContato() {
    auto dados = menu.requestContactData();
    try {
        Contact c;
        c.setName(dados[0]);
        c.setPhoneNumber(dados[1]);
        c.setEmail(dados[2]);
        std::string tipoStr = dados[3];
        std::transform(tipoStr.begin(), tipoStr.end(), tipoStr.begin(), ::toupper);

        if (tipoStr == "PESSOAL") c.setType(ContactType::PESSOAL);
        else if (tipoStr == "PROFISSIONAL") c.setType(ContactType::PROFISSIONAL);
        else if (tipoStr == "FAMILIAR") c.setType(ContactType::FAMILIAR);
        else if (tipoStr == "OUTRO") c.setType(ContactType::OUTRO);
        else throw std::invalid_argument("Tipo de contato inválido.");


        auto contatoAdicionado = service.adicionarContato(c);
        if (contatoAdicionado.getId() != 0)
            menu.showMessage("Contato adicionado com sucesso!");
    } catch (...) {
        menu.showMessage("Tipo de contato inválido.");
    }
}

void ContactController::listarContatos() {
    auto lista = service.listarContatos();
    menu.showContacts(lista);
}

void ContactController::editarContato() {
    int id = menu.requestContactId();
    Contact *contato = service.buscarPorId(id);
    if (!contato) {
        menu.showMessage("Contato não encontrado.");
        return;
    }

    auto dados = menu.requestContactData();
    try {
        contato->setName(dados[0]);
        contato->setPhoneNumber(dados[1]);
        contato->setEmail(dados[2]);
        contato->setType(static_cast<ContactType>(std::stoi(dados[3])));
        bool atualizado = service.atualizarContato(*contato);
        menu.showMessage(atualizado ? "Contato atualizado!" : "Erro ao atualizar.");
    } catch (...) {
        menu.showMessage("Erro ao interpretar tipo de contato.");
    }
}

void ContactController::removerContato() {
    int id = menu.requestContactId();
    bool removido = service.removerContato(id);
    menu.showMessage(removido ? "Contato removido!" : "Contato não encontrado.");
}

void ContactController::buscarPorNome() {
    std::string nome = menu.readString("Nome para busca: ");
    auto encontrados = service.buscarPorNome(nome);
    menu.showContacts(encontrados);
}
