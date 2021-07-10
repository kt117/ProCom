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

vector<vector<ll>> g(52 * 52 * 52);
vector<ll> ok(52 * 52 * 52, 0);
vector<bool> use(52 * 52 * 52), use2(52 * 52 * 52);

void memo(ll at){
    use[at] = true;
    if(g[at].size() == 0){ok[at] = -1; return;}

    zep(i, 0, g[at].size()){
        ll nx = g[at][i];
        if(!use[nx])memo(nx);
    }

    bool allwin = true, anylose = false;
    zep(i, 0, g[at].size()){
        ll nx = g[at][i];
        if(ok[nx] == -1)anylose = true;
        if(ok[nx] != 1)allwin = false;
    }

    if(allwin){
        ok[at] = -1;
    }else if(anylose){
        ok[at] = 1;
    }else{
        ok[at] = 0;
    }
}

void memo2(ll at){
    use2[at] = true;
    if(g[at].size() == 0){ok[at] = -1; return;}
    
    zep(i, 0, g[at].size()){
        ll nx = g[at][i];
        if(!use2[nx])memo2(nx);
    }

    bool allwin = true, anylose = false;
    zep(i, 0, g[at].size()){
        ll nx = g[at][i];
        if(ok[nx] == -1)anylose = true;
        if(ok[nx] != 1)allwin = false;
    }

    if(allwin){
        ok[at] = -1;
    }else if(anylose){
        ok[at] = 1;
    }else{
        ok[at] = 2;
    }
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n; cin >> n;
    string s[n]; zep(i, 0, n)cin >> s[i];
    
    set<P> suse;
    zep(i, 0, n){
        ll a = encode(s[i].substr(0, 3));
        ll b = encode(s[i].substr(s[i].size() - 3, 3));
        
        if(suse.find(P(a, b)) == suse.end()){
            suse.insert(P(a, b));
            g[a].push_back(b);
        }
    }

    zep(i, 0, n){
        ll b = encode(s[i].substr(s[i].size() - 3, 3));
        
        if(!use[b]){memo(b);}
        if(!use2[b]){memo2(b);}

        if(ok[b] == 1){
            print("Aoki")
        }else if(ok[b] == 2){
            print("Draw")
        }else{
            print("Takahashi")
        }
    }
    
    return 0;
}