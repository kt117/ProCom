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
    
    ll t; cin >> t;
    while(t--){
        ll n, m; cin >> n >> m;
        ll u[m], v[m]; zep(j, 0, m){cin >> u[j] >> v[j]; u[j]--; v[j]--;}

        dijkstra d(n);
        zep(j, 0, m)d.append(u[j], v[j], 1);
        d.run(0);

        dijkstra e(2 * n);
        zep(i, 0, n){
            e.append(0, i, d.get(i));
            e.append(0, i + n, d.get(i));
        }

        zep(j, 0, m){
            if(d.get(u[j]) < d.get(v[j])){
                e.append(v[j], u[j], 0);
                e.append(v[j] + n, u[j] + n, 0);
            }else{
                e.append(v[j], u[j] + n, 0);
            }
        }
        e.run(0);

        zep(i, 0, n){
            cout << min(e.get(i), e.get(i + n)) << " ";
        }
        cout << endl;
    }

    return 0;
}