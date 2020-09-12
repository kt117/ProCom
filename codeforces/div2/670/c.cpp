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

ll n;
vector<vector<ll>> g, dp(1e5 + 10);

vector<ll> ide(){
    return {0, 0};
}

vector<ll> f1(vector<ll> a, vector<ll> b){
    return {a[0] + b[0], max(a[1], b[0])};
}

vector<ll> f2(vector<ll> a){
    return {a[0] + 1, a[1]};
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

ll dfs3(ll at, ll fr, ll s1, ll s2){
    if(at == s1)return s2;
    if(at == s2)return s1;

    zep(i, 0, g[at].size()){
        ll nx = g[at][i];
        if(nx != fr){
            ll res = dfs3(nx, at, s1, s2);
            if(res != -1)return res;
        }
    }
    return -1;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll t; cin >> t;
    while(t--){
        cin >> n;
        vector<vector<ll>> tmp(n);//, tmp2(n);
        g.swap(tmp);
        //dp.swap(tmp2);

        zep(i, 0, n-1){
            ll a, b;
            cin >> a >> b;
            a--; b--;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        dfs1(0);
        dfs2(0);

        ll mn = INF;
        zep(i, 0, n)mn = min(mn, dp[i][1]);
        
        vector<ll> s;
        zep(i, 0, n)if(dp[i][1] == mn)s.push_back(i);

        if(s.size() == 1){
            cout << 1 << " " << g[0][0] + 1 << endl;
            cout << 1 << " " << g[0][0] + 1 << endl;
            continue;
        }

        ll x = 0;
        while(g[x].size() != 1)x++;
        cout << x + 1 << " " << g[x][0] + 1 << endl;

        ll res = dfs3(x, -1, s[0], s[1]);
        cout << x + 1 << " " << res + 1 << endl;
    }
    
    return 0;
}