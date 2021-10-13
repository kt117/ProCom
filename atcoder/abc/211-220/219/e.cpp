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

ll encode(ll i, ll j){
    return 4 * i + j;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll a[4][4]; zep(i, 0, 4)zep(j, 0, 4)cin >> a[i][j];

    ll ans = 0;
    zep(bit, 0, (1LL << 16)){
        bool ok = true;
        ll b[6][6]; memset(b, 0, sizeof(b));
        zep(i, 0, 4){
            zep(j, 0, 4){
                if(bit & (1LL << encode(i, j))){
                    b[i + 1][j + 1] = 1;
                }
            }
        }

        zep(i, 0, 4){
            zep(j, 0, 4){
                if(a[i][j] == 1 && b[i + 1][j + 1] == 0){
                    ok = false;
                }
            }
        }
        if(!ok)continue;

        union_find u(16);
        ll di[2] = {0, 1}, dj[2] = {1, 0};
        zep(i, 0, 4){
            zep(j, 0, 4){
                zep(k, 0, 2){
                    ll x = i + di[k], y = j + dj[k];
                    if(x < 4 && y < 4){
                        if(b[i + 1][j + 1] == 1 && b[x + 1][y + 1] == 1){
                            u.unite(encode(i, j), encode(x, y));
                        }
                    }
                }
            }
        }

        set<ll> s;
        zep(i, 0, 4){
            zep(j, 0, 4){
                if(b[i + 1][j + 1] == 1){
                    s.insert(u.find(encode(i, j)));
                }
            }
        }

        if(s.size() != 1)continue;

        union_find v(36);
        zep(i, 0, 6){
            zep(j, 0, 6){
                zep(k, 0, 2){
                    ll x = i + di[k], y = j + dj[k];
                    if(x < 6 && y < 6){
                        if(b[i][j] == 0 && b[x][y] == 0){
                            v.unite(encode(i, j), encode(x, y));
                        }
                    }
                }
            }
        }

        set<ll> t;
        zep(i, 0, 6){
            zep(j, 0, 6){
                if(b[i][j] == 0){
                    t.insert(v.find(encode(i, j)));
                }
            }
        }
        if(t.size() != 1)continue;

        ans++;
    }
    print(ans)
    
    return 0;
}