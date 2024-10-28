#include<bits/stdc++.h>
	  using namespace std;
	  #define ll long long
	  #define vv vector<long long> 
	  #define mm map<long long, longlong>
	  #define st set<long long>
	  #define at for(int i=0; i<n ; i++)
	  int main(){
        int t; cin>>t; while(t--){
          int n, k;
		  cin>>n>>k;
		  string s;
		  cin>>s;
		  int count = 0;
			for(int i=0; i<n; i++){
				if(s[i]=='B') {
					s[i]='w';
					int x = min(i+k, n);
					for(int j=i; j<x; j++){
						if(s[j]=='B') {s[j]='w'; i=j-1;}
					}
					count++;
				}
			}
			cout<<count<<endl;
	  }}
