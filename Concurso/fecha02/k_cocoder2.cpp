//
//  main.cpp
//  setters
//
//  Created by Adán López Alatorre on 3/10/17.
//  Copyright © 2017 Adán López Alatorre. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int k,n;

double comb(int r,int k,int r1,int k1){
    double res=1;
    for (int i=k+1,j=k1+1; i<=r; i++,j++)
        res=res*i/j;
    return res;
}
int main(){
    cin>>k>>n;
    double res=0,mult=1;
    const int TOT=pow(2, k);
    for (int i=0,p=1; i<k-1 && TOT-n+1-p>0; i++,p*=2){
        mult*=comb(TOT-n+1-p, TOT-n+1-2*p,TOT-p, TOT-2*p);
        res+=mult;
    }
    printf("%.5lf\n",res);
}
/*#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    string variable,type;
    while(cin>>type>>variable){
    cout<<"void set"<<(char)(variable[0]-32)<<variable.substr(1)<<" ("<<type<<" "<<variable.substr(0,variable.length()-1)<<"){\n\t"<<variable<<"="<<variable.substr(0,variable.length()-1)<<";\n}\n";
    cout<<type<<" get"<<(char)(variable[0]-32)<<variable.substr(1)<<"(){\n\t"<<"return "<<variable<<";\n}\n";
    }
}*/
