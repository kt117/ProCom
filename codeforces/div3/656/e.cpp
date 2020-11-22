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

class tsort {
public:
	int V;
	vector<vector<int> > G;
	vector<int> deg,res;
	tsort(int node_size) : V(node_size), G(V), deg(V, 0){}
	void add_edge(int from,int to){
		G[from].push_back(to);
		deg[to]++;
	}
	bool solve() {
		queue<int> que;
		for(int i = 0; i < V; i++){
			if(deg[i] == 0){
				que.push(i);
			}
		}
		while(!que.empty()){
			int p = que.front();
			que.pop();
			res.push_back(p);
			for(int v : G[p]){
				if(--deg[v] == 0){
					que.push(v);
				}
			}
		}
		return (*max_element(deg.begin(),deg.end()) == 0);
	}
};

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll t; cin >> t;
    while(t--){
        ll n, m; cin >> n >> m;

        vector<vector<ll>> g(n);
        tsort ts(n);
        vector<P> ans;

        zep(i, 0, m){
            ll t, x, y; cin >> t >> x >> y; x--; y--;

            if(t == 0){
                g[x].push_back(y);
                g[y].push_back(x);
            }else{
                ts.add_edge(x, y);
                ans.push_back(P(x, y));
            }
        }

        if(!ts.solve()){
            print("NO")
            continue;
        }
        print("YES")

        auto v = ts.res;// reverse(v.begin(), v.end());
        set<ll> unuse; zep(i, 0, n)unuse.insert(i);
        bool use[n]; memset(use, 0, sizeof(use));
        queue<ll> q; zep(i, 0, v.size()){q.push(v[i]); use[v[i]] = true;}

        while(!unuse.empty()){
            if(q.empty()){
                q.push(*unuse.begin());
                use[*unuse.begin()] = true;
            }

            ll at = q.front(); q.pop();
            unuse.erase(at);

            zep(i, 0, g[at].size()){
                ll nx = g[at][i];

                if(unuse.find(nx) != unuse.end()){
                    ans.push_back(P(at, nx));
                    if(!use[nx]){
                        use[nx] = true;
                        q.push(nx);
                    }
                }
            }
        }

        zep(i, 0, m){
            cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
        }
    }
    
    return 0;
}