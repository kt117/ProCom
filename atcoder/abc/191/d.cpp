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

ll M = 10000;

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    double x, y, r; cin >> x >> y >> r;

    ll X = round(x * M);
    ll Y = round(y * M);
    ll R = round(r * M);

    ll ans = 0;
    rep(i, (X - R) / M - 10, (X + R) / M + 10){
        ll xx = (i * M - X) * (i * M - X);
        ll dy2 = R * R - xx;

        if(dy2 >= 0){
            ll dy = round(sqrt(dy2));

            ll u = (Y + dy) / M + 10; zep(i, 0, 20){if((u * M - Y) * (u * M - Y) + xx <= R * R)break; u--;}
            ll l = (Y - dy) / M - 10; zep(i, 0, 20){if((l * M - Y) * (l * M - Y) + xx <= R * R)break; l++;}
            //cout << i << u << l << endl;
            if(u >= l)ans += u - l + 1;
        }
    }
    print(ans)
    
    return 0;
}