ll modExp(ll base, ll exp, ll mod = MOD) {
	ll res = 1;
	base %= mod;
	while (exp > 0) {
		if (exp & 1)
			res = (res * base) % mod;
		base = (base * base) % mod;
		exp >>= 1;
	}
	return res;
}
