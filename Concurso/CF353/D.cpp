#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <cstdio>
//#define der second
//#define izq second
using namespace std;


//struct nodo
//{
	int izq, der;
//};
#define tam 100009
int papas[tam];//, izqq[tam], deri[tam];
//vector < nodo > Lista(1000005, nodo{0,0});
//int papas[100005];
int n, raiz, hijo, actual, i;
/*
void insertar()
{
	//cout<<actual<<" "<<hijo<<endl;
	//return ;
	if ( actual<hijo )
	{
		if (Lista[actual].der ==0)
		{ Lista[actual].der=hijo; papas[i]=actual; }
		else { actual=Lista[actual].der; insertar(); }
	}
	else
	{
		if (Lista[actual].izq ==0)
		{ Lista[actual].izq=hijo; papas[i]=actual; }
		else { actual=Lista[actual].izq; insertar(); }
	}
}
*/


#include<stdlib.h>
#include<stdio.h>

struct tree_el {
   int val;
   struct tree_el * right, * left;
};

typedef struct tree_el node;

void insert(node ** tree, node * item) {
   if(!(*tree)) {
      *tree = item;
      return;
   }
   if(item->val<(*tree)->val)
      {papas[i]=(*tree)->val ;insert(&(*tree)->left, item);}
   else if(item->val>(*tree)->val)
      {papas[i]=(*tree)->val ;insert(&(*tree)->right, item);}
}

void printout(node * tree) {
   if(tree->left) printout(tree->left);
   printf("%d\n",tree->val);
   if(tree->right) printout(tree->right);
}

/*void main() {
   node * curr, * root;
   int i;

   root = NULL;

   for(i=1;i<=10;i++) {
      curr = (node *)malloc(sizeof(node));
      curr->left = curr->right = NULL;
      curr->val = rand();
      insert(&root, curr);
   }

   printout(root);
}
*/

int main()
{
	node * curr, * root;
   //int i;

   root = NULL;
	cin>>n;
	//cin>>raiz;
	//cout<<"hola"<<endl;
	//return 0;
	for (i=1; i<=n;++i)
	{
		
		curr = (node *)malloc(sizeof(node));
      	curr->left = curr->right = NULL;
      	cin>>curr->val;
      	insert(&root, curr);


		//cin>>hijo;
		//actual=raiz;
		//insertar();
		//cout<<papas[i];
		//if (i!=n) cout<<" ";		
	}
for (i=2; i<=n;++i)
{
	cout<<papas[i];
		if (i!=n) cout<<" ";		
}
	cout<<endl;
	return 0;
}