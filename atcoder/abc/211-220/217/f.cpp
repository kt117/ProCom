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

ll n, m, dp[3][500][500]; 
bool ok[500][500], use[500][500];

ll memo(ll l, ll r){
    if(use[l][r])return dp[0][l][r];
    use[l][r] = true;
    
    if(l == r)return dp[0][l][r] = 1;
    
    ll L = (r - l) / 2;
    zep(i, 1, L){
        // memo(l, l + 2 * i);
        memo(l + 2 * i, r);

        dp[0][l][r] += memo(l, l + 2 * i) * dp[1][l + 2 * i][r] % MOD * COM(L, i) % MOD;
        dp[0][l][r] %= MOD;
    }

    if(ok[l][r]){
        dp[1][l][r] += memo(l + 1, r - 1);
        dp[1][l][r] %= MOD;
        dp[0][l][r] += dp[1][l][r];
        dp[0][l][r] %= MOD;
    }

    return dp[0][l][r];
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    COMinit();

    cin >> n >> m;
    zep(i, 0, m){
        ll a, b; cin >> a >> b; a--;
        ok[a][b] = true;
    }

    print(memo(0, 2 * n))
    
    return 0;
}