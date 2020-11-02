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

ll n, x[100], y[100];

bool f(double R){
    union_find uf(n + 2);

    zep(i, 0, n){
        zep(j, i + 1, n){
            if(R * R > (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])){
                uf.unite(i, j);
            }
        }
    }

    zep(i, 0, n)if(R > 100 - y[i])uf.unite(i, n);
    zep(i, 0, n)if(R > y[i] + 100)uf.unite(i, n + 1);
    
    return !uf.same(n, n + 1);
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n;
    zep(i, 0, n)cin >> x[i] >> y[i];
    
    double ng = 200, ok = 0;
    while(ng - ok > 1e-6){
        double mid = (ok + ng) / 2;

        if(f(mid)){
            ok = mid;
        }else{
            ng = mid;
        }
    }

    cout << fixed << setprecision(20) << ok / 2 << endl;
    
    return 0;
}