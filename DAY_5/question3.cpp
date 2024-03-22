//Q3. You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
/*
 MARK: maximumValuesInWindowSize is a function which will print the maximum values from the window size given.
 DESC:maximumValuesInWindowSize uses a priority queue which is max heap and push all the current window values along with their indexes also it checks if the currentIndex-maxContainer.top().second>windowSize it pop out the top value from the heap
 PARAM:maximumValuesInWindowSize takes array and the size of the window.
 */
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void maximumValuesInWindowSize(vector<int> &array, int windowSize)
{
    int lengthOfArray=array.size();
    priority_queue<pair<int,int>>maxContainer;

    for(int currentIndex=0;currentIndex<lengthOfArray;currentIndex++)
    {
        maxContainer.push({array[currentIndex],currentIndex});
        if(currentIndex>=windowSize-1)
        {
            while(windowSize<=currentIndex-maxContainer.top().second)
            {
                maxContainer.pop();
            }
            cout<<maxContainer.top().first<<" ";
        }
    }
}
int main()
{
    
    int sizeOfArray;
    cout << "Enter the size of the array: ";
    cin >> sizeOfArray;
    vector<int>array(sizeOfArray);
    
    cout << "Enter the elements of the array" << endl;
        for (int i = 0; i < sizeOfArray; i++)
        {
            cin >>array[i];
        }
    
    int windowSize;
    cout << "Enter the window size "<<endl;
    cin >> windowSize;

    if (windowSize > 0)
    {
        maximumValuesInWindowSize(array,windowSize);
    }
    else
    {
        cout << "window size is zero" << endl;
    }
    
//    vector<int>v{8, 5, 10, 7, 9, 4, 15, 12, 90, 13};
//    vector<int>v1{15, 1,1,1,1,1,1};
//    int k = 3 ;
//    findMaxInWindowSize(v1,k);

    return 0;
}
