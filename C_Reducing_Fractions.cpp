
/*
   Author: SONIT RAJ
    created: 10:02:35 10-05-2026
*/


#include<bits/stdc++.h>
using namespace std;




vector<int>spf(1e7+1);

void pre() {

    // Initially every number is its own SPF
    for (int i = 1; i <= 1e7; i++) {
        spf[i] = i;
    }

    // 0 and 1 special cases
    spf[0] = 0;
    spf[1] = 1;

    for (int i = 2; i * i <= 1e7; i++) {

        // If prime
        if (spf[i] == i) {

            // Mark SPF for multiples
            for (int j = i * i; j <= 1e7; j += i) {

                // First time visiting
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

// ╭──────────────────────────────╮
// │        SOLVER ZONE           │
// ╰──────────────────────────────╯
void solve(){

    int n,m;
    cin>>n>>m;
    unordered_map<int,int>up;
    unordered_map<int,int>down;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        int x=a[i];
        while (x!=1) {
            up[spf[x]]++;
            x /= spf[x];
        }
    }
    vector<int>b(m);
    for(int i=0;i<m;i++){
        cin>>b[i];
        int x=b[i];
        while (x!=1) {
            down[spf[x]]++;
            x /= spf[x];
        }
    }
    vector<int>num;
    vector<int>deno;
    for(auto &x:up){
        if(down.find(x.first)!=down.end()){
            int v1=x.second;
            int v2=down[x.first];
            int mini=min(v1,v2);
            up[x.first]-=mini;
            down[x.first]-=mini;
        }
    }
    vector<int>num1(n);
    vector<int>deno1(m);
    for(int i=0;i<n;i++){
        int val=a[i];
        int r=1;
        while(val>1){
            int p=spf[val];
            if(up[p]>0){
                up[p]--;
                r*=p;
            }
            val/=p;
        }
        num1[i]=r;
    }
    for(int i=0;i<m;i++){
        int val=b[i];
        int r=1;
        while(val>1){
            int p=spf[val];
            if(down[p]>0){
                down[p]--;
                r*=p;
            }
            val/=p;
        }
        deno1[i]=r;
    }

    cout<<n<<" "<<m<<endl;
    for(int i=0;i<n;i++){
        cout<<num1[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<m;i++){
        cout<<deno1[i]<<" ";
    }

}
// ╭──────────────────────────────╮
// │             MAIN             │
// ╰──────────────────────────────╯
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    pre();
    int _=1;
    while(_--){
        solve();
    }
}