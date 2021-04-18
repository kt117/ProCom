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

ll n, c[100008];
bool use[100008], ans[100008];
vector<vector<ll>> g;

void dfs(ll at, ll from){
    if(!use[c[at]]){
        ans[at] = true;
    }

    bool buf = use[c[at]];
    use[c[at]] = true;

    zep(i, 0, g[at].size()){
        ll nx = g[at][i];
        if(nx != from){
            dfs(nx, at);
        }
    }

    use[c[at]] = buf;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n;
    zep(i, 0, n)cin >> c[i];

    g.resize(n);
    zep(i, 0, n - 1){
        ll a, b; cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(0, -1);
    zep(i, 0, n){
        if(ans[i]){
            print(i + 1)
        }
    }
    
    return 0;
}