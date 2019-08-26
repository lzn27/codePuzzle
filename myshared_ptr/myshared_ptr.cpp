#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

struct pa {
    int x;
    int y;
    pa(int X,int Y):x(X),y(Y){}
};

template<typename T>
class myshared_ptr {
private:
    T *ptr_;
    int *use_;
public:
    myshared_ptr():ptr_(NULL),use_(new int(0)){}
    myshared_ptr(T *P) :ptr_(P), use_(new int(0)) {}
    myshared_ptr(const myshared_ptr& other) :ptr_(other.ptr_), use_(other.use_) { 
        (*use_)++; 
    }
    myshared_ptr& operator=(const myshared_ptr& other) {
        if (this == &other)return *this;
        (*use_)--;
        if (ptr_&&use_ == 0) {
            delete ptr_;
            delete use_;
        }
        this->ptr_ = other.ptr_;
        (*other.use_)++;
        this->use_ = other.use_;
        return *this;
    }
    ~myshared_ptr() {
        (*use_)--;
        if (ptr_&&use_ == 0) {
            delete ptr_;
            delete use_;
        }
    }
    T& operator*() { return *ptr_; }
    T* operator->() { return ptr_; }
};
myshared_ptr<pa> sp2;

int main() {
    {
        myshared_ptr<pa> sp(new pa(1, 2));
        cout << sp->x << sp->y << endl;
        sp2 = sp;
        sp->y++;
    }

    cout << sp2->y;
    
    return 0;
}