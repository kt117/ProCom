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

const ll N = 1e5;
ll n, m, u[N], v[N], d[N], q;
vector<vector<P>> g;

struct union_find{
    vector<int> rnk, par;
    
    union_find(int n){
        rnk.resize(n);
        par.resize(n);
        for(int i = 0; i < n; i++){
            par[i] = i;
            rnk[i] = 0;
        }
    }
    
    int find(int x){
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }
 
    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if (x == y)return;
        if (rnk[x] < rnk[y]){
            par[x] = y;
        }
        else{
            par[y] = x;
            if (rnk[x] == rnk[y])rnk[x]++;
        }
    }
    
    bool same(int x, int y){
        return find(x) == find(y);
    }
};

struct dijkstra{
    vector<long long> min_dst;

    dijkstra(int n){
        min_dst.resize(n);
    }

    void run(int s){
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> que;
        fill(min_dst.begin(), min_dst.end(), -1);
        min_dst[s] = 0;
        que.push(make_pair(0, s));
        
        while(!que.empty()){
            auto p = que.top(); que.pop();
            int at = p.second;
            if(min_dst[at] < p.first){continue;}
            for(int i = 0; i < g[at].size(); i++){
                int to = g[at][i].first;
                long long cost = g[at][i].second;
                if(min_dst[to] == -1 || min_dst[at] + cost < min_dst[to]){
                    min_dst[to] = min_dst[at] + cost;
                    que.push(make_pair(min_dst[to], to));
                }
            }
        }	
    }
    
    long long get(int at){return min_dst[at];}
};

using Graph = vector<vector<P>>;
struct LCA {
    vector<vector<int> > parent; // parent[d][v] := 2^d-th parent of v
    vector<int> depth;
    LCA() { }
    LCA(const Graph &G, int r = 0) { init(G, r); }
    void init(const Graph &G, int r = 0) {
        int V = (int)G.size();
        int h = 1;
        while ((1<<h) < V) ++h;
        parent.assign(h, vector<int>(V, -1));
        depth.assign(V, -1);
        dfs(G, r, -1, 0);
        for (int i = 0; i+1 < (int)parent.size(); ++i)
            for (int v = 0; v < V; ++v)
                if (parent[i][v] != -1)
                    parent[i+1][v] = parent[i][parent[i][v]];
    }
    void dfs(const Graph &G, int v, int p, int d) {
        parent[0][v] = p;
        depth[v] = d;
        for (auto e : G[v]) if (e.first != p) dfs(G, e.first, v, d+1);
    }
    int get(int u, int v) {
        if (depth[u] > depth[v]) swap(u, v);
        for (int i = 0; i < (int)parent.size(); ++i)
            if ( (depth[v] - depth[u]) & (1<<i) )
                v = parent[i][v];
        if (u == v) return u;
        for (int i = (int)parent.size()-1; i >= 0; --i) {
            if (parent[i][u] != parent[i][v]) {
                u = parent[i][u];
                v = parent[i][v];
            }
        }
        return parent[0][u];
    }
};

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n >> m;
    g.resize(n);
    
    
    union_find uf(n);
    vector<int> w;

    zep(j, 0, m){
        cin >> u[j] >> v[j] >> d[j];
        u[j]--; v[j]--;

        if(!uf.same(u[j], v[j])){
            uf.unite(u[j], v[j]);
            g[u[j]].push_back(P(v[j], d[j]));
            g[v[j]].push_back(P(u[j], d[j]));
        }else{
            w.push_back(j);
        }
    }
    
    LCA lca(g, 0);
    dijkstra di(n); di.run(0);
    
    for(int j : w){
        g[u[j]].push_back(P(v[j], d[j]));
        g[v[j]].push_back(P(u[j], d[j]));
    }

    vector<dijkstra> dv;
    for(int j : w){
        dijkstra tmp(n); tmp.run(u[j]);
        dv.push_back(tmp);
    }

    cin >> q;
    while(q--){
        ll qu, qv; cin >> qu >> qv;
        qu--; qv--;

        ll ans = di.get(qu) + di.get(qv) - 2 * di.get(lca.get(qu, qv));

        zep(i, 0, w.size()){
            ans = min(ans, dv[i].get(qu) + dv[i].get(qv));
        }

        print(ans)
    }
    
    return 0;
}