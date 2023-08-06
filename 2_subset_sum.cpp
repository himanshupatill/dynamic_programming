//this problem is very similar to knapsack problem
//only differece it has is use of OR instead of max
//where should or be used and where should max be used will depend on the question and the context

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
