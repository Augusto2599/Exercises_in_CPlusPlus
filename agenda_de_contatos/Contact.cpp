#include "Contact.hpp"

Contact::Contact() : id(0), name(""), phoneNumber(""), email(""), type(ContactType::OUTRO) {
}

Contact::Contact(int id, const std::string &name, const std::string &phone, const std::string &email, ContactType type)
    : id(id), name(name), phoneNumber(phone), email(email), type(type) {
}

int Contact::getId() const {
    return id;
}

void Contact::setId(int newId) {
    id = newId;
}

std::string Contact::getName() const {
    return name;
}

void Contact::setName(const std::string &newName) {
    name = newName;
}

std::string Contact::getPhoneNumber() const {
    return phoneNumber;
}

void Contact::setPhoneNumber(const std::string &newPhone) {
    phoneNumber = newPhone;
}

std::string Contact::getEmail() const {
    return email;
}

void Contact::setEmail(const std::string &newEmail) {
    email = newEmail;
}

ContactType Contact::getType() const {
    return type;
}

void Contact::setType(ContactType newType) {
    type = newType;
}
