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
        string a; cin >> a;

        map<ll, ll> mp;
        mp[0] = 1;

        ll ans = 0;
        ll sm = 0;
        zep(i, 0, a.size()){
            sm += a[i] - '0';

            if(mp.find(sm - (i + 1)) != mp.end()){
                ans += mp[sm - (i + 1)];
            }else{
                mp[sm - (i + 1)] = 0;
            }

            mp[sm - (i + 1)]++;
        }

        print(ans)
    }
    
    return 0;
}