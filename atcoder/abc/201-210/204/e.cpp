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

ll f(ll t, ll d){
    return d / (t + 1) + t;
}

ll cal(ll t, ll d){
    ll x = int(sqrt(d));
    ll mn = INF;
    ll mi = -1;
    rep(i, max(0LL, x - 10), x + 10){
        if(f(i, d) < mn){
            mn = f(i, d);
            mi = i;
        }
    }

    mi = max(mi, t);
    return f(mi, d);
}

struct dijkstra{
    vector<long long> min_dst;
    vector<vector<vector<ll>>> G;

    dijkstra(int n){
        min_dst.resize(n);
        G.resize(n);
    }

    void append(int u, int v, ll c, ll d){G[u].push_back({v, c, d});}
    
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
                int to = G[at][i][0];
                long long cost = G[at][i][1] + cal(p.first, G[at][i][2]);
                
                if(min_dst[to] == -1 || cost < min_dst[to]){
                    min_dst[to] = cost;
                    que.push(make_pair(min_dst[to], to));
                }
            }
        }	
    }
    
    long long get(int at){return min_dst[at];}
};

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n, m; cin >> n >> m;
    dijkstra di(n);

    zep(j, 0, m){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        di.append(a, b, c, d);
        di.append(b, a, c, d);
    }

    di.run(0);
    print(di.get(n - 1))
    
    return 0;
}