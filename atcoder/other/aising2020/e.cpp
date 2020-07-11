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
    	ll k[n], l[n], r[n]; zep(i, 0, n)cin >> k[i] >> l[i] >> r[i];
    	
    	ll ans = 0, rb = n;
    	
    	map<ll, vector<ll>> mpr;
    	zep(i, 0, n){
    		if(l[i] < r[i]){
    			if(mpr.find(k[i]) == mpr.end())mpr[k[i]] = {};
    			mpr[k[i]].push_back(i);
    		}
    	}
 
		priority_queue<P> q;
		rep(i, 1, n){
			if(mpr.find(i - 1) != mpr.end()){
				auto v = mpr[i - 1];
				zep(j, 0, v.size())q.push(P(r[v[j]] - l[v[j]], v[j]));
			}
			
			if(!q.empty()){
    			ans += r[q.top().second];
    			q.pop();
    			rb--;
    		}
		}
		
		if(mpr.find(n) != mpr.end()){
			auto v = mpr[n];
			zep(j, 0, v.size())q.push(P(r[v[j]] - l[v[j]], v[j]));
		}
		
		while(!q.empty()){
    		ans += l[q.top().second];
    		q.pop();
    	}
 
    	map<ll, vector<ll>> mpl;
    	zep(i, 0, n){
    		if(l[i] > r[i]){
    			if(mpl.find(k[i]) == mpl.end())mpl[k[i]] = {};
    			mpl[k[i]].push_back(i);
    		}
    	}
    	
    	rrep(i, n, rb + 1){
    		if(mpl.find(i) != mpl.end()){
				auto v = mpl[i];
				zep(j, 0, v.size()){
					q.push(P(l[v[j]] - r[v[j]], v[j]));	
				}
			}
    	}
    	
    	rrep(i, rb, 1){
    		if(mpl.find(i) != mpl.end()){
				auto v = mpl[i];
				zep(j, 0, v.size()){
					q.push(P(l[v[j]] - r[v[j]], v[j]));	
				}
			}
    		
    		if(!q.empty()){
    			ans += l[q.top().second];
    			q.pop();
    		}
    	}
    	
    	while(!q.empty()){
    		ans += r[q.top().second];
    		q.pop();
    	}
    	
    	zep(i, 0, n)if(l[i] == r[i])ans += l[i];
    	
    	print(ans)
    }
    
    return 0;
}