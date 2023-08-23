//everything will be same as subset sum 
//difference - add all the possible solutions instead of taking OR for each true of false response

class Solution{   
public:
    int countSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
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
                    dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][sum];
    }
};
