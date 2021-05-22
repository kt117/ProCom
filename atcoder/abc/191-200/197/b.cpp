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

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll h, w, x, y; cin >> h >> w >> x >> y;
    x--; y--;
    string s[h]; zep(i, 0, h)cin >> s[i];

    ll ans = 0;
    rrep(i, x - 1, 0){
        if(s[i][y] == '#')break;
        ans++;
    }
    zep(i, x + 1, h){
        if(s[i][y] == '#')break;
        ans++;
    }
    rrep(j, y - 1, 0){
        if(s[x][j] == '#')break;
        ans++;
    }
    zep(j, y + 1, w){
        if(s[x][j] == '#')break;
        ans++;
    }
    print(ans + 1)
    
    return 0;
}