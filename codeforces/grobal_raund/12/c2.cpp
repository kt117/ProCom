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
        ll n; cin >> n;
        string s[n]; zep(i, 0, n)cin >> s[i];

        if(n >= 3){
            ll cnt[3][2]; memset(cnt, 0, sizeof(cnt));

            zep(k, 0, 3){
                zep(i, 0, n){
                    zep(j, 0, n){
                        if((i + k) % 3 == j % 3){
                            if(s[i][j] == 'X')cnt[k][0]++;
                            if(s[i][j] == 'O')cnt[k][1]++;
                        } 
                    }
                }
            }
            
            ll mn = INF;
            ll mnki, mnkj;
            zep(ki, 0, 3){
                zep(kj, 0, 3){
                    if(ki != kj && cnt[ki][0] + cnt[kj][1] < mn){
                        mn = cnt[ki][0] + cnt[kj][1];
                        mnki = ki;
                        mnkj = kj;
                    }
                }
            }

            zep(i, 0, n){
                zep(j, 0, n){
                    if((i + mnki) % 3 == j % 3 && s[i][j] == 'X')s[i][j] = 'O';
                    if((i + mnkj) % 3 == j % 3 && s[i][j] == 'O')s[i][j] = 'X';
                }
            }
        }

        zep(i, 0, n){
            print(s[i])
        }
    }
    
    return 0;
}