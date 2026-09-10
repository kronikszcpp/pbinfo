#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("input.in");
ofstream fout("output.out");

int main () {
    int pontEl[10][10] = {0}, elLista[100][5], szomszedsagiLista[100][100] = {0}, szomszedsagiMatrix[100][100] = {0};
    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            fin >> pontEl[i][j];
        }
    }

    int k = 0;
    for (int j = 0; j < 8; ++j)
    {
        int szam1 = -1, szam2 = -1;
        for (int i = 0; i < 6; ++i)
        {
            if (pontEl[i][j] == 1)
            {
                if (szam1 == -1)
                {
                    szam1 = i+1;
                }
                else
                {
                    szam2 = i+1;
                }
            }
        }
        szomszedsagiLista[szam1][0]++;
        szomszedsagiLista[szam1][szomszedsagiLista[szam1][0]] = szam2;
        szomszedsagiLista[szam2][0]++;
        szomszedsagiLista[szam2][szomszedsagiLista[szam2][0]] = szam1;
        szomszedsagiMatrix[szam1][szam2] = 1;
        szomszedsagiMatrix[szam2][szam1] = 1;
        elLista[k][0] = szam1;
        elLista[k][1] = szam2;
        k++;
     }

    for (int i = 0; i < k; ++i)
    {
        cout << elLista[i][0] << ' ' << elLista[i][1] << endl;
    }
    cout << "----------------------##----------------------" << endl;
    for (int i = 1; i <= 6; ++i)
    {
        cout << i << ": ";
        for (int j = 1; j <= szomszedsagiLista[i][0]; ++j)
        {
            cout << szomszedsagiLista[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "----------------------##----------------------" << endl;
    for (int i = 1; i <= 6; ++i)
    {
        for (int j = 1; j <= 6; ++j)
        {
            cout << szomszedsagiMatrix[i][j] << ' ';
        }
        cout << endl;
    }
}
