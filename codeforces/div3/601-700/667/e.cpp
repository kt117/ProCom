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
        ll n, k; cin >> n >> k;
        ll x[n]; zep(i, 0, n)cin >> x[i];
        ll y[n]; zep(i, 0, n)cin >> y[i];

        sort(x, x + n);

        ll l = 0, cnt = 0, mx[n];
        zep(r, 0, n){
            cnt++;

            while(x[l] < x[r] - k){
                l++;
                cnt--;
            }
            
            mx[r] = cnt;
        }
        
        l = 0;
        ll ans = 0, maxl = 0;
        zep(r, 0, n){
            while(x[l] < x[r] - k){
                maxl = max(maxl, mx[l]);
                l++;
            }

            ans = max(ans, maxl + mx[r]);
        }

        print(ans)
    }
    
    return 0;
}