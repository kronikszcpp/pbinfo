#include <iostream>
#include <cmath>
using namespace std;

bool primszam_ellenorzes(int n)
{
    bool primszame;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;

}

int main () {
    int n;
    cin >> n;
    cout << primszam_ellenorzes(n);
}
