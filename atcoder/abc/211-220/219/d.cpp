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

ll n, x, y, a[300], b[300];

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n >> x >> y;
    zep(i, 0, n)cin >> a[i] >> b[i];

    ll dp[x + 1][y + 1];
    rep(j, 0, x){
        rep(k, 0, y){
            dp[j][k] = INF;
        }
    }
    dp[0][0] = 0;

    zep(i, 0, n){
        rrep(j, x, 0){
            rrep(k, y, 0){
                dp[min(j + a[i], x)][min(k + b[i], y)] = min(dp[min(j + a[i], x)][min(k + b[i], y)], dp[j][k] + 1);
            }
        }
    }

    print((dp[x][y] < INF)? dp[x][y] : -1)

    return 0;
}