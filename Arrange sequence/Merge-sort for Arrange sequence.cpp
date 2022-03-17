				//USING MERGE_SORT FOR ARRANGE SEQUENCE//

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define faster()                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(0)
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define FORI(i, a) for (vector<ll>::iterator i = a.begin(); i != a.end(); ++i)
#define FORR(i, a, b) for (vector<ll>::iterator i = a; i <= b; ++i)
#define FORS(i, a, b) for(set<vector<ll>>::iterator i=a;i<=b;++i)
#define FORD(i,a,b,d) for(ll i=a;i<b;i+=d)
#define vll vector<ll>
#define vi vector<int>
#define vvll vector<vector<ll>>
#define vvi vector<vector<int>>
#define vs vector<string>
#define sll set<ll>
#define msll multiset<ll>
#define svll set<vector<ll>>
#define svi set<vector<int>>
#define Test() \
	ll t;      \
	cin >> t;  \
	while (t--)
#define pb push_back
#define po pop_back
#define rs resize
#define ins insert
#define del erase
const ll m = 1e9 + 7;
void merge(vll &a, ll l, ll m, ll r){
	vll res;
	ll i=l;
	ll j=m+1;
	while(i<=m && j<=r){
		if(a[i]<a[j]){
			res.pb(a[i]);
			++i;
		}
		else{
			res.pb(a[j]);
			++j;
		}
	}
	while(i<=m){
		res.pb(a[i]);
		++i;
	}
	while(j<=r){
		res.pb(a[j]);
		++j;
	}
	ll d=0;
	FOR(i,l,r+1){
		a[i]=res[d];
		++d;
	}
}
void merge_sort(vll &a, ll l, ll r){
	if(l>=r)
		return;
	ll m=(l+r)/2;
	merge_sort(a,l,m);
	merge_sort(a,m+1,r);
	merge(a,l,m,r);
}
int main(){
	faster();
	#ifndef ONLINE_JUDGE
		freopen("input_II.txt","r",stdin);
		freopen("output_II.txt","w",stdout);
	#endif
	ll n;
	cin>>n;
	vll a;
	FOR(i,0,n){
		ll x;
		cin>>x;
		a.pb(x);
	}
	merge_sort(a,0,n-1);
	FOR(i,0,n)
		cout<<a[i]<<" ";
}
