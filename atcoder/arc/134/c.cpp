#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 998244353;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define zep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(int i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

const long long MAX = 2e5+100;
long long fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

long long powmod(long long a, long long x){
    if(x == 0)return 1;
    long long r = powmod(a, x / 2);
    return (x%2)? (r * r % MOD) * (a % MOD) % MOD : r * r % MOD;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    COMinit();

    ll n, k; cin >> n >> k;
    ll a[n]; zep(i, 0, n)cin >> a[i];

    ll sm = 0;
    zep(i, 1, n)sm += a[i];

    if(a[0] < sm + k){print(0) return 0;}

    a[0] -= sm + k;
    ll ans = 1;

    // vector<ll> r(k + 1, 1);
    zep(i, 0, n){
        zep(j, 0, k - 1){
            ans *= a[i] + k - 1 - j;
            ans %= MOD;
            ans *= inv[j + 1];
            ans %= MOD;
        }
    }

    print(ans)
    
    return 0;
}