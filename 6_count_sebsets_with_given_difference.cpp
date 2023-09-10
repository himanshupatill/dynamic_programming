//

class Solution {
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        int m = 1000000007;
        int sum = 0;
        
        for(int i=0; i<n; i++){
            sum += arr[i];
        }
        sum+=d;
        
        if(sum%2==1){
            return 0;
        }
        
        sum/=2;
        
        vector<vector<int>>dp(n+1, vector<int>(sum+1, 0));
        
        for(int i=0; i<n+1; i++){
            for(int j=0; j<sum+1; j++){
                if(i==0){
                    dp[i][j] = 0;
                }
                if(j==0){
                    dp[i][j] = 1;
                }
            }
        }
        
        for(int i=1; i<=n; ++i){
            for(int j=0; j<=sum; ++j){
                if(arr[i-1]<=j){
                    dp[i][j] = (dp[i-1][j-arr[i-1]] + dp[i-1][j])%m;
                }
                else{
                    dp[i][j] = dp[i-1][j]%m;
                }
            }
        }
        
        return dp[n][sum];
    }
};
