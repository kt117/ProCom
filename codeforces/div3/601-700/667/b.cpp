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
        ll a, b, x, y, n; cin >> a >> b >> x >> y >> n;
        
        ll l = (a - min(n, a - x)) * (b - min(n - min(n, a - x), b - y));

        ll tmp = a; a = b; b = tmp;
        ll tmp2 = x; x = y; y = tmp2;

        ll r = (a - min(n, a - x)) * (b - min(n - min(n, a - x), b - y));
        print(min(l, r))
    }
    
    return 0;
}