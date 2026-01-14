#include <iostream>
using namespace std;

void rec(int n, int x)
{

    if (n == x)
    {
        cout << "+ + +" << endl;
    }
    cout << "- - -" << endl;
    if (n != 0)
    {
        cout << "* * *" << endl;
        cout << "# # #" << endl;

        rec(n-1, x);
    }
}

int main () {
    int n, x;
    cin >> n;
    x = n;
    rec(n, x);

}
