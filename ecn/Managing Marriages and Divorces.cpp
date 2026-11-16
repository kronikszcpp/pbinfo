#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("input.in");
ofstream fout("output.out");

struct adatok {
    int code;
    int sex;
    int married;
}t[250005];

int np, validM = 0, validD = 0, errorCode[10] = {0};
int main ()
{
    fin >> np;
    for (int i = 0; i < np; ++i)
    {
        char s;
        fin >> t[i].code;
        fin >> s;
        if (s == 'M')
        {
            t[i].sex = 0;
        }
        else
        {
            t[i].sex = 1;
        }
        t[i].married = -1;
    }
    char req;
    while (fin >> req)
    {
        int code1, code2, nr1, nr2;
        fin >> code1 >> code2;
        for (int i = 0; i < np; ++i)
        {
            if (t[i].code == code1)
            {
                nr1 = i;
            }
        }
        for (int i = 0; i < np; ++i)
        {
            if (t[i].code == code2)
            {
                nr2 = i;
            }
        }
        if (req == 'M')
        {
            if (t[nr1].sex != 0)
            {
                errorCode[1]++;
            }
            else if (t[nr2].sex != 1)
            {
                errorCode[2]++;
            }
            else if (t[nr1].married != -1)
            {
                errorCode[3]++;
            }
            else if (t[nr2].married != -1)
            {
                errorCode[4]++;
            }
            else
            {
                t[nr1].married = code2;
                t[nr2].married = code1;
                validM++;
            }
        }
        else if (req == 'D')
        {
            if (t[nr1].sex != 0)
            {
                errorCode[1]++;
            }
            else if (t[nr2].sex != 1)
            {
                errorCode[2]++;
            }
            else if (t[nr1].married != t[nr2].code && t[nr2].married != t[nr1].code)
            {
                errorCode[5]++;
            }
            else
            {
                validD++;
                t[nr1].married = -1;
                t[nr2].married = -1;
            }
        }
    }
    fout << "Valid M: " << validM << endl;
    fout << "Valid D: " << validD << endl;
    for (int i = 1; i <= 5; ++i)
    {
        fout << "Error code " << i << ": " << errorCode[i] << endl;
    }
}
