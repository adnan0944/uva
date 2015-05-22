#include<bits/stdc++.h>


using namespace std;


int main()
{
    int t,cost[1005],weight[1005],weigh[105],dp[1002];

    int i, j, n, num, k, ans;
    scanf("%d", &t);
    while (t--)
    {
        ans = 0;
        scanf("%d", &n);
        for (i = 0; i < n; i++)
            scanf("%d %d", &cost[i],&weight[i]);
        scanf("%d", &num);
        for (i = 0; i < num; i++)
            scanf("%d", &weigh[i]);
        for (i = 0; i < num; i++)
        {
            memset(dp, 0, sizeof(dp));
            for (j = 0; j < n; j++)
                for (k = weigh[i]; k >= weight[j]; k--)
                    if (dp[k] < dp[k - weight[j]] + cost[j])
                        dp[k] = dp[k - weight[j]] + cost[j];
            ans += dp[weigh[i]];
        }
        printf("%d\n", ans);
    }
    return 0;

}
