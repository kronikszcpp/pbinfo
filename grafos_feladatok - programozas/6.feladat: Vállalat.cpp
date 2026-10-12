#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
ifstream fin("vallalat.be");
ofstream fout("vallalat.ki");
int N, K, t[1500] = {0}, G = 0;
stack<int> sor;
int main ()
{
    fin >> N >> K;
    for (int i = 1; i <= N; ++i)
    {
        int sz1, sz2;
        fin >> sz1 >> sz2;
        t[sz1] = i;
        t[sz2] = i;
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
    fout << G << '\n';
    while (!sor.empty())
    {
        fout << sor.top() << ' ';
        sor.pop();
    }
}
