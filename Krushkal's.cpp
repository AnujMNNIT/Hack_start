#include<bits/stdc++.h>
using namespace std;
void make_set(int v,int parent[],int size[]){
	parent[v]=v;
	size[v]=1;
}

int find_set(int v,int parent[]){
	if(v==parent[v])
		return v;
		
	parent[v]=find_set(parent[v],parent);
}

void union_set(int a,int b,int parent[],int size[]){
	a=find_set(a,parent);
	b=find_set(b,parent);
	if(a!=b){
		if(size[a]<size[b]){
			parent[a]=b;
			size[b]+=size[a];
		}
		else{
			parent[b]=a;
			size[a]+=size[b];
		}
	}
}

int main(){
	vector < pair <int,pair < int,int > > > v;
	int mx=INT_MIN;
	int i,n,a,b,c;
	set<int> st;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a>>b>>c;
		v.push_back(make_pair(a,make_pair(b,c)));
		mx=max(mx,max(a,b));
		st.insert(b);
		st.insert(c);
	}
	sort(v.begin(),v.end());
	int parent[mx+1],size[mx+1];
	set<int> :: iterator it;
	for(it=st.begin();it!=st.end();++it)
		make_set(*it,parent,size);
	 
	vector< pair <int,pair < int,int > > > ans;
	vector< pair <int,pair < int,int > > >::iterator itr,itrr;
	for(itr=v.begin();itr!=v.end();itr++){
		if(find_set((*itr).second.first,parent)!=find_set((*itr).second.second,parent)){
		union_set((*itr).second.first,(*itr).second.second,parent,size);
		ans.push_back(*itr);
		}
	}
	for(itrr=ans.begin();itrr!=ans.end();itrr++){
		cout<<(*itrr).first<<"  |  "<<(*itrr).second.first<<"  ->  "<<(*itrr).second.second<<endl;
	}
	
	
}
