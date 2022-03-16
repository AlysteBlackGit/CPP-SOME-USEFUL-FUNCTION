			//	DIFFERENCE OF TWO BIG INTEGERS //

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
int res[10005];
void Difference_of_two_bigint(string a,string b){
	string num_1 = "";
	string num_2 = "";
	if (a.length() > b.length())
	{
		num_1 = a;
		num_2 = b;
	}
	else if (b.length() > a.length())
	{
		num_1 = b;
		num_2 = a;
	}
	else
	{
		if (b > a)
		{
			num_1 = b;
			num_2 = a;
		}
		else
		{
			num_1 = a;
			num_2 = b;
		}
	}
	int res[2000];
	for (int i = 0; i < 2000; i++)
		res[i] = 0;
	int k = num_1.length() - num_2.length();
	int redundance = 0;
	for (int i = num_1.length() - 1; i >= k; i--)
	{
		num_1[i] -= 48;
		num_2[i - k] -= 48;
		if (redundance)
		{
			res[i] -= 1;
			redundance = 0;
		}
		res[i] += (num_1[i] - num_2[i - k]);
		if (res[i] < 0)
		{
			++redundance;
			res[i] += 10;
		}
	}
	for (int i = k - 1; i >= 0; i--)
	{
		num_1[i] -= 48;
		if (redundance)
		{
			res[i] -= 1;
			redundance = 0;
		}
		res[i] += num_1[i];
		if (res[i] < 0)
		{
			++redundance;
			res[i] += 10;
		}
	}
	for (int i = 0; i < num_1.length(); i++)
		cout << res[i];
	cout << endl;
}
int main(){
	faster();
	#ifndef ONLINE_JUDGE
		freopen("input_II.txt","r",stdin);
		freopen("output_II.txt","w",stdout);
	#endif
	string a,b;
	cin>>a>>b;
	Difference_of_two_bigint(a,b);
}
