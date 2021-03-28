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

vector<vector<P>> g;
vector<ll> w, c, ch, ech;

void dfs(ll at, ll from){
    ch[at] = 0;
    if(from != -1 && g[at].size() == 1){
        ch[at]++;
        return;
    }

    zep(i, 0, g[at].size()){
        ll nx = g[at][i].first;
        if(nx != from){
            dfs(nx, at);

            ch[at] += ch[nx];
            ech[g[at][i].second] = ch[nx];
        }
    }
}

ll ds(ll ww, ll cc){
    return (ww - ww / 2) * cc;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll t; cin >> t;
    while(t--){
        g.clear();

        ll n, s; cin >> n >> s;
        g.resize(n);
        w.resize(n);
        c.resize(n);
        ch.resize(n);
        ech.resize(n);
       
        zep(i, 0, n - 1){
            ll u, v; cin >> u >> v >> w[i] >> c[i]; u--; v--;
            g[u].push_back(P(v, i));
            g[v].push_back(P(u, i));
        }

        dfs(0, -1);
       
        priority_queue<P> q[2];
        ll sm = 0;
        zep(i, 0, n - 1){
            sm += w[i] * ech[i];
            q[c[i] - 1].push(P(ds(w[i], ech[i]), i));
        }

        vector<ll> dv[2];
        zep(j, 0, 2){
            dv[j].push_back(0);

            ll dsm = 0;
            while(!q[j].empty()){
                ll d = q[j].top().first;
                ll k = q[j].top().second;
                q[j].pop();

                dsm += d;
                w[k] /= 2;

                d = ds(w[k], ech[k]);
                if(d)q[j].push(P(d, k));
                dv[j].push_back(dsm);
            }
        }

        map<ll, ll> mp;
        zep(i, 0, dv[0].size())mp[dv[0][i]] = i;

        ll ans = INF;
        zep(i, 0, dv[1].size()){
            if(sm - dv[1][i] <= s){
                ans = min(ans, 2 * i);
            }else{
                ans = min(ans, 2 * i + (*mp.lower_bound(sm - dv[1][i] - s)).second);
            }
        }

        print(ans)
    }
    
    return 0;
}