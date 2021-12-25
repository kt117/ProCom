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

ll n, x, a[100];

map<ll, ll> memo;

ll f(ll y, ll i){
    if(memo.find(y) != memo.end()){
        return memo[y];
    }else if(i == n - 1){
        return memo[y] = y / a[i];
    }else{
        ll r = y % a[i + 1]; 
        return memo[y] = min(
            f(y - r, i + 1) + r / a[i],
            f(y + a[i + 1] - r, i + 1) + (a[i + 1] - r) / a[i]
        );
    }
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n >> x;
    zep(i, 0, n)cin >> a[i];
    
    print(f(x, 0))
    
    return 0;
}