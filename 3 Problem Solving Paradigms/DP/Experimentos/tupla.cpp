// packing/unpacking tuples
#include <iostream>     // std::cout
#include <tuple>        // std::tuple, std::make_tuple, std::tie
using namespace std;
int main ()
{
  int myint;
  char mychar;

  tuple<int,float,char> mytuple;

  mytuple = std::make_tuple (10, 2.6, 'a');          // packing values into tuple

  tie (myint, std::ignore, mychar) = mytuple;   // unpacking tuple into variables
  get<2>(mytuple)=57;
  myint=50;

  cout << "myint contains: " << myint << '\n';
  cout << "mychar contains: " << mychar << '\n';

  return 0;
}