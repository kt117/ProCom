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

    map<ll, ll> mp;
    mp[0] = 1;
    ll ans = 0, buf = 0;
    zep(i, 0, n){
        if(i % 2){
            buf += a[i];
        }else{
            buf -= a[i];
        }

        if(mp.find(buf) != mp.end()){
            ans += mp[buf];
        }else{
            mp[buf] = 0;
        }
        mp[buf]++;
    }
    print(ans)
    
    return 0;
}