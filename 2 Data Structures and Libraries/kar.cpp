#include<iostream>
#include<stdio.h>
#include<queue>

using namespace std;

int main(){

	priority_queue<int> cola_de_p;
	cola_de_p.push(-4);
	cola_de_p.push(-76);
	cola_de_p.push(-1);
	cola_de_p.push(-55);

	while(!cola_de_p.empty())
	{
		cout<<cola_de_p.top()<<"\n";
		cola_de_p.pop();
	}
}


