#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 998244353;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define zep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(int i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

long long powmod(long long a, long long x){
    if(x == 0)return 1;
    long long r = powmod(a, x / 2);
    return (x%2)? (r * r % MOD) * a % MOD : r * r % MOD;
}

struct dijkstra{
    vector<long long> min_dst;
    vector<vector<pair<long long, long long>>> G;

    dijkstra(int n){
        min_dst.resize(n);
        G.resize(n);
    }

    void append(int u, int v, long long cost){G[u].push_back(make_pair(v, cost));}
    
    void run(int s){
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> que;
        fill(min_dst.begin(), min_dst.end(), -1);
        min_dst[s] = 0;
        que.push(make_pair(0, s));
        
        while(!que.empty()){
            auto p = que.top(); que.pop();
            int at = p.second;
            if(min_dst[at] < p.first){continue;}
            for(int i = 0; i < G[at].size(); i++){
                int to = G[at][i].first;
                long long cost = G[at][i].second;
                if(min_dst[to] == -1 || min_dst[at] + cost < min_dst[to]){
                    min_dst[to] = min_dst[at] + cost;
                    que.push(make_pair(min_dst[to], to));
                }
            }
        }	
    }
    
    long long get(int at){return min_dst[at];}
};

ll ecnt, di;
vector<vector<ll>> g;

void dfs(ll at, ll from, ll dst){
    if(2 * dst == di)ecnt++;

    zep(i, 0, g[at].size()){
        ll nx = g[at][i];
        if(nx != from){
            dfs(nx, at, dst + 1);
        }
    }
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n; cin >> n;
    ll u[n - 1], v[n - 1];
    zep(i, 0, n - 1){
        cin >> u[i] >> v[i];
        u[i]--; v[i]--;
    }

    dijkstra d(n), e(n);
    zep(i, 0, n - 1){
        d.append(u[i], v[i], 1);
        d.append(v[i], u[i], 1);
        e.append(u[i], v[i], 1);
        e.append(v[i], u[i], 1);
    }
    d.run(0);

    ll l = 0;
    zep(i, 0, n){
        if(d.get(i) > d.get(l))l = i;
    }
    d.run(l);
    
    ll r = 0;
    zep(i, 0, n){
        if(d.get(i) > d.get(r))r = i;
    }
    e.run(r);
    
    di = d.get(r);
    if(di % 2 == 1){
        ll c = -1, b = -1;
        zep(i, 0, n){
            if(d.get(i) == di / 2 && e.get(i) == di / 2 + 1)c = i;
            if(e.get(i) == di / 2 && d.get(i) == di / 2 + 1)b = i;
        }

        d.run(c);
        e.run(b);
        ll lc = 0, rc = 0;
        zep(i, 0, n){
            if(d.get(i) == di / 2 + 1)lc++;
            if(e.get(i) == di / 2 + 1)rc++;
        }
        // print(c)
        // print(lc)
        // print(rc)
        print(lc * rc % MOD)
    }else{
        ll c = -1;
        zep(i, 0, n){
            if(2 * d.get(i) == di && 2 * e.get(i) == di)c = i;
        }

        g.resize(n);
        zep(i, 0, n - 1){
            g[u[i]].push_back(v[i]);
            g[v[i]].push_back(u[i]);
        }

        ll ans = 1, esum = 0;
        zep(i, 0, g[c].size()){
            ecnt = 0;
            dfs(g[c][i], c, 1);
            esum += ecnt;
            ans *= ecnt + 1;
            ans %= MOD;
        }
        print((ans + MOD - esum - 1) % MOD)

    }

    return 0;
}