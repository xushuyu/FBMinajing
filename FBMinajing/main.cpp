//
//  main.cpp
//  FBMinajing
//
//  Created by Shuyu on 2/3/18.
//  Copyright © 2018 Shuyu. All rights reserved.
//

#include <iostream>
#include "fb.h"

using namespace std;

bool isSingle(vector<int>& nums, int i){
    if( i == 0 && nums[i] != nums[i+1])
        return true;
    
    if( i == nums.size()-1 && nums[i] != nums[i-1])
        return true;
    
    if( i-1 >= 0 && i+1 < nums.size() && nums[i] != nums[i+1] && nums[i] != nums[i-1] )
        return true;
    
    return false;
}

int singleNumber(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    
    int n = nums.size();
    int left = 0, right = n-1;
    
    while(left < right){
        int mid = left + (right-left)/2;
        
        if( isSingle(nums,mid)){
            return nums[mid];
        }else{
            int idx;
            if( mid + 1 < n && nums[mid] == nums[mid+1] ){
                idx = mid;
            }else
                idx = mid++;
            
            if(mid%2 == 0){
                left = mid +1;
            }else{
                right = mid -1;
            }
        }
    }
    
    return INT_MAX;
}

template<typename ForwardIterator, typename T>
ForwardIterator my_lower_bound (ForwardIterator first,
                             ForwardIterator last, T value) {
    while (first != last) {
        auto mid = next(first, distance(first, last) / 2);
        if (value > *mid)   first = ++mid;
        else                last = mid;
    }
    return first;
}


template<typename ForwardIterator, typename T>
ForwardIterator my_upper_bound (ForwardIterator first,
                             ForwardIterator last, T value) {
    while (first != last) {
        auto mid = next(first, distance (first, last) / 2);
        if (value >= *mid) first = ++mid; // 与 lower_bound 仅此不同
        else                 last = mid;
    }
    return first;
}

int maxless(vector<int> nums, int target){
    int l = 0, r = (int)nums.size()-1;
    
    while(l < r){
        int mid = (l+r+1)/2;
        
        if(nums[mid] < target)
            l = mid;
        else
            r = mid - 1;
    }
    
    return l;
}



int main(int argc, const char * argv[]) {
    Evalueation * sol = new Evalueation();
    cout<<sol->evaluate("( + 1 2 3 )")<<endl;
    
    return 0;
}

