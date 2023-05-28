#include "contact.h"

// Implementarea claselor Contact, Prieten, Cunoscut, Coleg

Contact::Contact(const std::string& nume) : nume(nume) {}

Contact::~Contact() {}

std::string Contact::getNume()
{
    return nume;
}

Prieten::Prieten(const std::string& nume, const std::string& dataNastere, const std::string& numarTelefon, const std::string& adresa)
    : Contact(nume), dataNastere(dataNastere), numarTelefon(numarTelefon), adresa(adresa) {}

void Prieten::AfisareDetalii()
{
    printf("Nume: %s\nData de nastere: %s\nNumar de telefon: %s\nAdresa: %s\n", nume.c_str(), dataNastere.c_str(), numarTelefon.c_str(), adresa.c_str());
}

Cunoscut::Cunoscut(const std::string& nume, const std::string& numarTelefon)
    : Contact(nume), numarTelefon(numarTelefon) {}

void Cunoscut::AfisareDetalii()
{
    printf("Nume: %s\nNumar de telefon: %s\n", nume.c_str(), numarTelefon.c_str());
}

Coleg::Coleg(const std::string& nume, const std::string& numarTelefon, const std::string& firma, const std::string& adresa)
    : Contact(nume), numarTelefon(numarTelefon), firma(firma), adresa(adresa) {}

void Coleg::AfisareDetalii()
{
    printf("Nume: %s\nNumar de telefon: %s\nFirma: %s\nAdresa: %s\n", nume.c_str(), numarTelefon.c_str(), firma.c_str(), adresa.c_str());
}

Contact* Agenda::CautaContact(const std::string& nume)
{
    for (Contact* contact : contacte)
    {
        if (contact->getNume() == nume)
            return contact;
    }
    return nullptr;
}

std::vector<Prieten*> Agenda::GetPrieteni()
{
    std::vector<Prieten*> prieteni;
    for (Contact* contact : contacte)
    {
        if (dynamic_cast<Prieten*>(contact) != nullptr)
            prieteni.push_back(dynamic_cast<Prieten*>(contact));
    }
    return prieteni;
}

void Agenda::StergeContact(const std::string& nume)
{
    for (auto it = contacte.begin(); it != contacte.end(); ++it)
    {
        if ((*it)->getNume() == nume)
        {
            delete *it;
            contacte.erase(it);
            break;
        }
    }
}

void Agenda::AdaugaContact(Contact* contact)
{
    contacte.push_back(contact);
}

std::vector<Contact*> Agenda::GetContacte()
{
    return contacte;
}
