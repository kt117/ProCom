#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
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
    return (x%2)? (r * r % MOD) * a % MOD : r * r % MOD;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    COMinit();

    ll t; cin >> t;
    while(t--){
        ll n, k; cin >> n >> k;

        ll e = 0;
        rep(i, 0, n){
            if(i % 2 == 0){
                e += COM(n, i); e %= MOD;
            }
        }
        // print(e)

        ll dp[k + 1][2]; memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;

        rep(i, 1, k){
            if(n % 2){
                dp[i][0] = dp[i - 1][0] * (e + 1) % MOD;
            }else{
                dp[i][0] = dp[i - 1][0] * (e + MOD - 1) % MOD;
                dp[i][1] = (dp[i - 1][0] + dp[i - 1][1] * powmod(2, n) % MOD) % MOD;
            }
        }

        print((dp[k][0] + dp[k][1]) % MOD)
    }
    
    return 0;
}