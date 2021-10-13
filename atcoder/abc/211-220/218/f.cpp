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

ll n, m, s[404 * 404], t[404 * 404];

struct dijkstra{
    vector<long long> min_dst;
    vector<long long> from;
    vector<vector<pair<long long, long long>>> G;

    dijkstra(int n){
        min_dst.resize(n);
        from.resize(n);
        G.resize(n);
    }

    void append(int u, int v, long long cost){G[u].push_back(make_pair(v, cost));}
    
    void run(int s){
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> que;
        fill(min_dst.begin(), min_dst.end(), -1);
        min_dst[s] = 0;
        from[s] = -1;
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
                    from[to] = at;
                    que.push(make_pair(min_dst[to], to));
                }
            }
        }	
    }
    
    long long get(int at){return min_dst[at];}

    vector<ll> getp(int s, int at){
        vector<ll> res;
        ll cur = at;
        while(cur != s){
            res.push_back(cur);
            cur = from[cur];
        }
        res.push_back(s);
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n >> m;
    dijkstra d(n);

    zep(i, 0, m){
        cin >> s[i] >> t[i]; s[i]--; t[i]--;
        d.append(s[i], t[i], 1);
    }

    d.run(0);
    if(d.get(n - 1) == -1){
        zep(i, 0, m)print(-1) return 0;
    }

    auto v = d.getp(0, n - 1);
    set<P> use;
    zep(i, 1, v.size()){
        use.insert(P(v[i - 1], v[i]));
    }

    zep(i, 0, m){
        if(use.find(P(s[i], t[i])) == use.end()){
            print(d.get(n - 1));
        }else{
            dijkstra e(n);
            zep(j, 0, m){
                if(j != i){
                    e.append(s[j], t[j], 1);
                }
            }
            e.run(0);
            print(e.get(n - 1))
        }
    }

    return 0;
}