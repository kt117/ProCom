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
ll a[100 * 100], b[100 * 100];
bool use[100 * 100], ans[100 * 100], usev[100];

void dfs(ll at){
    usev[at] = true;
    
    zep(i, 0, g[at].size()){
        auto nx = g[at][i];
        if(!usev[nx.first]){
            if(!use[nx.second]){
                use[nx.second] = true;
                ans[nx.second] = (a[nx.second] == at);
            }
            dfs(nx.first);
        }else{
            if(!use[nx.second]){
                use[nx.second] = true;
                ans[nx.second] = (a[nx.second] == at);
            }
        }
    }
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n, m; cin >> n >> m;
    zep(j, 0, m){cin >> a[j] >> b[j]; a[j]--; b[j]--;}
    ll c[n]; zep(i, 0, n)cin >> c[i];
    
    g.resize(n);
    zep(j, 0, m){
        if(c[a[j]] > c[b[j]]){
            ans[j] = true;
        }else if(c[a[j]] < c[b[j]]){
            ans[j] = false;
        }else{
            g[a[j]].push_back(P(b[j], j));
            g[b[j]].push_back(P(a[j], j));
        }
    }

    zep(i, 0, n)dfs(i);

    zep(j, 0, m){
        print(ans[j]? "->" : "<-")
    }

    return 0;
}