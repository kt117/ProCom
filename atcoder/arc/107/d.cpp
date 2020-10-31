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

ll n, k, dp[2][3030][3030];
//ll a[12] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n >> k;

    dp[0][n - k][k] = 1;

    rep(x, 1, n - k){
        rep(i, 1, n - k){
            
        }
    }
    zep(x, 0, 12){
        rep(i, 0, k - 1){

        }
    }
    rep(i, 0, k - 1){
        rep(j, 0, n){
            zep(x, 0, 12){
                if(j + a[x] <= n){
                    dp[i + 1][j + a[x]] += dp[i][j];
                    dp[i + 1][j + a[x]] %= MOD;
                }
            }
        }
    }
    print(dp[k][n])

    return 0;
}