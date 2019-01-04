#include<bits/stdc++.h>
using namespace std;
#define tam 1505
#define pb push_back
typedef long long ll;
typedef pair <int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;


int main()
{
    //------------1------------
    stack <char> pila;
    string s;
    int suma = 0, basura = 0;

    cin>>s;
    pila.push('{');
    for (int i=1; i<s.size(); ++i)
    {
        if (s[i] == '!')
            ++i;            
        else if (pila.top() == '<')
        {
            if (s[i] == '>')
                pila.pop();
            //------------2------------
            else ++basura;            
        }
        else if (s[i] == '{' or s[i] == '<')
            pila.push(s[i]);            
        else if (s[i] == '}' )
        {                            
            suma += pila.size();
            pila.pop();
        }
    }
    cout<<suma<<endl;
    cout<<basura<<endl;
    return 0;
}
