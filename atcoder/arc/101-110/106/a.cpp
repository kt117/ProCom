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
    
    ll n; cin >> n;
    ll b = 0;
    ll pb = 1;
    while((n - 3) / 5 >= pb){
        b++;
        pb *= 5;

        ll a = 0;
        ll pa = 1;
        while(pa <= (n - pb) / 3){
            a++;
            pa *= 3;
        }

        if(pa + pb == n){
            cout << a << " " << b << endl;
            return 0;
        }
        //cout << a << " " << b << endl;
        //cout << pa << " " << pb << endl;
    }
    print(-1)
    
    return 0;
}