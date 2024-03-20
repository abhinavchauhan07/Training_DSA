//iii) Write a program to print the below pattern:
//\*****/
//*\***/*
//**\*/**
//***/***
//**/*\**
//*/***\*
///*****\


#include<iostream>
using namespace std;

//void pattern_print1(int rows)
//{
//    int backward_slash=0,forward_slash=rows;
//    for(int row_index=0;row_index<rows-2;row_index++)
//    {
//        if(backward_slash==0){
//            cout<<"\\";
//            
//        }
//        for(int col_index=0;col_index<rows;col_index++)
//        {
//            if(backward_slash==col_index && backward_slash!=0){
//                cout<<"\\";
//            }
//            if(forward_slash==col_index && forward_slash!=rows){
//                cout<<"/";
//                while(col_index<rows)
//                {
//                    cout<<"*";
//                    col_index++;
//                }
//            }
//            else
//            cout<<"*";
//        }
//        if(forward_slash==rows){
//            cout<<"/";
//            
//        }
//        backward_slash++;
//        forward_slash--;
//        cout<<endl;
//            
//    }
//    int counter=0;
//    int middle_index=(rows+1)/2;
//    for(int index=0;index<rows+2;index++)
//    {
//        if(counter==middle_index)
//        {
//            cout<<"/";
//            counter=middle_index+1;
//        }
//        else{
//            cout<<"*";
//            counter++;
//        }
//    }
//  cout<<endl;
//    backward_slash=middle_index+1;
//    forward_slash=middle_index-1;
//    for(int row_index=0;row_index<rows-2;row_index++)
//    {
////        if(row_index==row-3)
////            cout<<"\\";
//        for(int col_index=0;col_index<rows+1;col_index++)
//        {
//            if(backward_slash==col_index && backward_slash!=rows+1){
//                cout<<"\\";
//                while(col_index<rows)
//                {
//                    cout<<"*";
//                    col_index++;
//                }
//                
//            }
//            if(forward_slash==col_index && forward_slash!=0){
//                cout<<"/";
//                while(col_index<backward_slash-1)
//                {
//                    cout<<"*";
//                    col_index++;
//                }
//            }
//            else
//            cout<<"*";
//            
//        }
//        forward_slash--;
//        backward_slash++;
//        cout<<"/";
//        cout<<endl;
//    }
////    cout<<"\\";
////
////    cout<<"/";
//}

void pattern_print(int rows)
{
    for(int row_index=0;row_index<rows;row_index++)
    {
        for(int col_index=0;col_index<rows;col_index++)
        {
            if(row_index+col_index==rows-1)
            {
                cout<<"/";

            }
            else if(row_index==col_index)
                cout<<"\\";
            
            else
                cout<<"*";
        }
        cout<<endl;
    }
}
int main()
{
    int row=7;
    cout<<"Enter the number of rows"<<endl;
    cin>>row;
    pattern_print(row);
    
    return 0;
}



