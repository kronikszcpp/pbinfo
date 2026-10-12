#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("zapada.in");
ofstream fout("zapada.out");
int n, m, elLista[15000][3] = {0}, k, kotelezoUtcak[150] = {0}, komponensek[150] = {0}, koltseg = 0;
int main ()
{
    fin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        fin >> elLista[i][0] >> elLista[i][1] >> elLista[i][2];
    }
    for (int i = 1; i <= n; ++i)
    {
        komponensek[i] = i;
    }
    fin >> k;
    for (int i = 0; i < k; ++i)
    {
        int sz;
        fin >> sz;
        int s1 = elLista[sz][0], s2 = elLista[sz][1];
        koltseg += elLista[sz][2];
        int k1 = komponensek[s1], k2 = komponensek[s2];
        for (int j = 1; j <= n; ++j)
        {
            if (komponensek[j] == k2)
            {
                komponensek[j] = k1;
            }
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j < m - i + 1; ++j)
        {
            if (elLista[j][2] > elLista[j+1][2])
            {
                int tmp = elLista[j][2];
                elLista[j][2] = elLista[j+1][2];
                elLista[j+1][2] = tmp;

                tmp = elLista[j][1];
                elLista[j][1] = elLista[j+1][1];
                elLista[j+1][1] = tmp;

                tmp = elLista[j][0];
                elLista[j][0] = elLista[j+1][0];
                elLista[j+1][0] = tmp;

            }
        }
    }

    for (int i = 1; i <= m; ++i)
    {
        int sz1 = elLista[i][0], sz2 = elLista[i][1];
        if (komponensek[sz1] != komponensek[sz2])
        {
            koltseg += elLista[i][2];
            int k1 = komponensek[sz1], k2 = komponensek[sz2];
            for (int j = 1; j <= n; ++j)
            {
                if (komponensek[j] == k2)
                {
                    komponensek[j] = k1;
                }
            }
        }
    }
    fout << koltseg;
}
