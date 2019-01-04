#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	int m;
	string s;
	scanf("%d", &n);

	vector <string> palabra;
	vector <string> consulta;

	for (int i = 0; i < n; ++i)
	{
		cin >> s;
		palabra.push_back(s);
	}
	scanf("%d", &m);

	for (int i = 0; i < m; ++i)
	{
		cin >>s;
		consulta.push_back(s);
	}

	string t, word;
	int contador;
	for (int i = 0; i < consulta.size(); ++i)
	{
		//Para cada consulta
		contador = 0;
		t = consulta[i];
		bool match = true;

		cout << "Word #" << i + 1 <<": "<< t << endl;

		//printf("Word # %d : %s \n", i, t);
		for (int  j = 0; j < palabra.size() ; ++j)
		{
			//para cada palabra
			word = palabra[j];
			if (word.size() != t.size())
				{//cout <<"!size"<< endl;
			continue;}

			for (int k = 0; k < t.size(); ++k)
			{
				//Para cada caracter de la consulta
				if (t[k] == word[k] || t[k] == '-')
				{
				//	cout << word[k] << " = " << t[k] << endl;
					match = true;
				}
				else
				{
					match = false; 
					break;
				}
			}
			if (match)
			{
				contador++;
				cout << word << endl;
				//printf("%s\n", word);
			}
		}
		printf("Total number of candidate words = %d\n", contador);
	}


	return 0;
}