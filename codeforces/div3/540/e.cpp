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
    
    ll n, k; cin >> n >> k;

    if(k * k - k < n){
        print("NO")
    }else{
        print("YES")

        vector<P> ans;
        zep(i, 1, k){
            zep(j, 0, k){
                ans.push_back(P((i + j) % k, j));
                if(ans.size() >= n){
                    zep(x, 0, n){
                        cout << ans[x].first + 1 << " " << ans[x].second + 1 << endl; 
                    }
                    return 0;
                }
            }
        }
    }
    
    return 0;
}