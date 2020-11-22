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
        ll n, x, y; cin >> n >> x >> y;

        ll d = y - x;

        ll ans = INF;
        ll ansi = -1;
        rep(i, 1, 50){
            if(d % i == 0 && d / i + 1 <= n){
                ll ini = (x % i > 0)? x % i : i;
                ll res = max(y, i * (n - 1) + ini);
                if(res < ans){
                    ans = res;
                    ansi = i;
                }
            }
        }
        
        zep(i, 0, n)cout << ans - i * ansi << " "; cout << endl;
    }
    
    return 0;
}