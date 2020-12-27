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
    
    ll n, m, k; cin >> n >> m >> k;
    ll g[m][3]; zep(j, 0, m){zep(d, 0, 3)cin >> g[j][d]; g[j][0]--; g[j][1]--;}
    ll a[k][2]; zep(kk, 0, k){cin >> a[kk][0] >> a[kk][1]; a[kk][0]--; a[kk][1]--;}

    ll c[m]; memset(c, 0, sizeof(c));
    zep(kk, 0, k){
        vector<dijkstra> di(2, dijkstra(n));
        zep(d, 0, 2){
            zep(j, 0, m){
                di[d].append(g[j][0], g[j][1], g[j][2]);
                di[d].append(g[j][1], g[j][0], g[j][2]);
            }
            di[d].run(a[kk][d]);
        }

        zep(j, 0, m){
            ll z = min(di[0].get(g[j][0]) + di[1].get(g[j][1]), di[0].get(g[j][1]) + di[1].get(g[j][0])); 
            c[j] += min(di[0].get(a[kk][1]), z);
        }
    }

    ll ans = INF;
    zep(j, 0, m)ans = min(ans, c[j]);
    print(ans)
    
    return 0;
}