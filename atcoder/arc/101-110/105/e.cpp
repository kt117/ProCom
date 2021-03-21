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
    vector<int> par, siz, div;
    union_find(int n) {
        par.resize(n);
        siz.resize(n);
        div.resize(n);
        for(int i = 0; i < n; i++){
            par[i] = i;
            siz[i] = 1;
            div[i] = 0;
        }
    }
    
    int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }
 
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        div[x]++;
        if (x == y)return;
        if (siz[x] < siz[y]) {
            par[x] = y;
            siz[y] += siz[x];
            div[y] += div[x];
        }else{
            par[y] = x;
            siz[x] += siz[y];
            div[x] += div[y];
        }
    }
    
    long long size(int x){
        return siz[find(x)];
    }

    long long getd(int x){
        return div[find(x)];
    }

    bool same(int x, int y) {
        return (find(x) == find(y));
    }
};

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll t; cin >> t;
    while(t--){
        ll n, m; cin >> n >> m;

        union_find uf(n);
        zep(j, 0, m){
            ll a, b; cin >> a >> b; a--; b--;
            uf.unite(a, b);
        }

        if(n % 2 == 1){
            print(((n * (n - 1) / 2 - m) % 2 == 0)? "Second" : "First")
            continue;
        }

        ll cap = 0, cnt = 0;
        zep(i, 0, n){
            if(i == uf.find(i)){
                cap += uf.size(i) * (uf.size(i) - 1) / 2;
                if(!uf.same(i, 0) && !uf.same(i, n - 1) && uf.size(i) % 2 == 1)cnt++;
            }
        }

        cap -= m;
        if(cap % 2 == 0){
            print((cnt % 4 == 0)? "Second" : "First")
        }else{
            print((cnt % 4 == 2)? "Second" : "First")
        }
    }
    
    return 0;
}