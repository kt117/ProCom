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

ll dp[1000 + 1][1LL << 10][10];

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n; cin >> n;
    string s; cin >> s;

    zep(i, 0, n){
        ll x = s[i] - 'A';
        // print(x)
        dp[i + 1][1LL << x][x]++;
        dp[i + 1][1LL << x][x] %= MOD;

        zep(bit, 1, 1LL << 10){
            zep(k, 0, 10){
                dp[i + 1][bit][k] += dp[i][bit][k];
                dp[i + 1][bit][k] %= MOD;
            }

            if(bit & (1LL << x)){
                dp[i + 1][bit][x] += dp[i][bit][x];
                dp[i + 1][bit][x] %= MOD;
            }else{
                zep(k, 0, 10){
                    dp[i + 1][bit | (1LL << x)][x] += dp[i][bit][k];
                    dp[i + 1][bit | (1LL << x)][x] %= MOD;
                }    
            }
        }
    }
    
    ll ans = 0;
    zep(bit, 0, (1LL << 10)){
        zep(k, 0, 10){
            ans += dp[n][bit][k];
            ans %= MOD;
        }
    }
    print(ans)

    return 0;
}