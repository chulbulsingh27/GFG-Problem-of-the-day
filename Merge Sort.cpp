Given an array arr[], its starting position l and its ending position r. Sort the array using merge sort algorithm.
Example 1:

Input:
N = 5
arr[] = {4 1 3 9 7}
Output:
1 3 4 7 9
  
  // code
  
  class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
        int n1 = m-l+1;
        int n2 = r-m;
        int larr[n1],rarr[n2];
        for(int i=0;i<n1;i++) larr[i] = arr[l+i];
        for(int j=0;j<n2;j++) rarr[j] = arr[m+1+j];
        int i=0,j=0,k=l;
        while(i<n1 && j<n2){
            if(larr[i] <= rarr[j]){
                arr[k] = larr[i];
                k++;
                i++;
            }
            else{
                arr[k] = rarr[j];
                j++;
                k++;
            }
        }
        while(i<n1){
            arr[k] = larr[i];
            i++;
            k++;
        }
        while(j<n2){
            arr[k] = rarr[j];
            j++;
            k++;
        }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l<r){
            int m = l+(r-l)/2;
            mergeSort(arr, l, m);
            mergeSort(arr, m+1, r);
            merge(arr,l,m,r);
        }
    }
};
