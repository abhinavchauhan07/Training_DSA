//iii) Find the largest number less than N whose each digit is prime number
#include<iostream>
using namespace std;

bool check_prime(int number) //this function will validates if all the digits of a number is prime or not
{
    int temporary=number;
    while(temporary!=0)
    {
        int rem=temporary%10;   //extracting the digits from the number that is passed by the function largest_prime
        for(int index=2;index<=rem/2;index++)
        {
            if(rem%index==0)return false;     //if the digit is divisble then it can not be prime
        }
        temporary/=10;              //dividing the number by 10 to extract the another digit from it
    }
    return true;
}

int largest_prime(int number)     //this function will return the prime number less than N
{
    if(number==2 || number==3)return 0;
    
    
    for(int index=number-1;index>=2;index--)
    {
        if(check_prime(index))return index;
    }
    
    return 0;
}
int main()
{
    int n; //Declaring the N
    cout<<"Enter the Number"<<endl;
    cin>>n;//taking the input N
    cout<<largest_prime(n)<<endl;//printing the output returned by the function largest_prime
    
    return 0;
}
