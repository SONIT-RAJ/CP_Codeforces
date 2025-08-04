/*
   Author: SONIT RAJ
    created: 21:17:48 04-08-2025
*/


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

vector<int> c(vector<int>&a,int &m,int &k,int &n){
    vector<int>b(n,-1);
    vector<int>p(n,0);
    for(int i=0;i<n;i++){
        if(a[i]>=m)b[i]=1;
    }
    p[0]=b[0];
    for(int i=1;i<n;i++){
        p[i]=p[i-1]+b[i];
    }
    int mini=0;
    int left=0;
    int right=k-1;
    for(int i=k-1;i<n;i++){
        if(p[i]-mini>=0){
            right=i;
            return {1,left,right};
        }
        if(mini>p[i-(k-1)]){
            mini=p[i-(k-1)];
            left=i-(k-1)+1;
        }
    }
    return {0,-1,-1};


}

void solve(){

    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans=1;
    int l=1;
    int h=n;
    int left=0;
    int right=k-1;
    vector<int>temp;
    while(l<=h){
        int m=l+(h-l)/2;
        temp=c(a,m,k,n);
        if(temp[0]==1){
            ans=max(ans,m);
            left=temp[1];
            right=temp[2];
            l=m+1;
        }
        else{
            h=m-1;
        }
    }
    cout<<ans<<" "<<left+1<<" "<<right+1;




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