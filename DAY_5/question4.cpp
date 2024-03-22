//You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
//Find two lines that together with the x-axis form a container, such that the container contains the most water.
//Return the maximum amount of water a container can store.
//Notice that you may not slant the container.

#include<iostream>
#include<vector>
using namespace std;
//int maximumWaterContainer(vector<int>&height)
//{
//    int ans=0;
//    vector<int>left(height.size()),right(height.size());
//    left[0]=height[0];
//    for(int index=1;index<height.size();index++)
//    {
//        left[index]=max(height[index],left[index-1]);
//    }
//    right[height.size()-1]=height[height.size()-1];
//    for(int index=height.size()-2;index>=0;index--)
//        right[index]=max(height[index],right[index+1]);
//    
//    for(int index=1;index<height.size();index++)
//        ans=ans+(min(left[index],right[index])-height[index]);
//    
//    return ans;
//}
int maximumWaterheight(vector<int>&height)
{
    int startPointer=0,endPointer=height.size()-1;
    int maximumWater=0;
    while(startPointer<endPointer)
    {
        maximumWater=max(maximumWater,((endPointer-startPointer)*min(height[startPointer],height[endPointer])));
        if(height[startPointer]<height[endPointer])
            startPointer++;
        else
            endPointer--;
    }
    return maximumWater;
}
int main()
{
    vector<int>height{1,8,6,2,5,4,8,3,7};
    cout<<maximumWaterheight(height);
    return 0;
}
