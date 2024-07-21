struct nod
{
    int info;
    nod *urm;
};

void inserare(nod *&p)
{
    nod *curent = p;

    if (p->info % 2 == 0)
    {
        nod *newNod = new nod;
        newNod->info = p->info * 2;
        newNod->urm = p;
        p = newNod;
    }

    while (curent->urm)
    {
        if (curent->urm->info % 2 == 0)
        {
            nod *newNod = new nod;
            newNod->info = curent->urm->info * 2;
            newNod->urm = curent->urm;
            curent->urm = newNod;
            curent = newNod;
        }
        curent = curent->urm;
    }
}