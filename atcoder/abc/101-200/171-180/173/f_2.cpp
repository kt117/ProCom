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
    
    ll ans = 0;
    zep(i, 0, n)ans += (i + 1) * (n - i);

    zep(i, 0, n - 1){
    	ll u, v; cin >> u >> v;
    	if(u > v){ll tmp = u; u = v; v = tmp;}

        ans -= u * (n - v + 1);
    }

    print(ans)
    
    return 0;
}