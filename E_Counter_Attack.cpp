#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>&adj,set<int>&s,vector<vector<int>>&mpp,queue<int>&q,int i,int &first){
    sort(adj[i].begin(),adj[i].end());
    for(auto it=s.begin();it!=s.end();){
        int val=(*it);
        auto low=lower_bound(adj[i].begin(),adj[i].end(),val);
        if(low!=adj[i].end() && (*low==val)){
            ++it;
        }
        else{
            mpp[first].push_back(val);
            q.push(val);
            it=s.erase(it);
        }
    }
}

// ╭──────────────────────────────╮
// │        SOLVER ZONE           │
// ╰──────────────────────────────╯
void solve(){

    int n,m;
    cin>>n>>m;
    set<int>s;
    for(int i=1;i<=n;i++){
        s.insert(i);
    }
    vector<vector<int>>adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // for (int i = 1; i <= n; i++) {
    //     sort(adj[i].begin(), adj[i].end());
    // }
    queue<int>q;
    vector<int>ans;
    ans.reserve(n);
    vector<vector<int>>mpp(n+1);
    for(int i=1;i<=n;i++){
        if(s.find(i)==s.end())continue;
        q.push(i);
        ans.push_back(i);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            dfs(adj,s,mpp,q,node,i);
        }
    }
    int sz=ans.size();
    cout<<sz<<endl;
    for(int i=0;i<sz;i++){
        int val=ans[i];
        int szz=mpp[val].size();
        cout<<szz<<" ";
        for(int j=0;j<szz;j++){
            cout<<mpp[val][j]<<" ";
        }
        cout<<endl;
    }




}
// ╭──────────────────────────────╮
// │             MAIN             │
// ╰──────────────────────────────╯
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--){
        solve();
    }
}