#include <iostream>
#include <vector>
#include "contact.h"

int main()
{
    // Exemplu de utilizare a claselor
    Agenda agenda;

    // Adaugare contacte
    Contact* prieten1 = new Prieten("Ana", "01.01.1990", "123456789", "Strada A");
    Contact* prieten2 = new Prieten("Maria", "02.02.1991", "987654321", "Strada B");
    Contact* cunoscut1 = new Cunoscut("Ion", "111111111");
    Contact* coleg1 = new Coleg("Alex", "222222222", "Compania X", "Strada C");

    agenda.AdaugaContact(prieten1);
    agenda.AdaugaContact(prieten2);
    agenda.AdaugaContact(cunoscut1);
    agenda.AdaugaContact(coleg1);

    // Cautare contact
    printf("Cautare contact:\n");
    Contact* contactCautat = agenda.CautaContact("Maria");
    if (contactCautat != nullptr)
        contactCautat->AfisareDetalii();
    else
        printf("Contactul nu a fost gasit.\n");

    printf("\n");

    // Afisare prieteni
    printf("Lista de prieteni:\n");
    std::vector<Prieten*> prieteni = agenda.GetPrieteni();
    for (Prieten* prieten : prieteni)
        prieten->AfisareDetalii();

    printf("\n");

    // Stergere contact
    printf("Stergere contact:\n");
    agenda.StergeContact("Ana");

    // Afisare contacte ramase
    printf("Contacte ramase:\n");
    for (Contact* contact : agenda.GetContacte())
        contact->AfisareDetalii();

    // Eliberare memorie
    for (Contact* contact : agenda.GetContacte())
        delete contact;

    return 0;
}


