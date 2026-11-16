#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("countsub.in");
ofstream fout("countsub.out");

struct graf {
    int ertek;
    int bal;
    int jobb;
}t[15000];

int n, k, sz;

void bejaras (int S)
{
    if (S == 0) {
        return;
    }

    sz++;
    bejaras(t[S].bal);
    bejaras(t[S].jobb);
}

int main ()
{
    fin >> n;
    for (int i = 1; i <= n; ++i)
    {
        fin >> t[i].ertek >> t[i].bal >> t[i].jobb;
    }
    fin >> k;
    for (int i = 1; i <= k; ++i)
    {
        sz = 0;
        int a;
        fin >> a;
        bejaras(a);
        fout << sz << endl;
    }
}
