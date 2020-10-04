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

ll n, m, sx, sy, fx, fy, x[100008], y[100008]; 

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

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n >> m >> sx >> sy >> fx >> fy;

    rep(i, 1, m)cin >> x[i] >> y[i];

    dijkstra d(m + 2);
    d.append(0, m + 1, abs(sx - fx) + abs(sy - fy));

    rep(i, 1, m)d.append(i, m + 1, abs(x[i] - fx) + abs(y[i] - fy));
    rep(i, 1, m)d.append(0, i, min(abs(x[i] - sx), abs(y[i] - sy)));

    vector<vector<P>> v(2);

    rep(i, 1, m)v[0].push_back({x[i], i});
    rep(i, 1, m)v[1].push_back({y[i], i});
    
    zep(k, 0, 2){
        sort(v[k].begin(), v[k].end());

        zep(i, 0, m - 1){
            d.append(v[k][i].second, v[k][i + 1].second, v[k][i + 1].first - v[k][i].first);
            d.append(v[k][i + 1].second, v[k][i].second, v[k][i + 1].first - v[k][i].first);
        }
    }

    d.run(0);
    print(d.get(m + 1))

    return 0;
}