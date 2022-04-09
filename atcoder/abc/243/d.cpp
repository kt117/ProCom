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
    
    ll n, x; cin >> n >> x;
    string s; cin >> s;

    vector<ll> v;
    zep(i, 0, n){
        if(s[i] == 'U'){
            if(v.empty()){
                x /= 2;
            }else{
                v.pop_back();
            }
        }else if(s[i] == 'L'){
            v.push_back(0);
        }else{
            v.push_back(1);
        }
    }

    zep(i, 0, v.size()){
        x *= 2;
        if(v[i] == 1)x++;
    }
    print(x)
    
    return 0;
}