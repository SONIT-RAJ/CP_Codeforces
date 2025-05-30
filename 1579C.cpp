/*
   Author: SONIT RAJ
    created: 08:36:28 30-05-2025
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

    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<char>>a(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    map<pair<int,int>,bool>mpp;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<m;j++){
            if(a[i][j]=='.'){
                continue;
            }
            else{
                int p;
                int q1;
                int q2;
                    int c=0;
                    for(int v=1;v<=max(n,m);v++){
                        p=i-v;
                        q1=j-v;
                        q2=j+v;
                        if(p>=0 && p<n){
                            if(q1>=0 && q1<m && a[p][q1]=='*'){
                                if(q2>=0 && q2<m && a[p][q2]=='*'){
                                    c++;
                                    continue;
                                }
                            }
                            break;
                        }
                        break;
                    }
                    if(c<k && mpp[{i, j}]==false){
                        cout<<"NO";
                        return;
                    }
                    else if(c<k){
                        mpp[{i, j}]=true;
                    }
                    else{
                        int c=0;
                        for(int v=1;v<=max(n,m);v++){
                        p=i-v;
                        q1=j-v;
                        q2=j+v;
                        if(p>=0 && p<n){
                            if(q1>=0 && q1<m && a[p][q1]=='*'){
                                if(q2>=0 && q2<m && a[p][q2]=='*'){
                                    mpp[{p, q1}]=true;
                                    mpp[{p, q2}]=true;
                                    c++;
                                    continue;
                                }
                            }
                            break;
                        }
                        break;
                        }
                    }
            }

        }
    }
    cout<<"YES";




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