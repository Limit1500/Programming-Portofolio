#include <iostream>
#include <fstream>
using namespace std;

ifstream input("info.in");
ofstream output("plaja.out");

int nrLinii, nrColoane, arieMax = 0;
int hist[100];

void checkHist()
{
    hist[nrColoane] = 0;
    int stiva[100], lungimeStiva = 0;
    for (int i = 0; i <= nrColoane; i++)
    {
        if (lungimeStiva == 0 || hist[stiva[lungimeStiva - 1]] <= hist[i])
        {
            stiva[lungimeStiva++] = i;
        }
        else
        {
            while (lungimeStiva && hist[stiva[lungimeStiva - 1]] > hist[i])
            {
                int arie = hist[stiva[lungimeStiva - 1]] * ((lungimeStiva >= 2) ? (i - 1 - stiva[lungimeStiva - 2]) : i);
                if (arie > arieMax)
                {
                    arieMax = arie;
                    cout << arie << ' ';
                }
                lungimeStiva--;
            }
            stiva[lungimeStiva++] = i;
        }
    }
}

int main()
{
    input >> nrLinii >> nrColoane;
    for (int i = 0; i < nrLinii; i++)
    {
        char numar;
        input.get(numar);
        for (int j = 0; j < nrColoane; j++)
        {
            input.get(numar);
            if (numar == '1')
            {
                hist[j] = 0;
            }
            else
            {
                hist[j]++;
            }
        }

        cout << '\n';
        cout << "Se calculeaza ariile pentru histul: ";
        for (int j = 0; j < nrColoane; j++)
            cout << hist[j] << ' ';
        cout << '\n';
        checkHist();
    }
}