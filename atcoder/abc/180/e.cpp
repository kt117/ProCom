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

ll n, dst[20][20], dp[17][1LL << 18];

void warshall_floid(){
    for(ll k = 0; k < n; k++)
        for(ll i = 0; i < n; i++)
            for(ll j = 0; j < n; j++)
                dst[i][j] = min(dst[i][k] + dst[k][j], dst[i][j]);
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n;
    ll x[n][3]; zep(i, 0, n)zep(j, 0, 3)cin >> x[i][j];

    zep(i, 0, n){
        zep(j, 0, n){
            dst[i][j] = abs(x[i][0] - x[j][0]) + abs(x[i][1] - x[j][1]) + max(0LL, x[j][2] - x[i][2]);
        }
    }

    warshall_floid();
    //zep(i, 0, n)zep(j, 0, n)print(dst[i][j])

    zep(bit, 1, (1LL << n))zep(i, 0, n)dp[i][bit] = INF;
    dp[0][1] = 0;

    zep(bit, 1, (1LL << n)){
        zep(i, 0, n){
            zep(j, 0, n){
                if((bit & (1LL << i)) && !(bit & (1LL << j))){
                    dp[j][bit | (1LL << j)] = min(dp[j][bit | (1LL << j)], dp[i][bit] + dst[i][j]);
                }
            }
        }
    }

    //zep(i, 0, n){zep(bit, 0, (1LL << n))cout << dp[i][bit] << " "; cout << endl;} 

    ll ans = INF;
    zep(i, 0, n)ans = min(ans, dp[i][(1LL << n) - 1] + dst[i][0]);
    print(ans)

    return 0;
}