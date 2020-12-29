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
        string s; cin >> s;
        
        bool ans = false;
        rep(i, 0, 4){
            //print(s.substr(0, i))
            //print(s.substr(n - (4 - i), 4 - i))
            if(s.substr(0, i) + s.substr(n - (4 - i), 4 - i) == "2020")ans = true;
        }

        print(ans? "YES" : "NO")
    }
    
    return 0;
}