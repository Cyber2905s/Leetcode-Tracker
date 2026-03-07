/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int bs(int low, int high,int target,MountainArray& arr, bool rev){
        while(low!=high){
            int mid= low+(high-low)/2;
            if(rev){
                if(arr.get(mid)>target){
                    low=mid+1;
                }
                else{
                    high=mid;
                }
            }
            else{
                if(arr.get(mid)<target){
                    low=mid+1;
                }
                else{
                    high=mid;
                }
            }
        }
        return low;
    }
    int peak(int low,int high,MountainArray &mountainArr){
        while(low!=high){
            int mid=low+(high-low)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1)){
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
        return low;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int len = mountainArr.length();
        int p= peak(1,len-2,mountainArr);
        int inc= bs(0,p,target,mountainArr,false);
        if(mountainArr.get(inc)==target){
            return inc;
        }
        int dec= bs(p+1,len-1,target,mountainArr,true);
        if(mountainArr.get(dec)==target){
            return dec;
        }
        return -1;
    }
};
