#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("bipartit1.in");
ofstream fout("bipartit1.out");
int n, m, szomszdsagiLista[150][150] = {0}, S = 0, sor1[150] = {0}, sor2[150] = {0}, s1 = 0, s2 = 0;
int voltMar[150] = {0};
int main ()
{
    fin >> m >> n;
    int sz1, sz2;
    for (int i = 1; i <= n; ++i)
    {
        fin >> sz1 >> sz2;
        szomszdsagiLista[sz1][0]++;
        szomszdsagiLista[sz1][szomszdsagiLista[sz1][0]] = sz2;
        szomszdsagiLista[sz2][0]++;
        szomszdsagiLista[sz2][szomszdsagiLista[sz2][0]] = sz1;
    }
    for (int i = 1; i <= m; ++i)
    {
        if (voltMar[i] == 0)
        {
            voltMar[i] = 1;
            sor1[s1] = i;
            s1++;
            S++;
            for (int j = 1; j <= szomszdsagiLista[i][0]; ++j)
            {
                if (voltMar[szomszdsagiLista[i][j]] == 0)
                {
                    voltMar[szomszdsagiLista[i][j]] = 2;
                    sor2[s2] = szomszdsagiLista[i][j];
                    s2++;
                    S++;
                }
            }
        }
    }
    if (S == m)
    {
        fout << "DA";
        fout << endl;
        sort(sor1, sor1 + s1);
        sort(sor2, sor2 + s2);
        for (int i = 0; i < s1; ++i)
        {
            fout << sor1[i] << ' ';
        }
        fout << endl;
        for (int i = 0; i < s2; ++i)
        {
            fout << sor2[i] << ' ';
        }
    }
    else
    {
        fout << "NU";
    }

}
