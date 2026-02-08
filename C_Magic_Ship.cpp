#include<bits/stdc++.h>
using namespace std;

#define int long long

bool check(vector<pair<int,int>>&d,int mid,int req_up,int req_right){
	int size=d.size();
	size--;
	int total=mid/size;
	int rem=mid-(size*total);
	int wind_up=d[rem].first+total*d[size].first;
	int wind_right=d[rem].second+total*d[size].second;
	req_up-=wind_up;
	req_right-=wind_right;
	return mid>=abs(req_up)+abs(req_right);
}

void solve(){
	int x1,y1;
	cin>>x1>>y1;

	int x2,y2;
	cin>>x2>>y2;

	int req_up=y2-y1;
	int req_right=x2-x1;

	int n;
	cin>>n;

	string s;
	cin>>s;

	vector<pair<int,int>>d(n+1);
	int up=0;
	int right=0;
	for(int i=1;i<=n;i++){
        if(s[i-1]=='U'){
            up++;
        }
        else if(s[i-1]=='D'){
            up--;
        }
        else if(s[i-1]=='L'){
            right--;
        }
        else if(s[i-1]=='R'){
            right++;
        }
        d[i]={up,right};
    }


    int low=1;
    int high=1e18;
    int ans=-1;


    while(low<=high){

        int mid=low+(high-low)/2;
        if(check(d,mid,req_up,req_right)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }

cout<<ans;

}

signed main(){
	int t = 1;
	//cin>>t;
	while(t--){
        solve();
        cout<<"\n";
    }
}
