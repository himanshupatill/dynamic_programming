//this problem is very similar to knapsack problem
//only differece it has is use of OR instead of max
//where should or be used and where should max be used will depend on the question and the context


//                  Recursive solution                   //
/*
class Solution{   
public:
    bool solve(int n, vector<int>& arr, int sum){
        if(n==0){
            if( sum == 0){
                return true;
            }
            else{
                return false;
            }
        }
        if(sum == 0){
            return true;
        }
        
        if(arr[n-1]<=sum){
            return solve(n-1, arr, sum-arr[n-1])||solve(n-1, arr, sum);
        }
        else{
            return solve(n-1, arr, sum);
        }
    }
    
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        return solve(n, arr, sum);
    }
};
*/


//                      memoization                    //
// small change in recursive solution

/*
class Solution{   
public:
    int solve(int n, vector<int>& arr, int sum, vector<vector<int>>&dp){
        if(sum == 0){
            return 1;
        }
        
        if(n==0){
            return 0;
        }
        
        if(dp[n][sum]!=-1){
            return dp[n][sum];
        }
        
        if(arr[n-1]<=sum){
            return dp[n][sum]=solve(n-1, arr, sum-arr[n-1], dp)||solve(n-1, arr, sum, dp);
        }
        else{
            return dp[n][sum]=solve(n-1, arr, sum, dp);
        }
    }
    
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<int>>dp(n+1, vector<int>(sum+1, -1));
        return (bool)solve(n, arr, sum, dp);
    }
};
*/


//               tabulation                 //

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
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
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return (bool)dp[n][sum];
    }
};
