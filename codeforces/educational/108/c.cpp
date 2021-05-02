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
        ll u[n]; zep(i, 0, n){cin >> u[i]; u[i]--;}
        ll s[n]; zep(i, 0, n)cin >> s[i];

        vector<vector<ll>> v(n);
        zep(i, 0, n)v[u[i]].push_back(s[i]);

        ll ans[n + 1]; memset(ans, 0, sizeof(ans));
        zep(i, 0, n){
            sort(v[i].begin(), v[i].end(), greater<>());
            ll m = v[i].size();

            zep(j, 1, m){
                v[i][j] += v[i][j - 1];
            }

            rep(j, 1, m){
                ans[j] += v[i][(m / j) * j - 1];
            }
        }

        rep(i, 1, n)cout << ans[i] << " "; cout << endl;
    }
    
    return 0;
}