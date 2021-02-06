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

double dp[110][110][110];

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    rep(i, 0, 100)rep(j, 0, 100)rep(k, 0, 100)dp[i][j][k] = 0;

    ll a, b, c; cin >> a >> b >> c;
    dp[a][b][c] = 1;
    
    zep(i, 0, 100){
        zep(j, 0, 100){
            zep(k, 0, 100){
                if(i + j + k > 0){
                    dp[i + 1][j][k] += (double(i)) / (i + j + k) * dp[i][j][k];
                    dp[i][j + 1][k] += (double(j)) / (i + j + k) * dp[i][j][k];
                    dp[i][j][k + 1] += (double(k)) / (i + j + k) * dp[i][j][k];
                }
            }
        }
    }

    double ans = 0;
    zep(i, a, 100){
        zep(j, b, 100){
            ans += ((i - a) + (j - b) + (100 - c)) * dp[i][j][100];
        }
    }

    zep(j, b, 100){
        zep(k, c, 100){
            ans += ((100 - a) + (j - b) + (k - c)) * dp[100][j][k];
        }
    }

    zep(k, c, 100){
        zep(i, a, 100){
            ans += ((i - a) + (100 - b) + (k - c)) * dp[i][100][k];
        }
    }

    cout << fixed << setprecision(20) << ans << endl;

    return 0;
}