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

vector<ll> ans;

struct dijkstra{
    vector<long long> min_dst;
    vector<vector<vector<long long>>> G;

    dijkstra(int n){
        min_dst.resize(n);
        G.resize(n);
    }

    void append(int u, int v, long long cost, int i){G[u].push_back({v, cost, i});}
    
    void run(int s){
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> que;
        fill(min_dst.begin(), min_dst.end(), -1);
        min_dst[s] = 0;
        que.push({0, s, -1});
        
        while(!que.empty()){
            auto v = que.top(); que.pop();
            int at = v[1];
            if(min_dst[at] < v[0]){continue;}
            
            ans.push_back(v[2]);

            for(int i = 0; i < G[at].size(); i++){
                int to = G[at][i][0];
                long long cost = G[at][i][1];
                int from = G[at][i][2];
                
                if(min_dst[to] == -1 || min_dst[at] + cost < min_dst[to]){
                    min_dst[to] = min_dst[at] + cost;
                    que.push({min_dst[to], to, from});
                }
            }
        }	
    }
    
    long long get(int at){return min_dst[at];}
};

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n, m, k;
    cin >> n >> m >> k;
    
    dijkstra d(n);
    ll x[m], y[m], w[m];
    rep(i, 1, m){
        cin >> x[i] >> y[i] >> w[i];
        x[i]--; y[i]--;
        d.append(x[i], y[i], w[i], i);
        d.append(y[i], x[i], w[i], i);
    }

    d.run(0);
    
    k = min(k, n - 1);
    print(k)
    printa(ans, 1, k)

    return 0;
}