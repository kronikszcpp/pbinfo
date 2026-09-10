#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("input.in");
ofstream fout("output.out");
int main ()
{
    int szam1, szam2, ln = -1;
    int szomszedsagiMatrix[100][100] = {0};
    int szomszedsagiLista[100][100] = {0};
    while (fin >> szam1)
    {
        fin >> szam2;
        szomszedsagiMatrix[szam1][szam2] = 1;
        szomszedsagiMatrix[szam2][szam1] = 1;

        ln = max(ln, szam1);
        ln = max(ln, szam2);

        szomszedsagiLista[szam1][0]++;
        szomszedsagiLista[szam1][szomszedsagiLista[szam1][0]] = szam2;
        szomszedsagiLista[szam2][0]++;
        szomszedsagiLista[szam2][szomszedsagiLista[szam2][0]] = szam1;
    }
    for (int i = 1; i <= ln; ++i)
    {
        for (int j = 1; j <= ln; ++j)
        {
            fout << szomszedsagiMatrix[i][j] << ' ';
        }
        fout << endl;
    }

    fout << "-------------------##-------------------" << endl;

    for (int i = 1; i <= ln; ++i)
    {
        for (int j = 1; j <= szomszedsagiLista[i][0]; ++j)
        {
            fout << szomszedsagiLista[i][j] << ' ';
        }
        fout << endl;
    }

}
