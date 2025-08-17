double new21Game(int n, int k, int maxPts) {
    double dp[100000]={0};
    for(int i=k;i<=n;i++){
        dp[i]=1;
    }
    for(int i=k-1;i>=0;i--){
        double cnt=0;
        for(int j=1;j<=maxPts;j++){
            cnt+=dp[i+j];
        }
        cnt/=maxPts;
        dp[i]=cnt;
    }
    return dp[0];
}
