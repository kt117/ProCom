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
    
    ll n, k; cin >> n >> k;
    ll a[n]; zep(i, 0, n)cin >> a[i];
    zep(i, 1, n)a[i] += a[i - 1];

    map<ll, ll> mp; mp[0] = 1;
    ll ans = 0;
    zep(i, 0, n){
        // cout << a[i] << " " << k - a[i] << endl;
        if(mp.find(a[i] - k) != mp.end())ans += mp[a[i] - k];

        if(mp.find(a[i]) == mp.end())mp[a[i]] = 0;
        mp[a[i]]++;
    }
    print(ans)
    
    return 0;
}