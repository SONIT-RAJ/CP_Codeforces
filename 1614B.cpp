/*
   Author: SONIT RAJ
    created: 00:17:08 01-04-2025
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

void solve(){

    int n;
    cin>>n;
    vector<vector<int>>a(n,vector<int>(2,0));
    for(int i=0;i<n;i++){
        cin>>a[i][0];
        a[i][1]=i;
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    int ans=0;
    int head=(n%2==1)?((n+1)/2):(n/2+1);
    int count=0;
    int j=1;
    vector<vector<int>>b(n,vector<int>(2,0));
    for(int k=0;k<n;k++){
        if(count<2){
            ans+=2*j*a[k][0];
            count++;
            if(count%2==1){
                b[k][0]=a[k][1];
                b[k][1]=head+j;
            }
            else{
                b[k][0]=a[k][1];
                b[k][1]=head-j;
            }
        }
        else{
            j++;
            ans+=2*j*a[k][0];
            count=1;
            b[k][0]=a[k][1];
            b[k][1]=head+j;

        }
    }
    sort(b.begin(),b.end());
    cout<<ans<<"\n";
    cout<<head<<" ";
    for(int i=0;i<n;i++){
        cout<<b[i][1]<<" ";
    }




}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
        cout<<"\n";
    }
}