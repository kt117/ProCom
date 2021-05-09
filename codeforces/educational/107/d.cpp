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

    vector<ll> v;
    zep(i, 0, k){
        v.push_back(i);
        zep(j, i + 1, k){
            v.push_back(i);
            v.push_back(j);
        }
    }
    ll m = v.size();
    zep(i, 0, n / m){
        zep(j, 0, m)cout << char('a' + v[j]);
    }
    zep(j, 0, n % m)cout << char('a' + v[j]);
    cout << endl;
    
    return 0;
}