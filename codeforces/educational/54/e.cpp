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
ll n, m;
vector<ll> ans(N), sg(N, 0);
vector<vector<ll>> g;
vector<vector<P>> q;

void dfs(ll at, ll from, ll cur){
    zep(i, 0, q[at].size()){
        sg[cur] += q[at][i].second;
        if(cur + q[at][i].first + 1 < N)sg[cur + q[at][i].first + 1] -= q[at][i].second;
    }
    sg[cur] += sg[cur - 1];

    ans[at] = sg[cur];

    zep(i, 0, g[at].size()){
        ll nx = g[at][i];
        if(nx != from)dfs(nx, at, cur + 1);
    }

    sg[cur] -= sg[cur - 1];

    zep(i, 0, q[at].size()){
        sg[cur] -= q[at][i].second;
        if(cur + q[at][i].first + 1 < N)sg[cur + q[at][i].first + 1] += q[at][i].second;
    }
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n;
    g.resize(n);
    zep(i, 0, n - 1){
        ll x, y; cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    cin >> m;
    q.resize(n);
    zep(i, 0, m){
        ll v, d, x; cin >> v >> d >> x;
        v--;
        q[v].push_back(P(d, x));
    }

    dfs(0, -1, 1);

    printa(ans, 0, n - 1)

    return 0;
}