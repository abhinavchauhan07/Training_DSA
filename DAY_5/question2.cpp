//Q2. Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

/*
 MARK: medianOfTwoSortedArrays is the function which returns the median of both the sorted arrays
 
 DESC: medianOfTwoSortedArrays takes two sorted arrays as a parameter and then find the combined length of both the arrays and then check for the odd median index and the even median index and if the combined length is even return the average of element at odd median and even median otherwise return the odd median element.
 
 PARAM: medianOfTwoSortedArrays takes two sorted arrays as input
 
 RETURN:medianOfTwoSortedArrays return the median of the two sorted arrays
 
 */
#include<iostream>
using namespace std;
int medianOfTwoSortedArrays(vector<int>&array1,vector<int>&array2)
{
        int sizeOfarray1 = array1.size(), sizeOfarray2 = array2.size();
        int combinedLength = sizeOfarray1+sizeOfarray2;
        
        int indexForOdd = combinedLength/2;//odd index
        int indexForEven = indexForOdd - 1;//even index
        int counter = 0; //counter to check the index for odd and even index
        int medianForOdd = -1, medianForEven = -1;

        int array1Pointer = 0, array2Pointer = 0;
        while (array1Pointer <sizeOfarray1 && array2Pointer <sizeOfarray2) {
            //if the array1 element is smaller than the element of array2
            if (array1[array1Pointer] < array2[array2Pointer]) {
                if (counter == indexForOdd) medianForOdd = array1[array1Pointer];
                if (counter == indexForEven) medianForEven = array1[array1Pointer];
                counter++;
                array1Pointer++;
            }//if the array2 element is smaller than the element of array1
            else {
                if (counter == indexForOdd) medianForOdd = array2[array2Pointer];
                if (counter == indexForEven) medianForEven = array2[array2Pointer];
                counter++;
                array2Pointer++;
            }
        }
            //if the array1 elements are still remaining then to check for those left out elements
        while (array1Pointer < sizeOfarray1) {
            if (counter == indexForOdd) medianForOdd = array1[array1Pointer];
            if (counter == indexForEven) medianForEven = array1[array1Pointer];
            counter++;
            array1Pointer++;
        }
    //if the array2 elements are still remaining then to check for those left out elements
        while (array2Pointer < sizeOfarray2) {
            if (counter == indexForOdd) medianForOdd = array2[array2Pointer];
            if (counter == indexForEven) medianForEven = array2[array2Pointer];
            counter++;
            array2Pointer++;
        }

        //if the combined length of both the arrays results in odd number(length) then median is the middle one element of the combined arrays
        if (combinedLength % 2 == 1) {
            return medianForOdd;
        }
        else{
    return (medianForEven+medianForOdd)/2;
    }
}
int main()
{
    int sizeOfArray1,sizeOfArray2;
    cout<<"Enter the size of the Array 1"<<endl;
    cin>>sizeOfArray1;
    vector<int>array1(sizeOfArray1);
    cout<<"Enter the Elements of the Array 1"<<endl;
    for(int index=0;index<sizeOfArray1;index++)
        cin>>array1[index];
    
    cout<<"Enter the size of the Array 2"<<endl;
    cin>>sizeOfArray2;
    vector<int>array2(sizeOfArray2);
    cout<<"Enter the Elements of the Array 2"<<endl;
    for(int index=0;index<sizeOfArray2;index++)
        cin>>array2[index];
        
   
    
//    vector<int>array1{1,3,5,7,9};
//    vector<int>array2{2,4,6,8};
    cout<<"The median of both the arrays is: "<<medianOfTwoSortedArrays(array1, array2)<<endl;
//    1 2 3 4 5 6 7 8 9
    return 0;
}
