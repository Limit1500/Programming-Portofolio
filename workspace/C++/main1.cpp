#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
using namespace std;

ifstream input("submdiv.in");
ofstream output("submdiv.out");

int n, m;
int permutare[6], divizori[32], nrDiv = 0;
bool sol = false;

void afisare()
{
    for (int i = 0; i < m; i++)
    {
        output << permutare[i] << " ";
    }
    output << '\n';
    sol = true;
}

int gasesteDivizori()
{

    for (int d = 1; d * d <= n; d++)
        if (n % d == 0)
        {
            divizori[nrDiv++] = d;
            if (d * d < n)
                divizori[nrDiv++] = n / d;
        }
}

void backtraking(int k = 0, int next = 0)
{
    if (k == m)
    {
        afisare();
        return;
    }
    for (int i = next; i < nrDiv; i++)
    {
        permutare[k] = divizori[i];
        backtraking(k + 1, i + 1);
    }
}

int main()
{
    input >> n >> m;
    gasesteDivizori();
    sort(divizori, divizori + nrDiv);
    backtraking(0, 0);
    if (sol == false)
    {
        output << "fara solutie";
    }
}