#include <string>
#include <iostream>

using namespace std;

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()) :
        ps(new std::string(s)), i(0) {}

    // new string(*rhs.ps) 返回新分配的地址的指针，ps 和 新的指针相等
    HasPtr(const HasPtr& rhs): ps(new string(*rhs.ps)), i(rhs.i) {}

    // 析构函数
    ~HasPtr() { delete ps; }

    HasPtr& operator=(const HasPtr& rhs) {
        i = rhs.i;
        string *temp = new string(*rhs.ps);
        delete ps;
        ps = temp;
        
        return *this;
    }

    string get() const { return *ps; }
private:
    std::string *ps;
    int i;
};

int main()
{
    HasPtr hp("hello");
    HasPtr hpp = hp;
    cout << hpp.get() << endl;
}