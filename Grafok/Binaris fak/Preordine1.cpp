#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("preordine1.in");
ofstream fout("preordine1.out");

void bejaras()
{
    int a;
    if (!(fin >> a)) 
    {
        return;
    }
    
    if (a == 0)
    {
        return;
    }
    
    fout << a << ' ';
    
    bejaras();
    bejaras();
}

int main ()
{
    int gyoker;
    fin >> gyoker;
    bejaras();
}
