#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("nrnod.in");
ofstream fout("nrnod.out");

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

int S = 0;
void bejaras (graf* gyoker)
{
    if (gyoker == NULL)
    {
        return;
    }

    if (gyoker->bal == NULL && gyoker->jobb != NULL || gyoker->bal != NULL && gyoker->jobb == NULL)
    {
        ++S;
    }

    bejaras(gyoker->bal);
    bejaras(gyoker->jobb);
}

int main ()
{
    graf* gyoker = beolvasas();
    bejaras(gyoker);
    fout << S;
}
