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
    ll a[n], b[n]; zep(i, 0, n)cin >> a[i] >> b[i];

    vector<P> v;
    zep(i, 0, n)v.push_back(P(a[i], b[i]));
    sort(v.begin(), v.end(), greater<>());

    ll x = 0;
    while(k > 0){
        x += k;
        k = 0;
        while(!v.empty() && v.back().first <= x){
            k += v.back().second;
            v.pop_back();
        }
    }
    print(x)
    
    return 0;
}