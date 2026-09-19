#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>

using namespace std;

ifstream fin("input.in");
ofstream fout("output.out");

int n, m, X, szam1, szam2, szomszedsagiLista[150][150] = {0};
bool latva[150] = {false};
queue<int> sor;

void BFS()
{
    int S = X;
    latva[S] = true;
    sor.push(S);
    while (!sor.empty())
    {
        int sz;
        sz = sor.front();
        sor.pop();
        for (int i = 1; i <= szomszedsagiLista[sz][0]; ++i)
        {
            if (latva[szomszedsagiLista[sz][i]] == false)
            {
                latva[szomszedsagiLista[sz][i]] = true;
                sor.push(szomszedsagiLista[sz][i]);
            }
        }
        fout << sz << ' ';
    }
}

int main () {

    fin >> n >> m >> X;
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
        if (vanMar == false)
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
        if (vanMar == false)
        {
            szomszedsagiLista[szam2][0]++;
            szomszedsagiLista[szam2][szomszedsagiLista[szam2][0]] = szam1;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        sort(szomszedsagiLista[i] + 1, szomszedsagiLista[i] + szomszedsagiLista[i][0] + 1);
    }
    BFS();
}
