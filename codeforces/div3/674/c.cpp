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

        ll ok = n;
        ll ng = -1;
        while(ok - ng > 1){
            ll mid = (ok + ng) / 2;

            if((mid / 2 + 1) * (mid - mid / 2 + 1) >= n){
                ok = mid;
            }else{
                ng = mid;
            }
        }
        print(ok)
    }
    
    return 0;
}