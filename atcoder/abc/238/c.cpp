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

ll d = ((MOD + 1) / 2);

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n; cin >> n;
    ll ans = 0, p = 1;
    while(p <= n / 10){
        ll pp = p % MOD;
        ans += (1 + 9 * pp % MOD) * 9 % MOD * pp % MOD * d % MOD;
        ans %= MOD;
        p *= 10;
        // print(ans)
    }
    // print(p)
    p %= MOD;
    n %= MOD;
    ans += (2 + n + MOD - p) % MOD * ((1 + n + MOD - p) % MOD) % MOD * d % MOD;
    ans %= MOD;
    print(ans)
    
    return 0;
}