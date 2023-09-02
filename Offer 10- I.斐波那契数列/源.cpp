int mem[101] = { 0 };
int fib(int n) {
    if (mem[n])
        return mem[n];
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    mem[n] = (fib(n - 1) + fib(n - 2)) % (1000000007);
    return mem[n];
}