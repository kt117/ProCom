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
    ll a[n], b[n]; zep(i, 0, n)cin >> a[i] >> b[i];

    ll ao = 0;
    zep(i, 0, n)ao += a[i];

    vector<P> v;
    zep(i, 0, n)v.push_back(P(2 * a[i] + b[i], i));
    sort(v.begin(), v.end(), greater<>());

    ll tk = 0;
    ll at = 0;
    while(tk <= ao){
        ao -= a[v[at].second];
        tk += a[v[at].second] + b[v[at].second];
        at++;
    }
    print(at)

    return 0;
}