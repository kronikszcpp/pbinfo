#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("dfs.in");
ofstream fout("dfs.out");
int n, m, X, szomszedsagiLista[150][150] = {0};
bool latva[150] = {false};

void DFS(int S)
{
    latva[S] = true;
    fout << S << ' ';
    bool van = false;
    for (int i = 1; i <= szomszedsagiLista[S][0]; ++i)
    {
        if (latva[szomszedsagiLista[S][i]] == false)
        {
            latva[szomszedsagiLista[S][i]] = true;
            DFS(szomszedsagiLista[S][i]);
            van = true;
        }
    }
    if (van == false)
    {
        return;
    }
}

int main () {
    fin >> n >> m >> X;
    int szam1, szam2;
    for (int i = 0; i < m; ++i)
    {
        fin >> szam1 >> szam2;
        bool vanMar = false;
        for (int j = 1; j <= szomszedsagiLista[szam1][0]; ++j)
        {
            if (szomszedsagiLista[szam1][j] == szam2)
            {
                vanMar = true;
            }
        }
        if (!vanMar)
        {
            szomszedsagiLista[szam1][0]++;
            szomszedsagiLista[szam1][szomszedsagiLista[szam1][0]] = szam2;
        }
        vanMar = false;
        for (int j = 1; j <= szomszedsagiLista[szam2][0]; ++j)
        {
            if (szomszedsagiLista[szam2][j] == szam1)
            {
                vanMar = true;
            }
        }
        if (!vanMar)
        {
            szomszedsagiLista[szam2][0]++;
            szomszedsagiLista[szam2][szomszedsagiLista[szam2][0]] = szam1;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        sort(szomszedsagiLista[i] + 1, szomszedsagiLista[i] + szomszedsagiLista[i][0] + 1);
    }
    DFS(X);
}
