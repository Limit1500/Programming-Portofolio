void FAdaugaInainte(Nod *&head)
{
    Nod *curent = head;
    if (head->info % 2 == 1)
    {
        Nod *newNod = new Nod;

        newNod->leg = head;
        newNod->info = head->info * 2;

        head = newNod;
    }

    while (curent->leg != nullptr)
    {
        if (curent->leg->info % 2 == 1)
        {
            Nod *newNod = new Nod;

            newNod->info = curent->leg->info * 2;
            newNod->leg = curent->leg;

            curent->leg = newNod;
            curent = newNod->leg;
        }
        else
        {
            curent = curent->leg;
        }
    }
}