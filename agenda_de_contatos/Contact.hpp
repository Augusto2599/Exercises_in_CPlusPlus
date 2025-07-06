#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include "ContactType.hpp"

class Contact {
private:
    int id;
    std::string name;
    std::string phoneNumber;
    std::string email;
    ContactType type;

public:
    Contact();

    Contact(int id, const std::string &name, const std::string &phone, const std::string &email, ContactType type);

    int getId() const;

    void setId(int newId);

    std::string getName() const;

    void setName(const std::string &newName);

    std::string getPhoneNumber() const;

    void setPhoneNumber(const std::string &newPhone);

    std::string getEmail() const;

    void setEmail(const std::string &newEmail);

    ContactType getType() const;

    void setType(ContactType newType);
};

#endif
