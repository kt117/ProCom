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

ll n, m, u, v, w, ans;
map<ll, vector<P>> mp;

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

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n >> m;
   
    zep(i, 0, m){
        cin >> u >> v >> w;
        u--;
        v--;
        if(mp.find(w) == mp.end())mp[w] = {};
        mp[w].push_back(P(u, v));
    }

    union_find uf(n);
    for(auto it = mp.begin(); it != mp.end(); it++){
        auto a = (*it).second;

        ll work = 0;
        for(auto p : a){
            if(!uf.same(p.first, p.second))work++;
        }

        ll use = 0;
        for(auto p : a){
            if(!uf.same(p.first, p.second)){
                use++;
                uf.unite(p.first, p.second);
            }
        }

        ans += work - use;
    }
    
    print(ans)

    return 0;
}