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
        ll a, b, c; cin >> a >> b >> c;

        ll g = 1;
        while(g < pow(10, c - 1))g *= 2;
        ll x = g, y = g;
        while(x < pow(10, a - 1))x *= 3;
        while(y < pow(10, b - 1))y *= 5;

        cout << x << " " << y << endl;
    }
    
    return 0;
}