#include <iostream>
#include <string>

using namespace std;

bool diferentes(string sc)
{
	int aux;
	aux=sc.size();
	for (int i = 0; i < aux; ++i)
		for (int j = 0; j < aux; ++j)
			if (i!=j)
			{
				if (sc[i]==sc[j])
				{
					return false;
				}
			}
	return true;
}

int main()
{
	int n, contador=0;
	string sc,sc2,sc3;
	bool t;
	while(cin>>n && n)
	{
		t=1;
		if ( contador ) cout<<endl;
		++ contador;
		for (int i = 1234; i <= 98765/n; ++i)
		{
				sc=to_string(i*n);
				sc2=to_string(i);
				if (sc.size()<5)
				{
					sc='0'+sc;
				}
				if (sc2.size()<5)
				{
					sc2='0'+sc2;
				}
				sc3=sc+sc2;
				if (diferentes(sc3))
				{
					cout<<sc<<" / "<<sc2<<" = "<<n<<endl;
					t=0;
				}
		}
		if (t)
		{
			cout<<"There are no solutions for "<<n<<"."<<endl;
		}
		
	}
	return 0;
}