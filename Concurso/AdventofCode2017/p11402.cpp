#include <bitset>
#include <cstring>
#include <iostream>
using namespace std;
bitset<1024> mybit;
bitset<4096> arbol;

class Segemento{
  public:
    int a, b; 
    int cambio[4096], letra;
  void construir(int p, int i, int j){
    if(i==j){
      arbol[p] = mybit[i];
      return;
    }
    construir(p<<1,i,(i+j)/2); 
    construir((p<<1)+1,((i+j)/2)+1,j);
    arbol[p] = arbol[p<<1] + arbol[(p<<1)+1];
  }
  int consulta(int p, int i, int j){

    if((b<i) or(j<a)){
      return 0;
    }

    propaga(int p,int i,int j);
    if((a<=i) and (b>=j)){
      return arbol[p];
    } else{
      return consulta(p<<1,i,(i+j)/2) + consulta((p<<1)+1,((i+j)/2)+1,j);
    }
  }
  void actualiza(int p, int i, int j, int l){
    letra = l;
    if((b<i) or(j<a)){
      return;
    } if((a<=i) and (b>=j)){
      if(l == 1){
        arbol[p] = 1*((b-a)+1);
        propagar(p,i,j);
      } else if(l == 0){
        arbol[p] = 0;
        propagar(p,i,j);
      } else if(l == 2){
        arbol[p] = ((b-a)+1)-arbol[p];
        propagar(p,i,j);
      } return;
    } else{
      actualiza(p<<1, i ,(i+j)/2, l);
      actualiza((p<<1)+1,((i+j)/2)+1, j, l);
      arbol[p] = arbol[p<<1] + arbol[(p<<1)+1];
      return;
    }
  }
    void propagar(int p, int i, int j){
      if(cambio[p] == 4){
        cambio[p<<1]  = letra;
        cambio[(p<<1)+1] = letra;
        return;
      } else{
        actualiza(p,i,j,letra);
        cambio[p] = 4;
        cambio[p<<1]  = letra;
        cambio[(p<<1)+1] = letra;
        return;
      }
  }
};

int main(){
  int t; cin>>t;
  for(int i = 0; i<t; i++){
     int m, contador = 1;
    cin >> m;
    for(int j = 0; j<m; j++){
      string numero = ""; int k;
      cin >> k;
      cin >> numero;
      for(int i1 = 0; i1<k; i1++){
        for(char c:numero){
          int num = c-'0';
          mybit[contador] = num;
          contador++;
        }
      }
    }
    Segemento mySeg;
    contador--;
    mySeg.construir(1,1,contador);
    int q; cin >> q;
    for(int q2 = 0; q2 < q; q2++){
      char letra;
      cin>>letra >> mySeg.a >> mySeg.b;
      if(letra == 'S'){
        cout << mySeg.consulta(1,1,contador);
      } else{
        if(letra == 'F'){
          int letra2 = 1;
          mySeg.actualiza(1,1,contador,letra2);
        } else if(letra =='E'){
          int letra2 = 0;
          mySeg.actualiza(1,1,contador,letra2);
        } else{
          int letra2 = 2;
          mySeg.actualiza(1,1,contador,letra2);
        }
      }
    }
  }
  return 0;
}
