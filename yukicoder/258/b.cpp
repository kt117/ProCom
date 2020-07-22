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
    ll a[n]; zep(i, 0, n)cin >> a[i];
    ll b[n]; zep(i, 0, n)cin >> b[i];
    
    if(n == 2){
    	if(a[0] + a[1] == b[0] + b[1]){
    		print(abs(a[0] - b[0]))
    	}else{
    		print(-1)
    	}
    	return 0;
    }
    
    ll sm = 0;
    zep(i, 0, n){
    	sm += a[i] - b[i];
    }
    
    if(sm < 0 || sm % (n - 2) != 0){
    	print(-1) return 0;
    }
    
    ll x = sm / (n - 2);
    
    ll cnt = 0;
    zep(i, 0, n){
    	ll y = x - (a[i] - b[i]);
    	if(y % 2 != 0 || y < 0){print(-1) return 0;}
    	cnt += y / 2;
    }
    
    if(cnt == x){
    	print(x)
    }else{
    	print(-1)
    }
    
    return 0;
}