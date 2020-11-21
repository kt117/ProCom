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

struct union_find{
    vector<int> rnk, par;
    
    union_find(int n){
        rnk.resize(n);
        par.resize(n);
        for(int i = 0; i < n; i++){
            par[i] = i;
            rnk[i] = 0;
        }
    }
    
    int find(int x){
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }
 
    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if (x == y)return;
        if (rnk[x] < rnk[y]){
            par[x] = y;
        }
        else{
            par[y] = x;
            if (rnk[x] == rnk[y])rnk[x]++;
        }
    }
    
    bool same(int x, int y){
        return find(x) == find(y);
    }
};

vector<vector<P>> g;

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n, m; cin >> n >> m;
    g.resize(n);
    ll u[m], v[m], c[m];
    zep(j, 0, m){
        cin >> u[j] >> v[j] >> c[j];
        u[j]--;
        v[j]--;
        c[j]--;
        g[u[j]].push_back(P(v[j], c[j]));
        g[v[j]].push_back(P(u[j], c[j]));
    }

    ll ans[n];
    ans[0] = 0;
    queue<ll> q;
    q.push(0);
    bool use[n]; memset(use, 0, sizeof(use));

    while(!q.empty()){
        ll at = q.front(); q.pop();
        use[at] = true;
        
        zep(j, 0, g[at].size()){
            ll nx = g[at][j].first;
            ll la = g[at][j].second;
            
            if(!use[nx]){
                q.push(nx);
                if(ans[at] != la){
                    ans[nx] = la;
                }else{
                    ans[nx] = (la + 1) % n;
                }
            }
        }
    }

    zep(i, 0, n){
        print(ans[i] + 1)
    }

    return 0;
}