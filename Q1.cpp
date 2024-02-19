#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        if(k>=s.length()) return 0;
        
        vector<int>freq(26,0);
        
        for(int i=0;i<s.length();i++){
            int idx=s[i]-'a';
            freq[idx]++;
        }
        
        priority_queue<int>que;
        
        for(int i=0;i<26;i++){
            if(freq[i]>0){
                que.push(freq[i]);
            }
        }
        
        
        while(k--){
            int tp = que.top();
            cout<<"k="<<k<<"top="<<tp<<endl;
            que.pop();
            tp--;
            que.push(tp);
            
            cout<<"k="<<k<<"after pop top="<<tp<<endl;
        }
        
         int res = 0;
        while(!que.empty()){
            int top = que.top();
            
            que.pop();
            
            res+=pow(top,2);
        }
        return res;
        
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } 