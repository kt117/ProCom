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

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll t; cin >> t;
    while(t--){
        ll n, a, b; cin >> n >> a >> b;

        if(n - a - b < 0){
            print(0)
            continue;
        }

        ll x = (1 + n - a - b + 1) * (n - a - b + 1) % MOD * ((MOD + 1) / 2) % MOD;
        ll y = (n - a + 1) * (n - b + 1) % MOD * x % MOD;
        ll z = x * x % MOD;
        //cout << x << " " << y << " " << z << endl;

        print((4 * y % MOD + (MOD - 4 * z % MOD)) % MOD)
    }
    
    return 0;
}