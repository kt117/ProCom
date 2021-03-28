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
        ll x; cin >> x;

        ll ans = INF;
        zep(bit, 0, (1LL << 9)){
            ll sm = 0;
            zep(j, 0, 9){
                if(bit & (1LL << j)){
                    sm += j + 1;
                }
            }

            if(sm == x){
                ll tmp = 0;
                zep(j, 0, 9){
                    if(bit & (1LL << j)){
                        tmp *= 10;
                        tmp += j + 1;
                    }
                }
                ans = min(ans, tmp);
            }
        }

        print((ans == INF)? -1 : ans)
    }
    
    return 0;
}