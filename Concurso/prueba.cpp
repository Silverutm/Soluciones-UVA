#include <iostream>
#include <map>

using namespace std;

int main()
{

	map <string, int> mapa1;
	mapa1["david"] = 10;
	mapa1["moro"]  = 9;

	for (auto x: mapa1)
		cout << "(" << x.first << ", " << x.second << ")\n";
	cout << endl;

	map <string, int> mapa2 = {{"david", 100}, {"moro", 90}};

	for (auto x: mapa2)
		cout << "(" << x.first << ", " << x.second << ")\n";
	
	cout << mapa2["edgar"] << "\n";

	for (auto x: mapa2)
		cout << "(" << x.first << ", " << x.second << ")\n";

	return 0;
}