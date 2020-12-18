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
    
    ll n, k; cin >> n >> k;
    ll p[n]; zep(i, 0, n){cin >> p[i]; p[i]--;}
    ll x[k], y[k]; zep(i, 0, k){cin >> x[i] >> y[i]; x[i]--; y[i]--;}

    ll pr[n], ch[n];
    memset(pr, -1, sizeof(pr)); 
    memset(ch, -1, sizeof(ch));
    zep(i, 0, k){
        if(pr[y[i]] != -1){print(0) return 0;}
        if(ch[x[i]] != -1){print(0) return 0;}
        pr[y[i]] = x[i];
        ch[x[i]] = y[i];
    }
    
    ll g[n], h[n];
    bool use[n]; memset(use, 0, sizeof(use));
    vector<vector<ll>> v;
    zep(i, 0, n){
        if(!use[i]){
            ll at = i;
            while(pr[at] != -1){
                at = pr[at];
                if(at == i){print(0) return 0;}
            }

            vector<ll> u;
            while(ch[at] != -1){
                use[at] = true;
                u.push_back(at);
                g[at] = v.size();
                h[at] = u.size();
                at = ch[at];
            }
            use[at] = true;
            u.push_back(at);
            g[at] = v.size();
            h[at] = u.size();

            v.push_back(u);
        }
    }

    tsort ts(v.size());
    zep(i, 0, n){
        if(p[i] != -1){
            if(g[p[i]] == g[i]){
                if(h[p[i]] > h[i]){
                    print(0) return 0;
                }
            }else{
                ts.add_edge(g[p[i]], g[i]);
            }
        }
    } 

    bool ans = ts.solve();
    if(!ans){
        print(0)
    }else{
        zep(i, 0, ts.res.size()){
            zep(j, 0, v[ts.res[i]].size()){
                cout << v[ts.res[i]][j] + 1 << " ";
            }
        }
        cout << endl;
    }

    return 0;
}