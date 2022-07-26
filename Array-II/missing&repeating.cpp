// #include <bits/stdc++.h> 


// ----------best approach in O(N) time using some maths only ----------------
// pair<int,int> missingAndRepeating(vector<int> &arr, int n)
// {
// 	long long int sum=0,square_sum=0;
//     for(int i=0; i<n; i++){
//         sum+=arr[i];
//         square_sum+=(arr[i]*arr[i]);
//     }
// 	long long  int total_sum=n*(n+1)/2,
//     tsquare_sum=(n*(n+1)*(2*n+1))/6;
//     long long int sub=total_sum-sum;
//     long long  int add=tsquare_sum-square_sum;
//     long long int missing=(sub+add/sub)/2;
//     long long int repeating=missing-sub;
//     return {missing,repeating};
    
// }
//  ------------same approach with less chanceof over flow------------
// pair<int,int> missingAndRepeating(vector<int> &arr, int n)
// {
//     long long int sum=(n*(n+1))/2;
//     long long int sq_sum=(n*(n+1)*(2*n+1))/6;
//     for(int i=0; i<n; i++){
//         sum-=arr[i];
//         sq_sum-=(arr[i]*arr[i]);
//     }
//     int missing=(sq_sum/sum+sum)/2;
//     int repeating=missing-sum;
//     return {missing,repeating};
// }


// -------------using maps with o(N) extra space -----------------
// pair<int,int> missingAndRepeating(vector<int> &arr, int n){
//     map<int,int> mp;
//     for(int i=0; i<n; i++){
//         mp[arr[i]]++;
//     }
//     int missing,repeating;
//     for(int i=1; i<=n; i++){
//         if(mp[i]==0){
//             missing=i;
//         }
//         if(mp[i]>1){
//             repeating=i;
//         }
//     }
//     return {missing,repeating};
// }


