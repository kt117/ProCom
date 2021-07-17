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

template<typename T> class FordFulkerson{
public:
    struct edge{
        int to;
        T cap;
        int rev;
    };
    int V;
    vector<vector<edge> > G;
    vector<bool> used;
    FordFulkerson(int node_size) : V(node_size), G(V), used(V, false){};
    void add_edge(int from, int to, T cap){
        G[from].push_back((edge){to,cap,(int)G[to].size()});
    	G[to].push_back((edge){from,0,(int)G[from].size()-1});
    }
    T dfs(int v, int t, T f){
    	if(v == t) return f;
    	used[v] = true;
    	for(auto& e : G[v]){
    		if(!used[e.to] && e.cap > 0){
    			T d = dfs(e.to, t, min(f, e.cap));
    			if(d > 0){
    				e.cap -= d;
    				G[e.to][e.rev].cap += d;
    				return d;
    			}
    		}
    	}
    	return 0;
    }
    T max_flow(int s, int t){
        T flow = 0;
        for(;;){
            fill(used.begin(), used.end(), false);
    		T f = dfs(s, t, numeric_limits<T>::max());
    		if(!f) return flow;
    		flow += f;
    	}
    }
};

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    int h, w, n; cin >> h >> w >> n;

    FordFulkerson<int> F(h + w + 2 * n + 2);

    rep(i, 1, h)F.add_edge(0, i, 1);
    rep(j, 1, w)F.add_edge(h + j, h + w + 2 * n + 1, 1);
    rep(k, 1, n)F.add_edge(h + w + k, h + w + n + k, 1);

    rep(k, 1, n){
        ll a, b, c, d; cin >> a >> b >> c >> d;

        rep(i, a, c)F.add_edge(i, h + w + k, 1);
        rep(j, b, d)F.add_edge(h + w + n + k, h + j, 1);
    }

    print(F.max_flow(0, h + w + 2 * n + 1))
    
    return 0;
}