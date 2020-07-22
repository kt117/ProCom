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
    
    ll q; cin >> q;
    while(q--){
        ll n, m, k; cin >> n >> m >> k;

        if(max(n, m) > k){
            print(-1) continue;
        }

        ll ans = 0;
        ll mn = min(n, m);
        ans += mn;
        k -= mn;
        ll r = max(n, m) - mn;
          
        if(k % 2 == 0){
            if(r % 2 == 0){
                ans += k;
            }else{
                ans += k - 1;
            }
        }else{
            if(r % 2 == 0){
                ans += k - 2;
            }else{
                ans += k - 1;
            }
        }

        print(ans)
    }
    
    return 0;
}