/*
   Author: SONIT RAJ
    created: 19:12:33 18-06-2025
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

int andd(vector<vector<int>>&p,int l,int mid){
    int ad=0;
    int d=mid-l+1;
    for(int i=0;i<32;i++){
        int back=(l-1<0)?0:p[i][l-1];
        int front=p[i][mid];
        if(front-back==d){
            ad+=(1<<i);
        }
    }
    return ad;
}

void solve(){

    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<vector<int>>p(32,vector<int>(n,0));
    for(int i=0;i<32;i++){
        int p1=(1<<i);
        for(int j=0;j<n;j++){
            int c=0;
            if(a[j]&p1){
                c++;
            }
            if(j==(0*1LL)){
                p[i][j]=c;
            }
            else{
                p[i][j]=p[i][j-1]+c;
            }
        }
    }
    int q;
    cin>>q;
    while(q--){
        int l,k;
        cin>>l>>k;
        l--;
        if(a[l]<k){
            cout<<-1<<" ";
            continue;
        }
        int low=l;
        int high=n-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int ad=andd(p,l,mid);
            if(ad<k){
                high=mid-1;
            }
            else{
                low=mid+1;
                ans=mid;
            }

        }
        cout<<ans+1<<" ";
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