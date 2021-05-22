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

ll t[101 * 1001], k[101 * 1001];

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
                int j = G[at][i].second;
                if(min_dst[to] == -1 || (min_dst[at] + k[j] - 1) / k[j] * k[j] + t[j] < min_dst[to]){
                    min_dst[to] = (min_dst[at] + k[j] - 1) / k[j] * k[j] + t[j];
                    que.push(make_pair(min_dst[to], to));
                }
            }
        }	
    }
    
    long long get(int at){return min_dst[at];}
};

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n, m, s, g; cin >> n >> m >> s >> g;
    s--; g--;

    dijkstra d(n);
    zep(j, 0, m){
        ll a, b; cin >> a >> b >> t[j] >> k[j];
        a--; b--;
        d.append(a, b, j);
        d.append(b, a, j);
    }
    
    d.run(s);
    print(d.get(g))

    return 0;
}