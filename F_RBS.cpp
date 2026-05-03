/*
   Author: SONIT RAJ
    created: 20:26:20 03-05-2026
*/


#include<bits/stdc++.h>
using namespace std;

// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC optimize("Ofast,unroll-loops,O3,no-stack-protector,fast-math")
#pragma GCC target("avx,avx2,fma,sse4")


// ╭──────────────────────────────╮
// │         MACROS ZONE          │
// ╰──────────────────────────────╯
#define ll                long long
#define int               long long
#define eb                emplace_back
#define mp                make_pair
#define ff                first
#define ss                second
#define pb                push_back
#define lb                lower_bound
#define ub                upper_bound
#define all(x)            x.begin(), x.end()
#define rall(x)           x.rbegin(),x.rend()
#define ins               insert
#define ln                '\n'
#define endl              "\n"
#define endlf             "\n" << flush;
#define yes               cout << "YES\n"
#define no                cout << "NO\n"
#define fr(i,n)           for(int i = 0; i < n; ++i)
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define getunique(v)      {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define NP(a)             next_permutation(all(a))
#define sz(x)             (int)((x).size())
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll



int f(vector<string>&a,vector<int>&b,vector<int>&c,vector<map<int,vector<int>>>&fq,vector<int>&dp,int &n,int mask){
    int ones=ppcll(mask);
    if(ones>=n){
        return 0;
    }
    if(dp[mask]!=-1)return dp[mask];
    int last=0;
    for(int i=0;i<n;i++){
        if((mask&(1<<i))!=0){
            last+=b[i];
        }
    }
    int maxi=0;
    for(int i=0;i<n;i++){
        if((mask&(1<<i))==0){
            int ans=0;
            int new_mask=(mask|(1<<i));
            auto it = fq[i].lower_bound(-last);
            if (it != fq[i].end()) {
                if(it!=fq[i].begin()){
                    int key=it->first;
                    if(key!=(-last)){
                        ans=0;
                    }
                    else{
                        auto temp=it->second;
                        --it;
                        int idx=(it->second)[0];
                        int req=lower_bound(temp.begin(),temp.end(),idx)-temp.begin();
                        ans=req;
                    }
                }
                else{
                    int key=it->first;
                    if(key==(-last)){
                        ans=(int)(it->second).size()+f(a,b,c,fq,dp,n,new_mask);
                    }
                    else{
                        ans=f(a,b,c,fq,dp,n,new_mask);
                    }
                }
            }
            else{
                ans=0;
            }
            maxi=max(maxi,ans);
        }
    }
    return dp[mask]=maxi;
}



// ╭──────────────────────────────╮
// │        SOLVER ZONE           │
// ╰──────────────────────────────╯
void solve(){

    int n;
    cin>>n;
    vector<string>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int>b(n);
    vector<int>c(n);
    vector<map<int,vector<int>>>fq(n);
    for(int i=0;i<n;i++){
        int p=0;
        int mini=LLONG_MAX;
        for(int j=0;j<a[i].size();j++){
            int t=(a[i][j]==')')?-1:1;
            p+=t;
            mini=min(mini,p);
            fq[i][p].push_back(j);
        }
        b[i]=p;
        c[i]=mini;
    }
    vector<int>dp(1<<n,-1);
    cout<<f(a,b,c,fq,dp,n,0);



}
// ╭──────────────────────────────╮
// │             MAIN             │
// ╰──────────────────────────────╯
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--){
        solve();
    }
}