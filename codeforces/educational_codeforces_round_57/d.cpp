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
    string s; cin >> s;
    ll a[n]; zep(i, 0, n)cin >> a[i];

    ll dp[n + 1][5]; memset(dp, 0, sizeof(dp));
    //zep(j, 0, 5)dp[0][j] = 0;

    string h = "hard";
    zep(i, 0, n){
        bool ok = false;
        zep(k, 0, 4){
            if(s[i] == h[k]){
                zep(j, 0, 4){
                    if(j != k){
                        dp[i + 1][j] = dp[i][j];
                    }else{
                        dp[i + 1][j] = dp[i][j] + a[i];
                    }
                }
                dp[i + 1][k + 1] = min(dp[i + 1][k + 1], dp[i][k]);
                
                ok = true;
                break;
            }
        }

        if(!ok){
            zep(j, 0, 4){    
                dp[i + 1][j] = dp[i][j];
            }
        }
    }

    ll ans = INF;
    zep(k, 0, 4){
        ans = min(ans, dp[n][k]);
    }
    print(ans)

    return 0;
}