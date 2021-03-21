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
    
    ll n; cin >> n;
    char c[2][2]; cin >> c[0][0] >> c[0][1] >> c[1][0] >> c[1][1];
    if(n <= 3){print(1) return 0;}

    ll x = 1; zep(i, 0, n - 3){x *= 2; x %= MOD;}
    
    ll dp[n][2]; memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    zep(i, 1, n - 1){
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
        dp[i][1] = dp[i - 1][0];
    }

    if(c[0][1] == 'A'){
        if(c[0][0] == 'A'){
            print(1)
        }else{
            if(c[1][0] == 'B'){
                print(x)
            }else{
                print(dp[n - 2][0])
            }
        }
    }else{
        if(c[1][1] == 'B'){
            print(1)
        }else{
            if(c[1][0] == 'A'){
                print(x)
            }else{
                print(dp[n - 2][0])
            }
        }
    }
    
    return 0;
}