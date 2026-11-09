#include <iostream>
#include <fstream>
#include <climits>
#define cost 100000005
using namespace std;
ifstream fin("roy-floyd.in");
ofstream fout("roy-floyd.out");
int n, m, hossz[150][150];
int main ()
{
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            hossz[i][j] = cost;
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        int a, b, c;
        fin >> a >> b >> c;
        hossz[a][b] = c;
    }
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                hossz[i][j] = min(hossz[i][j], hossz[i][k] + hossz[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (i == j)
            {
                fout << 0 << ' ';
            }
            else if (hossz[i][j] == cost)
            {
                fout << -1 << ' ';
            }
            else
            {
                fout << hossz[i][j] << ' ';
            }
        }
        fout << endl;
    }
}
