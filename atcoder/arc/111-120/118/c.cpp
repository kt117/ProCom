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
    
    
    vector<ll> ok;
    rep(i, 1, 10000){
        if(i % 6 == 0 || i % 10 == 0 || i % 15 == 0)ok.push_back(i);
    }
    //print(ok.size())
    ll n; cin >> n;
    if(n == 3){
        cout << 6 << " " << 10 << " " << 15 << endl;
    }else{
        zep(i, 0, n)cout << ok[i] << " "; cout << endl;
    }

    return 0;
}