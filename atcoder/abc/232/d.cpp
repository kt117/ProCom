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
    
    ll h, w; cin >> h >> w;
    string c[h]; zep(i, 0, h)cin >> c[i];

    ll memo[h][w]; memset(memo, 0, sizeof(memo));
    memo[0][0] = 1;
    
    ll ans = 1;
    zep(i, 0, h){
        zep(j, 0, w){
            if(memo[i][j] > 0){
                if(i + 1 < h && c[i + 1][j] == '.'){
                    memo[i + 1][j] = i + j + 2;
                    ans = max(ans, memo[i + 1][j]);
                }
                if(j + 1 < w && c[i][j + 1] == '.'){
                    memo[i][j + 1] = i + j + 2;
                    ans = max(ans, memo[i][j + 1]);
                }
            }
        }
    }
    print(ans)
    
    return 0;
}