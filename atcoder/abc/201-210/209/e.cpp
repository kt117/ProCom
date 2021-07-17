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

ll h(char c){
    if('a' <= c && c <= 'z'){
        return c - 'a';
    }else{
        return c - 'A' + 26;
    }
}

ll encode(string s){
    return h(s[0]) * 52 * 52 + h(s[1]) * 52 + h(s[2]);
}

const ll N = 52 * 52 * 52;
vector<vector<ll>> g(N), rg(N);
vector<ll> ok(N, 0);

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n; cin >> n;
    string s[n]; zep(i, 0, n)cin >> s[i];
    
    set<P> use;
    zep(i, 0, n){
        ll a = encode(s[i].substr(0, 3));
        ll b = encode(s[i].substr(s[i].size() - 3, 3));
        
        if(use.find(P(a, b)) == use.end()){
            use.insert(P(a, b));
            g[a].push_back(b);
            rg[b].push_back(a);
        }
    }

    queue<ll> q;
    zep(i, 0, N)if(g[i].size() == 0){
        q.push(i);
    }

    while(!q.empty()){
        ll at = q.front(); q.pop();

        bool allwin = true, anylose = false;
        zep(i, 0, g[at].size()){
            ll nx = g[at][i];
            if(ok[nx] == -1)anylose = true;
            if(ok[nx] != 1)allwin = false;
        }
        if(anylose)ok[at] = 1;
        if(allwin)ok[at] = -1;
        
        if(ok[at] != 0){
            zep(i, 0, rg[at].size()){
                ll nx = rg[at][i];
                if(ok[nx] == 0)q.push(nx);
            }
        }
    }

    zep(i, 0, n){
        ll b = encode(s[i].substr(s[i].size() - 3, 3));
    
        if(ok[b] == -1){
            print("Takahashi")
        }else if(ok[b] == 1){
            print("Aoki")
        }else{
            print("Draw")
        }
    }

    return 0;
}