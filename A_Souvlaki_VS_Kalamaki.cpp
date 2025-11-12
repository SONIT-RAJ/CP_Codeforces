#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tc; cin >> tc;
	while(tc--) {
		int n; cin >> n;
		vector<int> a(n); for(auto &x : a) cin >> x;
		sort(a.begin(), a.end());
		bool ans = true;
		for(int i = 1; i + 1 < n; i += 2) {
			if(a[i] != a[i+1]) ans = false;
		}
		if(ans) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}