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
            ll mnk = -1;
            ll mn = n * n;
            zep(k, 0, 3){
                ll cnt = 0;
                zep(i, 0, n){
                    zep(j, 0, n){
                        if((i + k) % 3 == j % 3 && s[i][j] == 'X')cnt++;
                    }
                }

                if(cnt < mn){
                    mn = cnt;
                    mnk = k;
                }
            }
            
            zep(i, 0, n){
                zep(j, 0, n){
                    if((i + mnk) % 3 == j % 3 && s[i][j] == 'X')s[i][j] = 'O';
                }
            }
        }

        zep(i, 0, n){
            print(s[i])
        }
    }
    
    return 0;
}