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

ll n, m; 

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

ll encode(ll i, ll j){
    return i * n + j;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n >> m;
    ll a[m], b[m];
    char c[m];
    zep(i, 0, m){
        cin >> a[i] >> b[i] >> c[i];
        a[i]--; b[i]--;
    }

    dijkstra d(n * n + 1);
    zep(i, 0, m){
        zep(j, 0, m){
            if(c[i] == c[j]){
                d.append(encode(a[i], a[j]), encode(b[i], b[j]), 2);
                d.append(encode(b[i], b[j]), encode(a[i], a[j]), 2);
                d.append(encode(a[i], b[j]), encode(b[i], a[j]), 2);
                d.append(encode(b[i], a[j]), encode(a[i], b[j]), 2);
            }
        }
    }

    zep(i, 0, m){
        d.append(encode(a[i], b[i]), n * n, 1);
        d.append(encode(b[i], a[i]), n * n, 1);
    }

    zep(i, 0, n){
        d.append(encode(i, i), n * n, 0);
    }

    d.run(encode(0, n - 1));

    print(d.get(n * n))

    return 0;
}