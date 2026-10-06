#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
using namespace std;
ifstream fin ("input.in");
ofstream fout("output.out");
struct elLista {
    int kezdoPont;
    int vegPont;
    int suly;
}t[150];
int n, m, komponensek[150] = {0}, S = 0;
queue<int> sor;
int main ()
{
    fin >> n >> m;
    int szam1, szam2, szam3;
    for (int i = 1; i <= m; ++i)
    {
        fin >> szam1 >> szam2 >> szam3;
        t[i].kezdoPont = szam1;
        t[i].vegPont = szam2;
        t[i].suly = szam3;
    }
    sort(t + 1, t + m + 1, [](elLista a, elLista b){
            return a.suly < b.suly;
         });
    for (int i = 1; i <= n; ++i)
    {
        komponensek[i] = i;
    }
    for (int i = 1; i <= m; ++i)
    {
        int sz1, sz2;
        sz1 = t[i].kezdoPont;
        sz2 = t[i].vegPont;
        int k1, k2;
        if (komponensek[sz1] != komponensek[sz2])
        {
            sor.push(sz1);
            sor.push(sz2);
            S += t[i].suly;
            k1 = komponensek[sz1];
            k2 = komponensek[sz2];
            for (int j = 1; j <= n; ++j)
            {
                if (komponensek[j] == k2)
                {
                    komponensek[j] = k1;
                }
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
}
