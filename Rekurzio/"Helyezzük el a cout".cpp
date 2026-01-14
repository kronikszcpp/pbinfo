#include <iostream>
using namespace std;

void rec(int n)
{
    cout << ". . ." << endl;
    if (n == 0)
    {
        cout << "---" << endl;
    }
    else
    {
        cout << "***" << endl;
        rec(n-1);
        cout << "###" << endl;
    }
}

int main () {
    int n;
    cin >> n;
    rec(n);
}
