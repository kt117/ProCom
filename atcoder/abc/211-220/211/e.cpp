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

ll n, k, c[10][10], ans; 
string s[10];

bool ok(ll i, ll j){
    if(c[i][j] != 0)return false;

    if(c[i - 1][j] == 2 || c[i + 1][j] == 2 || c[i][j - 1] == 2 || c[i][j + 1] == 2){
        return true;
    }else{
        return false;
    }
}

P fi(){
    rep(i, 1, n){
        rep(j, 1, n){
            if(ok(i, j))return P(i, j);
        }
    }
    return P(-1, -1);
}

void g(ll r){
    if(r == 0){
        ans++; return;
    }

    P nx = fi();
    if(nx.first == -1)return;
    
    c[nx.first][nx.second] = 2;
    g(r - 1);
    c[nx.first][nx.second] = 1;
    g(r);
    c[nx.first][nx.second] = 0;
}

void f(){
    rep(i, 1, n){
        rep(j, 1, n){
            if(c[i][j] == 0){
                c[i][j] = 2;
                g(k - 1);
                c[i][j] = 1;
            }
        }
    }
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n >> k;
    zep(i, 0, n)cin >> s[i];

    zep(i, 0, 10)zep(j, 0, 10)c[i][j] = 1;
    zep(i, 0, n)zep(j, 0, n)if(s[i][j] == '.')c[i + 1][j + 1] = 0;
    
    f();
    print(ans)

    return 0;
}