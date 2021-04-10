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

ll n, l, r;

ll f(ll x, ll cc, ll bb){
    ll res = 0;
    res += 3 * min(x, cc);
    x -= min(x, cc);
    res += 2 * min(x, bb);
    x -= min(x, bb);
    res += 1 * min(x, n - cc - bb);
    x -= min(x, n - cc - bb);
    return res;
}

ll g(ll x, ll aa, ll bb){
    ll res = 0;
    res += 1 * min(x, aa);
    x -= min(x, aa);
    res += 2 * min(x, bb);
    x -= min(x, bb);
    res += 3 * min(x, n - aa - bb);
    x -= min(x, n - aa - bb);
    return res;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll t; cin >> t;
    while(t--){
        cin >> n;

        ll a[n], b[n], c[n]; zep(i, 0, n)cin >> a[i] >> b[i] >> c[i];

        l = c[0];
        r = b[0];
        zep(i, 1, n){
            if(c[i] < l){
                if(f(c[i] + b[i], l, r) >= 3 * c[i] + 2 * b[i]){
                    r = b[i];   
                }else{
                    r += 2 * (l - c[i]);
                }
                l = c[i];
            }else{
                if(f(l + r, c[i], b[i]) < 3 * l + 2 * r){
                    r = 2 * (c[i] - l) + b[i];
                }
            }
            cout << l <<  " " << r << endl;
        }

        ll time = 0;
        bool ans = true;
        zep(i, 0, n){
            if(l){
                l--;
                time += 3;
            }else if(r){
                r--;
                time += 2;
            }else{
                time++;
            }
            cout << time << " " << g(i + 1, a[i], b[i]) << endl;
            if(time < g(i + 1, a[i], b[i]))ans = false;
        }
        print(ans? "Yes" : "No")
    }
    
    return 0;
}