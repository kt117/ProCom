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
        ll r, g, b; cin >> r >> g >> b;

        ll ans = INF;

        if(r % 3 == g % 3)ans = min(ans, max(r, g));
        if(g % 3 == b % 3)ans = min(ans, max(g, b));
        if(b % 3 == r % 3)ans = min(ans, max(b, r));

        print((ans == INF)? -1 : ans)
    }
    
    return 0;
}