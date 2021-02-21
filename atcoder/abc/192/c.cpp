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

ll f(ll x){
    vector<ll> u, v;
    while(x){
        u.push_back(x % 10);
        v.push_back(x % 10);
        x /= 10;
    }

    sort(u.begin(), u.end(), greater<>());
    sort(v.begin(), v.end());

    ll y = 0;
    zep(i, 0, u.size()){
        y *= 10;
        y += u[i] - v[i];
    }
    return y;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n, k; cin >> n >> k;

    ll a = n;
    zep(i, 0, k){
        a = f(a);
    }
    print(a)

    return 0;
}