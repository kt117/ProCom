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

const ll MAX = 2e5 + 10;
ll n, a[MAX], b[MAX], q, cnta[MAX], cntb[MAX], dp[MAX], dp2[MAX];
vector<vector<P>> g;

void dfs(ll at, ll from, ll ei){
    zep(i, 0, g[at].size()){
        ll nx = g[at][i].first;
        if(nx != from){
            dfs(nx, at, g[at][i].second);
        }
    }

    if(from == a[ei]){
        dp[from] += dp[at] + cnta[ei];
    }else{
        dp[from] += dp[at] + cntb[ei];
    } 
}

void dfs2(ll at, ll from, ll v){
    dp2[at] += v;

    zep(i, 0, g[at].size()){
        ll nx = g[at][i].first;
        if(nx != from){
            ll u;
            if(a[g[at][i].second] == at){
                u = cntb[g[at][i].second];
            }else{
                u = cnta[g[at][i].second];
            }

            ll w;
            if(a[g[at][i].second] == at){
                w = cnta[g[at][i].second];
            }else{
                w = cntb[g[at][i].second];
            }

            dfs2(nx, at, dp[at] - dp[nx] - w + dp2[at] + u);
        }
    }
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n;
    zep(i, 0, n - 1){cin >> a[i] >> b[i]; a[i]--; b[i]--;}
    cin >> q;
    while(q--){
        ll t, e, x; cin >> t >> e >> x; e--;

        if(t == 1){
            cnta[e] += x;
        }else{
            cntb[e] += x;
        }
    }

    g.resize(n);
    zep(i, 0, n - 1){
        g[a[i]].push_back(P(b[i], i));
        g[b[i]].push_back(P(a[i], i));
    }

    dfs(0, n, n);
    //printa(dp, 0, n - 1)
    dfs2(0, -1, 0);
    //printa(dp2, 0, n - 1)
    zep(i, 0, n)print(dp[i] + dp2[i])

    return 0;
}