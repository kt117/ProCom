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

ll h, w, anscnt; 
string s[2500];
vector<vector<ll>> g;
vector<vector<P>> ans;
union_find u(5000);

void dfs(ll at, ll from){
    zep(i, 0, g[at].size()){
        ll nx = g[at][i];

        if(nx != from){
            dfs(nx, at);
        }
    }
    if(from != -1){
        ans[u.find(at)].push_back(P(at, from));
        anscnt++;
    }
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> h >> w;
    zep(i, 0, h)cin >> s[i];
    g.resize(h + w);

    zep(i, 0, h){
        zep(j, 0, w){
            if(s[i][j] == 'R'){
                if(!u.same(i, h + j)){
                    u.unite(i, h + j);
                    g[i].push_back(h + j);
                    g[h + j].push_back(i);
                }
            }
        }
    }

    ans.resize(h + w);
    zep(i, 0, h + w){
        if(u.find(i) == i){
            dfs(i, -1);
        }
    }

    ll k = 0;
    zep(i, 0, h + w)if(u.find(i) == i && u.size(i) > 1)k++;

    ll cnth = 0, cntw = 0;
    zep(i, 0, h + w){
        if(u.size(i) > 1){
            if(i < h){
                cnth++;
            }else{
                cntw++;
            }
        }
    }
    // cout << k << " " << cnth << " " << cntw << endl;

    print(anscnt)
    zep(i, 0, h + w){
        if(u.find(i) == i && u.size(i) > 1){
            zep(j, 0, ans[i].size() - 1){
                if(ans[i][j].first < h){
                    cout << "X " << ans[i][j].first + 1 << " " << ans[i][j].second - h + 1 << endl;
                }else{
                    cout << "Y " << ans[i][j].second + 1 << " " << ans[i][j].first - h + 1 << endl;
                }
            }

            if((h - cnth + k) * (w - cntw) < (h - cnth) * (w - cntw + k)){
                if(ans[i].back().first < h){
                    cout << "Y " << ans[i].back().first + 1 << " " << ans[i].back().second - h + 1 << endl;
                }else{
                    cout << "Y " << ans[i].back().second + 1 << " " << ans[i].back().first - h + 1 << endl;
                }
            }else{
                if(ans[i].back().first < h){
                    cout << "X " << ans[i].back().first + 1 << " " << ans[i].back().second - h + 1 << endl;
                }else{
                    cout << "X " << ans[i].back().second + 1 << " " << ans[i].back().first - h + 1 << endl;
                }
            }
        }
    }
    
    return 0;
}