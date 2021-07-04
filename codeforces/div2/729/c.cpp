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
        ll n; cin >> n;

        ll v[200];
        zep(i, 2, 200)v[i] = i;

        ll ans = 0;
        zep(i, 2, 200){
            if(n && v[i] != 0){
                ans += (n - n / v[i]) % MOD * i % MOD;
                ans %= MOD;
                n /= v[i];

                for(ll j = 2; j * i < 200; j++){
                    v[j * i] /= v[i];
                }
            }
        }

        print(ans)
    }
    
    return 0;
}