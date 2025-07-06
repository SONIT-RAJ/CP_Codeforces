#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#define ll long long
#define int long long
#define rep(i,a,b) for(int i = a; i<b; i++)
#define rew(x) for(int i = 0; i<x; i++)
#define all(x) x.begin(), x.end()
#ifdef ONLINE_JUDGE
    #define de(...)
    #define de2(...)
#endif
const ll inf = 2e18 + 5;
const ll M = 1e9 + 7;
#define PI 3.141592653589

void solve(){

    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int>a(n+1,0);
    int f=0;
    int b=0;
    int flag=0;
    int change=-1;
    for(int i=1;i<=n;i++){
        if(s[i-1]=='('){
            a[i]=a[i-1]+1;
            f++;
        }
        else{
            b++;
            a[i]=a[i-1]-1;
        }
        if(a[i]==0 && change==-1){
            change=i;
        }
        if(a[i]<0){
            flag=1;
        }
    }
    if(f!=b){
        cout<<-1;
        return;
    }
    if(flag==0){
        cout<<1<<endl;
        for(int i=0;i<n;i++){
            cout<<1<<" ";
        }
        return;
    }
    vector<int>ans(n+1,0);
    flag=0;
    unordered_set<int>se;
    for(int i=1;i<=n;i++){
        if(flag==0){
            if(a[i]>0)flag=1;
            if(a[i]<0)flag=2;
            if(a[i]==0)flag=0;
        }
        ans[i]=flag;
        se.insert(flag);
        if(a[i]>0)flag=1;
        if(a[i]<0)flag=2;
        if(a[i]==0)flag=0;
    }
    cout<<se.size()<<"\n";
    for(int i=1;i<=n;i++){
        if(se.size()==1){
            cout<<1<<" ";
        }
        else{
            cout<<ans[i]<<" ";
        }
    }




}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
        cout<<"\n";
    }
}