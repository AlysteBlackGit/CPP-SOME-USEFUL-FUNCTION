#include<bits/stdc++.h>
using namespace std;
void permutations_generator(int n){
	int a[n+5];
	for(int i=0;i<n;++i)
		a[i]=i+1;
	for(int i=0;i<n;++i)
		cout<<a[i]<<" ";
	cout<<endl;
	int i=n;
	while (i>0){
		--i;
		if (a[i]<a[i+1]){
			int pos_max=i;
			for(int j=i+1;j<n;++j)
				if(a[j]>a[i])
					pos_max=j;
			swap(a[i],a[pos_max]);
			int j=n-1;
			for(int x=i+1;x<=j;++x){
				swap(a[x],a[j]);
				--j;
			}
			for(int x=0;x<n;++x)
				cout<<a[x]<<" ";
			cout<<endl;
			i=n;
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
	permutations_generator(n);
}
