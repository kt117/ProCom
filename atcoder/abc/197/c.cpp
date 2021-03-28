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
    
    ll n; cin >> n;
    ll a[n]; zep(i, 0, n)cin >> a[i];

    ll ans = INF;
    zep(bit, 0, (1LL << n - 1)){
        ll x = 0;
        ll xx = a[0];

        zep(i, 0, n - 1){
            if(bit & (1LL << i)){
                x ^= xx;
                xx = 0;
            }
            xx |= a[i + 1];
        }
        x ^= xx;

        ans = min(ans, x);
    }
    print(ans)
    
    return 0;
}