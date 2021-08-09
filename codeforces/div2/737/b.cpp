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
        ll n, k; cin >> n >> k;
        ll a[n]; zep(i, 0, n)cin >> a[i];

        vector<P> v;
        zep(i, 0, n)v.push_back(P(a[i], i));
        sort(v.begin(), v.end());

        ll cnt = 0;
        zep(i, 1, n){
            if(v[i].second != v[i - 1].second + 1)cnt++;
        }

        print((cnt + 1 <= k)? "YES" : "NO")
    }
    
    return 0;
}