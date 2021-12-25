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
    
    union_find u(n);
    ll cnt[n]; memset(cnt, 0, sizeof(cnt));
    zep(i, 0, m){
        ll a, b; cin >> a >> b; a--; b--;

        if(u.same(a, b)){
            print("No") return 0;
        }
        u.unite(a, b);

        if(cnt[a] < 2 && cnt[b] < 2){
            cnt[a]++;
            cnt[b]++;
        }else{
            print("No") return 0;
        }
    }

    print("Yes")

    return 0;
}