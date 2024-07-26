struct nod
{
    int info;
    nod *ant, *urm;
};

bool Palindrom(nod *prim, nod *ultim)
{
    while (prim != ultim)
    {
        if (prim->info != ultim->info)
        {
            return false;
        }
        prim = prim->urm;
        ultim = ultim->ant;
    }
    return true;
}