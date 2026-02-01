#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>>f(1e5+1);

void pre(){
    for(int i=1;i<=1e5;i++){
        for(int j=i;j<=1e5;j+=i){
            f[j].push_back(i);
        }
    }
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    map<int,int>mpp;
    int c=0;
    int i=0;
    int j=0;
    int ans=1e6;
    for(int j=0;j<n;j++){
        for(auto &d:f[a[j]]){
            mpp[d]++;
            if(mpp[d]==1 && d<=m){
                c++;
            }
        }
        while(c>=m){
            ans=min(ans,a[j]-a[i]);
            for(auto &d:f[a[i]]){
                mpp[d]--;
                if(mpp[d]==0 && d<=m){
                    c--;
                }
            }
            i++;
        }
    }
    if(ans==1e6){
        cout<<-1;
        return;
    }
    cout<<ans;
}

signed main(){
    int tt;
    cin>>tt;

    pre();

    while(tt--){
        solve();
        cout<<endl;
    }
}