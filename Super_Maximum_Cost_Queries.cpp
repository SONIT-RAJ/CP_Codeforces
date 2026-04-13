#include<bits/stdc++.h>
using namespace std;
#define int long long
struct DSU {
    vector<int> parent, sz;
    DSU(int n) {
        parent.resize(n + 1);
        sz.assign(n + 1, 1);
        for(int i=0;i<=n;i++){
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

    int n,q;
    cin>>n>>q;
    vector<vector<int>>a(n-1,vector<int>(3));
    for(int i=0;i<n-1;i++){
        cin>>a[i][1]>>a[i][2]>>a[i][0];
    }
    sort(a.begin(),a.end());
    DSU d(n);
    map<int,int>mpp;
    for(int i=0;i<n-1;i++){
        int s1=d.sz[d.find(a[i][1])];
        int s2=d.sz[d.find(a[i][2])];
        d.unite(a[i][1],a[i][2]);
        if(mpp.find(a[i][0])==mpp.end()){
            mpp[a[i][0]]=s1*s2;
        }
        else{
            mpp[a[i][0]]+=s1*s2;
        }
    }
    int pre=0;
    vector<int>b;
    vector<int>c;
    b.reserve(n);
    c.reserve(n);
    for(auto &x:mpp){
        b.push_back(x.first);
        c.push_back(x.second+pre);
        pre+=x.second;
    }
    while(q--){
        int l,r;
        cin>>l;
        cin>>r;
        auto it=upper_bound(b.begin(),b.end(),r);
        r=it-b.begin();
        r--;
        it=lower_bound(b.begin(),b.end(),l);
        l=it-b.begin();
        l--;
        int up=(r>=0)?c[r]:0;
        int down=(l>=0)?c[l]:0;
        cout<<up-down<<'\n';
    }





}
signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int _=1;
    while(_--){
        solve();
    }
}