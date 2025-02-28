#include <iostream>
using namespace std;

int main()
{
    int a[10], n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

        if (a[i] == 1)
        {
            cout << "DA" << '\n';
        }
        else
        {
            int x = 1, y = 1;

            while (a[i] < x + y)
            {
                int c = x + y;
                x = y;
                y = c;
            }
            if (x + y != a[i])
            {
                cout << "NU" << '\n';
            }
            else
            {
                cout << "DA" << '\n';
            }
        }
    }
}
