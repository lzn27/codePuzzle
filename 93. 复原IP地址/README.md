# 93. 复原IP地址
```c++
class Solution {
public:
    vector<string> restoreIpAddresses(string str) {
        vector<string> ans;
        DFS(ans,str,0,0,string(""));
        return ans;
    }
    void DFS(vector<string>& ans,const string& str,int index,int num,string s){
        if(index>=str.size())return;
        if(num==3){
            string temp=str.substr(index);
            if(isok(temp)){
                s+=temp;
                ans.push_back(s);
                return;
            }
            else{
                return;
            }
        }
        for(int i=index;i<str.size();i++){
            string temp=str.substr(index,i-index+1);
            if(isok(temp)){
                DFS(ans,str,i+1,num+1,s+temp+".");//回溯法可以在函数调用中计算，不会改变原值
            }
            else
                break;
        }
    }

    bool isok(const string& str){
        if(str.size()>3||(str[0]=='0'&&str.size()>1))return false;
        int x=0;
        for(int i=str.size()-1;i>=0;i--){
            x+=(str[i]-'0')*pow(10,str.size()-1-i);
        }
        if(x>255)return false;
        else
        return true;
    }
};
```