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
    ll a[n]; zep(i, 0, n)cin >> a[i];

    vector<P> v;
    zep(i, 0, n){
        if(v.empty()){
            v.push_back(P(a[i], 1));
        }else{
            if(a[i] != v.back().first){
                v.push_back(P(a[i], 1));
            }else{
                if(a[i] == v.back().second + 1){
                    while(!v.empty() && v.back().first == a[i])v.pop_back();
                }else{
                    v.push_back(P(a[i], v.back().second + 1));
                }
            }
        }

        print(v.size())
    }
    
    return 0;
}