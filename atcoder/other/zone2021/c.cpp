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

ll n, a[3030][5];
bool dp[3030][(1LL << 5)][4];

bool f(ll mid){
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = true;

    zep(i, 0, n){
        ll bit = 0;
        zep(j, 0, 5)if(a[i][j] >= mid)bit |= (1LL << j);
        
        zep(b, 0, (1LL << 5)){
            zep(j, 0, 4){
                if(dp[i][b][j]){
                    dp[i + 1][b][j] = true;
                }
            }

            zep(j, 0, 3){
                if(dp[i][b][j]){
                    dp[i + 1][b | bit][j + 1] = true;
                }
            }
        }
    }

    return dp[n][(1LL << 5) - 1][3];
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n;
    zep(i, 0, n)zep(j, 0, 5)cin >> a[i][j];

    ll ok = 1;
    ll ng = 1e9 + 1;

    while(ng - ok > 1){
        ll mid = (ok + ng) / 2;

        if(f(mid)){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    print(ok)
    
    return 0;
}