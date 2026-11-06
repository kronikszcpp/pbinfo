#include <iostream>
#include <fstream>
#include <climits>
using namespace std;
ifstream fin("dijkstra.in");
ofstream fout("dijkstra.out");
int pp[150][150] = {0}, hossz[150], n, m, pont, megtalaltElek = 0;
bool voltMar[150] = {false};
int main ()
{
    fin >> n >> pont;
    for (int i = 1; i <= n; ++i)
    {
        hossz[i] = INT_MAX;
    }

    int a, b, c;
    while (fin >> a >> b >> c)
    {
        pp[a][b] = c;
    }
    hossz[pont] = 0;

    for (int i = 1; i <= n; ++i)
    {
        if (pp[pont][i] > 0)
        {
            hossz[i] = pp[pont][i];
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        int legkisebb = INT_MAX;
        int legkisebbSzam = -1;

        for (int j = 1; j <= n; ++j)
        {
            if (!voltMar[j] && hossz[j] < legkisebb)
            {
                legkisebb = hossz[j];
                legkisebbSzam = j;
            }
        }

        if (legkisebbSzam == -1)
        {
            break;
        }

        pont = legkisebbSzam;
        voltMar[pont] = true;

        for (int j = 1; j <= n; ++j)
        {
            if (pp[pont][j] > 0 && !voltMar[j])
            {
                if (hossz[j] > hossz[pont] + pp[pont][j])
                {
                    hossz[j] = hossz[pont] + pp[pont][j];
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (hossz[i] == INT_MAX)
        {
            fout << -1;
        }
        else
        {
            fout << hossz[i];
        }
        
        if (i < n)
        {
            fout << ' ';
        }
    }
}
