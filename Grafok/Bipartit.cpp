#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("bipartit.in");
ofstream fout("bipartit.out");
int n, m, k, szomszedsagiLista[150][150] = {0}, szamokA[150] = {0}, szamokB[150] = {0};
bool bipartit = true, szamokBvan[150] = {false};
int main ()
{
    fin >> n >> m;
    int sz1, sz2;
    for (int i = 0; i < m; ++i)
    {
        fin >> sz1 >> sz2;
        bool vanMar = false;
        for (int j = 1; j <= szomszedsagiLista[sz1][0]; ++j)
        {
            if (szomszedsagiLista[sz1][j] == sz2)
            {
                vanMar = true;
            }
        }
        if (!vanMar)
        {
            szomszedsagiLista[sz1][0]++;
            szomszedsagiLista[sz1][szomszedsagiLista[sz1][0]] = sz2;
        }
        vanMar = false;
        for (int j = 1; j <= szomszedsagiLista[sz2][0]; ++j)
        {
            if (szomszedsagiLista[sz2][j] == sz1)
            {
                vanMar = true;
            }
        }
        if (!vanMar)
        {
            szomszedsagiLista[sz2][0]++;
            szomszedsagiLista[sz2][szomszedsagiLista[sz2][0]] = sz1;
        }
    }
    fin >> k;
    for (int i = 1; i <= k; ++i)
    {
        fin >> szamokA[i];
        szamokBvan[szamokA[i]] = true;
    }
    int f = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (szamokBvan[i] == false)
        {
            szamokB[f] = i;
            ++f;
        }
    }
    for (int i = 1; i <= k; ++i)
    {
        for (int j = 1; j <= szomszedsagiLista[szamokA[i]][0]; ++j)
        {
            for (int h = 1; h <= k; ++h)
            {
                if (szomszedsagiLista[szamokA[i]][j] == szamokA[h] && szamokA[i] != szamokA[h])
                {
                    bipartit = false;
                }
            }
        }
    }
    for (int i = 1; i <= f; ++i)
    {
        for (int j = 1; j <= szomszedsagiLista[szamokB[i]][0]; ++j)
        {
            for (int h = 1; h <= f; ++h)
            {
                if (szomszedsagiLista[szamokB[i]][j] == szamokB[h] && szamokB[i] != szamokB[h])
                {
                    bipartit = false;
                }
            }
        }
    }
    if (bipartit == true)
    {
        for (int i = 1; i <= n; ++i)
        {
            if (szomszedsagiLista[i][0] == 0)
            {
                bipartit = false;
            }
        }
    }
    if (bipartit == false)
    {
        fout << "NU";
    }
    else
    {
        fout << "DA";
    }
}
