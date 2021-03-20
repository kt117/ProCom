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
    
    ll h, w, a, b; cin >> h >> w >> a >> b;

    ll dp[h * w + 10][(1LL << w)][a + 1][b + 1]; memset(dp, 0, sizeof(dp));
    dp[0][0][0][0] = 1;

    zep(i, 0, h * w){
        ll hh = i / w;
        ll ww = i % w;
        //cout << hh << ww << endl;
        //cout << "i " << i << endl;
        zep(bit, 0, (1LL << w)){
            //cout << "bit " << bit << endl;
            //rep(j, 0, b)cout << dp[i][bit][j] << " "; cout << endl;

            if(bit & (1LL << ww)){
                rep(j, 0, a){
                    rep(k, 0, b){//none
                        dp[i + 1][bit - (1LL << ww)][j][k] += dp[i][bit][j][k];
                    }
                }
            }else{
                rep(j, 0, a){
                    zep(k, 0, b){//one
                        dp[i + 1][bit][j][k + 1] += dp[i][bit][j][k];
                    }
                }

                zep(j, 0, a){
                    rep(k, 0, b){//tate
                        dp[i + 1][bit | (1LL << ww)][j + 1][k] += dp[i][bit][j][k];
                    }
                }

                if((ww < w - 1) && ~(bit & (1LL << (ww + 1)))){//yoko
                    zep(j, 0, a){
                        rep(k, 0, b){
                            dp[i + 1][bit | (1LL << (ww + 1))][j + 1][k] += dp[i][bit][j][k];
                        }
                    }
                }
            }
        }
        //print(" ")
    }

    print(dp[h * w][0][a][b])
    
    return 0;
}