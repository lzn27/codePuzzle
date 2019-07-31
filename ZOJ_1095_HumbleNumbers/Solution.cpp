#include <iostream>
#include <vector>
using namespace std;

vector<int> vec{2, 3, 5, 7};

bool invec(const int& num, const int& i, const int& j) {
    if (i > j) return false;
    if (vec[(i + j) / 2] > num)
        return invec(num, i, (i + j) / 2);
    else {
        if (vec[(i + j) / 2] == num)
            return true;
        else {
            if (vec[(i + j) / 2] < num) return invec(num, (i + j) / 2, j);
        }
    }
}

bool isHumber(int num) {
    if (invec(num,0,vec.size()-1)) return true;
    if (num % 2 == 0) return isHumber(num / 2);
    if (num % 3 == 0) return isHumber(num / 3);
    if (num % 5 == 0) return isHumber(num / 5);
    if (num % 7 == 0) return isHumber(num / 7);
    return false;
}

int main() {
    int n;
    cin >> n;
    int i = 8;
    while (vec.size() < n) {
        if (isHumber(i)) vec.push_back(i);
        i++;
    }
    cout<<vec[n-1];
    return 0;
}