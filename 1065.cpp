#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int t = 0;
    long long int A, B, C;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> A >> B >> C;
        long long int r = A+B;
        if (A > 0 && B > 0 && r < 0)
            printf("Case #%d: true\n", i);
        else if (A < 0 && B < 0 && r >= 0)
            printf("Case #%d: false\n", i);
        else if (r>C)
            printf("Case #%d: true\n", i);
        else
            printf("Case #%d: false\n", i);

    }
    return 0;
}
