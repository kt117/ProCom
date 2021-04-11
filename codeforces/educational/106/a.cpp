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
        ll n, k1, k2; cin >> n >> k1 >> k2;
        ll w, b; cin >> w >> b;

        w -= abs(k1 - k2) / 2;
        b -= abs(k1 - k2) / 2;
        w -= min(k1, k2);
        b -= n - max(k1, k2);

        if(w <= 0 && b <= 0){
            print("YES")
        }else{
            print("NO")
        }
    }
    
    return 0;
}