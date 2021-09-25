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
    ll a[k]; zep(i, 0, k)cin >> a[i];

    queue<ll> u, v;
    ll at = 0;
    rep(i, 1, n){
        if(at < k && a[at] == i){
            u.push(i);
            at++;
        }else{
            v.push(i);
        }
    }

    vector<ll> ans;
    while(u.size() > 1){
        ans.push_back(u.front());
        if(!v.empty() && v.front() < u.front()){
            ans.push_back(v.front());
            v.pop();
        }
        u.pop();
    }

    vector<ll> tmp;
    while(!u.empty()){tmp.push_back(u.front()); u.pop();}
    while(!v.empty()){tmp.push_back(v.front()); v.pop();}
    sort(tmp.begin(), tmp.end(), greater<>());
    zep(i, 0, tmp.size())ans.push_back(tmp[i]);

    printa(ans, 0, n - 1)

    return 0;
}