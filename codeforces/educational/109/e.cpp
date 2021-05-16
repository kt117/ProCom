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

const long long MAX = 100;
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

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    COMinit();

    ll n, m; cin >> n >> m;
    ll d[n][m]; zep(i, 0, n)zep(j, 0, m)cin >> d[i][j];
    
    zep(i, 0, n)zep(j, 0, m)d[i][j] = n + 1 - d[i][j];

    ll ans = 0;
    zep(j, 0, m){
        vector<ll> v;
        zep(i, 0, n)v.push_back(d[i][j]);
        sort(v.begin(), v.end(), greater<>());

        ll a = 0, b = 1;
        zep(i, 0, n){
            a += b * v[i] % MOD * fac[n - (i + 1)] % MOD;
            a %= MOD;
            b *= n - i - v[i];
            b %= MOD;
        }    

        ans += a;
        ans %= MOD;
    }
    print(ans * finv[n] % MOD)
    
    return 0;
}