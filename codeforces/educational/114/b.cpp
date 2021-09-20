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
        ll a, b, c, m; cin >> a >> b >> c >> m;
        if(a < b){ll tmp = a; a = b; b = tmp;}
        if(a < c){ll tmp = a; a = c; c = tmp;}

        if(m > a + b + c - 3){print("NO") continue;}
        if(m < a - b - c - 1){print("NO") continue;}
        print("YES")
    }

    return 0;
}