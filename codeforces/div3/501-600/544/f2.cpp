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

vector<vector<ll>> g;

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n, m, d; cin >> n >> m >> d;
    g.resize(n);

    ll u[m], v[m];
    zep(i, 0, m){
        cin >> u[i] >> v[i]; u[i]--; v[i]--;
        g[u[i]].push_back(v[i]);
        g[v[i]].push_back(u[i]);
    }

    if(g[0].size() < d){
        print("NO") return 0;
    }

    union_find test(n);
    zep(i, 0, m){
        if(u[i] != 0 && v[i] != 0 && !test.same(u[i], v[i])){
            test.unite(u[i], v[i]);
        }
    }

    set<ll> uq;
    zep(i, 1, n){
        uq.insert(test.find(i));
    }

    if(uq.size() > d){
        print("NO") return 0;
    }

    print("YES")

    vector<P> ans;
    union_find uf(n);

    zep(i, 0, g[0].size()){
        if(ans.size() == d)break;

        if(uq.find(test.find(g[0][i])) != uq.end()){
            uq.erase(test.find(g[0][i]));
            ans.push_back(P(0, g[0][i]));
            uf.unite(0, g[0][i]);
        }
    }

    zep(i, 0, g[0].size()){
        if(ans.size() == d)break;

        if(!uf.same(0, g[0][i])){
            ans.push_back(P(0, g[0][i]));
            uf.unite(0, g[0][i]);
        }
    }

    zep(i, 0, m){
        if(u[i] != 0 && v[i] != 0 && !uf.same(u[i], v[i])){
            ans.push_back(P(u[i], v[i]));
            uf.unite(u[i], v[i]);
        }
    }

    zep(i, 0, n - 1){
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
    }

    return 0;
}