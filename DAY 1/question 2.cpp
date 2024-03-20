//ii) Write a program (without using inbuilt functions and not using Strings or array) to swap first and last digits of any number

#include<iostream>
using namespace std;
void swap_numbers(int &number1,int &number2)    // this function will swap two numbers
{
    int temporary_variable=number1;
    number1=number2;
    number2=temporary_variable;
}
int swap_first_and_last_digits(int number)
{
    int count_digits=0;
    int temporary_number=number; // taking the number into a temporary variable so that the original data is not mainpulated
    while(temporary_number!=0)     // this loop will count the digits in a number
    {
        count_digits++;
        temporary_number/=10;
    }
    if(count_digits==1)return number;     //if there is only one digit than return that only
    temporary_number=number;
    int end_digit=temporary_number%10;        //end_digit takes the number%10 digit of the number
    int start_digit=0;                         //start digit of the nubmer
    int reverse_digit=0;                // it will contain the reverse of the original number
    while(temporary_number!=0)
    {
        reverse_digit=reverse_digit*10+(temporary_number%10);
        start_digit=temporary_number%10; //start digit will be assigned in each iteration until loop ends
        temporary_number/=10;
    }
    int result=end_digit;    //assigning the last digit to result so that it will become first digit
    reverse_digit=reverse_digit/10; //dividing by 10 to remove the last digit as it is already assigned to result;
    while(reverse_digit>10)
    {

        result=result*10+(reverse_digit%10);
        reverse_digit/=10;
    }
    result=(result*10)+start_digit;
//
    
    return result;  //returns the new number after swapping
}
int main()
{
    int N;  //Declaration of the N
    cout<<"Enter the number"<<endl;
    cin>>N;//taking input from the user
    cout<<swap_first_and_last_digits(N);//printing the number after swapping that is returned fromt the function  swap_first_and_last_digits
    return 0;
}
