#include <iostream>
/*
*/

using namespace std;
 char upper (char c)
 {
      return 'A'+(c - 'a');
 }
int main()
{
    while(true)
    {
        string s;
         cin>>s;
        //getline(cin , s);  this will take whole sentence then we will have to parse the extra spaces.
        if (s.size()==0)
        {
            break;  
        }
        for (int i = 0; i < s.size(); i++)
        {
           s[i] = upper(s[i]);
        }
        cout<<s<<endl;
        
    }
    return 0;
}