#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[2005][2005][2];
int m,d,mod = 1e9 + 7;

int solve(string&a,int i = 0,int j = 0,int is = 1)
{
    if (i==(int)a.size()){
        if (j==0)return 1;
        return 0;
    }

    if (dp[i][j][is] != -1)return dp[i][j][is];

    int ans = 0;
    int pos = (i + 1)%2;

    if (is){
        for (int p = 0;p<(a[i]-'0');p++){
            if (pos==0 && p!=d)continue;
            if (pos==1 && p==d)continue;

            ans += solve(a,i + 1,(10 * j + p)%m,0);
            ans %= mod;
        }
        int p = (a[i] - '0');
        if (!((pos==0 && p!=d) || (pos==1 && p==d)))
            ans += solve(a,i + 1,(10 * j + (a[i] - '0'))%m,1);
    }
    else{
        for(int p = 0;p<=9;p++){
            if (pos==0 && p!=d)continue;
            if (pos==1 && p==d)continue;

            ans += solve(a,i + 1,(10 * j + p)%m,0);
            ans %= mod;
        }
    }

    return dp[i][j][is] = ans;
}
bool is(string&a)
{
    int rem = 0;
    for (int i = 0;i<(int)a.size();i++){
        int pos = (i + 1)%2;
        if (pos==0 && (a[i] - '0') != d)return false;
        if (pos==1 && (a[i] - '0') == d)return false;
        rem = (10 * rem + (a[i] - '0'))%m;
    }
    return rem==0;
}
int32_t main()
{
    cin>>m>>d;
    int aa,bb;
    cin>>aa>>bb;
    string b=to_string(bb);
    string a=to_string(aa-1);
    memset(dp,-1,sizeof(dp));

    int ans = solve(b);
    memset(dp,-1,sizeof(dp));
    ans -= solve(a);
    ans %= mod;
    //if (is(a))ans++;
    ans %= mod;
    if (ans<0)ans += mod;
    cout<<ans;
    return 0;
}