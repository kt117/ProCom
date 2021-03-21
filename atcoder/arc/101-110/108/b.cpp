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
    string s; cin >> s;
    
    stack<ll> st;
    ll ans = n;
    zep(i, 0, n){
        if(s[i] == 'f'){
            st.push(0);
        }else if(s[i] == 'o'){
            st.push(1);
        }else if(s[i] == 'x'){
            if(!st.empty() && st.top() == 1){
                st.pop();
                if(!st.empty() && st.top() == 0){
                    st.pop();
                    ans -= 3;
                }else{
                    st.push(1);
                    st.push(2);
                }
            }else{
                st.push(2);
            }
        }else{
            st.push(3);
        }
    }
    print(ans)

    return 0;
}