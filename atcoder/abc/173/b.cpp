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
    ll cnt[4]; memset(cnt, 0, sizeof(cnt));
    
    string s[4] = {"AC", "WA", "TLE", "RE"};
    zep(i, 0, n){
    	string t; cin >> t;
    	zep(j, 0, 4){
    		if(t == s[j])cnt[j]++;
    	}
    }
    
    zep(j, 0, 4){
    	cout << s[j] << " x " << cnt[j] << endl;
    }
    
    return 0;
}