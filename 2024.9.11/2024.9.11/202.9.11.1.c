#define _CRT_SECURE_NO_WARNINGS
//两个线段获得的最多奖品
int maximizeWin(int* prizePositions, int prizePositionsSize, int k) {
    int n = prizePositionsSize;
    int* dp = calloc(n + 1, sizeof(int));
    int ans = 0;
    for (int left = 0, right = 0; right < n; right++) {
        while (prizePositions[right] - prizePositions[left] > k) {
            left++;
        }
        ans = fmax(ans, right - left + 1 + dp[left]);
        dp[right + 1] = fmax(dp[right], right - left + 1);
    }
    return ans;
}