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
        ll n, s; cin >> n >> s;

        vector<ll> v;
        while(n){
            v.push_back(n % 10);
            n /= 10;
        }
        v.push_back(0);

        ll sm = 0;
        zep(i, 0, v.size())sm += v[i];

        ll ans = 0;
        ll at = 0;
        ll p = 1;
        while(sm > s){
            if(v[at] > 0){
                ans += (10 - v[at]) * p; 
                sm -= v[at]; sm++;
                v[at + 1]++;
            }
            at++;
            p *= 10;
        }
        
        print(ans)
    }
    
    return 0;
}