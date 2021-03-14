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

vector<ll> X = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};
ll dp[80][1LL << 20]; 

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll a, b; cin >> a >> b;
    ll n = b - a + 1;
    
    dp[0][0] = 1;

    zep(i, 0, n){
        ll x = a + i;
        ll bit = 0;
        zep(j, 0, 20){
            if(x % X[j] == 0)bit |= (1LL << j);
        }

        zep(k, 0, (1LL << 20)){
            dp[i + 1][k] += dp[i][k];
        }

        zep(k, 0, (1LL << 20)){
            if((k & bit) == 0){
                dp[i + 1][(k | bit)] += dp[i][k];
            }
        }
    }

    ll ans = 0;
    zep(k, 0, (1LL << 20)){
        ans += dp[n][k];
    }
    print(ans)

    return 0;
}