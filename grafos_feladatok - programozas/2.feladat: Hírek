#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("input.in");
ofstream fout("output.out");
int n, t[150][150] = {0}, S = 0, K, szomszedsagiLista[150][150] = {0};
bool bejarva[150] = {false};
void DFS(int X)
{
    ++K;
    bejarva[X] = true;
    bool van = false;
    for (int i = 1; i <= szomszedsagiLista[X][0]; ++i)
    {
        if (bejarva[szomszedsagiLista[X][i]] == false)
        {
            bejarva[szomszedsagiLista[X][i]] = true;
            DFS(szomszedsagiLista[X][i]);
            van = true;
        }
    }
    if (!van)
    {
        return;
    }
}
int main ()
{
    fin >> n;
    char c;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            fin >> c;
            if (c == 'i')
            {
                t[i][j] = 1;
            }
            else
            {
                t[i][j] = 0;
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (t[i][j] == 1 && t[j][i] == 1)
            {
                ++S;
            }
        }
    }
    S /= 2;
    S /= 2;
    fout << S << endl;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (t[i][j] == 1)
            {
                szomszedsagiLista[i][0]++;
                szomszedsagiLista[i][szomszedsagiLista[i][0]] = j;
            }
        }
    }
    int sz = 0;
    for (int i = 1; i <= n; ++i)
    {
        K = 0;
        for (int j = 1; j <= n; ++j)
        {
            bejarva[j] = false;
        }
        DFS(i);
        if (K == n)
        {
            sz++;
        }
    }
    fout << sz;
}
