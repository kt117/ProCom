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

vector<vector<vector<ll>>> g;
vector<ll> nw;
vector<P> e[2];
priority_queue<vector<ll>> q[2];


void dfs(ll at, ll from){
    if(from != -1 && g[at].size() == 1){
        nw[at] = 1;
        return;
    }

    zep(i, 0, g[at].size()){
        ll nx = g[at][i][0];
        if(nx != from){
            dfs(nx, at);

            nw[at] += nw[nx];
            e[g[at][i][2] - 1].push_back(P(g[at][i][1], nw[nx]));
        }
    }
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll t; cin >> t;
    while(t--){
        g.clear();
        nw.clear();
        e[0].clear();
        e[1].clear();
        zep(i, 0, 2)while(!q[i].empty())q[i].pop();

        ll n, s; cin >> n >> s;
        g.resize(n);
        nw.resize(n, 0);

        zep(i, 0, n - 1){
            ll U, V, w, c; cin >> U >> V >> w >> c; U--; V--;
            g[U].push_back({V, w, c});
            g[V].push_back({U, w, c});
        }

        dfs(0, -1);
       
        ll sm = 0;
        zep(j, 0, 2){
            zep(i, 0, e[j].size()){
                ll ww = e[j][i].first;
                ll pp = e[j][i].second;

                sm += ww * pp;
                q[j].push({(ww - ww / 2) * pp, ww, pp});
            }
        }
        q[0].push({0, 0, 0});
        q[0].push({0, 0, 0});
        q[1].push({0, 0, 0});

        ll ans = 0;
        
        while(sm > s){
            vector<ll> v = q[0].top(); q[0].pop();

            if(sm - v[0] <= s){
                ans++;
                break;
            }

            if(q[0].top()[0] + v[0] > q[1].top()[0]){
                sm -= v[0];

                v[1] /= 2;
                v[0] = (v[1] - v[1] / 2) * v[2];

                q[0].push(v);
                ans++;
            }else{
                q[0].push(v);
                vector<ll> u = q[1].top(); q[1].pop();
                sm -= u[0];

                u[1] /= 2;
                u[0] = (u[1] - u[1] / 2) * u[2];

                q[1].push(u);
                ans += 2;
            }
        }

        print(ans)
    }
    
    return 0;
}