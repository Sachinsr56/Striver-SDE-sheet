// ------ using merge sort--------

class Solution {
public:
    int merge(vector<int> &nums,int low,int mid,int high)
{
    int j=mid+1 ;
    int count=0;
    vector<int> temp;
    
    for(int i=low;i<=mid;i++){
        while(j<=high && nums[i]>2LL*nums[j]){
            j++;
        }
        count+= (j-(mid+1));
    }
    
    int i=low;j=mid+1;
    
    while(i<=mid && j<=high)
    {
        if(nums[i]<=nums[j]){
            temp.push_back(nums[i++]);
        }
        else
            temp.push_back(nums[j++]);
    }
    
    while(i<=mid)
        temp.push_back(nums[i++]);
    
    
    while(j<=high)
        temp.push_back(nums[j++]);
    
    
    int k=0;
    for(int i=low;i<=high;i++)
    {
        nums[i]=temp[k++];
    }
    
    return count;
}

int mergeSort(vector<int> &nums ,int low,int high)
{
    int count=0;
    if(low<high)
    {
        int mid=(low+high)/2;
        count+=mergeSort(nums,low,mid);
        count+=mergeSort(nums,mid+1,high);
        count+=merge(nums,low,mid,high);
    }
    return count;
}

int reversePairs(vector<int>& nums) {
    int n=nums.size();
    int ans=mergeSort(nums,0,n-1);
    return ans;
}
};


// -------------using merge sort with a little modification-----

class Solution {
public:
    int merge(vector<int>&arr,int low ,int mid,int high){
        int cnt=0;
        int j=mid+1;
        for(int i=low; i<=mid;  i++){
            while(j<=high && arr[i]>(long long int)2*arr[j]){
                j++;
            }
            cnt+=(j-(mid+1));
        }
        sort(arr.begin()+low,arr.begin()+high+1);
        return cnt;
    }
    int mergeSort(vector<int>&arr,int low,int high){
        if(low>=high)  return 0;
        int mid=low+(high-low)/2;
        int inv=mergeSort(arr,low,mid);
        inv+=mergeSort(arr,mid+1,high);
        inv+=merge(arr,low,mid,high);
        return inv;
    }
    int reversePairs(vector<int> &arr){
        return mergeSort(arr,0,arr.size()-1);
    }
};