#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    char s[16][300];
    for (int e = 0; e <= n; ++e)
    {
        cin.getline(s[e], 300);
    }
    for (int e = 0; e <= n; ++e)
    {
        int i = 0;
        while (s[e][i] != '\0')
        {
            if ((s[e][i] == '!' || s[e][i] == '?' || s[e][i] == '.' || s[e][i] == ',') && s[e][i + 1] != '\0')
            {
            }
            else
                cout << s[e][i];
            i++;
        }
        if (e > 0)
            cout << endl;
    }
    return 0;
}