#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream fin("difsub.in");
ofstream fout("difsub.out");
int n, t[1005][5], gyoker;
bool van[1005] = {false};
int B = 0, J = 0, S;
void bej(int gy)
{
    if (gy == 0)
    {
        return;
    }
    S += t[gy][0];
    if (t[gy][1] != 0)
    {
        bej(t[gy][1]);
    }
    if (t[gy][2] != 0)
    {
        bej(t[gy][2]);
    }
}

int main ()
{
    fin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int a, b, c;
        fin >> a >> b >> c;
        t[i][0] = a;
        t[i][1] = b;
        t[i][2] = c;
        van[b] = true;
        van[c] = true;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (van[i] == false)
        {
            gyoker = i;
        }
    }
    S = 0;
    bej(t[gyoker][1]);
    B = S;
    S = 0;
    bej(t[gyoker][2]);
    J = S;
    fout << abs(B - J);
}
