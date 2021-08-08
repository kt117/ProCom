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

ll h, w, c, a[1010][1010];

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> h >> w >> c;
    zep(i, 0, h)zep(j, 0, w)cin >> a[i][j];

    ll dp[h][w];
    ll ans = INF;

    zep(i, 0, h){
        zep(j, 0, w){
            dp[i][j] = a[i][j];
            if(i > 0)dp[i][j] = min(dp[i][j], dp[i - 1][j] + c);
            if(j > 0)dp[i][j] = min(dp[i][j], dp[i][j - 1] + c);
        }
    }

    zep(i, 0, h){
        zep(j, 0, w){
            if(i > 0)ans = min(ans, dp[i - 1][j] + c + a[i][j]);
            if(j > 0)ans = min(ans, dp[i][j - 1] + c + a[i][j]);
        }
    }

    zep(i, 0, h){
        rrep(j, w - 1, 0){
            dp[i][j] = a[i][j];
            if(i > 0)dp[i][j] = min(dp[i][j], dp[i - 1][j] + c);
            if(j < w - 1)dp[i][j] = min(dp[i][j], dp[i][j + 1] + c);
        }
    }

    zep(i, 0, h){
        rrep(j, w - 1, 0){
            if(i > 0)ans = min(ans, dp[i - 1][j] + c + a[i][j]);
            if(j < w - 1)ans = min(ans, dp[i][j + 1] + c + a[i][j]);
        }
    }

    print(ans)
    
    return 0;
}