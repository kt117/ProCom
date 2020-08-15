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
    ll l[n]; zep(i, 0, n)cin >> l[i];
    sort(l, l + n);
    
    ll ans = 0;
    zep(i, 0, n){
    	zep(j, 0, i){
    		zep(k, 0, j){
    			if(l[i] != l[j] && l[j] != l[k] && l[i] < l[j] + l[k])ans++;	
    		}
    	}
    }
    print(ans)
    
    return 0;
}
