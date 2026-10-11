#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
ifstream fin("VEZETEK.TXT");
ofstream fout("output.out");
int n, pp[150][150] = {0}, elLista[15000][3] = {0}, komponensek[150];
queue<int> sor;
int main () {
    fin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            fin >> pp[i][j];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        komponensek[i] = i;
    }
    int k = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i+1; j <= n; ++j)
        {
            if (pp[i][j] > 0)
            {
                elLista[k][0] = i;
                elLista[k][1] = j;
                elLista[k][2] = pp[i][j];
                ++k;
            }
        }
    }
    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < k - i - 1; ++j)
        {
            if ((elLista[j][2] > elLista[j+1][2]) ||
                (elLista[j][2] == elLista[j+1][2] && elLista[j][0] > elLista[j+1][0]) ||
                (elLista[j][2] == elLista[j+1][2] && elLista[j][0] == elLista[j+1][0] && elLista[j][1] > elLista[j+1][1]))
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
    for (int i = 0; i < k; ++i)
    {
        int sz1 = elLista[i][0], sz2 = elLista[i][1];
        if (komponensek[sz1] != komponensek[sz2])
        {
            sor.push(sz1);
            sor.push(sz2);
            int k1 = komponensek[sz1], k2 = komponensek[sz2];
            for (int j = 1; j <= n; ++j)
            {
                if (komponensek[j] == k2)
                    komponensek[j] = k1;

            }
        }
    }
    while (!sor.empty())
    {
        fout << '(' << sor.front() << ", ";
        sor.pop();
        fout << sor.front() << ");";
        sor.pop();
    }
}
