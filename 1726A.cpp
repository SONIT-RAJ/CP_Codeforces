#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        int maxi=INT_MIN;
        int mini=INT_MAX;
        int d=INT_MIN;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(mini>a[i]){
                mini=a[i];
            }
            if(maxi<a[i]){
                maxi=a[i];
            }
            if(i!=0){
                if(d<a[i-1]-a[i]){
                    d=a[i-1]-a[i];
                }
            }
        }
        if(d<a[n-1]-a[0]){
            d=a[n-1]-a[0];
        }
        if(mini==a[0]){
            cout<<maxi-mini<<endl;
        }
        else if(maxi==a[n-1]){
            cout<<maxi-mini<<endl;
        }
        else{
            int ans=max(d,maxi-a[0]);
            cout<<max(a[n-1]-mini,ans)<<endl;
        }

    }
    return 0;
}