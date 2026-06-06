/*
   Author: SONIT RAJ
    created: 10:01:43 06-06-2026
*/


#include<bits/stdc++.h>
using namespace std;

// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC optimize("Ofast,unroll-loops,O3,no-stack-protector,fast-math")
#pragma GCC target("avx,avx2,fma,sse4")


#define ll long long

template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

struct DSU {
    vector<int> parent, sz;
    DSU(int n) {
        parent.resize(n);
        sz.assign(n, 1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find(int x) { return x == parent[x] ? x : parent[x] = find(parent[x]); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

void solve(){

    int n;
    cin>>n;
    vector<pair<int,int>>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }
    vector<int>c(n);
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    vector<int>k(n);
    for(int i=0;i<n;i++){
        cin>>k[i];
    }
    pqg<pair<ll,pair<int,int>>>pq;
    for(int i=0;i<n;i++){
        pq.push({c[i],{i,i}});
        for(int j=i+1;j<n;j++){
            ll cost=1ll*k[i]+k[j];
            cost*=(abs(a[i].first-a[j].first)+abs(a[i].second-a[j].second));
            pq.push({cost,{i,j}});
        }
    }
    DSU d(n);
    vector<int>light(n,0);
    vector<int>p;
    p.reserve(n);
    vector<pair<int,int>>ans;
    ans.reserve(n*n);
    ll final_cost=0;
    int on=0;
    int comp=n;
    while(!pq.empty()){
        if(on>=comp)break;
        auto temp=pq.top();
        pq.pop();
        ll cost=temp.first;
        int i=temp.second.first;
        int j=temp.second.second;
        int pi=d.find(i);
        int pj=d.find(j);
        if(i==j){
            if(light[pi]==1){
                continue;
            }
            else{
                on++;
                light[pi]=1;
                final_cost+=cost;
                p.push_back(i);
                continue;
            }
        }
        if(pi==pj)continue;
        if(light[pi]==1 && light[pj]==1)continue;
        if(light[pi]==0 && light[pj]==0){
            comp--;
            d.unite(i,j);
            final_cost+=cost;
            ans.push_back({i,j});
            continue;
        }
        if(light[pi]==1){
            comp--;
            d.unite(i,j);
            final_cost+=cost;
            ans.push_back({i,j});
            int new_pi=d.find(i);
            light[new_pi]=1;
        }
        else if(light[pj]==1){
            comp--;
            d.unite(i,j);
            final_cost+=cost;
            ans.push_back({i,j});
            int new_pi=d.find(i);
            light[new_pi]=1;
        }

    }
    cout<<final_cost<<endl;
    int sz=p.size();
    cout<<sz<<endl;
    for(int i=0;i<sz;i++){
        cout<<p[i]+1<<" ";
    }
    cout<<endl;
    int tz=ans.size();
    cout<<tz<<endl;
    for(int i=0;i<tz;i++){
        cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
    }





}
// ╭──────────────────────────────╮
// │             MAIN             │
// ╰──────────────────────────────╯
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // precomp_fact();  // Enable if using nCr or factorials
    int _=1;
    while(_--){
        solve();
    }
}