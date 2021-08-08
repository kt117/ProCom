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
    ll c[n]; zep(i, 0, n)cin >> c[i];

    map<ll, ll> mp;
    zep(i, 0, k){
        if(mp.find(c[i]) == mp.end())mp[c[i]] = 0;
        mp[c[i]]++;
    }

    ll ans = mp.size();
    zep(i, k, n){
        if(mp.find(c[i]) == mp.end())mp[c[i]] = 0;
        mp[c[i]]++;

        mp[c[i - k]]--;
        if(mp[c[i - k]] == 0)mp.erase(c[i - k]);

        ll x = mp.size();
        ans = max(ans, x);
    }
    print(ans)
    
    return 0;
}