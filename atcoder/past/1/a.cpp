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
    
    string s; cin >> s;
    bool ans = true;
    zep(i, 0, s.size()){
        if('a' <= s[i] && s[i] <= 'z')ans = false;
    }

    if(ans){
        ll res = 0;
        zep(i, 0, s.size()){
            res *= 10;
            res += s[i] - '0';
        }
        print(2 * res)
    }else{
        print("error")
    }
    
    return 0;
}