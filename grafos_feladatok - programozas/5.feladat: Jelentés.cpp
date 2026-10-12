#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
ifstream fin("JELENT.BE");
ofstream fout("JELENT.KI");
int N, K, t[250] = {0}, G = 0;
queue<int> sor;
int main ()
{
    fin >> N >> K;
    for (int i = 1; i <= N; ++i)
    {
        fin >> t[i];
    }
    for (int i = 2; i <= N; ++i)
    {
        int S = 0, sz;
        sz = t[i];
        while (S < K && sz != 0)
        {
            ++S;
            sz = t[sz];
        }
        if (S == K && sz == 0)
        {
            ++G;
            sor.push(i);
        }
    }
    fout << G << endl;
    while (!sor.empty())
    {
        fout << sor.front() << ' ';
        sor.pop();
    }
}
