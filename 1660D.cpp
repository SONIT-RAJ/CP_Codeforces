#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
int mod=998244353;
/*
    coding time:-
*/
signed main(){
    fastio;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int T=1,N=2e5+5;
    cin>>T;
    for(int test=1;test<=T;test++){
      int n;
      cin>>n;
      vector<int> v(n);
      for(int i=0;i<n;i++){
        cin>>v[i];
      }
      int l=0,r=0,best=0,ctn=0,cnt=0;
      int left=n,right=0;
      while(l<n){
        while(l<n and v[l]==0)
        l++;
        if(l==n)
        break;
        int r=l;
        while(r<n and v[r]!=0)
        r++;
        cnt=0;
        ctn=0;
        // ek baar left se right jaa kar dekhe
        for(int i=l;i<r;i++){
          if(v[i]<0)
          ctn++;
          if(abs(v[i])==2)
          cnt++;
          if(ctn%2==0 and cnt>best){
            left=l;
            right=n-i-1;
            best=cnt;
          }
        }
        cnt=0;ctn=0;
        // ek baar right se left jaa kr dekhe
        for(int i=r-1;i>=l;i--){
          if(v[i]<0)
          ctn++;
          if(abs(v[i])==2)
          cnt++;
          if(ctn%2==0 and cnt>best){
            left=i;
            right=n-r;
            best=cnt;
          }
        }
        l=r+1;
      }
      cout<<left<<" "<<right<<endl;
    }
    return 0;
}