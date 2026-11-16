#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("bifrunze.in");
ofstream fout("bifrunze.out");
int n, t[1005], k = 0;
int main ()
{
    fin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int a, b, c;
        fin >> a >> b >> c;
        if (b == 0 && c == 0)
        {
            t[k] = i;
            ++k;
        }
        
    }
    sort(t, t + k);
    for (int i = 0; i < k; ++i)
    {
        fout << t[i] << ' ';
    }
}
