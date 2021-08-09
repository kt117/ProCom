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
vector<vector<ll>> g;

void dfs(ll at, ll from){
    cout << at + 1 << " ";

    vector<ll> v;
    zep(i, 0, g[at].size()){
        if(g[at][i] != from){
            v.push_back(g[at][i]);
        }
    }
    sort(v.begin(), v.end());

    zep(i, 0, v.size()){
        dfs(v[i], at);
        cout << at + 1 << " ";
    }
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n;
    g.resize(n);
    zep(i, 0, n - 1){
        ll a, b; cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(0, -1);
    cout << endl;
    
    return 0;
}