//PRIM algoritmus
//Kimenet: fa eleinek sulya + apasagi tomb
#include <iostream>
#include <fstream>
#include <climits>
#include <queue>
using namespace std;
ifstream fin("prim.in");
ofstream fout("prim.out");
int n, m, elLista[15000][3] = {0}, pp[150][150] = {0}, S = 0, apa[150] = {0};
bool bejarva[150] = {false};
queue<int> sor;
int main ()
{
    fin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        fin >> elLista[i][0] >> elLista[i][1] >> elLista[i][2];
    }
    for (int i = 0; i < m; ++i)
    {
        pp[elLista[i][0]][elLista[i][1]] = elLista[i][2];
        pp[elLista[i][1]][elLista[i][0]] = elLista[i][2];
    }
    bejarva[1] = true;
    for (int lepes = 1; lepes < n; ++lepes)
    {
        int minSuly = INT_MAX, u = -1, v = -1;
        for (int i = 1; i <= n; ++i)
        {
            if (bejarva[i])
            {
                for (int j = 1; j <= n; ++j)
                {
                    if (!bejarva[j] && pp[i][j] > 0 && pp[i][j] < minSuly)
                    {
                        minSuly = pp[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        if (v != -1)
        {
            S += minSuly;
            bejarva[v] = true;
            apa[v] = u;
        }
    }
    fout << S << endl;
    for (int i = 1; i <= n; ++i)
    {
        fout << apa[i] << ' ';
    }
}
