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

ll n, m, dp[6000][100];

ll f(ll bit, ll p){
    if(dp[bit][p] != -1)return dp[bit][p];
    ll x = (bit >> p);

    if(p == 0){
        if(x % 2 || x > n)return 0;
        return dp[bit][p] = COM(n, x);        
    }else{
        ll res = 0;
        rep(i, 0, x){
            if(i % 2 == 0 && i <= n){
                res += f(bit - i * (1LL << p), p - 1) * COM(n, i) % MOD;
                res %= MOD;
            }
        }
        return  dp[bit][p] = res;
    }
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    COMinit();

    cin >> n >> m;
    if(m % 2){print(0) return 0;}

    ll p = 0;
    while((1LL << p) <= m){
        p++;
    }

    memset(dp, -1, sizeof(dp));
    print(f(m, p))
    
    return 0;
}