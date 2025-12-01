#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;//Only input. Main logic starts below.
        for(int i = 1; i < n-1; i++) cout<<(k&1 ? n:n-1)<<" ";
        cout<<n<<" "<<n-1<<endl;
    }//End of main logic.   l   lines used - 1
    return 0;
}