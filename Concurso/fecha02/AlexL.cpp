#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <bitset>
#include <set>

using namespace std;

main(){
    vector<long long> pesas;
    vector<long long> platos;
    bitset<14> alo;
    bitset<13> alo2;
    set <int> calu;
    set <int> calu2;
    calu.insert(0);
    int a, b, c, counter, maximocontador=1;
    cin>>a>>b;
    for(int i=1;i<=a;i++){
        cin>>c;
        pesas.push_back(c);
    }
    for(int i=1;i<=b;i++){
        cin>>c;
        platos.push_back(c);
    }
    for(int i=1;i<pow(2,b);i++){
        int suma=0;
        for(int j=0; j<b;j++){
            if(alo[j]==1) suma=suma+platos[j];
        }
        if(calu.end()==calu.find(suma*2)){
            bool boleano=true;
            for(int k=1;k<pow(2,b-alo.count()) and boleano;k++){
                int cc2=0,suma2=0;
                for(int j=0;j<b;j++){
                    if(alo[j]==0){
                        if(alo2[cc2]==1){
                            suma2=suma2+platos[j];
                        }
                        cc2++;
                    }
                }
                if(suma==suma2){
                    calu.insert(suma*2);
                    boleano=false;
                    maximocontador++;
                }
                counter=1;
                for (int j = 0; j <= b-alo.count() and counter==1 and boleano; ++j){
                    if(counter==1){
                        if(alo2[j]==1) alo2[j]=0;
                        else{
                            alo2[j]=1;
                            counter=0;
                        }
                    }
                }
            }
        }
        //--------------------------------
        counter=1;
        for (int j = 0; j <= b and counter==1; ++j){
            if(counter==1){
                if(alo[j]==1) alo[j]=0;
                else{
                    alo[j]=1;
                    counter=0;
                }
            }
        }
    }     
    for (int j=0;j<a;j++)
    for (std::set<int>::iterator it=calu.begin(); it!=calu.end(); ++it)
         calu2.insert(pesas[j]+ *it );
      for (std::set<int>::iterator it=calu2.begin(); it!=calu2.end(); ++it)
        std::cout<< *it<<endl;
      //std::cout << '\n';
}