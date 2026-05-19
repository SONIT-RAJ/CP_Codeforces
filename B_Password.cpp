/*
   Author: SONIT RAJ
    created: 18:10:36 19-05-2026
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long

const int maxn=1e6+1;

const int m1 = 1e9+7;
const int m2 = 1e9+9;

int hash1(string &s,int mid){
    int h=0;
    for(int i=0;i<mid;i++){
        char c=s[i];
        h=(h*31+c-'a'+1)%m1;
    }
    return h;
}
int hash2(string &s,int mid){
    int h=0;
    for(int i=0;i<mid;i++){
        char c=s[i];
        h=(h*59+c-'a'+1)%m2;
    }
    return h;
}

int p31[maxn];
int p57[maxn];

bool check(string &s,int mid){
    int n=s.size();
    int h1=hash1(s,mid);
    int h2=hash2(s,mid);
    int temp1=h1;
    int temp2=h2;
    for(int i=mid;i<n-1;i++){
        char c=s[i];
        temp1=(temp1-((s[i-mid]-'a'+1)*p31[mid-1])%m1+m1)%m1;
        temp1=(temp1*31+c-'a'+1)%m1;
        temp2=(temp2-((s[i-mid]-'a'+1)*p57[mid-1])%m2+m2)%m2;
        temp2=(temp2*59+c-'a'+1)%m2;
        if(temp1==h1 && temp2==h2){
            return true;
        }
    }
    return false;
}

// ╭──────────────────────────────╮
// │        SOLVER ZONE           │
// ╰──────────────────────────────╯
void solve(){

    string s;
    cin>>s;
    int n=s.size();
    vector<int>a;
    a.reserve(n);
    int ph1=0;
    int ph2=0;
    int sh1=0;
    int sh2=0;
    for(int i=0;i<n-1;i++){
        char c=s[i];
        char c2=s[n-1-i];
        ph1=(ph1*31+c-'a'+1)%m1;
        ph2=(ph2*59+c-'a'+1)%m2;
        sh1=(sh1+(c2-'a'+1)*p31[i])%m1;
        sh2=(sh2+(c2-'a'+1)*p57[i])%m2;
        if(ph1==sh1 && ph2==sh2){
            a.push_back(i+1);
        }
    }
    string v="Just a legend";
    if(a.size()==0){
        cout<<v;
        return;
    }
    int low=0;
    int high=(int)a.size()-1;
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(check(s,a[mid])){
            ans=a[mid];
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    if(ans==-1){
        cout<<v;
        return;
    }
    for(int i=0;i<ans;i++){
        cout<<s[i];
    }



}
// ╭──────────────────────────────╮
// │             MAIN             │
// ╰──────────────────────────────╯
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // precomp_fact();  // Enable if using nCr or factorials
    int _=1;
    p31[0]=1;
    p57[0]=1;
    for(int i=1;i<=1e6;i++){
        p31[i]=(p31[i-1]*31)%m1;
        p57[i]=(p57[i-1]*59)%m2;
    }
    while(_--){
        solve();
    }
}