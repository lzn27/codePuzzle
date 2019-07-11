#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
#include<algorithm>
using namespace std;


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> word_set(wordList.begin(),wordList.end());
        queue<string> que;
        que.push(beginWord);
        int ans = 1;
        while (!que.empty()) {
            int len = que.size();
            while (len--) {//带有层数的BFS可以采用一次遍历一层的方式记录层数。
                string lookword = que.front();
                que.pop();
                if (lookword == endWord)//遍历某节点的语句最好写在这里。
                    return ans;

                //==寻找lookword的相邻word，循环测试查找26个字母的方法，笨拙但有效，毕竟26个也不多嘛....
                for (int i = 0; i < lookword.size(); i++) {
                    char save_c = lookword[i];
                    for (int j = 0; j < 26; j++) {
                        lookword[i] = 'a' + j;
                        unordered_set<string>::iterator iter(word_set.find(lookword));
                        if (iter != word_set.end()) {
                            que.push(*iter);
                            word_set.erase(iter);
                        }
                    }
                    lookword[i] = save_c;
                }
            }
            ans++;  
        }
        return 0;
    }
};

int main() {
    Solution solu;
    vector<int> vec = { 7,6,4,3,1 };
    return 0;
}