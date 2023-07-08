int mem[101][101] = { 0 };
int uniquePaths(int m, int n) {
    if (n == 1 || m == 1)
        return 1;
    if (mem[m][n])
        return mem[m][n];
    mem[m][n] = uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
    return mem[m][n];
}