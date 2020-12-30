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

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n, m; cin >> n >> m;

    union_find u(m + 1);
    vector<ll> ans;
    zep(i, 0, n){
        ll k; cin >> k;
        ll x[k]; zep(j, 0, k)cin >> x[j];

        if(k == 1){
            if(!u.same(x[0], 0)){
                ans.push_back(i);
                u.unite(x[0], 0);
            }
        }else{
            if(!u.same(x[0], x[1])){
                ans.push_back(i);
                u.unite(x[0], x[1]);
            }
        }
    }

    bool use[m + 1]; memset(use, 0, sizeof(use));
    ll ts = 1;
    rep(j, 1, m){
        if(u.same(j, 0) || u.find(j) != j){
            ts *= 2;
            ts %= MOD;
        }
    }

    cout << ts << " " << ans.size() << endl;
    zep(i, 0, ans.size()) cout << ans[i] + 1 << " "; cout << endl;
    
    return 0;
}