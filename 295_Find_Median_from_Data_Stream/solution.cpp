#include<iostream>
#include<list>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

class MedianFinder1 {
private:
    multiset<int> median;
    set<int>::iterator ml; 
    set<int>::iterator mr;
public:
    /** initialize your data structure here. */
    MedianFinder1() {

    }

    void addNum(int num) {
        median.insert(num);
        if (median.size() == 1) {
            ml = median.begin();
            mr = median.begin();
        }
        else {
            if (median.size() % 2 == 0) {//odd before
                if (num >= *ml) {
                    mr++;
                }
                else {
                    ml--;
                }
            }
            else {
                if (num >= *mr) {
                    ml++;
                }
                else if (num < *ml) {
                    mr--;
                }
                else{
                    ml++;
                    mr--;
                }
            }
        }
    }

    double findMedian() {
        return (*mr + *ml) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


// 如果全部在100以内的优化方案
class MedianFinder {
    vector<int> vec_;
    int size_;
public:
    MedianFinder():vec_(101,0),size_(0) {

    }
    void addNum(int num) {
        vec_[num]++;
        size_++;
    }
    double findMedian() {
        int mid = size_ / 2 + 1;
        int index = 0;
        double median = 0;
        for (int i = 0; i < 101;i++) {
            index += vec_[i];
            if (index >= mid) {
                if (size_ % 2 == 0 && index - vec_[i] + 1 == mid) {
                    int ipre = i - 1;
                    while (vec_[ipre] == 0)ipre--;
                    median = (i + ipre) / 2.0;
                }
                else
                    median = i;
                break;
            }
        }
        return median;
    }

};

int main() {
    MedianFinder MF;
    vector<int> vec{ 6,10,2,6,5,0,6,3,1,0,0 };
    for (int x : vec) {
        MF.addNum(x);
        cout << MF.findMedian()<<endl;
    }
    return 0;
}