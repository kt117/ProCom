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
        ll w[n]; zep(i, 0, n)cin >> w[i];

        ll cnt[n]; memset(cnt, 0, sizeof(cnt));
        zep(i, 0, n - 1){
            ll u, v; cin >> u >> v;
            u--; v--;
            cnt[u]++;
            cnt[v]++;
        }

        ll ans = 0; zep(i, 0, n)ans += w[i];
        vector<ll> a; zep(i, 0, n)zep(j, 0, cnt[i] - 1)a.push_back(w[i]);
        sort(a.begin(), a.end(), greater<>());

        a.push_back(0);
        vector<ll> ansv;
        zep(i, 0, n - 1){
            ansv.push_back(ans);
            ans += a[i];
        }
        printa(ansv, 0, n - 2);
    }
    
    return 0;
}