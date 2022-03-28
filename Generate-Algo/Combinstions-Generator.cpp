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
	a[a.size()-1]=1;
	print(a);
	int i=n;
	while(i>=0){
		--i;
		if(i>=0&&a[i]==0&&a[i+1]==1){
			a[i]=1;
			for(int j=i+1;j<n;++j)
				a[j]=0;
			print(a);
			i=n;
		}
		else if(i>=0&&a[i]==1&&a[i+1]==0){
			a[a.size()-1]=1;
			i=n;
			print(a);
		}
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