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

const ll MAX = 2e5 + 100;

ll n, m, a[MAX];
vector<vector<ll>> g;

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n >> m;
    zep(i, 0, n)cin >> a[i];

    g.resize(n);
    zep(j, 0, m){
        ll x, y; cin >> x >> y; x--; y--;
        g[x].push_back(y);
    }

    ll ans = -INF;
    vector<ll> c(n, INF);
    
    zep(i, 0, n){
        ans = max(ans, a[i] - c[i]);
        c[i] = min(c[i], a[i]);

        zep(j, 0, g[i].size()){
            c[g[i][j]] = min(c[g[i][j]], c[i]);
        }
    }
    
    print(ans)
    
    return 0;
}