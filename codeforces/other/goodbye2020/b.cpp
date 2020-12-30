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
        ll x[n]; zep(i, 0, n)cin >> x[i];

        ll ans = 0;
        ll b = INF;
        rrep(i, n - 1, 0){
            if(x[i] + 1 < b){
                ans++;
                b = x[i] + 1;
            }else if(x[i] + 1 == b){
                ans++;
                b = x[i];
            }
        }

        print(ans)
    }
    
    return 0;
}