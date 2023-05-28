#pragma once 
#include <string>
#include <vector>

class Contact
{
protected:
    std::string nume;

public:
    Contact(const std::string& nume);
    virtual ~Contact();

    virtual void AfisareDetalii() = 0;
    std::string getNume();
};

class Prieten : public Contact
{
private:
    std::string dataNastere;
    std::string numarTelefon;
    std::string adresa;

public:
    Prieten(const std::string& nume, const std::string& dataNastere, const std::string& numarTelefon, const std::string& adresa);

    void AfisareDetalii() override;
};

class Cunoscut : public Contact
{
private:
    std::string numarTelefon;

public:
    Cunoscut(const std::string& nume, const std::string& numarTelefon);

    void AfisareDetalii() override;
};

class Coleg : public Contact
{
private:
    std::string numarTelefon;
    std::string firma;
    std::string adresa;

public:
    Coleg(const std::string& nume, const std::string& numarTelefon, const std::string& firma, const std::string& adresa);

    void AfisareDetalii() override;
};

class Agenda
{
private:
    std::vector<Contact*> contacte;

public:
    Contact* CautaContact(const std::string& nume);
    std::vector<Prieten*> GetPrieteni();
    void StergeContact(const std::string& nume);
    void AdaugaContact(Contact* contact);
    std::vector<Contact*> GetContacte();
};

