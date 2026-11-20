#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("input.in");
ofstream fout("output.out");
int tesztekSzama;
char betuk[10005], edzesTerv[50];
int main ()
{
    fin >> tesztekSzama;

    int edzesekSzama;
    for (int i = 1; i <= tesztekSzama; ++i)
    {
        fin >> betuk;
        int g = 0;
        while (g < strlen(betuk))
        {
            if (betuk[g] == betuk[g+1])
            {
                strcpy(betuk + g, betuk + g + 1);
            }
            else
            {
                g++;
            }
        }
        fout << "Test #" << i << ":" << endl;
        fin >> edzesekSzama;
        for (int j = 1; j <= edzesekSzama; ++j)
        {
            fin >> edzesTerv;
            int S = 0;
            for (int k = 0; k < strlen(betuk); ++k)
            {
                if (betuk[k] == edzesTerv[0])
                {
                    bool ok = true;
                    int h = 0;
                    while (ok && k+1 < strlen(betuk) && h+1 < strlen(edzesTerv))
                    {
                        ++k;
                        ++h;
                        if (betuk[k] != edzesTerv[h])
                        {
                            ok = false;

                        }
                    }
                    if (ok && h == strlen(edzesTerv) - 1)
                    {
                        S++;
                    }
                }

            }

            fout << edzesTerv << ": " << S << endl;
        }
    }
}
