Given an array of integers. Find the Inversion Count in the array. 

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
 

Example 1:

Input: N = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 
has three inversions (2, 1), (4, 1), (4, 3).

// code
#define ll long long
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    ll merge(ll arr[], ll low, ll mid, ll high){
        ll n1 = mid - low + 1;
        ll n2 = high - mid;
        ll a[n1], b[n2];
        for(ll i = 0; i < n1; i++) a[i] = arr[low + i];
        for(ll i = 0; i < n2; i++) b[i] = arr[mid + 1 + i];
        ll i = 0, j = 0, k = low;
        ll count = 0;
        while(i < n1 && j < n2){
            if(a[i] <= b[j]) arr[k++] = a[i++];
            else{
                arr[k++] = b[j++];
                count += n1 - i; 
            }
        }
        while(i < n1)  arr[k++] = a[i++];
        while(j < n2) arr[k++] = b[j++];
        return count;
    }
    ll mergeSort(ll arr[], ll low, ll high){
        ll count = 0;
        if(low >= high) return 0;
        ll mid = (low + high)/2;
        count += mergeSort(arr, low, mid);
        count += mergeSort(arr, mid + 1, high);
        count += merge(arr, low, mid, high);
        return count;
    }
    long long int inversionCount(long long arr[], long long n)
    {
        return mergeSort(arr,0,n-1);
    }

};
