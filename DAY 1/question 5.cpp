//v) Write a program to find the smallest number divisible by all the numbers between 1 to n
#include<iostream>
using namespace std;

int gcd(int number1,int number2)  // function to find the highest common factor of two numbers
{
    if(number2==0)
        return number1;
    return gcd(number2,number1%number2);
}

int smallest_divisible(int number)    //function that return smallest divisible number that can be divisible by all the numbers between 1 to n
{

    int smallest_number=1;
    for(int index=1;index<=number;index++)
    {
        int lowest_common_factor=(smallest_number*index);//finding the lowest_common_factor
        smallest_number=lowest_common_factor/(gcd(smallest_number,index));//dividing lowest common factor by highest common factor
        
    }
    return smallest_number;
}
int main()
{
    int Number;     //declaration of the n
    cin>>Number;    //taking input n
    cout<<smallest_divisible(Number)<<endl; //printing the result returned from the function
    
    return 0;
}






















//    int ans=1;
//    for(int i=2;i<n;i++)
//    {
//        if(is_divisible(n,i))return i;
//    }
//    return ans;
