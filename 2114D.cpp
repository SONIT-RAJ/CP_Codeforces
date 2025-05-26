/*
   Author: SONIT RAJ
    created: 20:46:40 26-05-2025
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

bool cmp(vector<int>&p,vector<int>&q){
    if(p[1]!=q[1]){
        return p[1]<q[1];
    }
    else{
        return p[0]<q[0];
    }
}

int find(pair<int,int>&point,vector<vector<int>>&a){
    int minix=INT_MAX;
    int miniy=INT_MAX;
    int maxix=INT_MIN;
    int maxiy=INT_MIN;
    int n=a.size();
    for(int i=0;i<n;i++){
        if(point.first==a[i][0] && point.second==a[i][1]){
            continue;
        }
        minix=min(minix,a[i][0]);
        miniy=min(miniy,a[i][1]);
        maxix=max(maxix,a[i][0]);
        maxiy=max(maxiy,a[i][1]);
    }
    int W = maxix - minix + 1;
    int H = maxiy - miniy + 1;
    int area = W * H;
    int filled = n - 1;
    if (area == filled) {
        area = min((W + 1) * H, W * (H + 1));
    }
    return area;
}

void solve(){

    int n;
    cin>>n;
    vector<vector<int>>a(n,vector<int>(2,0));
    for(int i=0;i<n;i++){
        cin>>a[i][0];
        cin>>a[i][1];
    }
    if(n<=2){
        cout<<n;
        return;
    }
    sort(a.begin(),a.end());
    pair<int,int>minix;
    minix.first=a[0][0];
    minix.second=a[0][1];
    pair<int,int>maxix;
    maxix.first=a[n-1][0];
    maxix.second=a[n-1][1];
    sort(a.begin(),a.end(),cmp);
    pair<int,int>miniy;
    pair<int,int>maxiy;
    miniy.first=a[0][0];
    miniy.second=a[0][1];
    maxiy.first=a[n-1][0];
    maxiy.second=a[n-1][1];
    int area1=find(minix,a);
    int area2=find(miniy,a);
    int area3=find(maxix,a);
    int area4=find(maxiy,a);
    int ans=min(area1,area2);
    ans =min(ans,area3);
    ans=min(ans,area4);
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