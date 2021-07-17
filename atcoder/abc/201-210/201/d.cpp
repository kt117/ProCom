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
    
    ll h, w; cin >> h >> w;
    string a[h]; zep(i, 0, h)cin >> a[i];
    if(h == 1 && w == 1){
        print("Draw") return 0;
    }

    ll dp[h][w];
    dp[h - 1][w - 1] = 0;
    if((h + w) % 2 == 0){
        if(a[h - 1][w - 1] == '+'){
            dp[h - 1][w - 1]--;
        }else{
            dp[h - 1][w - 1]++;
        }
    }else{
        if(a[h - 1][w - 1] == '+'){
            dp[h - 1][w - 1]++;
        }else{
            dp[h - 1][w - 1]--;
        }
    }
        
    
    rrep(i, h - 1, 0){
        rrep(j, w - 1, 0){
            if(i != h - 1 || j != w - 1){
                if(i == h - 1 && j != w - 1){
                    dp[i][j] = dp[i][j + 1];
                }else if(i != h - 1 && j == w - 1){
                    dp[i][j] = dp[i + 1][j];
                }else if(i != h - 1 && j != w - 1){
                    if((i + j) % 2 == 0){
                        if(dp[i + 1][j] > dp[i][j + 1]){
                            dp[i][j] = dp[i + 1][j];
                        }else{
                            dp[i][j] = dp[i][j + 1];
                        }
                    }else{
                        if(dp[i + 1][j] < dp[i][j + 1]){
                            dp[i][j] = dp[i + 1][j];
                        }else{
                            dp[i][j] = dp[i][j + 1];
                        }
                    }
                }

                if(i != 0 || j != 0){
                    if((i + j) % 2 == 0){
                        if(a[i][j] == '+'){
                            dp[i][j]--;
                        }else{
                            dp[i][j]++;
                        }
                    }else{
                        if(a[i][j] == '+'){
                            dp[i][j]++;
                        }else{
                            dp[i][j]--;
                        }
                    }
                }
            }
        }
    }

    if(dp[0][0] > 0){
        print("Takahashi")
    }else if(dp[0][0] < 0){
        print("Aoki")
    }else{
        print("Draw")
    }

    return 0;
}