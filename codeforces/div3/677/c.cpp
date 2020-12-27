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

        bool same = true;
        zep(i, 0, n)if(a[i] != a[0])same = false;

        if(same){
            print(-1)
        }else{
            ll mx = 0;
            zep(i, 0, n)mx = max(mx, a[i]);

            zep(i, 0, n){
                if(a[i] == mx && ((i > 0 && a[i] > a[i - 1]) || (i <= n - 1 && a[i] > a[i + 1]))){
                    print(i + 1)
                    break;
                }
            }
        }
    }
    
    return 0;
}