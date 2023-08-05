// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
// make recurssion solution and then add if(dp[n][W]!=-1) line in the code before doing recurssion
// for recursive solution first make a choice diagram
// then make a base condition
// how to make base condition - choose minimum possible condition for the variable parameters from the choice diagram

int solve(int W, int wt[], int val[], int n, vector<vector<int>>&dp){
          if(n==0 || W==0){
            return 0;
          }
          
          if(dp[n][W]!=-1){
            return dp[n][W];
          }
           
          if(wt[n-1]<=W){
            return dp[n][W]=max(val[n-1]+solve(W-wt[n-1], wt, val, n-1, dp), solve(W, wt, val, n-1, dp));
          }
          if(wt[n-1]>W){
            return dp[n][W]=solve(W, wt, val, n-1, dp);
          }
    }
    
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>>dp(n+1, vector<int>(W+1, -1));
        return solve(W, wt, val, n, dp);
        
    }
