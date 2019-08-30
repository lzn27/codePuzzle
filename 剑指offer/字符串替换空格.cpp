class Solution {
public:
    void replaceSpace(char *str, int length) {
        if (str == nullptr || length <= 0)
            return;
        int i = 0;
        int num = 0;
        while (str[i] != '\0') {
            if (str[i] == ' ')
                num++;
            i++;
        }
        int newlength = i + 1 + num * 2;
        if (newlength > length)return;
        int j = newlength - 1;
        while (i!=j) {
            if (str[i] == ' ') {
                str[j--] = '0';
                str[j--] = '2';
                str[j--] = '%';
                i--;
            }
            else {
                str[j--] = str[i];
                i--;
            }
        }
    }
};