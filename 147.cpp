#include<bits/stdc++.h>


using namespace std;

long long n, dp[30005];
int main()
{
    int coins[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < 11; i++) {
	for (int j = coins[i]; j < 30005; j++)  //precalculate
	    dp[j] += dp[j - coins[i]];
    }


    double coin;
    while (scanf("%lf", &coin) == 1) {
	n = (coin + 0.005) * 100;  // making n
	if (!n)	break;
	printf("%6.2lf%17lld\n", coin, dp[n]);
    }
    return 0;
}
