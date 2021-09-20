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

ll n, m, q;
vector<vector<ll>> g, mg;

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n >> m >> q;
    g.resize(n);

    zep(i, 0, m){
        ll u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    mg.resize(n);
    zep(i, 0, n){
        zep(j, 0, g[i].size()){
            if(g[g[i][j]].size() >= 500){
                mg[i].push_back(g[i][j]);
            }
        }
    }

    P ans[n]; zep(i, 0, n)ans[i] = P(i, -1);
    P buf[n]; zep(i, 0, n)buf[i] = P(-1, -INF);

    zep(i, 0, q){
        ll x; cin >> x; x--;

        P c = ans[x];
        zep(j, 0, mg[x].size()){
            if(buf[mg[x][j]].second > c.second){
                c = buf[mg[x][j]];
                ans[x] = c;
            }
        }

        if(g[x].size() >= 500){
            buf[x] = P(c.first, i);
        }else{
            zep(j, 0, g[x].size()){
                ans[g[x][j]] = P(c.first, i);
            }
        }
    }

    zep(i, 0, n){
        zep(j, 0, mg[i].size()){
            if(buf[mg[i][j]].second > ans[i].second){
                ans[i] = buf[mg[i][j]];
            }
        }
        cout << ans[i].first + 1 << " ";
    }
    cout << endl;
    
    return 0;
}