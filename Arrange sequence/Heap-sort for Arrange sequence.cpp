				//USING HEAP_SORT FOR ARRANGE SEQUENCE//

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
vll b(10005,0);
vll res;
void heap_build(ll i,vll a){
	ll j=i;
	while(b[j]!=0)
		++j;
	b[j]=b[i];
	if(j!=a.size()-1)
		b[j+1]=b[i];
}
void heap_sort(vll a){
	b[0]=1;
	b[1]=1;
	b[2]=2;
	ll i=1;
	while(b[a.size()-1]==0){
		heap_build(i,a);
		++i;
	}
	vll c(10,0);
	ll pos_max0, pos_max1;
	i=a.size()-1;
	while(a.size()){
		if(a.size()==1){
			res.pb(a[0]);
			break;
		}
		if(b[i]==1 && a[i]>c[0]){
			c[0]=a[i];
			pos_max0=i;
		}
		else if(b[i]==2 && a[i]>c[1]){
			c[1]=a[i];
			pos_max1=i;
		}
		--i;
		if(i==0){
			ll max;
			if(c[0]>c[1])
				max=c[0];
			else
				max=c[1];
			if(a[0]>=max){
				res.pb(a[0]);
				swap(a[0],a[a.size()-1]);
				a.del(a.begin()+a.size()-1);
			}
			else{
				if(max==c[0])
					swap(a[0],a[pos_max0]);
				else
					swap(a[0],a[pos_max1]);
			}
			c[0] = 0;
			c[1] = 0;
			i = a.size() - 1;
		}	
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
	heap_sort(a);
	for(ll i=n-1;i>=0;--i)
		cout<<res[i]<<" ";
}
