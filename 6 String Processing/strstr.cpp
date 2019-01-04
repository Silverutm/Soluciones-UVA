#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main()
{
	string s2="hok", s1="jajahola";
	if ( strstr(s1.c_str(),s2.c_str())!=NULL )
		cout<<"Lo logre";
	else cout<<"nel";
	return 0;
}