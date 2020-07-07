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
ll n, k, cnt[MAX], c, col[MAX]; 
vector<vector<P>> g(MAX);

void dfs(ll at, ll from){
    bool one = g[at].size() > c;
    
    bool use[c]; memset(use, 0, sizeof(use));
    zep(i, 0, g[at].size())if(col[g[at][i].second] != -1)use[col[g[at][i].second]] = true;

    ll it = 0; while(use[it])it++;
    zep(i, 0, g[at].size()){
        ll nx = g[at][i].first, e = g[at][i].second;

        if(nx != from){
            col[e] = (one)? 0 : it;
            it++; while(it < c && use[it])it++;
            dfs(nx, at);
        }
    }
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n >> k;
    zep(i, 0, n - 1){
        ll u, v; cin >> u >> v; u--; v--;
        g[u].push_back(P(v, i));
        g[v].push_back(P(u, i));
    }

    zep(i, 0, n){cnt[i] = g[i].size();}
    sort(cnt, cnt + n, greater<>());
    c = cnt[k];

    memset(col, -1, sizeof(col));
    dfs(0, -1);
    
    print(c)
    zep(i, 0, n - 1)cout << col[i] + 1 << " ";
    cout << endl;

    return 0;
}