#include<bits/stdc++.h>
using namespace std;
#define int long long

int f(vector<int>&a,vector<vector<int>>&dp,int i,int b){
    if(i>=a.size())return 0;
    if(dp[i][b]!=-1)return dp[i][b];
    if(a[i]>4){
        return dp[i][b]=1+f(a,dp,i+1,0);
    }
    if(a[i]==0){
        return dp[i][b]=f(a,dp,i+1,0);
    }
    if(b==0){
        int mini=1+f(a,dp,i+1,0);
        mini=min(mini,2+f(a,dp,i+1,15));
        if(a[i]<=2){
            mini=min(mini,1+f(a,dp,i+1,3));
        }
        return dp[i][b]=mini;
    }
    else if(b==15){
        return dp[i][b]=f(a,dp,i+1,0);
    }
    else if(b==12){
        return dp[i][b]=1+f(a,dp,i+1,3);
    }
    else{
        if(a[i]<=2){
            return dp[i][b]=f(a,dp,i+1,0);
        }
        else{
            return dp[i][b]=1+f(a,dp,i+1,12);
        }
    }

}

void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<vector<int>>dp(n,vector<int>(16,-1));
    cout<<f(a,dp,0,0);
}

signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;
    while(tc--){
        solve();
        cout<<"\n";
    }
}