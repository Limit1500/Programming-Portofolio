#include <iostream>
using namespace std;

int main()
{
    int stiva[1000], lungimeStiva = 0;
    int nrOperatii;

    cin >> nrOperatii;

    string operatie;
    int numar;

    int elAfisate[200], lungimeElAfisate = 0;

    for (int i = 0; i < nrOperatii; i++)
    {
        cin >> operatie;

        if (operatie == "push")
        {
            cin >> numar;

            stiva[lungimeStiva++] = numar;
        }
        else if (operatie == "pop")
        {
            if (lungimeStiva > 0)
                lungimeStiva--;
        }
        else if (operatie == "top")
        {
            if (lungimeStiva > 0)
                elAfisate[lungimeElAfisate++] = stiva[lungimeStiva - 1];
        }
    }

    cout << lungimeElAfisate;

    for (int i = 0; i < lungimeElAfisate; i++)
    {
        cout << elAfisate[i] << '\n';
    }
}
