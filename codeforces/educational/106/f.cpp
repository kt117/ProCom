#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 998244353;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define zep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(ll i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

ll n, k;
vector<vector<ll>> g, dp;

vector<ll> ide(){
    vector<ll> res =  vector<ll>(n, 0);
    res[0] = 1;
    return res;
}

vector<ll> f1(vector<ll> a, vector<ll> b){
    vector<ll> cuma(n, 0), cumb(n, 0);
    zep(i, 0, n){
        cuma[i] += a[i];
        cumb[i] += b[i];
        if(i > 0){
            cuma[i] += cuma[i - 1]; cuma[i] %= MOD;
            cumb[i] += cumb[i - 1]; cumb[i] %= MOD;
        }
    }
    vector<ll> res(n, 0);
    rep(i, 0, k){
        res[i] = (a[i] * cumb[min(i, k - i)] % MOD + b[i] * cuma[min(i, k - i)] % MOD) % MOD;
        if(2 * i <= k){res[i] += MOD - a[i] * b[i] % MOD; res[i] %= MOD;}
    }
    return res;
}

vector<ll> f2(vector<ll> a){
    vector<ll> res(n, 0);
    rep(i, 0, k){res[0] += a[i]; res[0] %= MOD;}
    zep(i, 0, k){res[i + 1] += a[i]; res[i + 1] %= MOD;}
    return res;
}

void dfs1(ll at, ll from = -1){
    dp[at] = ide();
    zep(i, 0, g[at].size()){
        ll nx = g[at][i];
        if(nx != from){
            dfs1(nx, at);
            dp[at] = f1(dp[at], f2(dp[nx]));
        }
    }
}

void dfs2(ll at, ll from = -1, vector<ll> x = ide()){
    dp[at] = f2(f1(dp[at], x));

    ll m = g[at].size();
    vector<ll> l[m], r[m];
    zep(i, 0, m){l[i] = r[i] = (g[at][i] == from)? x : f2(dp[g[at][i]]);}
    rep(i, 1, m-1){l[i] = f1(l[i], l[i-1]);}
    rrep(i, m-2, 0){r[i] = f1(r[i], r[i+1]);}

    zep(i, 0, m){
        ll nx = g[at][i];
        if(nx != from){
            vector<ll> tmp = ide();
            if(i > 0){tmp = f1(tmp, l[i-1]);}
            if(i < m-1){tmp = f1(tmp, r[i+1]);}
            dfs2(nx, at, f2(tmp));
        }
    }
}


int main(){
    cin.tie(0); ios::sync_with_stdio(false);

    cin >> n >> k;
    g.resize(n);
    dp.resize(n);
    zep(i, 0, n-1){
        ll a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs1(0);
    //dfs2(0);

    /*zep(i, 0, n){
        zep(j, 0, n)cout << dp[i][j] << " ";
        cout << endl; 
    }*/

    ll ans = 0;
    rep(i, 0, k){
        ans += dp[0][i];
        ans %= MOD;
    }
    print(ans)
    return 0;
}
