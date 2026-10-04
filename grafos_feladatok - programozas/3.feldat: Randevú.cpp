#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;
ifstream fin("RANDI.BE");
ofstream fout("RANDI.KI");
int N, E, A, R, M, szomszedsagiLista[150][150] = {0};
int adamSzulo[150] = {0}, evaSzulo[150] = {0};
bool adamBejarasa[150] = {false}, evaBejarasa[150] = {false};
queue<int> sor;
stack<int> adamUt;
stack<int> evaUt;
int main ()
{
    fin >> N >> E >> A >> R >> M;
    int szam1, szam2;
    for (int i = 0; i < M; ++i)
    {
        fin >> szam1 >> szam2;
        bool vanMar = false;
        for (int j = 1; j <= szomszedsagiLista[szam1][0]; ++j)
        {
            if (szomszedsagiLista[szam1][j] == szam2)
            {
                vanMar = true;
                break;
            }
        }
        if (!vanMar)
        {
            szomszedsagiLista[szam1][0]++;
            szomszedsagiLista[szam1][szomszedsagiLista[szam1][0]] = szam2;
        }
    }
    for (int i = 1; i <= N; ++i)
    {
        sort(szomszedsagiLista[i] + 1, szomszedsagiLista[i] + szomszedsagiLista[i][0] + 1);
    }
    sor.push(A);
    adamBejarasa[A] = true;
    adamSzulo[A] = 0;
    while (!sor.empty())
    {
        int sz;
        sz = sor.front();
        sor.pop();
        for (int i = 1; i <= szomszedsagiLista[sz][0]; ++i)
        {
            if (adamBejarasa[szomszedsagiLista[sz][i]] == false)
            {
                adamBejarasa[szomszedsagiLista[sz][i]] = true;
                adamSzulo[szomszedsagiLista[sz][i]] = sz;
                sor.push(szomszedsagiLista[sz][i]);
            }
        }
    }
    sor.push(E);
    evaBejarasa[E] = true;
    evaSzulo[E] = 0;
    while (!sor.empty())
    {
        int sz;
        sz = sor.front();
        sor.pop();
        for (int i = 1; i <= szomszedsagiLista[sz][0]; ++i)
        {
            if (evaBejarasa[szomszedsagiLista[sz][i]] == false)
            {
                evaBejarasa[szomszedsagiLista[sz][i]] = true;
                evaSzulo[szomszedsagiLista[sz][i]] = sz;
                sor.push(szomszedsagiLista[sz][i]);
            }
        }
    }
    int S = R, G = 0;
    while (adamSzulo[S] != 0)
    {
        ++G;
        adamUt.push(S);
        S = adamSzulo[S];
    }
    G++;
    adamUt.push(S);
    int K = 0;
    S = R;
    while (evaSzulo[S] != 0)
    {
        ++K;
        evaUt.push(S);
        S = evaSzulo[S];
    }
    K++;
    evaUt.push(S);
    fout << K << ' ';
    fout << G << endl;
    while (!evaUt.empty())
    {
        int sz;
        sz = evaUt.top();
        evaUt.pop();
        fout << sz << ' ';
    }
    fout << endl;
    while(!adamUt.empty())
    {
        int sz;
        sz = adamUt.top();
        adamUt.pop();
        fout << sz << ' ';
    }
}
