#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
ifstream fin("input.in");
ofstream fout("output.out");
int n, m = 0, elLista[150][3] = {0}, bandak[150]={0},  S = 0, szomszedsagiLista[150][150] = {0};
bool nemMaganyos[150] = {false};
queue<int> sor;
void BFS(int X)
{
    bandak[X] = S;
    sor.push(X);
    while (!sor.empty())
    {
        int sz;
        sz = sor.front();
        sor.pop();
        for (int i = 1; i <= szomszedsagiLista[sz][0]; ++i)
        {
            if (bandak[szomszedsagiLista[sz][i]] == 0)
            {
                sor.push(szomszedsagiLista[sz][i]);
                bandak[szomszedsagiLista[sz][i]] = S;
            }
        }
    }
}
int main ()
{
    fin >> n;
    int szam1, szam2;
    while (fin >> szam1 >> szam2)
    {
        elLista[m][0] = szam1;
        elLista[m][1] = szam2;
        nemMaganyos[szam1] = true;
        nemMaganyos[szam2] = true;
        ++m;
        bool vanMar = false;
        for (int i = 1; i <= szomszedsagiLista[szam1][0]; ++i)
        {
            if (szomszedsagiLista[szam1][i] == szam2)
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
        for (int i = 1; i <= szomszedsagiLista[szam2][0]; ++i)
        {
            if (szomszedsagiLista[szam2][i] == szam1)
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
    //a:
    for (int i = 1; i <= n; ++i)
    {
        if (!nemMaganyos[i])
        {
            fout << i << ' ';
        }
    }
    fout << endl;
    //b:
    for (int i = 1; i <= n; ++i)
    {
        if (bandak[i] == 0)
        {
            ++S;
            BFS(i);
        }
    }
    S = 0;
    for (int i = 1; i <= n; ++i)
    {
        int sz = 0;
        for (int j = 1; j <= n; ++j)
        {
            if (bandak[j] == i)
            {
                ++sz;
            }
        }
        if (sz >= 2)
        {
            ++S;
        }
    }
    fout << S << endl;
    //c:
    for (int i = 1; i <= S; ++i)
    {
        int lt = -1, lsz;
        for (int j = 1; j <= n; ++j)
        {
            if (bandak[j] == i)
            {
                if (szomszedsagiLista[j][0] > lt)
                {
                    lt = szomszedsagiLista[j][0];
                    lsz = j;
                }
            }
        }
        fout << lsz << ' ';
    }
    fout << endl;
    //d:
    int lt = -1;
    for (int i = 1; i <= S; ++i)
    {
        int sz = 0;
        for (int j = 1; j <= n; ++j)
        {
            if (bandak[j] == i)
            {
                ++sz;
            }
        }
        if (sz > lt)
        {
            lt = sz;
        }
    }
    fout << lt << endl;
    //e:
    for (int i = 1; i <= S; ++i)
    {
        int elemek[150] = {0}, k = 1;
        for (int j = 1; j <= n; ++j)
        {
            if (bandak[j] == i)
            {
                elemek[k++] = j;
            }
        }
        queue<int> sor2;
        for (int j = 1; j < k; ++j)
        {
            
        }
    }
}
