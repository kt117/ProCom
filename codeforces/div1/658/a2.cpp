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
        ll n; cin >> n;
        string a, b; cin >> a >> b;

        vector<ll> ans;
        bool turn = false;
        ll l = 0, r = n - 1;

        rrep(i, n - 1, 0){
            if(!turn){
                if(a[r] != b[i]){
                    if(a[l] == b[i]){
                        ans.push_back(0);
                    }

                    ans.push_back(i);
                    l++;
                    turn = !turn;
                }else{
                    r--;
                }
            }else{
                if(a[l] == b[i]){
                    if(a[r] != b[i]){
                        ans.push_back(0);
                    }

                    ans.push_back(i);
                    r--;
                    turn = !turn;
                }else{
                    l++;
                }
            }
        }

        cout << ans.size() << " ";
        zep(i, 0, ans.size())cout << ans[i] + 1 << " "; cout << endl;
    }
    
    return 0;
}