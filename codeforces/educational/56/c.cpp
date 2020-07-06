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
	ll b[n / 2]; zep(i, 0, n / 2)cin >> b[i];
	
	ll a[n];
	a[0] = 0;
	a[n - 1] = b[0];

	zep(i, 1, n / 2){
		if(b[i] - a[n - 1 - (i - 1)] >= a[i - 1]){
			a[n - 1 - i] = a[n - 1 - (i - 1)];
			a[i] = b[i] - a[n - 1 - i];
		}else{
			a[i] = a[i - 1];
			a[n - 1 - i] = b[i] - a[i];
		}
	}

	printa(a, 0, n - 1)

	return 0;
}