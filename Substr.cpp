#include <iostream>
#include <string>
using namespace std;
int main()
{ 
 string str , str2;
 cin>>str;
 int size;
 cin>>size;
 cin>>str2;
 int success = 0;
 for (int i = 0; i < (str.length()-size); i++)
 {
    for (int j = 0; j < size; j++)
    {
        if (str[i]==str2[j])
        {
            i++;
            success++;
            if (success==size)
            {
                cout<<"Yes";
                return 0;
            }
            
        }
        else{
            i=0;
            success = -1;
            break;
        }
        
    }
    
 }
 cout<<"NO";
 
 return 0;
}