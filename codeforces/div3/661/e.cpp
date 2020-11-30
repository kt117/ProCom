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

vector<vector<P>> g;
vector<ll> nw;
vector<P> e;

void dfs(ll at, ll from){
    if(from != -1 && g[at].size() == 1){
        nw[at] = 1;
        return;
    }

    zep(i, 0, g[at].size()){
        ll nx = g[at][i].first;
        if(nx != from){
            dfs(nx, at);

            nw[at] += nw[nx];
            e.push_back(P(g[at][i].second, nw[nx]));
        }
    }
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll t; cin >> t;
    while(t--){
        g.clear();
        nw.clear();
        e.clear();

        ll n, s; cin >> n >> s;
        g.resize(n);
        nw.resize(n, 0);

        zep(i, 0, n - 1){
            ll u, v, w; cin >> u >> v >> w; u--; v--;
            g[u].push_back(P(v, w));
            g[v].push_back(P(u, w));
        }

        dfs(0, -1);
       
        priority_queue<vector<ll>> q;
        ll sm = 0;
        zep(i, 0, e.size()){
            ll ww = e[i].first;
            ll pp = e[i].second;

            sm += ww * pp;
            q.push({ww * pp - (ww / 2) * pp, ww, pp});
        }

        ll ans = 0;
        
        while(sm > s){
            auto v = q.top(); q.pop();
            sm -= v[0];

            v[1] /= 2;
            v[0] = v[1] * v[2] - (v[1] / 2) * v[2];

            q.push(v);
            ans++;
        }
        print(ans)
    }
    
    return 0;
}