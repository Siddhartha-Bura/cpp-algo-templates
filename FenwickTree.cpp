#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class FenwickTree {
	vector<ll> bit;
public:
	ll n;
	FenwickTree(ll size) {
		n = size;
		bit.assign(size + 1, 0);
	}

	void update(ll id, ll val) {
		while (id <= n) {
			bit[id] += val;
			id += (id & -id);
		}
	}

	ll sum(ll id) {
		ll sum = 0;
		while (id > 0) {
			sum += bit[id];
			id -= (id & -id);
		}
		return sum;
	}
};
