#include <iostream>
using namespace std;

struct nod
{
    int value;
    nod *nextNod = nullptr;
}

main()
{
    int numarOperatii;

    cin >> numarOperatii;

    nod *capulStivei = new nod;
    nod *capulElementelorAfisate = new nod;

    nod *curentStiva = capulStivei;
    nod *curentElementeAfisate = capulElementelorAfisate;

    for (int i = 0; i < numarOperatii; i++)
    {
        string operatie;

        cin >> operatie;

        if (operatie == "push")
        {
            int numar;
            cin >> numar;

            nod *elementNou = new nod;
            elementNou->value = numar;

            curentStiva->nextNod = elementNou;
            curentStiva = curentStiva->nextNod;
        }
        else if (operatie == "top")
        {
            if (capulStivei->nextNod != nullptr)
            {
                nod *nouElementAfisat = new nod;
                nouElementAfisat->value = curentStiva->value;

                curentElementeAfisate->nextNod = nouElementAfisat;
                curentElementeAfisate = curentElementeAfisate->nextNod;
            }
        }
        else if (operatie == "pop")
        {
        }
    }
}