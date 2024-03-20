//iv) Write a function Boolean isValidURL(String url).
#include<iostream>
#include<regex>
using namespace std;
bool isValidURL(string url)
{
        
    int n=url.length();
    if(url.length()==0 || (url.length()>7 && url.length()<12))return false;
    
    if(url.substr(0,8)=="https://" && url.substr(n-4,n-1)==".com")
        {
            for(int i=0;i<url.length();i++)
            {
                if(url[i]==' '|| url[i]==',')return false;
                
            }
        }
    else if(url.substr(0,7)!="http://" && url.substr(n-4,n-1)==".com")
    {
        for(int i=0;i<url.length();i++)
        {
            if(url[i]==' '|| url[i]==',')return false;
            
        }
    }
        else
            return false;

        
    
    return true;
   
}
bool is_valid(string url)
{
    const regex pattern("((http|https)://)(www.)?[a-zA-Z0-9@:%._\\+`#?&//=]{2,256}\\.[a-z]{2,6}\\b([-a-zA-Z0-9@:\\+`#?&//=]*)");
    if(url.empty())return false;     // if the url string is empty than it is not a valid url
    if(regex_match(url,pattern))return true;//if the string matches the pattern then return true;
    else
        return false; //if the string does not matches the pattern then return false;
}
int main()
{
    string str;         //Declaration of the string that takes url
    getline(cin,str);    //taking url as input
    if(isValidURL(str))   //if the function that validates url returns true than printing true
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;//if the function that validates url returns false than printing false
    
    return 0;
}
