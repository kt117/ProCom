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

vector<vector<ll>> g;
vector<ll> use, l;

bool dfs(ll at, ll from){
    if(use[at]){
        reverse(l.begin(), l.end());
        while(l.back() != at)l.pop_back();
        return true;
    }

    use[at] = true;
    l.push_back(at);
    zep(i, 0, g[at].size()){
        ll nx = g[at][i];
        if(nx != from){
            if(dfs(nx, at))return true;
        }
    }
    l.pop_back();
    return false;
}

ll dfs2(ll at, ll f1, ll f2){
    ll res = 1;
    zep(i, 0, g[at].size()){
        ll nx = g[at][i];
        if(nx != f1 && nx != f2){
            res += dfs2(nx, at, -1);
        }
    }
    return res;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        g.clear(); g.resize(n);
        zep(i, 0, n){
            ll u, v; cin >> u >> v; u--; v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        use.clear(); use.resize(n, false);
        l.clear();
        dfs(0, -1);
        
        ll m = l.size();
        ll ans = 0;
        zep(i, 0, m){
            ll cnt = dfs2(l[i], l[(i + m - 1) % m], l[(i + 1) % m]);
            ans += cnt * (cnt - 1) / 2 + cnt * (n - cnt);
        }
        print(ans)
    }
    
    return 0;
}