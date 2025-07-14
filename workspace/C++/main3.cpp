#include <iostream>
using namespace std;

char a[256];
int stiva[1000][2];
int l;

// citește un număr de după poziția i, returnând 1 dacă nu există cifre
int getNumber(int &i)
{
    int x = 0;
    while (a[i] >= '0' && a[i] <= '9')
    {
        x = x * 10 + (a[i] - '0');
        i++;
    }
    return x == 0 ? 1 : x;
}

// procesează sub-șirul începând de la start; la final întoarce noua poziție
int paranteza(int start)
{
    // intrăm pe un nou nivel
    l++;
    // inițial stiva[l-1] = {0,0}
    stiva[l - 1][0] = stiva[l - 1][1] = 0;

    // parcurgem până la ')' sau până la sfârșitul real al șirului
    while (a[start] != ')' && a[start] != '\0')
    {
        if (a[start] == '(')
        {
            // recursiv pentru sub-grup
            start = paranteza(start + 1);
        }
        else if (a[start] == 'A' || a[start] == 'B')
        {
            // litera curentă
            int idx = (a[start] == 'A' ? 0 : 1);
            start++;
            // adun numărul găsit (implicit 1)
            stiva[l - 1][idx] += getNumber(start);
        }
        else
        {
            // dacă e alt caracter, doar sărim peste el
            start++;
        }
    }

    // dacă am ajuns la sfârșit de șir, cobor fără a combina cu un nivel superior
    if (a[start] == '\0')
    {
        l--;
        return start;
    }

    // acum a[start] == ')' → sarim peste ')'
    start++;
    // și citim multiplicatorul
    int mul = getNumber(start);
    stiva[l - 1][0] *= mul;
    stiva[l - 1][1] *= mul;

    // combin doar dacă există un nivel superior real
    if (l > 1)
    {
        stiva[l - 2][0] += stiva[l - 1][0];
        stiva[l - 2][1] += stiva[l - 1][1];
    }
    l--;
    return start;
}

int main()
{
    // citire
    cin >> a;

    // inițializez stivă cu un cadru "rădăcină"
    l = 1;
    stiva[0][0] = stiva[0][1] = 0;

    // parse complete
    paranteza(0);

    // afișez rezultatul
    cout << stiva[0][0] << " " << stiva[0][1];
    return 0;
}
