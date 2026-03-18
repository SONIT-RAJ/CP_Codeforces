/*
   Author: SONIT RAJ
    created: 13:30:50 18-03-2026
*/


#include<bits/stdc++.h>
using namespace std;
bool f(vector<int>&mpp,string s,int real){
    int new_sum=0;
    for(int i=0;i<s.size();i++){
        if(mpp[s[i]-'0']>0){
            mpp[s[i]-'0']--;
            new_sum+=s[i]-'0';
        }
        else{
            return false;
        }
    }
    if(s.size()==1){
        int req_sum=0;
        for(int i=0;i<10;i++){
            req_sum+=i*mpp[i];
        }
        return req_sum==real;
    }
    bool flag=f(mpp,to_string(new_sum),real);
    return flag;
}


// ╭──────────────────────────────╮
// │        SOLVER ZONE           │
// ╰──────────────────────────────╯
void solve(){
    string s;
    cin>>s;
    int n=s.size();
    if(n<2){
        cout<<s;
        return;
    }
    vector<int>mpp(10,0);
    for(int i=0;i<n;i++){
        mpp[s[i]-'0']++;
    }
    int ans=0;
    for(int i=n*9;i>=0;i--){
        vector<int>temp=mpp;
        string sum=to_string(i);
        bool flag=f(temp,sum,i);
        if(flag==false)continue;
        ans=i;
        mpp=temp;
        break;
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=mpp[i];j++){
            cout<<i;
        }
    }
    int new_ans=0;
    while(1){
        string sum=to_string(ans);
        new_ans=0;
        for(int i=0;i<sum.size();i++){
            cout<<sum[i];
            if(sum.size()==1){
                return;
            }
            new_ans+=sum[i]-'0';
        }
        ans=new_ans;
    }




}
// ╭──────────────────────────────╮
// │             MAIN             │
// ╰──────────────────────────────╯
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // precomp_fact();  // Enable if using nCr or factorials
    int _=1;
    cin>>_;
    while(_--){
        solve();
        cout<<"\n";
    }
}