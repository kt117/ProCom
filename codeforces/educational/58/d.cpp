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

const ll MAX = 2e5;
ll n, a[MAX + 10], ans = 0;
vector<vector<ll>> g(MAX + 10);

map<ll, ll> dfs(ll at, ll from){
    map<ll, ll> res;

    for(ll i = 2; i * i <= a[at]; i++){
        bool ok = false;
        while(a[at] % i == 0){
            a[at] /= i;
            ok = true;
        }
        if(ok)res[i] = 1;
    }
    if(a[at] > 1)res[a[at]] = 1;
    if(res.size() > 0)ans = max(ans, 1LL);

    zep(i, 0, g[at].size()){
        ll nx = g[at][i];
        
        if(nx != from){
            auto mp = dfs(nx, at);

            for(auto it = mp.begin(); it != mp.end(); it++){
                ll x = (*it).first, y = (*it).second;
                if(res.find(x) != res.end()){
                    ans = max(ans, res[x] + y);
                    res[x] = max(res[x], y + 1);
                }
            }
        }
    }
    
    return res;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n;
    zep(i, 0, n)cin >> a[i];
    zep(i, 0, n - 1){
        ll x, y; cin >> x >> y; x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
     
    dfs(0, -1);

    print(ans)
    
    return 0;
}