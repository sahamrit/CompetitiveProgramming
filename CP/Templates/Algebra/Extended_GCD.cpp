#include <bits/stdc++.h>
using namespace std;

int exGCD(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    int x1, y1;
    int d = exGCD(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

int main()
{
    ios_base::sync_with_stdio(false);
 	cin.tie(NULL);

     int a, b, x, y;
     cin >> a >> b;
     int gcd = exGCD(a, b, x, y);
     cout << gcd << endl;
     cout << x << " " << y << endl;

    return 0;
}

// Input
// 15 18

//Output
// 5
// 1 1