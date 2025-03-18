#include<bits/stdc++.h>
using namespace std;
long long M = 1e9 + 7;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        vector<int>b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int flag=1;
        long long product=1;
        for(int i=n-1;i>=0;i--){
            auto it = upper_bound(a.begin(), a.end(), b[i]);
            if(it == a.end()){
               cout<<0<<endl;
               flag=0;
               break;
            }
            int index=it - a.begin();
            product%=M;
            product=(product*((n-index)-(n-1-i)))%M;

        }
        if(flag){
            cout<<product<<endl;
        }


    }
    return 0;
}
