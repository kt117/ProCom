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
    
    ll n, m, T; cin >> n >> m >> T;
    ll a[m], b[m]; zep(i, 0, m)cin >> a[i] >> b[i];

    ll bt = n;
    ll t = 0;
    zep(i, 0, m){
        if(a[i] - t >= bt){print("No") return 0;}

        bt -= a[i] - t;
        bt += b[i] - a[i];
        bt = min(bt, n);
        t = b[i];
    }
    print((T - t >= bt)? "No" : "Yes")
    
    return 0;
}