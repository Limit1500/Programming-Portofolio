#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char prenume[21], nume[21];
    cin >> nume >> prenume;

    for (int i = 0; i < strlen(prenume); i++)
    {
        if (prenume[i] != 'a' && prenume[i] != 'A' && prenume[i] != 'e' && prenume[i] != 'E' && prenume[i] != 'i' && prenume[i] != 'I' && prenume[i] != 'o' && prenume[i] != 'O' && prenume[i] != 'u' && prenume[i] != 'U')
        {
            cout << prenume[i];
        }
    }
    cout << " ";
    for (int i = 0; i < strlen(nume); i++)
    {
        cout << nume[i];
    }
}
