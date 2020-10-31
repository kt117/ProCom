#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 998244353;
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
    
    ll n, k; cin >> n >> k;
    ll a[n][n]; zep(i, 0, n)zep(j, 0, n)cin >> a[i][j];
    
    union_find ufi(n), ufj(n);

    zep(x, 0, n){
        zep(y, x + 1, n){
            bool ok = true;
            zep(j, 0, n)if(a[x][j] + a[y][j] > k)ok = false;
            if(ok)ufj.unite(x, y);
        }
    }

    zep(x, 0, n){
        zep(y, x + 1, n){
            bool ok = true;
            zep(i, 0, n)if(a[i][x] + a[i][y] > k)ok = false;
            if(ok)ufi.unite(x, y);
        }
    }

    ll ans = 1;
    zep(i, 0, n){
        if(ufj.find(i) == i){
            rep(p, 1, ufj.size(i)){
                ans *= p;
                ans %= MOD;
            }
        }
    }

    zep(j, 0, n){
        if(ufi.find(j) == j){
            rep(p, 1, ufi.size(j)){
                ans *= p;
                ans %= MOD;
            }
        }
    }

    print(ans)
    return 0;
}