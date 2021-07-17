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

ll n, ans, v[2 * 101 * 1001][60][2];
vector<vector<P>> g;

void dfs(ll at, ll from, ll x){
    zep(j, 0, 60)v[at][j][0]++;

    zep(i, 0, g[at].size()){
        ll nx = g[at][i].first;

        if(nx != from){
            dfs(nx, at, g[at][i].second);

            zep(j, 0, 60){
                ans += v[at][j][0] * v[nx][j][1] % MOD * ((1LL << j) % MOD) % MOD;
                ans %= MOD;
                ans += v[at][j][1] * v[nx][j][0] % MOD * ((1LL << j) % MOD) % MOD;
                ans %= MOD;
            }

            zep(j, 0, 60){
                v[at][j][0] += v[nx][j][0]; v[at][j][0] %= MOD;
                v[at][j][1] += v[nx][j][1]; v[at][j][1] %= MOD;
            }
        }
    }

    zep(j, 0, 60){
        if((1LL << j) & x){
            //ans += v[nx][j][0] * ((1LL << j) % MOD) % MOD; ans %= MOD;

            ll tmp = v[at][j][0];
            v[at][j][0] = v[at][j][1];
            v[at][j][1] = tmp;
        }else{
            //ans += v[nx][j][1] * ((1LL << j) % MOD) % MOD; ans %= MOD;
        }
    }
    //cout << at << " " << ans << endl;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n;
    g.resize(n);
    zep(i, 0, n - 1){
        ll u, v, w; cin >> u >> v >> w;
        u--; v--;
        g[u].push_back(P(v, w));
        g[v].push_back(P(u, w));
    }

    dfs(0, -1, 0);
    print(ans)

    return 0;
}