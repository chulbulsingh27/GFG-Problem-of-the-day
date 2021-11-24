Given a set of N jobs where each jobi has a deadline and profit associated with it. Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit if and only if the job is completed by its deadline. The task is to find the number of jobs done and the maximum profit.

Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job.


Example 1:

Input:
N = 4
Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
Output:
2 60
Explanation:
Job1 and Job3 can be done with
maximum profit of 60 (20+40)
  //code
  
  static bool comp(Job a,Job b){
    return a.profit > b.profit;
}
class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,comp);
        //create maximum deadline
        int maxi = arr[0].dead;
        for(int i=1;i<n;i++) maxi = max(maxi,arr[i].dead);
        int slot[maxi+1];
        //initialize it with -1
        for(int i=0;i<=maxi;i++) slot[i] = -1;
        int count = 0,profit = 0;
        for(int i=0;i<n;i++){
            //for any job id we will start as late as possible
            for(int j = arr[i].dead;j>0;j--){
                if(slot[j] == -1){
                    //whichever job is empty perform that job on that given day
                    slot[j] = i;
                    //update job count and profit
                    count++;
                    profit += arr[i].profit;
                    break;
                }
            }
        }
        return {count,profit};
    } 
};
