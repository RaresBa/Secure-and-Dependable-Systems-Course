#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

// Function to compute Numeric Edit Distance between two sequences
int numeric_edit_distance(int *seq1, int len1, int *seq2, int len2)
{
    int dp[len1 + 1][len2 + 1];

    // Initialize base cases
    for (int i = 0; i <= len1; i++)
        dp[i][0] = i; // Deletion cost
    for (int j = 0; j <= len2; j++)
        dp[0][j] = j; // Insertion cost

    // Fill DP table
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost_substitute = abs(seq1[i - 1] - seq2[j - 1]); // Absolute difference as cost
            int cost_delete = dp[i - 1][j] + 1; // Deletion
            int cost_insert = dp[i][j - 1] + 1; // Insertion
            int cost_swap = (i > 1 && j > 1 && seq1[i - 1] == seq2[j - 2] && seq1[i - 2] == seq2[j - 1])
                            ? dp[i - 2][j - 2] + 1 : INT_MAX; // Swap adjacent elements

            dp[i][j] = MIN(MIN(dp[i - 1][j - 1] + cost_substitute, cost_delete),
                           MIN(cost_insert, cost_swap));
        }
    }

    return dp[len1][len2]; // Return minimum transformation cost
}
