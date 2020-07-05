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
    
    ll h, w, k; cin >> h >> w >> k;
    string c[h]; zep(i, 0, h)cin >> c[i];
    
    ll ans = 0;
    zep(i, 0, (1LL << h)){
    	zep(j, 0, (1LL << w)){
    		ll cnt = 0;
    		
    		zep(ii, 0, h){
    			zep(jj, 0, w){
    				if(c[ii][jj] == '#' && (i & (1LL << ii)) && (j & (1LL << jj))){
    					cnt++;
    				}
    			}
    		}
    		
    		if(cnt == k)ans++;
    	}
    }
    
    print(ans)
    
    return 0;
}