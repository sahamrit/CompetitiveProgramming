#include <bits/stdc++.h>
using namespace std;

typedef int ftype;
typedef complex < ftype > point;
#define x real
#define y imag

ftype dot(point a, point b){
	return (conj(a)*b).x();
}

ftype cross(point a, point b){
	return (conj(a)*b).y();
}

vector < point > hull, vecs;

void add_line(ftype k, ftype b){
	point nw = {k, b};

	//Pops those points above the new Lower Convex Hull
	//Assuming when linear functions are added their k only increases
	//Else if k is decreasing 
	// Change '<' to '>' in the inequality in following while loop condition
	while(!vecs.empty() && dot(vecs.back(), nw - hull.back())<0){
		hull.pop_back();
		vecs.pop_back();
	}

	//Pushes the normal vector for last two point in the hull
	if(!hull.empty()){
		point iota = {0, 1};
		vecs.push_back(iota*(nw-hull.back()));
	}

	//Pushes the new  point in the Hull
	hull.push_back(nw);
}

int get(ftype x) {
    point query = {x, 1};
    auto it = lower_bound(vecs.begin(), vecs.end(), query, [](point a, point b) {
        return cross(a, b) > 0;
    });
    return dot(query, hull[it - vecs.begin()]);
}

// dp[i] = min {b[j]*a[i] + dp[j]} where j<i

int main()
{
	ios_base::sync_with_stdio(false);
 	cin.tie(NULL);
	
	int n;
	cin >> n;
	vector < int > a(n);
	for(int i=0; i<n; i++)
		cin >> a[i];
	vector < int > b(n);
	for(int i=0; i<n; i++)
		cin >> b[i];

	vector < int > dp(n);
	add_line(b[0], 0);
	for(int i=1; i<n; i++){
		dp[i] = get(a[i]);
		add_line(b[i], dp[i]);
	}

	cout << dp[n-1] << endl;
	
	return 0;
}