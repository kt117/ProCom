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
#define printa(x,m,n) for(ll i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;


/*
verify: https://atcoder.jp/contests/abc160/tasks/abc160_f
*/


ll n, d[2 * 101 * 1001];
vector<vector<P>> g; 
vector<vector<ll>> dp, dp2;

vector<ll> ide(){
    return {0};
}

vector<ll> f1(vector<ll> a, vector<ll> b){
    return {max(a[0], b[0])};
}

vector<ll> f2(ll at, ll c, vector<ll> a){
    return {max(d[at], a[0]) + c};
}

void dfs1(ll at, ll from = -1){
    dp[at] = ide();
    zep(i, 0, g[at].size()){
        ll nx = g[at][i].first;
        if(nx != from){
            dfs1(nx, at);
            dp[at] = f1(dp[at], f2(nx, g[at][i].second, dp[nx]));
        }
    }
}

void dfs2(ll at, ll from = -1, vector<ll> x = ide()){
    // dp[at] = f2(at, c, f1(dp[at], x));

    ll m = g[at].size();
    vector<ll> l[m], r[m];
    zep(i, 0, m){l[i] = r[i] = (g[at][i].first == from)? x : f2(g[at][i].first, g[at][i].second, dp[g[at][i].first]);}
    rep(i, 1, m-1){l[i] = f1(l[i], l[i-1]);}
    rrep(i, m-2, 0){r[i] = f1(r[i], r[i+1]);}
    dp2[at] = l[m - 1];

    zep(i, 0, m){
        ll nx = g[at][i].first;
        if(nx != from){
            vector<ll> tmp = ide();
            if(i > 0){tmp = f1(tmp, l[i-1]);}
            if(i < m-1){tmp = f1(tmp, r[i+1]);}
            dfs2(nx, at, f2(at, g[at][i].second, tmp));
        }
    }
}


int main(){
    cin.tie(0); ios::sync_with_stdio(false);

    cin >> n;
    g.resize(n);
    dp.resize(n);
    dp2.resize(n);
    zep(i, 0, n-1){
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        g[a].push_back(P(b, c));
        g[b].push_back(P(a, c));
    }

    zep(i, 0, n)cin >> d[i];

    dfs1(0);
    dfs2(0);

    zep(i, 0, n)print(dp2[i][0])
    
    return 0;
}