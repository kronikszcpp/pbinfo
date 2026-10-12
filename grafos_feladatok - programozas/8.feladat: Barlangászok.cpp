#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
using namespace std;
ifstream fin("Barlang.be");
ofstream fout("Barlang.ki");
int n, m, bejarva[250] = {0}, szomszedsagiLista[250][250] = {0}, S = 1;
queue<int> sor;
void BFS(int X)
{
    bejarva[X] = S;
    sor.push(X);
    while (!sor.empty())
    {
        int sz;
        sz = sor.front();
        sor.pop();
        for (int i = 1; i <= szomszedsagiLista[sz][0]; ++i)
        {
            if (bejarva[szomszedsagiLista[sz][i]] == 0)
            {
                bejarva[szomszedsagiLista[sz][i]] = S;
                sor.push(szomszedsagiLista[sz][i]);
            }
        }
    }
}
int main ()
{
    fin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int sz1, sz2;
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
    for (int i = 1; i <= n; ++i)
    {
        sort(szomszedsagiLista[i] + 1, szomszedsagiLista[i] + szomszedsagiLista[i][0] + 1);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (bejarva[i] == 0)
        {
            BFS(i);
            ++S;
        }
    }
    int G = -1;
    for (int i = 1; i < S; ++i)
    {
        int g = 0;
        for (int j = 1; j <= n; ++j)
        {
            if (bejarva[j] == i)
            {
                g++;
            }
        }
        if (g > G)
        {
            G = g;
        }
    }
    fout << G << endl;
    for (int i = 1; i <= n; ++i)
    {
        if (bejarva[i] == G)
        {
            fout << i << ' ';
        }
    }
}
