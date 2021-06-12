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

long long powmod(long long a, long long x){
    if(x == 0)return 1;
    long long r = powmod(a, x / 2);
    return (x%2)? (r * r % MOD) * a % MOD : r * r % MOD;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n; cin >> n;
    ll a[n]; zep(i, 0, n)cin >> a[i];

    ll l[n][2]; memset(l, 0, sizeof(l));
    l[0][0] = 1;
    zep(i, 1, n){
        l[i][0] = (l[i - 1][0] + l[i - 1][1]) % MOD;
        l[i][1] = l[i - 1][0];
    }

    ll r[n][2]; memset(r, 0, sizeof(r));
    r[n - 1][0] = 1;
    r[n - 1][1] = 1;
    rrep(i, n - 2, 0){
        r[i][0] = (r[i + 1][0] + r[i + 1][1]) % MOD;
        r[i][1] = r[i + 1][0];
    }

    ll ans = 0;
    zep(i, 0, n){
        ll x = 0;
        if(i == 0){
            x += (r[i + 1][0] + r[i + 1][1]) % MOD;
            // x += MOD - r[i + 1][0];
            x %= MOD;
        }else if(i == n - 1){
            x += (l[i - 1][0] + l[i - 1][1]) % MOD;
            x += MOD - l[i - 1][0];
            x %= MOD;
        }else{
            x += ((l[i - 1][0] + l[i - 1][1]) % MOD) * ((r[i + 1][0] + r[i + 1][1]) % MOD) % MOD;
            x += MOD - l[i - 1][0] * r[i + 1][0] % MOD;
            // x += MOD - ((l[i - 1][0] + l[i - 1][1]) % MOD) * r[i + 1][0] % MOD;
            // x += MOD - l[i + 1][0] * ((r[i + 1][0] + r[i + 1][1]) % MOD) % MOD;
            x %= MOD;
        }
        // print(x)
        ans += a[i] * x % MOD;
        ans %= MOD;
    }
    print(ans)

    return 0;
}