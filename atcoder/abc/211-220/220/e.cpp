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
    
    ll n, d; cin >> n >> d;
    
    ll cump[n];
    zep(i, 0, n)cump[i] = powmod(2, i); 
    zep(i, 1, n){
        cump[i] += cump[i - 1];
        cump[i] %= MOD;
    }

    ll ans = 0;
    zep(i, 0, n){
        if(d <= i + n - 1){
            ll l = max(0LL, (d - (n - 1 - i) + 1) / 2);

            ll tmp = 0;

            // tmp += cump[d - l];

            // if(d - i > 0){
            //     tmp += MOD - cump[d - i - 1];
            //     tmp %= MOD;
            // }

            // if(2 * l <= d && d <= 2 * i){
            //     tmp += MOD - 1;
            //     tmp %= MOD;
            // }

            rep(j, l, i){
                ll x = d - j;

                tmp += powmod(2, x);
                if(2 * j == d)tmp--;
            }

            ans += powmod(2, i) * tmp % MOD;
            ans %= MOD;
            // print(ans)
        }
    }
    print(ans)

    return 0;
}