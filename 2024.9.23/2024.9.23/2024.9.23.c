#define _CRT_SECURE_NO_WARNINGS
//最佳观光组合
int maxScoreSightseeingPair(int* values, int valuesSize) {
    int score = 0;
    int score1 = 0;
    int score2 = values[0] + 0;
    for (int i = 1; i < valuesSize; i++) {
        score1 = values[i] - i;
        if (score1 + score2 > score) {
            score = score1 + score2;
        }
        if (values[i] + i > score2)
            score2 = values[i] + i;
    }
    return score;
}