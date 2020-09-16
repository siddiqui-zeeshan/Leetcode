class Solution {
    public static double largestSumOfAverages(int[] A, int K) {
        double[][] cache = new double[A.length][K + 1];
        return topDown(0, A, K, cache);
    }

    static double topDown(int i, int[] A, int K, double[][] memo) {
        if (K <= 0 || i >= A.length) return 0;
        if (memo[i][K] != 0) return memo[i][K];
        if (K == 1) return avg(i, A);

        double sum = 0;
        int max_group_size = A.length - K; // max elements in the group for the given K
        for (int j = i; j <= max_group_size; j++) {
            sum += A[j];
            memo[i][K] = Math.max(memo[i][K], sum / (j - i + 1) + topDown(j + 1, A, K - 1, memo));
        }
        return memo[i][K];
    }
    
    static double avg(int start, int[] A, int end) {
        double sum = 0;
        for (int i = start; i <= end; i++) sum += A[i];
        return sum / (end - start + 1);
    }

    static double avg(int start, int[] A) {
        return avg(start, A, A.length - 1);
    }
}
