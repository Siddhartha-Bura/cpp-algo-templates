int nCr(int n, int r) {
    if (r > n) return 0;
    if (r == 0 || n == r) return 1;
    double res = 0;
    for (int i = 0; i < r; i++) {
        res += log(n-i) - log(i+1);
    }
    return (int)round(exp(res));
}

// Credits: gfg
// TC: O(r)
// SC: O(1)

int factMemo[100000] = {};
const int mod = 1e9+7;
ll power(ll a, ll b, ll m) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b = b >> 1;
    } 
    return res;
}
ll fact(ll n) {
    if (n == 0) return 1;
    if (factMemo[n]) return factMemo[n];
    factMemo[n] = (n * fact(n - 1)) % mod;
    return factMemo[n];
}
ll nCr(ll a, ll b) {
    return (((fact(a) * power(fact(b), mod - 2, mod)) % mod) * power(fact(a - b), mod - 2, mod)) % mod;
}
