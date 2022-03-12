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

ll n, L[200010], R[200010];
vector<vector<ll>> g;

ll dfs(ll at, ll from, ll l){
    L[at] = l;

    if(from != -1 && g[at].size() == 1){
        return R[at] = l;
    }

    zep(i, 0, g[at].size()){
        ll nx = g[at][i];
        
        if(nx != from){
            l = dfs(nx, at, l) + 1;
        }    
    }
    return R[at] = l - 1;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n;
    g.resize(n);
    zep(i, 0, n - 1){
        ll u, v; cin >> u >> v; u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0, -1, 1);
    zep(i, 0, n)cout << L[i] << " " << R[i] << endl;
    
    return 0;
}