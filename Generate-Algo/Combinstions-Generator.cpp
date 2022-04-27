#include<bits/stdc++.h>
using namespace std;
void print(vector<int> a){
	for(vector<int>::iterator i=a.begin();i!=a.end();++i)
		cout<<*i<<" ";
	cout<<endl;
}
void combinations_generator(int n){
	vector<int> a(n,0);
	print(a);
	ll i=n-1;
	while(i>=0){
		if(!a[i]){
			++a[i];
			FOR(j,i+1,n) a[j]=0;
			i=n-1;
			print(a);
		}
		else --i;
	}
}
int main(){
	#ifndef ONLINE_JUDGE
		freopen("input_II.txt","r",stdin);
		freopen("output_II.txt","w",stdout);
	#endif
	int n;
	cin>>n;
	combinations_generator(n);
}
