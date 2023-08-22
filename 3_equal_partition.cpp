class Solution{
public:
    int equalPartition(int n, int arr[])
    {
        //once we get total_sum/2 the problem is to find the subset sum 
        int sum = 0;
        for(int i=0; i<n; i++){
            sum+=arr[i];
        }
        
        if(sum%2!=0){
            return 0;
        }
        sum = sum/2;
        
        vector<vector<int>>dp(n+1, vector<int>(sum+1, -1));
        
        for(int i=0; i<=n; i++){
            dp[i][0] = 1;
        }
        for(int j=1; j<=sum; j++){
            dp[0][j] = 0;
        }
        
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=sum; ++j){
                if(arr[i-1]<=j){
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
};
