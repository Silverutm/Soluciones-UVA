#include <iostream>
#include <deque>    //libreria para las deque
using namespace std;
int main()
{
    //Declaracion
    //queue <Tipo_de_dato> mideque;
    deque <int> mideque;
    
    //meter elementos hasta arriba:
    for (int elemento=0; elemento<6; ++elemento)
        mideque.push_back( elemento );

    //meter elementos enfrente:
    for (int elemento=500; elemento<506; ++elemento)
        mideque.push_front( elemento );
        
    //ver el primer elemento de mideque
    cout<<"el de hasta adelante "<<mideque.front()<<endl;
    //tambien podemos modificarlo
    mideque.front()=42;
    cout<<mideque.front()<<endl;

    //ver ultimo elemento
    cout<<"el ultimo "<<mideque.back()<<endl;
    
    //eliminar el primer elemento de la mideque
    mideque.pop_front();
    cout<<"ahora el primer es "<<mideque.front()<<endl;

    //eliminar el ultimo elemento de la mideque
    mideque.pop_back();
    cout<<"ahora el ultimo es "<<mideque.back()<<endl;

    
    //tamaño del deque
    cout<<"cantidad de elementos "<<mideque.size()<<endl;

    //ver si esta vacia
    cout<<"vacia? "<<mideque.empty()<<endl;


    //recorrerlo
    for (int i=0; i<mideque.size(); ++i)
        cout<<mideque[i]<<" ";

    cout<<endl;
    //tambien se puede así
    for (auto elemento:mideque)
        cout<<elemento<<" ";
    cout<<endl;
    return 0;
}