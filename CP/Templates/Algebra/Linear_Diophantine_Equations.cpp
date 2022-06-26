#include <bits/stdc++.h>
using namespace std;

int exGCD(int a, int b, int &x, int &y){
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    int x1, y1;
    int gcd = exGCD(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

bool any_soln_present(int a, int b, int c, int &x0, int &y0, int &gcd){
    gcd = exGCD(abs(a), abs(b), x0, y0);
    if (c % gcd) {
        return false;
    }

    x0 *= c / gcd;
    y0 *= c / gcd;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

void shift_solution(int & x, int & y, int a, int b, int cnt){
    x += cnt * b;
    y -= cnt * a;
}

int no_of_solns(int a, int b, int c, int minx, int maxx, int miny, int maxy){
    int x, y, g;
    if (!any_soln_present(a, b, c, x, y, g))
        return 0;
    a /= g;  b /= g;

    int sign_a = a>0 ? +1 : -1;
    int sign_b = b>0 ? +1 : -1;

    shift_solution (x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution (x, y, a, b, sign_b);
    if (x > maxx)
        return 0;
    int lx1 = x;

    shift_solution (x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution (x, y, a, b, -sign_b);
    int rx1 = x;

    shift_solution (x, y, a, b, - (miny - y) / a);
    if (y < miny)
        shift_solution (x, y, a, b, -sign_a);
    if (y > maxy)
        return 0;
    int lx2 = x;

    shift_solution (x, y, a, b, - (maxy - y) / a);
    if (y > maxy)
        shift_solution (x, y, a, b, sign_a);
    int rx2 = x;

    if (lx2 > rx2)
        swap (lx2, rx2);
    int lx = max (lx1, lx2);
    int rx = min (rx1, rx2);

    if (lx > rx) return 0;
    return (rx - lx) / abs(b) + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
 	cin.tie(NULL);

    int a, b, c, x0, y0, gcd;
    cin >> a >> b >> c;
    if(any_soln_present(a, b, c, x0, y0, gcd))
        cout << x0 << " " << y0 << endl;
    else
        cout << "No Solution Present" << endl;

    int minx, maxx, miny, maxy;
    cin >> minx >> maxx >> miny >> maxy;
    cout << "Number of Solutions: " << no_of_solns(a, b, c, minx, maxx, miny, maxy) << endl;

    return 0;
}

// Input
// 3 -2 7
// 1 10000 1 10000

// Output
// 7 7
// Number of Solutions: 3334