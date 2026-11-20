#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("input.in");
ofstream fout("output.out");
char betuk[100005];
int ismetles, cserek = 0, cserekElsoben = 0, cserekIsmetlesben = 0;
int main ()
{
    fin.getline(betuk, 100000);
    fin >> ismetles;

    for (int i = 0; i < strlen(betuk); ++i)
    {
        for (int j = i + 1; j < strlen(betuk); ++j)
        {
            if (betuk[i] > betuk[j])
            {
                cserekElsoben++;
            }
        }
    }

    for (int i = strlen(betuk) - 1; i >= 0; i--)
    {
        for (int j = i - 1; j >= 0; --j)
        {
            if (betuk[i] > betuk[j])
            {
                cserekIsmetlesben++;
            }
        }
    }

    while (ismetles > 0)
    {
        cserek += cserekElsoben * ismetles;
        cserek += cserekIsmetlesben * (ismetles - 1);
                ismetles--;
    }
    fout << cserek;
}
