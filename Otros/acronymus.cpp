#include <iostream>
#include <string>
using namespace std;
int main()
{
	bool acabo;
	int i;
	string s1, s2, s3, s4;
	while (getline(cin, s1) and getline(cin, s2))
	{
		s3="";
		acabo=true;
		if (s1[0]!=' ') 
		{
			s3=s3+s1[0];
			acabo=false;
		}
		for (i=1; i<s1.size(); ++i)
		{
			if (acabo)
				if (s1[i]!=' ') 
				{
					acabo=false;
					s3=s3+s1[i];		
				}
			if (s1[i]==' ') 
				acabo=true;
		}

		s4="";
		acabo=true;
		if (s2[0]!=' ') 
		{
			s4=s4+s2[0];
			acabo=false;
		}
		for (i=1; i<s2.size(); ++i)
		{
			if (acabo)
				if (s2[i]!=' ') 
				{
					acabo=false;
					s4=s4+s2[i];		
				}
			if (s2[i]==' ') 
				acabo=true;
		}

		if (s3==s4)
			cout<<"yes\n";
		else cout<<"no\n";
		
		//cout <<s3<<endl<<s4<<endl<<endl;		
		
		


	}
	return 0;
}