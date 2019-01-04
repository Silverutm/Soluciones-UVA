#include<stdio.h>

int main()

{

    int a[1000],b[1000],i,j,band=0,cou=0,k;

    scanf("%d",&i);

    for(j=0;j<i;j++)

        {

            scanf("%d %d",&a[j],&b[j]);

            if(a[j]%2!=0)

                a[j]=a[j];

            else

                a[j]=a[j]+1;

        };

    for(j=0;j<i;j++)

        {

        if(a[j]<b[j]&&(a[j]+2)<b[j]&&(a[j]+4)<b[j])

            {

            for(k=3;k<a[j];k=k+2)

                {

                if(a[j]%(k)==0&&a[j]!=(k))

                    band=1;

                if((a[j]+2)%(k)==0&&(a[j]+2)!=(k))

                    band=1;

                if((a[j]+4)%(k)==0&&(a[j]+4)!=(k))

                    band=1;

                };

            if(band==0)

                    cou=cou+1;

            };

        printf("%d\n",cou);

        cou=0;

        };



    return(0);

}