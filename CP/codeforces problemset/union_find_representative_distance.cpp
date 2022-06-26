#include<bits/stdc++.h>
using namespace std;
pair<int,int> parent[1000];
int rank_1[1000];

void make_set(int v) {
    parent[v] = make_pair(v, 0);
    rank_1[v] = 0;
}

pair<int, int> find_set(int v) {
    if (v != parent[v].first) {
        int len = parent[v].second;
        parent[v] = find_set(parent[v].first);
        parent[v].second += len;
    }
    return parent[v];
}

void union_sets(int a, int b) {
    a = find_set(a).first;
    b = find_set(b).first;
    if (a != b) {
        if (rank_1[a] < rank_1[b])
            swap(a, b);
        parent[b] = make_pair(a, 1);
        if (rank_1[a] == rank_1[b])
            rank_1[a]++;
    }
}
int main()
{
	for(int i=1;i<=16;i++)
		make_set(i);
	union_sets(4,1);
	union_sets(4,2);
	union_sets(4,3);
	cout<<"after union 1"<<endl;
	for(int i=1;i<=16;i++){
		cout<<i<<" "<<parent[i].first<<" "<<parent[i].second<<endl;  
	}
	
	union_sets(8,5);
	union_sets(8,6);
	union_sets(8,7);
	cout<<"after union 2"<<endl;
	for(int i=1;i<=16;i++){
		cout<<i<<" "<<parent[i].first<<" "<<parent[i].second<<endl;  
	}
	union_sets(8,4);
	cout<<"after union 3"<<endl;
	for(int i=1;i<=16;i++){
		cout<<i<<" "<<parent[i].first<<" "<<parent[i].second<<endl;  
	}	
	find_set(3);
	cout<<"after find"<<endl;
	for(int i=1;i<=16;i++){
		cout<<i<<" "<<parent[i].first<<" "<<parent[i].second<<endl;  
	}

}