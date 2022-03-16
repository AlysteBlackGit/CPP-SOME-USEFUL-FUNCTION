			//	PRODUCT OF TWO BIG INTEGERS //

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
void Product_of_two_bigint(string a,string b){
	if (a[0] == '0' || b[0] == '0')
		cout << 0 << endl;
	else
	{
		int res[3000];
		for (int i = 1; i <= 3000; i++)
			res[i] = 0;
		int redundance = 0;
		string num_1, num_2;
		if (a.length() > b.length())
		{
			num_1 = a;
			num_2 = b;
		}
		else
		{
			num_1 = b;
			num_2 = a;
		}
		int pointer = -1;
		for (int i = num_2.length() - 1; i >= 0; i--)
		{
			++pointer;
			int m = num_2[i] - 48;
			for (int j = num_1.length() - 1; j >= 0; j--)
			{
				int n = num_1[j] - 48;
				int position = 2000 - num_1.length() + j + 1 - pointer;
				if (redundance > 0)
				{
					res[position] += redundance;
					redundance = 0;
				}
				res[position] += m * n;
				redundance = res[position] / 10;
				res[position] %= 10;
			}
			if (redundance > 0)
			{
				res[2000 - num_1.length() - pointer] += redundance;
				redundance = 0;
			}
		}
		for (int i = 1; i <= 2000; i++)
			if (res[i] != 0)
			{
				for (int j = i; j <= 2000; j++)
					cout << res[j];
				cout << endl;
				break;
			}
	}
}
int main(){
	faster();
	#ifndef ONLINE_JUDGE
		freopen("input_II.txt","r",stdin);
		freopen("output_II.txt","w",stdout);
	#endif
	string a,b;
	cin>>a>>b;
	Product_of_two_bigint(a,b);
}
