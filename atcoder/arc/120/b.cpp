#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 998244353;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define zep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(int i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll h, w; cin >> h >> w;
    string s[h]; zep(i, 0, h)cin >> s[i];

    bool r[1000], b[1000];
    memset(r, 1, sizeof(r));
    memset(b, 1, sizeof(b));

    zep(i, 0, h){
        zep(j, 0, w){
            if(s[i][j] == 'R')b[i + j] = false;
            if(s[i][j] == 'B')r[i + j] = false;
        }
    }

    ll ans = 1;
    rep(k, 0, h + w - 2){
        if(r[k] && b[k]){
            ans *= 2; ans %= MOD;
        }else if(!r[k] && !b[k]){
            ans *= 0;
        }
    }
    print(ans)
    
    return 0;
}