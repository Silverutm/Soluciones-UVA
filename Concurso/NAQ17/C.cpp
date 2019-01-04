#include <iostream>
#include <cstring>
using namespace std;

#define INF 1 << 29

int number_of_coins;
int coin_system[105];
int change_tb[2000100];
int V;

int count() {
 	
    for (int i = 1; i <= V; i++)
    {
        for (int j = 0; j < number_of_coins; j++)
			if (coin_system[j] <= i)
			{
			  int sub_res = change_tb[i-coin_system[j]];
			  if (sub_res != INF && sub_res + 1 < change_tb[i])
			      change_tb[i] = sub_res + 1;
			}
    }
    return change_tb[V];
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	int n;
	memset(coin_system, -1, sizeof coin_system);
	change_tb[0] = 0;
	cin >> number_of_coins;
	for (int i = 0; i < number_of_coins; ++i)
		cin >> coin_system[i];
	V = coin_system[number_of_coins - 1] + coin_system[number_of_coins - 2];
	for (int i=1; i<=V; i++)
        change_tb[i] = INF;
    int greedy = 0;
    int aux = V;
    int idx = number_of_coins;
    int dp = 0;
    bool flag = true;
    while(V) { 
    	greedy = 0;
    	idx = number_of_coins - 1;
    	aux = V;
		while (aux)
		{
			if (aux >= coin_system[idx])
			{
				aux -= coin_system[idx];
				greedy++;
			}
			else
				idx =  idx == 0 ? 0 : idx - 1;
		}
		dp = count();
//		cout << V << endl;
//    	cout << greedy << " " << dp << endl;
		if (dp != greedy) {
			flag = false;
		    cout << "non-canonical" << endl;
			break;
		}
		V--;
    }
    if (flag)
    {
	    cout << "canonical" << endl;
    }



	return 0;
}