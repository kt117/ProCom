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

string s;
ll n, dp[27][5050];

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    COMinit();

    cin >> s;
    n = s.size();

    rep(j, 1, n)dp[0][j] = 1;
    zep(i, 0, 26){
        ll cnt = 0;
        zep(j, 0, n)if(s[j] - 'a' == i)cnt++;
        // print(cnt)

        rep(j, 0, n){
            rep(k, 0, min(cnt, j)){
                dp[i + 1][j - k] += dp[i][j] * COM(j, k) % MOD;
                dp[i + 1][j - k] %= MOD;
            }
        }
    }
    print(dp[26][0])
    
    return 0;
}