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
    vector<long long> cnt;
    vector<vector<pair<long long, long long>>> G;

    dijkstra(int n){
        min_dst.resize(n);
        cnt.resize(n);
        G.resize(n);
    }

    void append(int u, int v, long long cost){G[u].push_back(make_pair(v, cost));}
    
    void run(int s){
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> que;
        fill(min_dst.begin(), min_dst.end(), -1);
        fill(cnt.begin(), cnt.end(), 0);
        min_dst[s] = 0;
        cnt[s] = 1;
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
                    cnt[to] = cnt[at];
                    que.push(make_pair(min_dst[to], to));
                }else if(min_dst[at] + cost == min_dst[to]){
                    cnt[to] += cnt[at];
                    cnt[to] %= MOD;
                }
            }
        }	
    }
    
    long long get(int at){return cnt[at];}
};

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n, m; cin >> n >> m;
    
    dijkstra d(n);
    zep(j, 0, m){
        ll a, b; cin >> a >> b;
        a--; b--;
        d.append(a, b, 1);
        d.append(b, a, 1);
    }
    d.run(0);

    print(d.get(n - 1))
    
    return 0;
}