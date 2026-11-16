#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("inordine1.in");
ofstream fout("inordine1.out");

struct graf {
    int ertek;
    graf* bal;
    graf* jobb;
};

graf* beolvasas()
{
    int a;
    if (!(fin >> a) || a == 0)
    {
        return NULL;
    }
    
    graf* uj = new graf;
    uj->ertek = a;
    uj->bal = beolvasas();
    uj->jobb = beolvasas();
    
    return uj;    
}

void inorder(graf* gyoker)
{
    if (gyoker == NULL)
    {
        return;
    }
    
    inorder(gyoker->bal);
    fout << gyoker->ertek << ' ';
    inorder(gyoker->jobb);
}

int main () 
{
    graf* gyoker = beolvasas();
    inorder(gyoker);
}
