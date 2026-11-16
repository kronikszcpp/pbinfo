#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("postordine.in");
ofstream fout("postordine.out");
int n, t[1005][5];
bool van[1005] = {false};
void bej(int gy)
{
    if (gy == 0)
    {
        return;
    }
    
    if (t[gy][1] != 0)
    {
        bej(t[gy][1]);
    }
    
    if (t[gy][2] != 0)
    {
        bej(t[gy][2]);
    }
    fout << t[gy][0] << ' ';
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
            bej(i);
        }
    }
}
