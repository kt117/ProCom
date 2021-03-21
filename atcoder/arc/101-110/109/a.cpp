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
    
    ll a, b, x, y;
    cin >> a >> b >> x >> y;

    if(a > b){
        if(2 * x < y){
            print(x + 2 * x * (a - b - 1))
        }else{
            print(x + y * (a - b - 1))
        }
    }else if(a == b){
        print(x)
    }else{
        if(2 * x < y){
            print(x + 2 * x * (b - a))
        }else{
            print(x + y * (b - a))
        }
    }
    
    return 0;
}