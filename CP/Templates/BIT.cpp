#include <bits/stdc++.h>
using namespace std;

const int N = 1e5; //Limit for Array Size

int bit_size; //Input Array Size in main()
int BIT[2*N];

//0-indexed

//Update frequency at an index
void update(int idx, int val){
	idx++;
    while (idx <= bit_size){
        BIT[idx] += val;
        idx += (idx & -idx);
    }
}

// Read Cumulative Frequency
int query(int idx){
	idx++;
    int sum = 0;
    while (idx > 0){
        sum += BIT[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

int main()
{
	int n;
	cin >> n;
	bit_size = n;
	for(int i=0; i<n; i++)
	{
		int a;
		cin >> a;
		update(i, a);
	}
	for(int i=0; i<n; i++)
		cout << query(i) << " ";
	cout << endl;
}

//Input
// 16
// 1 0 2 1 1 3 0 4 2 5 2 2 3 1 0 2

//Output
// 1 1 3 4 5 8 8 12 14 19 21 23 26 27 27 29 