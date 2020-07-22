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
    ll x[n], y[n]; zep(i, 0, n)cin >> x[i] >> y[i];
    
    vector<ll> v[10][10][2];
    zep(i, 0, n){
    	ll p = (x[i] / 9 + y[i] / 5) % 2;
    	v[x[i] % 9][y[i] % 5][p].push_back(i + 1);
    	
    }
    
    ll mx = 0, mi = -1, mj = -1, mk = -1;
    zep(i, 0, 9){
    	zep(j, 0, 5){
    		zep(k, 0, 2){
				if(v[i][j][k].size() > mx){
					mx = v[i][j][k].size();
					mi = i;
					mj = j;
					mk = k;
				}
    		}
    	}
    }
    
    print(mx)
    zep(i, 0, mx)cout << v[mi][mj][mk][i] << " "; cout << endl;
    
    return 0;
}