#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define INF(t) numeric_limits<t>::max()

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tc; cin >> tc;
	while(tc--) {
		ll n, x1, y1, x2, y2; cin >> n >> x1 >> y1 >> x2 >> y2;
		ll dx = abs(x1-x2), dy = abs(y1-y2);

		ll ddx = 0;
		if(x2 > x1) ddx = x1;
		if(x2 < x1) ddx = n-x1;

		ll ddy = 0;
		if(y2 > y1) ddy = y1;
		if(y2 < y1) ddy = n-y1;

		cout << max(dx+ddx, dy+ddy) << "\n";
	}

	return 0;
}