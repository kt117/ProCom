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

    vector<ll> v;
    v.push_back(0);
    zep(i, 0, n){
        v.push_back((v.back() + a[i]) % 360);
    }
    v.push_back(360);
    sort(v.begin(), v.end());
    ll ans = 0;
    zep(i, 1, v.size()){
        ans = max(ans, v[i] - v[i - 1]);
    }
    print(ans)
    
    return 0;
}