#include<bits/stdc++.h>
using namespace std;
#define tam 50
#define pb push_back
typedef long long ll;
typedef pair <int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;


int main()
{        
    //------------1------------
    int i=0;
    ll arrvar[500];
    char var_ins[tam];
    string arr_ins[tam], val_ins[tam];

    memset(arrvar, 0, sizeof arrvar);
    while(cin>>arr_ins[i])
    {
        cin>>var_ins[i];
        if (arr_ins[i] == "rcv" or arr_ins[i] == "snd")
        {
            ++i;
            continue;
        }
        cin>>val_ins[i];
        ++i;
    }
    int n=i;
    i = 0;
    int rec = -1;
    //bool ya = false;
    while(1)
    {
        cout<<i<<"  -- "<<arr_ins[i]<<"\n";
        if (arr_ins[i] == "snd")
        {
            rec = arrvar[ var_ins[i] ];
            cout<<"   "<<rec<<"\n";
        }
        else if (arr_ins[i] == "rcv")
        {
            cout<< var_ins[i] <<"  "<<arrvar[ var_ins[i] ]<<"\n";
            if (arrvar[ var_ins[i] ])
            {
                cout<<rec<<"\n";
                break;
            }
        }
        else
        {
            int val = 0;
            stringstream ss(val_ins[i]);
            if (val_ins[i][0]>='a' and val_ins[i][0]<='z')
            {
                char c;
                ss>>c;
                val = arrvar[c];
            }
            else ss>>val;
            
            if (arr_ins[i] == "set")
                arrvar[ var_ins[i] ] = val;
            else if (arr_ins[i] == "add")
                arrvar[ var_ins[i] ] += val;
            else if (arr_ins[i] == "mod")
                arrvar[ var_ins[i] ] %= val;
            else if (arr_ins[i] == "mul")
                arrvar[ var_ins[i] ] *= val;
            else if (arr_ins[i] == "jgz")
                if (arrvar[ var_ins[i] ]>0) 
                {
                    i += val;
                    continue;
                }
            //cout<< var_ins[i] <<" "arrvar[ var_ins[i] ]<<"\n";
        }
        ++i;
    }
    return 0;
}
