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
    
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        ll a[n]; zep(i, 0, n)cin >> a[i];

        map<ll, ll> mp;
        zep(i, 0, n){
            if(mp.find(a[i]) == mp.end()){
                mp[a[i]] = 0;
            }
            mp[a[i]]++;
        }

        ll mx = 0;
        for(auto it = mp.begin(); it != mp.end(); it++){
            mx = max(mx, (*it).second);
        }

        if(mx <= n / 2){
            print(n - 2 * (n / 2))
        }else{
            print(mx - (n - mx))
        }
    }
    
    return 0;
}