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

ll n, k;
vector<vector<ll>> g;

P dfs(ll at, ll from, ll mid){
    if(g[at].size() == 1 && g[at][0] == from){
        return P(1, 0);
    }

    ll cnt = 0, mnn = 0, mxp = 0;
    zep(i, 0, g[at].size()){
        ll nx = g[at][i];

        if(nx != from){
            P r = dfs(nx, at, mid);
            cnt += r.second;
            
            if(r.first >= 0){
                mxp = max(mxp, r.first);
            }else{
                mnn = min(mnn, r.first);
            }
        }
    }
    
    if(mnn + mxp < 0){
        return P(mnn + 1, cnt);
    }else{
        if(mxp == mid){
            return P(- mid, cnt + 1);
        }else{
            return P(mxp + 1, cnt);
        }
    }
}

bool f(ll mid){
    auto r = dfs(0, -1, mid);
    if(r.first > 0)r.second++;
    return r.second <= k;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n >> k;
    g.resize(n);
    zep(i, 0, n - 1){
        ll u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    ll ok = n;
    ll ng = 0;
    //f(1);
    while(ok - ng > 1){
        ll mid = (ok + ng) / 2;
        
        if(f(mid)){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    print(ok)
    
    return 0;
}