#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define tam 55

int x, y, xd, yd, n;
string arr;
int dir;

void simulacion()
{
    int i;
    for (char c:arr)
    {
        if (c=='F')
        {
            if (dir == 0) ++y;
            else if (dir == 2) ++x;
            else if (dir == 4) --y;
            else if (dir == 6) --x;
        }
        else if (c=='L') dir = (dir + 6)%8;
        else if (c=='R') dir = (dir + 2)%8;
    }
}


int main()
{
    string z[500];
    z['F'] = "Forward"; z['R'] = "Right"; z['L'] = "Left";
    int i;
    string ins;
    cin>>xd>>yd;
    cin>>n;
    for (i =0; i<n; ++i)
    {
        cin>>ins;
        arr.push_back(ins[0]);
    }

    for (i =0; i<n; ++i)
    {
        char ori = arr[i];
        for (auto m:{'F', 'L', 'R'})
        {
            arr[i] = m;
            x = y = dir = 0;
            simulacion();
            if (x==xd and y == yd)
            {
                printf("%d ", i+1);
                cout<<z[m]<<"\n";
                return 0;
            }
        }
        arr[i] = ori;
    }

}