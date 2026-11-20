#include <iostream>
#include <fstream>
#include <cstring>
#define MOD 1000000007
using namespace std;
ifstream fin("input.in");
ofstream fout("output.out");
char betuk[100005];
long long ismetles, cserek = 0, cserekElsoben = 0, cserekIsmetlesben = 0;
int main ()
{
    fin.getline(betuk, 100000);
    fin >> ismetles;

    for (long long i = 0; i < strlen(betuk); ++i)
    {
        for (long long j = i + 1; j < strlen(betuk); ++j)
        {
            if (betuk[i] > betuk[j])
            {
                cserekElsoben++;
            }
        }
    }

    for (long long i = 0; i < strlen(betuk); ++i)
    {
        for (long long j = 0; j < strlen(betuk); ++j)
        {
            if (betuk[i] > betuk[j])
            {
                cserekIsmetlesben++;
            }
        }
    }

    cserek = (ismetles % MOD * cserekElsoben % MOD) + ((ismetles % MOD * (ismetles % MOD - 1)) / 2) * cserekIsmetlesben % MOD;

    cout << cserek;
}
