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
    
    string x; cin >> x;
    ll n = x.size();
    vector<ll> v(n); zep(i, 0, n)v[i] = x[i] - '0';
    zep(i, 1, n)v[i] += v[i - 1];
    reverse(v.begin(), v.end());

    zep(i, 0, n - 1){
        v[i + 1] += v[i] / 10;
        v[i] %= 10;    
    }

    // cout << v[n - 1];
    rrep(i, n - 1, 0)cout << v[i];
    cout << endl;

    return 0;
}