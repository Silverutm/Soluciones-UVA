#include<stdio.h>
#include<string.h>

int main(){
	char v1[50], v2[50], c='S';
	int i=0, j=0, a=0;
	while(gets(v1)!=NULL){
		a=0; c='S';
	for(i=0; i<strlen(v1); i++){
		//printf("%d\n", );
		if(v1[i]=='a' || v1[i]=='e' || v1[i]=='i' || v1[i]=='o' || v1[i]=='u'){
			v2[a]=v1[i];
			a++;
		}
	}
	for(i=0, j=a-1; j>=0 && i<a; j--, i++){
		if(v2[i]!=v2[j]){
			c='N';
			i=a;
			j=-1;
		}
	}
	printf("%c\n",c);
    }
	return 0;
}
