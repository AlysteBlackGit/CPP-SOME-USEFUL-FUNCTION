					//	MILER - RABIN PRIMALITY TEST // 

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
#define svll set<vector<ll>>
#define svi set<vector<int>>
#define Test() \
	ll t;      \
	cin >> t;  \
	while (t--)za0tr
#define pb push_back
#define po pop_back
#define rs resize
#define ins insert
#define del erase
const ll m = 1e9 + 7;
ll random(ll a, ll b){
	return (a+(ll)(rand()*(b-a+1.0)/(1.0+RAND_MAX)));
}
ll generate_value(ll n){
	// d*2^r= n-1;
	ll o=log2(n-1);
	while(o>0){
		db d=(n-1)/pow(2,o);
		if((ll)d==d && (ll)d%2!=0)
			return (ll)d;
		--o;
	}
}
bool miller_test(ll n){
	if(n<2||n%2==0)
		return false;
	bool check=true;
	ll d=generate_value(n);
	ll x=0;
	FOR(i,1,4){
		// (ll)pow(a,d)%n = n-1||1
		ll a=random(2,n-2);
		x=(ll)pow(a,d)%n;
		if(x!=1&&x!=n-1){
			check=false;
			break;	
		}
	}
	if(check)
		return true;
		// final test: (x*x)%n = n-1||1
	x=(x*x)%n;
	if (x==1||x==n-1)
		return true;
	else
		return false;
}
int main(){
	#ifndef ONLINE_JUDGE
		freopen("input_II.txt","r",stdin);
		freopen("output_II.txt","w",stdout);
	#endif
	ll n;
	cin>>n;
	cout<<boolalpha<<miller_test(n);
}