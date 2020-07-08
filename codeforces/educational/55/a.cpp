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
        ll n, x, y, d; cin >> n >> x >> y >> d;

        if(abs(x - y) % d == 0){
            print(abs(x - y) / d)
            continue;
        }

        ll ans = INF;
        if((y - 1) % d == 0){
            ans = min(ans, (x - 1 + d - 1) / d + (y - 1) / d);
        }

        if((n - y) % d == 0){
            ans = min(ans, (n - x + d - 1) / d + (n - y) / d);
        }

        print((ans != INF)? ans : -1)
    }
    
    return 0;
}