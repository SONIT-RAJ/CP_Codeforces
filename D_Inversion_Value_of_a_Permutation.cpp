#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define INF(t) numeric_limits<t>::max()

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int N = 15*29;
	vector<pair<int, int>> dp(N+1, {1e9, -1});
	dp[0] = {0, 0};
	dp[1] = {2, 2};
	for(int i = 2; i <= N; i++) {
		for(int pt = 2; pt <= 30; pt++) {
			int sub = (pt*(pt-1))/2;
			if(i - sub < 0) break;
			if(dp[i-sub].first+pt < dp[i].first) {
				dp[i].first = dp[i-sub].first+pt;
				dp[i].second = pt;
			}
		}
	}

	int tc; cin >> tc;
	while(tc--) {
		int n, k; cin >> n >> k;
		vector<int> ans(n);
		iota(ans.begin(), ans.end(), 1);
		reverse(ans.begin(), ans.end());
		k = n*(n-1)/2 - k;
		if(dp[k].first > n) {
			cout << "0\n"; continue;
		}
		int pos = 0, cur = k;
		while(cur > 0) {
			int pt = dp[cur].second;
			reverse(ans.begin()+pos, ans.begin()+pos+pt);
			cur -= (pt*(pt-1))/2;
			pos += pt;
		}
		for(auto x : ans) cout << x << " ";
		cout << "\n";
	}

	return 0;
}