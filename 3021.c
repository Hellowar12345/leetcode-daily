long long flowerGame(int n, int m) {
    long long xeven=n/2;
    long long xodd=xeven+n%2;
    long long yeven=m/2;
    long long yodd=yeven+m%2;
    return xeven*yodd+yeven*xodd;
}
