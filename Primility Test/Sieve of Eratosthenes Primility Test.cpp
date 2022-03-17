			//	SIEVE_OF_ERATOSTHENES PRIMALITY TEST //

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
	while (t--)
#define pb push_back
#define po pop_back
#define rs resize
#define ins insert
#define del erase
const ll m = 1e9 + 7;
		//I will set up for 10000 nums in sieve
vll prime(10000,1);
void Sieve_of_Eratosthenes(){
	prime[0]=prime[1]=0;
	ll n=sqrt(10000);
	FOR(i,2,n){
		if(prime[i]==1)
		FORD(j,i*i,10001,i)
			prime[j]=0;
	}
}
int main(){
	#ifndef ONLINE_JUDGE
		freopen("input_II.txt","r",stdin);
		freopen("output_II.txt","w",stdout);
	#endif
	ll n;
	cin>>n;
	Sieve_of_Eratosthenes();
	if(prime[n]==1)
		cout<<"True";
	else
		cout<<"False";
}