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

ll n, x, a[50]; 
map<P, ll> mp;

ll f(ll xx, ll i){
    if(i == n - 1)return 1;
    if(mp.find(P(xx, i)) != mp.end())return mp[P(xx, i)];

    ll res = 0;
    if(xx % a[i + 1] == 0){
        res += f(xx, i + 1);
    }else{
        res += f(xx - xx % a[i + 1], i + 1);
        res += f(xx - xx % a[i + 1] + a[i + 1], i + 1);
    }
    
    return mp[P(xx, i)] = res;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n >> x;
    zep(i, 0, n)cin >> a[i];

    print(f(x, 0))
    
    return 0;
}