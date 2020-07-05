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
        ll n; cin >> n;

        vector<vector<ll>> lr(n);
        zep(i, 0, n){
            ll l, r; cin >> l >> r;
            lr[i] = {l, r, i};
        }
        sort(lr.begin(), lr.end());

        ll rb = lr[0][1];
        ll ans[n];
        bool ok = false;
        zep(i, 1, n){
            if(rb < lr[i][0]){
                zep(j, 0, i)ans[lr[j][2]] = 1;
                zep(j, i, n)ans[lr[j][2]] = 2;
                ok = true;
                break;
            }
            rb = max(rb, lr[i][1]);
        }

        if(ok){
            zep(i, 0, n)cout << ans[i] << " "; cout << endl;
        }else{
            print(-1)
        }
    }
    
    return 0;
}