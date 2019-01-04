#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>      // std::stringstream
using namespace std;
int main () {

  stringstream ss;
  string ss1;
  getline(cin, ss1);
  ss<<ss1;
  int foo,bar;
  ss >> foo >> bar>>ss1;

  cout << "foo: " << foo << '\n';
  cout << "bar: " << bar << '\n';
  cout<<ss1<<endl;
  return 0;
}