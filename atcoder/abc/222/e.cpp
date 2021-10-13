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

ll dp[2 * 101 * 1001];

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n, m, k; cin >> n >> m >> k;
    ll a[m]; zep(i, 0, m){cin >> a[i]; a[i]--;}
    ll u[n - 1], v[n - 1];
    zep(i, 0, n - 1){
        cin >> u[i] >> v[i];
        u[i]--; v[i]--;
    }

    ll count[n - 1]; memset(count, 0, sizeof(count));
    zep(i, 0, n - 1){
        union_find uf(n);
        
        zep(j, 0, n - 1){
            if(j != i)uf.unite(u[j], v[j]);
        }

        zep(j, 1, m){
            if(!uf.same(a[j - 1], a[j]))count[i]++;
        }
    }

    ll sm = 0;
    zep(i, 0, n - 1)sm += count[i];
    if(sm + k < 0 || (sm + k) % 2 == 1){print(0) return 0;}

    dp[0] = 1;
    zep(i, 0, n - 1){
        rrep(j, (sm + k) / 2, 0){
            if(j - count[i] >= 0){
                dp[j] += dp[j - count[i]];
                dp[j] %= MOD;
            }
        }
    }
    print(dp[(sm + k) / 2])
    
    return 0;
}