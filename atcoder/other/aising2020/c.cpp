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
    
    ll n; cin >> n;
    
    ll ans[n + 1]; memset(ans, 0, sizeof(ans));
    
    for(ll i = 2; i * i <= 2 *n; i++){
    	for(ll j = 2; j * j <= 2 * n; j++){
    		for(ll k = 2; k * k <= 2 * n; k++){
    			ll mn = min(i, min(j, k));
    			
    			ll x = i * i + j * j + k * k;
  
    			if((i + j + k) % 2 == 0 && x % 2 == 0 && x / 2 <= n){
    				if(i + j - k > 0 && i - j + k > 0 && - i + j + k > 0){
    					ans[x / 2]++;
    				}
    			}
    		}
    	}
    }
    
    rep(i, 1, n)print(ans[i])
    
    return 0;
}