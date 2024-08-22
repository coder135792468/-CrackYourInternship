//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
   
    void helper(string str,int k,string& temp, int i = 0){
        if(i == str.size()-1 or k == 0){
            temp = max(temp,str);
            return;
        };
        int mx = 0;
        for(int j = i;j<str.size();j++){
            mx = max(mx,str[j] - '0');
        };
        if((str[i]-'0') == mx){
            helper(str,k,temp,i+1);
            return;
        }
        for(int j = i+1;j<str.size();j++){
            if((str[j]-'0') == mx){
                swap(str[j],str[i]);
                helper(str,k-1,temp,i+1);
                swap(str[j],str[i]);
            }
        }
         
    }
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
       string temp = str;
       helper(str,k,temp);
       return temp;
    }
};

//{ Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}

// } Driver Code Ends