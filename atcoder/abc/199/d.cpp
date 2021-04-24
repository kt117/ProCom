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

struct union_find {
    vector<int> par, siz;
    union_find(int n) {
        par.resize(n);
        siz.resize(n);
        for(int i = 0; i < n; i++){
            par[i] = i;
            siz[i] = 1;
        }
    }
    
    int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }
 
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)return;
        if (siz[x] < siz[y]) {
            par[x] = y;
            siz[y] += siz[x];
        }
        else {
            par[y] = x;
            siz[x] += siz[y];
        }
    }
    
    long long size(int x){
        return siz[find(x)];
    }

    bool same(int x, int y) {
        return (find(x) == find(y));
    }
};

ll n, m, c[30], ans, cnt, anss[30];
vector<vector<ll>> g;
union_find u(30);

void dfs(ll at, ll cnt){
    //printa(c, 0, n - 1)
    bool use[4]; memset(use, 0, sizeof(use));
    zep(j, 0, g[at].size())use[c[g[at][j]]] = true;

    rep(i, 1, 3){
        if(!use[i]){
            c[at] = i;
            
            if(cnt == u.size(at)){
                anss[u.find(at)]++;
            }else{
                zep(j, at + 1, 2 * n){
                    if(u.same(j % n, at)){
                        dfs(j % n, cnt + 1);
                        break;
                    }
                }
            }
            
            c[at] = 0;
        }
    }
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n >> m;
    g.resize(n);

    zep(i, 0, m){
        ll a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
        u.unite(a, b);
    }

    zep(i, 0, n){
        if(u.find(i) == i){
            dfs(i, 1);
        }
    }

    ans = 1;
    zep(i, 0, n)if(u.find(i) == i)ans *= anss[u.find(i)];
    print(ans)

    return 0;
}