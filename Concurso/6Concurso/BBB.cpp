#include<cstdio>

#include<cstring>

int main()

{

    int t,n,k=0,i,j,a,b,c;

    char cifrado[200];

    char llave[30];

    int resolver[200];

    int resolver1[200];

    int llave1[30];

    int cifrado1[200];



    scanf("%d",&t);

    while(t!=k && k<t)

    {

    scanf("%c",cifrado);

    scanf("%c",llave);

    if (strlen(llave)==strlen(cifrado))

    {

        for(i=0;i<=200;i++)

        {

            llave1[i]=atoi(llave[i])-98;

        }

        for(j=0;j<=200;j++)

        {

            cifrado1[j]=atoi(cifrado[j])-98;

        }

        for(a=0;a<=200;a++)

         {

            resolver[a]=cifrado1[a]+llave1[a];

         }

        for(a=0;a<=200;a++)

        {

        resolver[a]=resolver[a]/resolver[a]%26;

        }

        printf("%c\n",cifrado);

        printf("%c",cifrado1);

        k++;

    }

    else

    {

        while(strlen(llave)<= strlen(cifrado))

        {

            for(b=0;b<=strlen(cifrado);b++)

            {

               resolver1[b]="llave[b]""llave[b++]";

            }

             for(i=0;i<=200;i++)

        {

            llave1[i]=atoi(llave[i])-98;

        }

        for(j=0;j<=200;j++)

        {

            cifrado1[j]=atoi(cifrado[j])-98;

        }

        for(a=0;a<=200;a++)

         {

            resolver[a]=cifrado1[a]+llave1[a];

         }

        for(a=0;a<=200;a++)

        {

        resolver1[a]=resolver1[a]/resolver1[a]%26;

        }

        printf("%c\n",cifrado);

        printf("%c",cifrado1);

        }

    }

return (0);

    }

}



