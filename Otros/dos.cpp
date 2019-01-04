#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string s, res;
int arreglo[23][12], i, veces[13];

void restar( int letra )
{
	//cout<<"i "<<i<<endl<<"letra "<<letra<<endl<<"veces "<<veces[letra]<<endl<<endl;
	--veces[letra];
	--letra;
	while (letra==-1)
	{
		--i;
		letra=s[i]-'0';
		//cout<<"i: "<<i<<endl<<"letra "<<letra<<endl<<"veces "<<veces[letra]<<endl<<endl;
		--veces[letra];
		--letra;
		//s[i]=letra+'0';
	}
	s[i]=letra+'0';
	++veces[letra];
	if (veces[letra]==3)
		restar( letra );
}


void magia()
{
	restar( s[i]-'0' );
}

int main()
{
	int j;
	while (cin>>s)
	{
		memset(veces, 0, sizeof veces);
		for ( i=0; i<s.size(); ++i  )
		{	
			++veces[ s[i]-'0' ];
			if ( veces[ s[i]-'0' ]==3 )
			{
				magia();
				break;
			}
		}
		j=9;
		for (++i ;i<s.size(); ++i )
		{
			while  (veces[j]==2) --j;
			s[i]=j+'0';
			++veces[j];
		}
		i=0;
		while (s[i]=='0') ++i;
		for ( ;i<s.size(); ++i )
			cout<<s[i];
		cout<<endl;


	}
	return 0;
}