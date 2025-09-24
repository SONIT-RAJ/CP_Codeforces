#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define INF(t) numeric_limits<t>::max()

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tc; cin >> tc;
	while(tc--) {
		int n; cin >> n;
		string s; cin >> s;

		vector<int> ans(n);
		iota(ans.begin(), ans.end(), 1);

		bool pos = true;
		for(int i = 0; i < n; i++) {
			if(s[i] == '0') {
				if(i && s[i-1] == '0') swap(ans[i], ans[i-1]);
				else if(i+1 == n || s[i+1] != '0') pos = false;
			}
		}

		if(pos) {
			cout << "YES\n";
			for(auto &x : ans) cout << x << " ";
			cout << "\n";
		}
		else cout << "NO\n";
	}

	return 0;
}