Given two binary max heaps as arrays, merge the given heaps to form a new max heap.

 

Example 1:

Input  : 
n = 4 m = 3
a[] = {10, 5, 6, 2}, 
b[] = {12, 7, 9}
Output : 
{12, 10, 9, 2, 5, 7, 6}



// code

class Solution{
    public:
    void heapify(vector<int> &a,int n, int i){
        if(i>=n) return;
        int l = 2*i+1;
        int r = 2*i+2;
        int max;
        if(l < n  && a[l] > a[i]) max = l;
        else max = i;
        if(r<n && a[r] > a[max]) max = r;
        if(max != i) {
            swap(a[max],a[i]);
            heapify(a,n,max);
        }
    }
    void buildmaxheap(vector<int> &a,int n){
        for(int i=n/2-1;i>=0;i--) heapify(a,n,i);
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        /*vector<int> vec;
        for(auto it : a) vec.push_back(it);
        for(auto it : b) vec.push_back(it);
        make_heap(vec.begin(),vec.end());
        return vec;*/
        vector<int> vec (n+m,0);
        for(int i=0;i<n;i++) vec[i] = a[i];
        for(int i=0;i<m;i++) vec[n+i] = b[i];
        buildmaxheap(vec,n+m);
        return vec;
        // your code here
    }
};




 
