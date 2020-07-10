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

ll n, m;
vector<vector<ll>> g, cnt;


void dfs(ll at, ll from){
    zep(i, 0, g[at].size()){
        ll nx = g[at][i];
        if(nx != from)dfs(nx, at);
    }

    ll l = 0;
    zep(i, 0, g[at].size()){
        ll nx = g[at][i];
        if(nx != from)l = max(l, cnt[nx].size);
    }
    
    vector<ll> res(l + 1, 0);
    res[0]++;
    zep(i, 0, g[at].size()){
        ll nx = g[at][i];
        if(nx != from){
            zep(j, 0, cnt[nx].size()){
                res[at][j + 1] += cnt[nx][j];
            }
        }
    }

    zep(j, 0, res.size() - 1){
        res[i + 1] += res[i];
    }

    cnt[at].swap(res);
}


int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n >> m;
    g.resize(n);
    zep(i, 0, n - 1){
        ll x, y; cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(0, -1);

    ll ans = 0;
    zep(i, 0, m){
        ll v, d, x; cin >> v >> d >> x;
        v--;
        d = min(d, ll(cnt[v].size() - 1));
        
        ans += cnt[v][d] * x;
    }
    print(ans)

    return 0;
}