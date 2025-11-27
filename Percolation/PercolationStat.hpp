
class PercolationStats {
public:
    // perform independent trials on an n-by-n grid
    PercolationStats(int n, int trials);

    // sample mean of percolation threshold
    double mean();

    // sample standard deviation of percolation threshold
    double stddev();

    // low endpoint of 95% confidence interval
    double confidenceLow();

    // high endpoint of 95% confidence interval
    double confidenceHigh();

    // test client
    static void test();
};