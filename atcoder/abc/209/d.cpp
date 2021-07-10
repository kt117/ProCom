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

ll col[100010];
vector<vector<ll>> g;


void dfs(ll at, ll from, ll x){
    col[at] = x;

    zep(i, 0, g[at].size()){
        ll nx = g[at][i];
        if(nx != from){
            dfs(nx, at, 1 - x);
        }
    }
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n, q; cin >> n >> q;
    g.resize(n);
    
    zep(i, 0, n - 1){
        ll a, b; cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(0, -1, 0);
    
    while(q--){
        ll c, d; cin >> c >> d; c--; d--;

        if(col[c] == col[d]){
            print("Town")
        }else{
            print("Road")
        }
    }

    return 0;
}