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

        ll b[n];
        zep(i, 0, n){
            ll res = 1;

            while(a[i] > 2 * res)res *= 2;

            if(a[i] - res < 2 * res - a[i] || 2 * res > 1e9){
                b[i] = res;
            }else{
                b[i] = 2 * res;
            }
        }
        printa(b, 0, n - 1)
    }
    
    return 0;
}