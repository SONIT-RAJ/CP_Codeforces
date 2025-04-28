/*
   Author: SONIT RAJ
    created: 12:25:51 25-04-2025
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
    string s;
    cin>>s;
    vector<int>position;
    int k=1;
    for(int i=0;i<n;i++){
        if(s[i]=='*'){
            position.push_back(i+1-k);
            k++;
        }
    }
    k--;
    if(k==n || k==0){
        cout<<0;
        return;
    }
    vector<int>prefix(k);
    prefix[0]=position[0];
    for(int i=1;i<k;i++){
        prefix[i]=prefix[i-1]+position[i];
    }
    int answer=prefix[k-1];
    int sum=0;
    for(int i=1;i<=n-k;i++){
        auto it = upper_bound(position.begin(), position.end(), i);

        if (it != position.end()) {
                int upper =distance(position.begin(), it);
                if(upper==0){
                    sum=prefix[k-1]-(k*i);
                }
                else{
                    int front=(prefix[k-1]-prefix[upper-1])-(i*(k-upper));
                    int back=prefix[upper-1]-(i*upper);
                    sum=front-back;
                }
        }
        else{
            sum = abs(prefix[k-1]-(k*i));
        }
        answer=min(answer,sum);
    }
    cout<<answer;
//this was a very good question


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