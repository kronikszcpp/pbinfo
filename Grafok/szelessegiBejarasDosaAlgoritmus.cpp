//---------------------##SZELESSEGI BEJARAS##---------------------
//---------------------## DOSA ALGORITMUS ##---------------------
//ELLISTABOL -> PONT-PONT MATRIX -> SZELESSEGI BEJARAS
#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("input.in");
ofstream fout("output.out");

int main () {
    int elLista[100][2], n, ln = -1;
    fin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int szam1, szam2;
        fin >> szam1 >> szam2;
        ln = max(ln, szam1);
        ln = max(ln, szam2);
        elLista[i][0] = szam1;
        elLista[i][1] = szam2;
    }

    int pontPont[ln+1][ln+1];
    for (int i = 1; i <= ln; ++i)
    {
        for (int j = 1; j <= ln; j++)
        {
            pontPont[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        pontPont[elLista[i][0]][elLista[i][1]] = 1;
        pontPont[elLista[i][1]][elLista[i][0]] = 1;
    }

    int bejarva[2][ln+1];
    for (int i = 1; i <= ln; ++i)
    {
        bejarva[0][i] = 0;
        bejarva[1][i] = 0;
    }

    int aktualisPozicio = 1, lepesek[100000] = {0}, aktualisLepeszszam = 1;
    bejarva[0][1] = 1;
    bejarva[1][1] = 1;
    lepesek[1] = 1;
    bool kesz = false;
    while (kesz == false)
    {
        for (int j = 1; j <= ln; ++j)
        {
            if (pontPont[aktualisPozicio][j] == 1)
            {
                bejarva[0][j] = 1;
            }
        }

        bool talalt = false;
        for (int j = 1; j <= ln; ++j)
        {
            if (pontPont[aktualisPozicio][j] == 1 && bejarva[1][j] == 0)
            {
                talalt = true;
                aktualisPozicio = j;
                aktualisLepeszszam++;
                lepesek[aktualisLepeszszam] = aktualisPozicio;
                bejarva[1][j] = 1;
                break;
            }
        }
        if (talalt == false)
        {
            aktualisLepeszszam--;
            if (aktualisLepeszszam == 0)
            {
                kesz = true;
            }
            else
            {
                aktualisPozicio = lepesek[aktualisLepeszszam];
            }
        }
    }
    for (int i = 1; i <= ln; ++i)
    {
        cout << bejarva[0][i] << ' ' << bejarva[1][i] << endl;
    }
}
