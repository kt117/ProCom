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
    vector<string> ans;

    ll cnt = 0;
    ll b = 0;
    zep(i, 0, s.size()){
        if('A' <= s[i] && s[i] <= 'Z'){
            cnt++;
            s[i] = char(s[i] - 'A' + 'a');

            if(cnt % 2 == 0){
                ans.push_back(s.substr(b, i - b + 1));
            }else{
                b = i;
            }
        }
    }
    sort(ans.begin(), ans.end());
    
    zep(i, 0, ans.size()){
        ans[i][0] = char(ans[i][0] - 'a' + 'A');
        ans[i][ans[i].size() - 1] = char(ans[i][ans[i].size() - 1] - 'a' + 'A');
        cout << ans[i];
    }
    cout << endl;

    return 0;
}