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

ll n, m, dp[1LL << 20];
bool e[20][20];

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n >> m;

    zep(i, 0, m){
        ll a, b; cin >> a >> b; a--; b--;
        e[a][b] = true;
        e[b][a] = true;
    }
    
    zep(bit, 0, (1LL << n)){
        dp[bit] = 1;
        zep(i, 0, n){    
            zep(j, i + 1, n){
                if((bit & (1LL << i)) && (bit & (1LL << j))){
                    if(!e[i][j])dp[bit] = INF;
                }
            }
        }
    } 

    zep(bit, 0, (1LL << n)){
        for(ll i = (1 << n) - 1; i >= 0; i--){
            i &= bit;
            dp[bit] = min(dp[bit | i], dp[i] + dp[bit ^ i]);
        }
    }

    print(dp[(1LL << n) - 1])

    return 0;
}