#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int>a(m);
        for(int i=0;i<m;i++){
            cin>>a[i];
        }
        for(int i=0;i<m;i++){
            a[i]=min(a[i],n-1);
        }


        sort(a.begin(),a.end());
        long long finalAnswer=0;
        for(int i=0;i<m;i++){
            auto it =lower_bound(a.begin(),a.end(),n-a[i]);
            if (it == a.end()){
                continue;
            }
            int requiredIndex=it - a.begin();;
            int choice=m-requiredIndex;
            if(a[requiredIndex]<=a[i]){
                choice--;
            }
            finalAnswer+=(2LL*(1LL*a[i]*choice)-(1LL*choice*n)+(1LL*choice));

        }
        cout<<finalAnswer<<endl;
    }
    return 0;
}

