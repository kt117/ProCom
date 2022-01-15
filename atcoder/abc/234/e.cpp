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

ll f(ll y, ll d, ll delta){
    ll r = y;
    zep(i, 0, d - 1){
        y += delta;
        if(y < 0 || 9 < y)return INF;
        r *= 10;
        r += y;
    }
    return r;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll x; cin >> x;

    ll y = x, d = 1;
    while(y / 10 > 0){
        y /= 10;
        d++;
    }
    
    ll ans = INF;
    rep(i, -9, 9){
        ll z = f(y, d, i);
        if(z >= x)ans = min(ans, z);
    }

    y++;
    rep(i, -9, 9){
        ll z = f(y, d, i);
        if(z >= x)ans = min(ans, z);
    }

    print(ans)

    return 0;
}