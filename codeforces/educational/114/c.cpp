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
    
    ll sm = 0; zep(i, 0, n)sm += a[i];
    set<ll> s; zep(i, 0, n)s.insert(a[i]);
    s.insert(0);
    s.insert(INF);

    ll m; cin >> m;
    zep(i, 0, m){
        ll x, y; cin >> x >> y;

        ll ans = INF;
        auto it = s.lower_bound(x);
        
        ll r = (*it);
        if(r != INF)ans = min(ans, max(y - (sm - r), 0LL));
        // print(r)

        it--;
        ll l = (*it);
        // print(l)
        if(l != 0)ans = min(ans, x - l + max(y - (sm - l), 0LL));
        
        print(ans)
    }
    
    return 0;
}