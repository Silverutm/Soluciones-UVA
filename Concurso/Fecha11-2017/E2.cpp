#include <bits/stdc++.h>
using namespace std;
#define tam 100005
typedef long long ll;
set<int> s, s2;
bool e(int x)
{
    return s.find(x)!=s.end();
}

int main()
{
    
    
    int a;
    
    for (int i=0; i<3; ++i)
    {
        scanf("%d", &a);    
        //arr[a] = 1;
        s.insert(a);
    }    

    if ( e(1) and e(2) and e(3) ) {printf("S\n");return 0;}
    if ( e(1) and e(2) and e(4) ) {printf("S\n");return 0;}
    if ( e(1) and e(2) and e(5) ) {printf("S\n");return 0;}
    if ( e(1) and e(2) and e(6) ) {printf("S\n");return 0;}
    if ( e(1) and e(2) and e(7) ) {printf("S\n");return 0;}
    if ( e(1) and e(3) and e(4) ) {printf("S\n");return 0;}
    if ( e(1) and e(3) and e(5) ) {printf("S\n");return 0;}
    if ( e(1) and e(3) and e(6) ) {printf("S\n");return 0;}
    if ( e(1) and e(3) and e(7) ) {printf("S\n");return 0;}
    if ( e(1) and e(4) and e(5) ) {printf("S\n");return 0;}
    if ( e(2) and e(3) and e(4) ) {printf("S\n");return 0;}
    printf("N\n");

    return 0;
}