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

        vector<ll> v;
        for(ll i = 1; i * i * i <= n; i++){
            v.push_back(i * i * i);
        }

        bool ans = false;
        for(ll i = 1; i * i * i <= n; i++){
            while(!v.empty() && i * i * i + v.back() > n)v.pop_back();
            if(!v.empty() && i * i * i + v.back() == n){
                ans = true;
                break;
            }
        }
        print(ans? "YES" : "NO")
    }
    
    return 0;
}