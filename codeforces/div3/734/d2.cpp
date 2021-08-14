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
    
    ll t; cin >> t;
    while(t--){
        ll n, m, k; cin >> n >> m >> k;

        if(k <= m / 2 * n && k >= (n % 2) * (m / 2) && k % 2 == (n % 2) * (m / 2) % 2){
            print("YES")

            char ans[n][m];
            zep(i, 0, n){
                zep(j, 0, m){
                    if((i % 4 <= 1 && j % 2 == 0) || (i % 4 > 1 && j % 2 == 1)){
                        ans[i][j] = 'a';
                    }else{
                        ans[i][j] = 'b';
                    }
                }
            }

            if(n % 2 == 1){
                zep(j, 0, m){
                    if(j % 4 <= 1){
                        ans[n - 1][j] = 'x';
                    }else{
                        ans[n - 1][j] = 'y';
                    }
                }
                k -= m / 2;
            }
            

            zep(i, 0, n / 2){
                zep(j, 0, m / 2){
                    if(k > 0){
                        if(j % 2 == 0){
                            ans[2 * i][2 * j] = 'w';
                            ans[2 * i][2 * j + 1] = 'w';
                            ans[2 * i + 1][2 * j] = 'z';
                            ans[2 * i + 1][2 * j + 1] = 'z';
                        }else{
                            ans[2 * i][2 * j] = 'z';
                            ans[2 * i][2 * j + 1] = 'z';
                            ans[2 * i + 1][2 * j] = 'w';
                            ans[2 * i + 1][2 * j + 1] = 'w';
                        }
                        k -= 2;
                    }
                }
            }

            zep(i, 0, n){
                zep(j, 0, m){
                    cout << ans[i][j];
                }
                cout << endl;
            }
        }else{
            print("NO")
        }
    }
    
    return 0;
}