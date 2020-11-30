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

ll x[4], y[4];

bool cross(ll a, ll b, ll c, ll d){
    return !(b < c || d < a);
}

vector<ll> g(ll a, ll b, ll c, ll d){
    ll cx = abs(a - b) + abs(c - d);
    ll llb = min(a, b);
    ll lrb = max(a, b);
    ll rlb = min(c, d);
    ll rrb = max(c, d);
    ll mnx = cross(llb, lrb, rlb, rrb)? 0 : min(abs(llb - rrb), abs(lrb - rlb));
    ll mxx = max(max(lrb - llb, rrb - rlb), max(lrb - rlb, rrb - llb));
    return {cx, mnx, mxx};
}

ll f(ll a, ll b, ll c){
    auto vx = g(x[0], x[a], x[b], x[c]);
    auto vy = g(y[0], y[b], y[a], y[c]);
    
    if(cross(vx[1], vx[2], vy[1], vy[2])){
        return vx[0] + vy[0];
    }
    return vx[0] + vy[0] + 2 * min(abs(vx[1] - vy[2]), abs(vx[2] - vy[1]));
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll t; cin >> t;
    while(t--){
        zep(i, 0, 4)cin >> x[i] >> y[i];

        ll ans = INF;
        ans = min(ans, f(1, 2, 3));
        ans = min(ans, f(1, 3, 2));
        ans = min(ans, f(2, 1, 3));
        ans = min(ans, f(2, 3, 1));
        ans = min(ans, f(3, 1, 2));
        ans = min(ans, f(3, 2, 1));
        print(ans)
    }
    
    return 0;
}