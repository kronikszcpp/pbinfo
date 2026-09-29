#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
ifstream fin("ISMER.BE");
ofstream fout("ISMER.KI");
int szomszedsagiMatrix[150][150] = {0}, n, m, S = 0, szomszedsagiLista[150][150] = {0}, G = 0;
queue<int> sor;
int main ()
{
    fin >> n >> m;
    int szam1, szam2;
    for (int i = 0; i < m; ++i)
    {
        fin >> szam1 >> szam2;
        szomszedsagiMatrix[szam1][szam2] = 1;
        szomszedsagiMatrix[szam2][szam1] = 1;
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
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            bool megegyezik = true;
            int k = 1, sz = 0;
            for (int k = 1; k <= n; ++k)
            {
                if (k == i || k == j)
                {
                    continue;
                }
                if (szomszedsagiMatrix[j][k] == 1 && szomszedsagiMatrix[i][k] == 1)
                {
                    ++sz;
                }
                if (szomszedsagiMatrix[j][k] != szomszedsagiMatrix[i][k])
                {
                    megegyezik = false;
                    break;
                }
            }
            if (megegyezik && sz >= 1)
            {
                ++S;
                sor.push(i);
                sor.push(j);
            }
        }
    }
    fout << S << endl;
    while (!sor.empty())
    {
        int sz1, sz2;
        sz1 = sor.front();
        sor.pop();
        sz2 = sor.front();
        sor.pop();
        fout << sz1 << ' ' << sz2 << endl;
    }
    bool vanKozos = false;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            vanKozos = false;
            for (int k = 1; k <= szomszedsagiLista[j][0]; ++k)
            {
                for (int h = 1; h <= szomszedsagiLista[i][0]; ++h)
                {
                    if (szomszedsagiLista[i][h] == szomszedsagiLista[j][k])
                    {
                        vanKozos = true;
                        break;
                    }
                }
            }
            if (vanKozos)
            {
                ++G;
                sor.push(i);
                sor.push(j);
            }
        }
    }
    fout << G << endl;
    while (!sor.empty())
    {
        int sz1, sz2;
        sz1 = sor.front();
        sor.pop();
        sz2 = sor.front();
        sor.pop();
        fout << sz1 << ' ' << sz2 << endl;
    }
}
