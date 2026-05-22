/*
   Author: SONIT RAJ
    created: 12:30:43 20-05-2026
*/


#include<bits/stdc++.h>
using namespace std;

// ╭──────────────────────────────╮
// │        SOLVER ZONE           │
// ╰──────────────────────────────╯
void solve(){

    int n;
    cin>>n;
    vector<int>a;
    a.reserve(2*n);
    vector<int>ans(2*n);
    stack<int>s;
    bool flag=false;
    for(int i=0;i<2*n;i++){
        char t;
        cin>>t;
        if(t=='+'){
            s.push(i);
        }
        else{
            int b;
            cin>>b;
            if(s.empty()){
                flag=true;
            }
            else{
                ans[s.top()]=b;
                s.pop();
            }
            ans[i]=-b;
        }
    }
    if(flag){
        cout<<"NO";
        return;
    }
    set<int>st;
    vector<int>f;
    f.reserve(n);
    for(int i=0;i<2*n;i++){
        if(ans[i]>0){
            f.push_back(ans[i]);
            st.insert(ans[i]);
        }
        else{
            if(st.empty()){
                cout<<"NO";
                return;
            }
            auto it=st.begin();
            int first=*it;
            if(first!=(-ans[i])){
                cout<<"NO";
                return;
            }
            st.erase(it);
        }
    }
    cout<<"YES"<<endl;
    for(int i=0;i<n;i++){
        cout<<f[i]<<" ";
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