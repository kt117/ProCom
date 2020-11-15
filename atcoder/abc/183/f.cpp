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

ll c[200010]; 

struct union_find{
    vector<int> rnk, par;
    vector<map<int, int>> mp;

    union_find(int n){
        rnk.resize(n);
        par.resize(n);
        mp.resize(n);

        for(int i = 0; i < n; i++){
            par[i] = i;
            rnk[i] = 0;
            mp[i][c[i]] = 1;
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

            for(auto it = mp[x].begin(); it != mp[x].end(); it++){
                int a = (*it).first, b = (*it).second;
                if(mp[y].find(a) == mp[y].end())mp[y][a] = 0;
                mp[y][a] += b;
            }
            mp[x].clear();
        }
        else{
            par[y] = x;

            for(auto it = mp[y].begin(); it != mp[y].end(); it++){
                int a = (*it).first, b = (*it).second;
                if(mp[x].find(a) == mp[x].end())mp[x][a] = 0;
                mp[x][a] += b;
            }
            mp[y].clear();
            
            if (rnk[x] == rnk[y])rnk[x]++;
        }
    }
    
    bool same(int x, int y){
        return find(x) == find(y);
    }

    int query(int a, int b){
        return mp[find(a)][b];
    }
};

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n, q; cin >> n >> q;
    zep(i, 0, n)cin >> c[i];

    union_find u(n);
    zep(i, 0, q){
        ll f, a, b; cin >> f >> a >> b;

        if(f == 1){
            u.unite(a - 1, b - 1);
        }else{
            print(u.query(a - 1, b))
        }
    }
    
    return 0;
}