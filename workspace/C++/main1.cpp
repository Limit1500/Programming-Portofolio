#include <iostream>
#include <fstream>
using namespace std;

ifstream input("info.in");
ofstream output("info.out");

int n, numereSelectate[10], numereleIntroduse[10];

void afisare()
{
    for (int i = 0; i < n; i++)
    {
        output << numereSelectate[i] << " ";
    }
    output << '\n';
}

bool suntPrime(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return (a == 1);
}

bool nuSeRepeta(int x, int k)
{
    for (int i = 0; i < k; i++)
    {
        if (numereSelectate[i] == x)
        {
            return false;
        }
    }
    return true;
}

bool esteValid(int x, int k)
{
    if (k == 0)
    {
        return true;
    }
    if (suntPrime(x, numereSelectate[k - 1]) && nuSeRepeta(x, k))
    {
        return true;
    }
    return false;
}

void backtraking(int k = 0)
{
    if (k == n)
    {
        afisare();
        return;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (esteValid(numereleIntroduse[i], k))
            {
                numereSelectate[k] = numereleIntroduse[i];
                backtraking(k + 1);
            }
        }
    }
}

void sortArray(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    input >> n;

    for (int i = 0; i < n; i++)
    {
        input >> numereleIntroduse[i];
    }
    sortArray(numereleIntroduse, n);

    backtraking();
}