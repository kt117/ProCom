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

const long long MAX = 2e5+500;
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

    ll ans = 0;
    rep(i, 1, m){
        vector<ll> v;
        ll x = i;
        for(ll j = 2; j * j <= x; j++){
            ll cnt = 0;
            while(x % j == 0){
                x /= j;
                cnt++;
            }
            v.push_back(cnt);
        }
        if(x > 1){
            v.push_back(1);
        }
        
        ll y = 1;
        zep(j, 0, v.size()){
            y *= COM(n - 1 + v[j], v[j]);
            y %= MOD;
        }
        ans += y;
        ans %= MOD;
    }
    print(ans)
    
    return 0;
}