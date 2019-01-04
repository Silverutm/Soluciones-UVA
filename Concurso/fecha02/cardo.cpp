
#include <iostream>
#include <vector>

using namespace std;
int matrix[52][52];
int main()
{
	string s;
	bool band;
	int aux,where2,max=0;
	int where1=0;
	int cont=1;
	
	//cout<<matrix[5][5]<<endl;
	//return 0;
	cin>>s;
	for (int i = 0; i < s.size(); ++i)
	{
		matrix[i][1]=s[i];
		for (int j = i+1; j < s.size()+1; ++j)
		{
			if (s[i]<s[j])
			{
				aux=s[j];
				matrix[i][j+1]=aux;
				matrix[i][0]++;
			}
		}
	}
	for (int i = 0; i < s.size(); ++i)
	{
		if (matrix[i][0]>max)
		{
			max=matrix[i][0];
			where1=i;
		}
	}
	while(max)
	{
		max=0;
		band=0;
		for (int i = 1; i < s.size()+1; ++i)
		{
			if (matrix[where1][i+1]!=0 and matrix[i][1]>matrix[where1][1])
			{
				if (max<matrix[i][0])
				{
					max=matrix[i][0];
					where2=i;
					band=1;
				}
			}
		}
		
			cont++;

		where1=where2;
	}
	cout<<26-cont<<endl;
	return 0;
}
