#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        double x;
        cin>>n>>x;
        vector<int>a(n);
        long long sum=0;
        long long maximum=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            maximum+=ceil(a[i]/x);
            sum+=a[i];
        }
        sum=ceil(sum/x);
        cout<<sum<<" "<<maximum<<endl;
    }
    return 0;
}