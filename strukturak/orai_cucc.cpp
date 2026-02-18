#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("bedat.txt");
ofstream fout("kesok.txt");
int main () {
    struct tanulo {
        char kartya[10];
        int ora, perc, esemeny;

    }d[2000];

    char sz[50], kett;
    int n = 0, i = 0;
    while (fin >> sz)
    {
        strcpy(d[i].kartya, sz);

        fin >> sz;
        d[i].ora = (sz[0]-'0')*10 + (sz[1]-'0');
        d[i].perc = (sz[3]-'0')*10 + (sz[4]-'0');

        fin >> d[i].esemeny;

        ++n;
        ++i;
    }
    /*for (int i = 0; i < n; i++)
    {
        cout << d[i].kartya << " " << d[i].ora << ":" << d[i].perc << " " << d[i].esemeny << endl;
    }*/

    cout << "2-es feladat" << endl << endl;
    bool ki = false, be = false;
    i = 0;
    while (be == false && i < n)
    {
        if (d[i].esemeny == 1)
        {
            be = true;
            cout << "Az elso tanulo (" << d[i].kartya << ") ekkor lepett be: " << d[i].ora << ":" << d[i].perc;
        }
        ++i;
    }
    cout << endl;
    i = n-1;
    while (ki == false && i >= 0)
    {
        if (d[i].esemeny == 2)
        {
            ki = true;
            cout << "Az elso tanulo (" << d[i].kartya << ") ekkor lepett ki: " << d[i].ora << ":" << d[i].perc;
        }
        --i;
    }

    i = 0;
    while (d[i].perc < 50)
    {
        ++i;
    }
    ++i;
    while ((d[i].ora == 7 && d[i].perc >= 50 && d[i].perc <= 59) || (d[i].ora == 8 && d[i].perc >= 0 && d[i].perc <= 15))
    {
        fout << d[i].kartya << " " << d[i].ora << ":" << d[i].perc << endl;
        ++i;
    }
    int ebed = 0, kolcsonzes = 0;
    char kolcsonzo[10];
    for (i = 0; i < n; ++i)
    {
        if (d[i].esemeny == 3)
        {
            ++ebed;
        }
        if (d[i].esemeny == 4)
        {
            kolcsonzes++;
            strcpy(kolcsonzo, d[i].kartya);
            for (int j = i+1; j < n; ++j)
            {
                if (strcmp(kolcsonzo, d[j].kartya) == 0 && d[j].esemeny == 4)
                {
                    d[j].esemeny = 44;
                }
            }
        }
    }
    i = 0;
    while (d[i].ora != 10)
    {
        i++;
    }
    while (d[i].perc < 50)
    {
        i++;
    }
    i++;


    cout << endl << endl << endl << "4-es feladat" << endl << endl << ebed << " diak ebedelt a menzan";
    cout << endl << endl << endl << "5-os feladat" << endl << endl << kolcsonzes << " diak kolcsonzott a konyvtarbol";
    cout << endl << "Tobben voltak a menzan";
    cout << endl << endl << endl << "6-os feladat" << endl << endl << "Az erintett tanulok: ";
    char logo[10];
    bool logoe;
    while (d[i].perc <= 59)
    {
        if (d[i].esemeny == 1)
        {
            strcpy (logo, d[i].kartya);
            logoe = false;
            for (int j = i-1; j >= 0 && logoe != true; j--)
            {
                if (strcmp(logo, d[j].kartya) == 0 && d[j].esemeny == 1)
                {
                    logoe = true;
                }
                if (strcmp(logo, d[j].kartya) == 0 && d[j].esemeny == 2)
                {
                    logoe = false;
                    break;
                }
            }
            if (logoe == true)
            {
                cout << d[i].kartya << " ";
            }
        }
        i++;
    }
}
