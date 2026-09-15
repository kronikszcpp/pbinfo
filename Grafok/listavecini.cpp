#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("listavecini.in");
ofstream fout("listavecini.out");

int main () {

    int n;
    fin >> n;
    int t[150][150] = {0}, szam1, szam2;
    while (fin >> szam1)
    {
        fin >> szam2;

        bool marVan = false;
        for (int j = 1; j <= t[szam1][0]; ++j)
        {
            if (t[szam1][j] == szam2)
            {
                marVan = true;
            }
        }
        if (marVan == false)
        {
            t[szam1][0]++;
            t[szam1][t[szam1][0]] = szam2;
        }

        marVan = false;
        for (int j = 1; j <= t[szam2][0]; ++j)
        {
            if (t[szam2][j] == szam1)
            {
                marVan = true;
            }
        }
        if (marVan == false)
        {
            t[szam2][0]++;
            t[szam2][t[szam2][0]] = szam1;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        sort(t[i] + 1, t[i] + t[i][0] + 1);
    }

    for (int i = 1; i <= n; ++i)
    {
        fout << t[i][0] << ' ';
        for (int j = 1; j <= t[i][0]; ++j)
        {
            fout << t[i][j] << ' ';
        }
        fout << endl;
    }
}
