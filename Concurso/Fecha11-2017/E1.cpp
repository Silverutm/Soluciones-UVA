#include <bits/stdc++.h>
using namespace std;
#define tam 100005
typedef long long ll;
typedef vector <int> vi;
typedef set<int> set;
set yo, el;
int arr[10];

bool comparar(set yo, set el, bool voy, carta);
{
    set cy = yo, ce = el;
    if (not voy)
    {
        for (auto e: yo)
        {

        }
    }
}

int main()
{
    int a;
    for (int i=0; i<3; ++i)
    {
        scanf("%d", &a);    
        arr[a] = 1;
        yo.push_back(a);
    }    
    for (int i=1; i<=7; ++i)
        if (not arr[i])
            el.insert(i);
    auto x = el.end(); --x;
    el.erase(x);
    bool res =false;
    for (auto e:yo)
    {
        set cy = yo;
        cy.erase(e);
        res = res or comparar(cy, el, 0, e);
    }
    return 0;
}