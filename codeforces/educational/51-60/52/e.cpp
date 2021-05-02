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

ll h = (MOD + 1) / 2;

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n, m, c; cin >> n >> m >> c;
    ll b[m]; zep(i, 0, m)cin >> b[i];
    
    ll len = n - 2 * b[m - 1];
    rrep(i, m - 1, 1)b[i] -= b[i - 1];

    ll ans = 1;
    zep(i, 0, m){
        ll x = powmod(c, b[i]);
        ll y = (x + ((powmod(c, 2 * b[i]) + (MOD - x)) % MOD) * h % MOD) % MOD;
        ans *= y; ans %= MOD;
    }
    ans *= powmod(c, len); ans %= MOD;

    print(ans)

    return 0;
}