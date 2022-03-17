			//USING QUICKSORT FOR ARRANGE SEQUENCE//

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
void Quick_sort(vll &a,ll begin,ll end){
	ll pivot=a[end];
	ll i=begin;
	ll j=end-1;
	while(1){
		while(i<=j && a[i]<=pivot) 
			++i;
		while(i<=j && a[j]>pivot) 
			--j;
		if(i>j)
			break;
		swap(a[i],a[j]);
	}
	if(begin<end){
		swap(a[end], a[i]);
		Quick_sort(a,i+1,end);
		Quick_sort(a,begin,i-1);
	}
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
	Quick_sort(a,0,n-1);
	FOR(i,0,n)
		cout<<a[i]<<" ";
}
