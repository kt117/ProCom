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
        if(n == 1){print(0) continue;}

        map<ll, ll> mp;
        zep(i, 0, n){
            if(mp.find(a[i]) == mp.end())mp[a[i]] = 0;
            mp[a[i]]++;
        }

        vector<ll> v;
        for(auto it = mp.begin(); it != mp.end(); it++){
            v.push_back((*it).second);
        }
        sort(v.begin(), v.end());
        //printa(v, 0, v.size() - 1)
        ll m = v.size();
        ll b[m];
        b[0] = v[0];
        zep(i, 1, m)b[i] = b[i - 1] + v[i];
        //printa(b, 0, m - 1)
        ll c[m];
        c[m - 1] = 0;
        rrep(i, m - 2, 0){
            c[i] = c[i + 1] + (m - i - 1) * (v[i + 1] - v[i]);
        }
        //printa(c, 0, m - 1)
        ll ans = min(b[m - 1], c[0]);
        zep(i, 1, m){
            ans = min(ans, b[i - 1] + c[i]);
        }
        print(ans)
    }
    
    return 0;
}