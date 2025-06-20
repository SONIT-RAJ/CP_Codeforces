/*
   Author: SONIT RAJ
    created: 09:44:06 16-06-2025
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

bool check(int mid,vector<int>&a,vector<int>&b,vector<int>&p,vector<int>&m,int n){
    vector<int>A=a;
    int mine=0;
    int opp=0;
    int flag=0;
    int i=0;
    int j=0;
    while(mine+opp<n){
        int up=A[i];
        if(up==m[mid-1] && flag==0){
            flag=1;
            up=max(up,p[mid-1]);
            A[i]=up;
        }
        if(up>b[j]){
            i++;
            mine++;
        }
        else{
            j++;
            opp++;
        }
    }
    return mine>=mid;
}

void solve(){

    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int>b(n);
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    vector<int>m(n);
    m[0]=a[0];
    for(int i=1;i<n;i++){
        m[i]=min(m[i-1],a[i]);
    }
    vector<int>p(n);
    p[n-1]=0;
    for(int i=n-2;i>=0;i--){
        p[i]=max(a[i+1],p[i+1]);
    }
    int low=1;
    int high=n;
    int ans=0;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(check(mid,a,b,p,m,n)){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    cout<<ans;




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