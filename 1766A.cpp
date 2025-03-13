#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int d=log10(n)+1;
        int p=pow(10,d-1);
        cout<<9*(d-1)+n/p<<endl;
    }
    return 0;
}