#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 10000009
int main()
{
    int t, mitad, n, i;
    string s;
    cin>>t;
    ll res;
    while (t--)
    {
        cin>>s;
        mitad = ( s.size() + 1 ) / 2;
        n = s.size();
        res = 1;
        for (i=0; i<mitad; ++i)
        {
            if (s[i] != s[n - i - 1] and s[i] != '?' and s[n -1 - i]!='?' )
                res = 0;
            if (s[i] == s[n - i - 1] and s[i] != '?' )
                continue;
            if (s[i] != s[n - i - 1] and (s[i] == '?' and s[n -1 - i]!='?') or (s[i] != '?' and s[n -1 - i]=='?') )
                continue;
            if (s[i] == s[n - i - 1] and s[i] == '?' )
                res = res * 26 % mod;
        }
        cout<<res<<endl;
    }
    return 0;
}

*/
https://unix.stackexchange.com/questions/3568/how-to-switch-between-users-on-one-terminal
https://github.com/Silverutm/contender/blob/master/executioner/evaluate
https://github.com/Silverutm?tab=repositories
https://www.lifewire.com/create-users-useradd-command-3572157


https://askubuntu.com/questions/143815/how-can-i-give-a-program-writing-access-to-a-directory
https://askubuntu.com/questions/261556/allow-user-and-program-to-use-a-directory-read-write-outside-home
https://superuser.com/questions/19318/how-can-i-give-write-access-of-a-folder-to-all-users-in-linux
https://superuser.com/questions/126073/chmod-to-allow-read-and-write-permissions-for-directory
https://stackoverflow.com/questions/27533711/redirect-execution-errors-to-file-c
https://stackoverflow.com/questions/33340301/core-dumped-message-is-not-captured-in-stderr


https://unix.stackexchange.com/questions/193141/catch-diagnose-user-process-being-killed-inexplicably-logged-out-automatically
https://stackoverflow.com/questions/29762189/how-to-execute-bash-commands-from-c
https://stackoverflow.com/questions/4757512/execute-a-linux-command-in-the-c-program
https://github.com/hex539/contender/blob/master/executioner/evaluate#L72
https://www.networkworld.com/article/2693414/operating-systems/setting-limits-with-ulimit.html





*/