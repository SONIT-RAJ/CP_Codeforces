#include<bits/stdc++.h>
using namespace std;
long long lcm(long long a, long long b) {
    return (a / __gcd(a, b)) * b;
}
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n,x,y;
        cin>>n>>x>>y;
        long long sub=(n/y)-(n/lcm(x,y));
        long long add=(n/x)-(n/lcm(x,y));
        long long ans=(((add)*(n+n+1-add))/2)-(((sub)*(1+sub))/2);
        cout<<ans<<endl;
    }
    return 0;
}