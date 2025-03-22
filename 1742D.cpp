#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        unordered_map<int,int>mpp;
        long long maximum=-1;
        for(int i=0;i<n;i++){
            cin>>a[i];
            mpp[a[i]]=i+1;
        }
        for(int i=1;i<=1000;i++){
            for(int j=i;j<=1000;j++){
                if(mpp[i]>0 && mpp[j]>0){
                    if(__gcd(i,j)==1 && maximum<mpp[i]+mpp[j]){
                        maximum=mpp[i]+mpp[j];
                    }
                }
            }
        }
        cout<<maximum<<endl;
    }
    return 0;
}