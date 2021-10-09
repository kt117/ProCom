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
    vector<ll> v;
    while(n){
        v.push_back(n % 10);
        n /= 10;
    }

    sort(v.begin(), v.end(), greater<>());
    ll a = 0, b = 0;
    zep(i, 0, v.size()){
        if(a <= b){
            a *= 10;
            a += v[i];
        }else{
            b *= 10;
            b += v[i];
        }
    }
    print(a * b)

    return 0;
}