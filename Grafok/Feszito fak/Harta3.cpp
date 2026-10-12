#include <iostream>
#include <fstream>
#include <cmath>
#include <climits>
#include <cfloat>
using namespace std;
ifstream fin("harta3.in");
ofstream fout("harta3.out");
int n, koordinatak[150][2] = {0};
bool bejarva[150] = {false};
float pp[150][150] = {0}, S = 0;
int main () {
    fin >> n;
    for (int i = 1; i <= n; ++i)
    {
        fin >> koordinatak[i][0] >> koordinatak[i][1];
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            float negyzet1 = pow(koordinatak[i][0] - koordinatak[j][0], 2);
            float negyzet2 = pow(koordinatak[i][1] - koordinatak[j][1], 2);
            pp[i][j] = sqrt(negyzet1 + negyzet2);
        }
    }

    bejarva[1] = true;
    for (int lepesek = 0; lepesek < n; ++lepesek)
    {
        float minSuly = FLT_MAX;
        int eleje = INT_MIN, vege = INT_MIN;
        for (int i = 1; i <= n; i++)
        {
            if (bejarva[i])
            {
                for (int j = 1; j <= n; j++)
                {
                    if (!bejarva[j] && pp[i][j] < minSuly && pp[i][j] > 0)
                    {
                        minSuly = pp[i][j];
                        eleje = i;
                        vege = j;
                    }
                }
            }
        }
        if (vege > INT_MIN)
        {
            bejarva[vege] = true;
            S += minSuly;
        }
    }
    fout << S;
}
