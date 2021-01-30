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

struct union_find {
    vector<int> par, siz;
    union_find(int n) {
        par.resize(n);
        siz.resize(n);
        for(int i = 0; i < n; i++){
            par[i] = i;
            siz[i] = 1;
        }
    }
    
    int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }
 
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)return;
        if (siz[x] < siz[y]) {
            par[x] = y;
            siz[y] += siz[x];
        }
        else {
            par[y] = x;
            siz[x] += siz[y];
        }
    }
    
    long long size(int x){
        return siz[find(x)];
    }

    bool same(int x, int y) {
        return (find(x) == find(y));
    }
};

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

ll k, dst[20][20], dp[20][(1LL << 20)];

ll memo(ll at, ll bit){
    if(dp[at][bit] != -1)return dp[at][bit];

    ll res = INF;
    zep(i, 0, k){
        if(i != at && (bit & (1LL << i))){
            res = min(res, memo(i, bit - (1LL << at)) + dst[i][at]);
        }
    }
    return dp[at][bit] = res;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n, m; cin >> n >> m;

    ll a[m], b[m];
    union_find u(n);
    dijkstra d(n);
    zep(i, 0, m){
        cin >> a[i] >> b[i]; a[i]--; b[i]--;
        u.unite(a[i], b[i]);
        d.append(a[i], b[i], 1);
        d.append(b[i], a[i], 1);
    }

    cin >> k;
    ll c[k]; zep(i, 0, k){cin >> c[i]; c[i]--;}

    /*if(k == 1){
        print(1) return 0;
    }*/

    zep(i, 0, k)zep(j, 0, k)if(!u.same(c[i], c[j])){print(-1) return 0;}

    zep(i, 0, k){
        d.run(c[i]);
        zep(j, 0, k){
            dst[i][j] = d.get(c[j]);
        }
    }
    
    memset(dp, -1, sizeof(dp));
    zep(i, 0, k)dp[i][1LL << i] = 0;

    ll ans = INF;
    zep(i, 0, k){
        ans = min(ans, memo(i, (1LL << k) - 1));
    }
    print(ans + 1)

    return 0;
}