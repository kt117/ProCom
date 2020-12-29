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
        ll a[n]; zep(i, 0, n)cin >> a[i];

        ll ans = 1;
        rep(i, 1, n){
            ll sm = 0; zep(j, 0, i)sm += a[j];
            
            bool ok = true;
            ll cnt = 0;
            ll buf = 0;
            zep(j, 0, n){
                buf += a[j];

                if(buf == sm){
                    cnt++;
                    buf = 0;
                }

                if(buf > sm){
                    ok = false;
                    break;
                }
            }

            if(buf == 0 && ok){
                ans = cnt;
                break;
            }
        }

        print(n - ans)
    }
    
    return 0;
}