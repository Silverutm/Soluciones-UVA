#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define tam 550

int num_letra[tam];
char letra_num[tam];


int main()
{
    for (char i = 'a'; i<='z'; ++i)
    {
        num_letra[i] = i - 'a' + 1;
        letra_num[i - 'a' + 1] = i;
    }

    num_letra[' '] = 0;
    letra_num[0] = ' ';
    //cout<<"hola"; return 0;
    int n;
    string s, res;
    cin>>n;
    getline(cin, s);
    for (int i=0;i<n; ++i)
    {
        getline(cin, s);
        res = s;
        if (s[0]== 'e')
        {
            int ant = 0, val;
            for (int i=2;i<s.size(); ++i)
            {
                val = (num_letra[s[i]] + ant)%27;
                printf("%c", letra_num[val]  );
                ant = val;
            }
            printf("\n");
        }
        else
        {
            int ant = 0, val;
            for (int i=2;i<s.size(); ++i)
            {
                val = ((num_letra[s[i]] - ant + 27)%27 + 27)%27;
                printf("%c", letra_num[val]  );
                ant = num_letra[s[i]];
            }
            printf("\n");
        }
    }
}