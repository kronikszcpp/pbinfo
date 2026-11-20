#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("data.in");
ofstream fout("data.out");
long long n,m,k;
struct kartyak{
    char nev[15];
    int hany;
}rakas[10000];


int main(){
    //coppa bad bitch popsi szendvics visitozik a kurva kozben a faszom bent sincs
    //barna hair tincs got the garage nem diplomas muvelet nem kell ide a cambridge
    //big hoes but i like emos vegtelen torok five star deepthroat mer a thai lany cant take five guys mer a pakkom big vakon fizetem a szamlat
    //711 hivom at a csajodat o idejon piheno reggelig megmutogatom mi meno kimeno nekem ingyenes ami neked fizeto elviszlek a csucsra a faszom lesz a libego
    //kik ezek de rajok edesharmasoznak a csajok kiveszem berakom a baratnojet addig mellete leszopatom
    //sokat ejszakazik a szemein latszik (kurva) man slut megis imadnak a gadzsik (szex szex)
    //akkora a pipam leveri a niket megakad a torkan hrkk and she like it
    int t;
    long long visszaadandoCnt=0;
    fin>>t;
    for(int tSzam=0;tSzam<t;++tSzam){

        visszaadandoCnt=0;
        fin>>k>>n>>m;
        for(int i=0;i<n;++i){
            rakas[i].hany=0;
        }
        for(int i=0;i<n;++i){
            fin>>rakas[i].nev;
        }
        for(int i=0;i<m;++i){
            char temp[10];
            fin>>temp;
            for(int j=0;j<n;++j){
                if(strcmp(temp,rakas[j].nev)==0){
                    rakas[j].hany++;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(k-rakas[i].hany>0)
                visszaadandoCnt+=k-rakas[i].hany;
        }
        cout<<visszaadandoCnt<<endl;
    }
    return 0;
}
