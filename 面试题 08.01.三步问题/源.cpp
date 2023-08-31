int mem[1000000] = { 0 };
int waysToStep(int n) {
    if (mem[n])
        return mem[n];
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    if (n == 3)
        return 4;
    mem[n] = ((long)waysToStep(n - 1) + waysToStep(n - 2) + waysToStep(n - 3)) % 1000000007;
    return mem[n];
}