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

        if(n % 3 == 0){
            cout << n / 3 << " " << n / 3 << endl;
        }else if(n % 3 == 1){
            cout << n / 3 + 1 << " " << n / 3 << endl;
        }else{
            cout << n / 3 << " " << n / 3 + 1 << endl;
        }
    }
    
    return 0;
}