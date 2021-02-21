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

long long powmod(long long a, long long x){
    if(x == 0)return 1;
    long long r = powmod(a, x / 2);
    return (x%2)? (r * r % MOD) * a % MOD : r * r % MOD;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n, m, k; cin >> n >> m >> k;
    if(n > m){
        ll tmp = n;
        n = m;
        m = tmp;
    }

    if(n == 1){
        print(powmod(k, m))
        return 0;
    }

    ll cnt[k + 1];
    rep(i, 1, k)cnt[i] = powmod(i, n);
    rrep(i, k, 2){cnt[i] += MOD - cnt[i - 1]; cnt[i] %= MOD;}

    ll ans = 0;
    rep(i, 1, k){
        ans += cnt[i] * powmod(k - i + 1, m) % MOD;
        ans %= MOD;
    }
    print(ans)

    return 0;
}