#ifndef CONTACTMENU_HPP
#define CONTACTMENU_HPP

#include "MenuOption.hpp"
#include "Contact.hpp"
#include "InputReader.hpp"
#include <string>
#include <vector>

class ContactMenu {
private:
    InputReader input;

public:
    MenuOption showMenu();

    std::vector<std::string> requestContactData();

    int requestContactId();

    void showMessage(const std::string &message);

    void showContacts(const std::vector<Contact> &contatos);

    std::string readString(const std::string &prompt);

    std::string tipoParaString(ContactType tipo);
};

#endif
