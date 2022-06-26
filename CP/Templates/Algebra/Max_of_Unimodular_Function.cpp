#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define EPS 1e-7

ld func(ld x){
    return 11-(x-5)*(x-5);
}

ld max_val(ld l, ld r){
    while(r>l+EPS)
    {
        ld m1 = l + (r-l)/3;
        ld m2 = r - (r-l)/3;
        if(func(m1)>func(m2))
            r = m2;
        else
            l = m1;
    }
    return l;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << max_val(-100, 100);

    return 0;
}