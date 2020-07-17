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

const ll N = 3e5 + 10;
ll n, a[N], ans = 0, b = 0;
vector<vector<ll>> g;

P dfs(ll at, ll from, ll c){
    c = (a[at] == 1)? 0 : c + 1;

    P res = P(0, 0);
    if(a[at] == 1)res.first++;
    if(a[at] == 2)res.second++;
    
    zep(i, 0, g[at].size()){
        ll nx = g[at][i];
        if(nx != from){
            auto p = dfs(nx, at, c);
            if(p.first == 0 && p.second == b)ans++;
            res.first += p.first;
            res.second += p.second;
        }
    }

    return res;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n;
    zep(i, 0, n)cin >> a[i];
    
    g.resize(n);
    zep(i, 0, n - 1){
        ll u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    zep(i, 0, n)if(a[i] == 2)b++;
    
    zep(i, 0, n){
        if(a[i] == 1){
            dfs(i, -1, 0);
            break;
        }
    }
    
    print(ans)

    return 0;
}