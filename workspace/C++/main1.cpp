#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == i || i + j == n - 1)
                cout << 0 << " ";
            else if (i + j < n - 1 && j > i)
                cout << 1 << " ";
            else if (i + j > n - 1 && i > j)
                cout << 2 << " ";
            else
                cout << 3 << " ";
        }
        cout << '\n';
    }
}