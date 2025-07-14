#include <iostream>
#include <fstream>
using namespace std;

ifstream input("info.in");
ofstream output("info.out");

int main()
{
    int a[100000], n;
    input >> n;
    for (int i = 0; i < n; i++)
    {
        input >> a[i];
    }

    int b[100000], m;
    input >> m;
    for (int i = 0; i < m; i++)
    {
        input >> b[i];
    }
    // pana aici e bine

    int i = 0, j = 0, cnt = 0;
    while (i != n && j != m)
    {
        if (a[i] <= b[j] && i < n)
        {
            output << a[i] << " ";
            i++;
            j++;
            cnt++;
        }
        else if (b[j] < a[i])
        {
            output << b[j] << " ";
            j++;
            cnt++;
        }
        if (cnt % 10 == 0)
        {
            output << '\n';
        }
    }

    if (i != n)
    {
        for (i; i < n; i++)
        {
            output << a[i] << " ";
            cnt++;
            if (cnt % 10 == 0)
                output << '\n';
        }
    }
    else if (j != m)
    {
        for (j; j < m; j++)
        {
            output << b[j] << " ";
            cnt++;
            if (cnt % 10 == 0)
                output << '\n';
        }
    }
}