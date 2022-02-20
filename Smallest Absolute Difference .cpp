Given an array of size N containing positive integers n and a number k,The absolute difference between values at indices i and j is |a[i] – a[j]|.
There are n*(n-1)/2 such pairs and you have to print the kth smallest absolute difference among all these pairs.
 

Example 1:

Input : 
N = 4
A[] = {1, 2, 3, 4}
k = 3
Output : 
1 
Explanation :
The possible absolute differences are :
{1, 2, 3, 1, 2, 1}.
The 3rd smallest value among these is 1.
  
  // code
  
  int help(int a[], int n, int mid){
    int ans = 0;
    for(int i=0;i<n;i++){
        ans += upper_bound(a+i,a+n,a[i]+mid)-(a+i+1);
    }
    return ans;
}
int kthDiff(int a[], int n, int k)
{
    sort(a,a+n);
    int low = a[1]-a[0];
    for(int i=1;i<=n-2;i++) low = min(low,a[i+1]-a[i]);
    int high = a[n-1]-a[0];
    while(low < high){
        int mid = (low+high)/2;
        if(help(a,n,mid) < k) low = mid+1;
        else high = mid;
    }
    return low;
    
}
