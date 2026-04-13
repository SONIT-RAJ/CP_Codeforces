#include<bits/stdc++.h>
using namespace std;
void solve(){

    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans=0;
    stack<pair<int,int>>s;
    for(int i=0;i<n;i++){
        int days=0;
        while(!s.empty() && s.top().first>=a[i]){
            days=max(days,s.top().second);
            s.pop();
        }
        if(s.empty()){
            s.push({a[i],0});
        }
        else{
            s.push({a[i],days+1});
            ans=max(days+1,ans);
        }
    }
    cout<<ans;




}
signed main(){
    int _=1;
    while(_--){
        solve();
    }
}