#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int maximum=INT_MAX;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        if(maximum>abs(x)){
            maximum=abs(x);
        }
    }
    cout<<maximum;

    return 0;
}