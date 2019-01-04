#include<stdio.h>

int main(){
	char v1[50], v2[50], c='S';
	int i=0, j=0, a=0;
	while(gets(v1)){
	a=0;
	for(i=0; i<sizeof(v1); i++){
		if(v1[i]=='a' || v1[i]=='e' || v1[i]=='i' || v1[i]=='o' || v1[i]=='u'){
			v2[a]=v1[i];
			a++;
		}
	}
	for(i=0, j=a-1; j>=0, i<a; j--, i++){
		if(v2[i]!=v2[j]){
			c='N';
			break;
		}
	}
	printf("%c\n",c);
    }
	return 0;
}


7
1 2 3
2 0 0
3 4 0
4 0 5
5 0 6
6 7 0
7 0 0
7
1 2 3
2 4 0
3 5 0
4 0 6
5 0 0
6 0 7
7 0 0

5
1 2 3
2 4 5
3 0 0
4 0 0
5 0 0
3
1 2 3
2 0 0
3 0 0

3
3 0 2
2 0 0
1 0 3
2
2 0 0
1 2 0