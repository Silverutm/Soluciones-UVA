#include <iostream>
#include <queue>    //libreria para las colas de prioridad
using namespace std;

int main ()
{
    //priority_queue<Tipo de Dato> Cola_De_Prioridad;
    priority_queue<int> Cola_De_Prioridad;
      
    //Ingresar Elementos
    for (int i=0; i<5; i++) 
        Cola_De_Prioridad.push(i);
    for (int i=10; i>5; i-- ) 
        Cola_De_Prioridad.push(i);
    
    cout << "Tamaño " << Cola_De_Prioridad.size() << "\n";

    cout<< "Primer elemento" << Cola_De_Prioridad.top()<< "\n";
    
    //Eliminar un elemento
    Cola_De_Prioridad.pop();
    
    //Mientras no este vacia
    while ( not Cola_De_Prioridad.empty() ) 
    {
        cout<< "Siguiente elemento " <<Cola_De_Prioridad.top()<<"\n";        
        Cola_De_Prioridad.pop();
    }    
  return 0;
}