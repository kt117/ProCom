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

ll t, n, m, x[200 * 1001], y[200 * 1001], a[200 * 1001], b[200 * 1001];

ll sum(ll l, ll r, ll cnt){
    return ((l + r) * cnt) / 2;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> t;
    while(t--){
        cin >> n >> m;
        rep(i, 1, n)cin >> x[i] >> y[i];

        rep(i, 1, n)b[i] = b[i - 1] + x[i] * y[i];

        rep(i, 1, n)a[i] = a[i - 1] + sum(b[i - 1] + x[i], b[i], y[i]);
        
        ll ans = -INF;
        rep(i, 1, n)ans = max(ans, a[i]);
        rep(i, 1, n)ans = max(ans, a[i - 1] + b[i - 1] + x[i]);

        // printa(b, 0, n);
        // printa(a, 0, n);
        
        rep(i, 1, n){
            if(x[i] < 0 && b[i - 1] + x[i] >= 0 && b[i] <= 0){
                // ll r = b[i - 1] % (-x[i]);
                ll s = b[i - 1] / (-x[i]);
                ll t = a[i - 1] + sum(b[i - 1] + x[i], b[i - 1] + x[i] * s, s);
                // cout << r << s << t << i << endl;
                ans = max(ans, t);
            }
        }

        print(ans)
    }
    
    return 0;
}