struct nod
{
    int info;
    nod *urm;
};

void sterge(nod *&p)
{
    nod *curent = p;

    while (curent != nullptr)
    {
        if (curent->info % 2 == 0)
        {
            nod *temp = curent;
            curent = curent->urm;
            delete temp;
        }
        else
        {
            curent = curent->urm;
        }
    }
}

void sterge(nod *&p)
{
    // Verificăm și ștergem nodurile de la începutul listei dacă sunt pare
    while (p != nullptr && p->info % 2 == 0)
    {
        nod *temp = p;
        p = p->urm;
        delete temp;
    }

    if (p == nullptr) // Dacă lista a devenit goală
        return;

    nod *curent = p;
    while (curent != nullptr && curent->urm != nullptr)
    {
        if (curent->urm->info % 2 == 0)
        {
            nod *temp = curent->urm;
            curent->urm = curent->urm->urm;
            delete temp;
        }
        else
        {
            curent = curent->urm;
        }
    }
}