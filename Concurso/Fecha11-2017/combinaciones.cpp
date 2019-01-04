#include<stdio.h>
#include<stdlib.h>
long int funcion(int, int);

int main()
{
    long int n;
    int *resultados;
    scanf("%ld",&n);
    resultados=(int*)malloc(n*sizeof(int));
    for (int i=0; i<n; i++)
    {
      scanf("%d",&resultados[i]);
    }
    for (int i=0; i<n; i++)
    {
        if((resultados[i]-1)!=0)
            printf("%ld \n",funcion(3,resultados[i]-1));
        else
            printf("3\n");
    }
    return 0;
}

long int funcion(int num, int n)
{
    if(n==1)
    {
        if(num==2)
            return 6;
        else
            return 8;   
    }
    else
    {
        if(num==2)
            return (2*funcion(3,n-1));
        else
            return (funcion(2,n-1)+2*(funcion(3,n-1)));
    }
}
