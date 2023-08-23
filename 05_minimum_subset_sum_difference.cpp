//main logic 
//s1+s2=sum
//s1-s2=difference
//s1-sum+s1=difference
//2*s1-sum=difference
//now check the last row of the dp array 
//all the elements are used for sum and we get ith sum
//dp[n][i]
//now check for the elements 
//find the sums which are possible i.e. dp[n][i]==true
//then get the minimum difference

class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    int sum = 0;
	    for(int i=0; i<n; i++){
	        sum+=arr[i];
	    }
	    int s1 = INT_MAX;
	    
	    vector<vector<bool>>dp(n+1, vector<bool>(sum+1, false));
	    
	    for(int i=0; i<=n; i++){
	        dp[i][0] = true;
	    }
	    for(int j=1; j<=sum; j++){
	        dp[0][j] = false;
	    }
	    
	    
	    for(int i=1; i<=n; i++){
	        for(int j=1; j<=sum; j++){
	            if(arr[i-1]<=j){
	                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
	            }
	            else{
	                dp[i][j] = dp[i-1][j];
	            }
	        }
	    }
	    
	    for(int i=0; i<=sum/2; i++){
	        if(dp[n][i] == true){
	            s1 = min(s1, sum-(2*i));
	        }
	    }
	    
	    return s1;
	} 
};
