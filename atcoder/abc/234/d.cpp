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
    ll p[n]; zep(i, 0, n)cin >> p[i];

    // priority_queue<ll> q;
    priority_queue<ll, vector<ll>, greater<ll>> q;
    
    zep(i, 0, n){
        q.push(p[i]);
        
        if(q.size() > k)q.pop();
        if(q.size() == k)print(q.top())
    }

    return 0;
}