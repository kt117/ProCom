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
    
    ll a, b; cin >> a >> b;
    
    if(a > b){
        ll sm = 0;
        rep(i, 1, a){
            cout << i << " ";
            sm += i;
        }
        rep(i, 1, b - 1){
            cout << -i << " ";
            sm += -i;
        }
        cout << -sm << endl;
    }else{
        ll sm = 0;
        rep(i, 1, b){
            cout << -i << " ";
            sm += -i;
        }
        rep(i, 1, a - 1){
            cout << i << " ";
            sm += i;
        }
        cout << -sm << endl;
    }
    
    return 0;
}