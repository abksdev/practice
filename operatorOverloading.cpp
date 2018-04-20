#include <iostream>using namespace std;
class OpOverloading{    int a;    public:    OpOverloading(int x = 10):a(x){ cout << "Constructor called" << endl; }        OpOverloading operator+(const OpOverloading& obj){        cout << "addition overloaded" << endl;        OpOverloading ob;        ob.a = this->a + obj.a;        return ob;    }        OpOverloading operator-(const OpOverloading& obj){        cout << "substraction overloaded" << endl;        OpOverloading ob;        ob.a = this->a - obj.a;        return ob;    }        OpOverloading operator*(const OpOverloading& obj){        cout << "multiplication overloaded" << endl;        OpOverloading ob;        ob.a = this->a * obj.a;        return ob;    }        void operator=(const OpOverloading& obj){        cout << "assignment overloaded" << endl;        this->a = obj.a;    }        OpOverloading& operator++(){        cout << "pre-increment overloaded" << endl;        this->a += 1;        return *this;    }        OpOverloading operator++(int){        cout << "post-increment overloaded" << endl;        OpOverloading obj = *this;        this->a += 1;        return obj;    }        OpOverloading& operator--(){        cout << "pre-decrement overloaded" << endl;        this->a -= 1;        return *this;    }        OpOverloading operator--(int){        cout << "post-decrement overloaded" << endl;        OpOverloading obj = *this;        this->a -= 1;        return obj;    }        friend ostream& operator << (ostream& out,const OpOverloading& obj);};
ostream& operator << (ostream& out,const OpOverloading& obj){    cout << "value: " << obj.a << endl;}
int main() {    OpOverloading a(9), b;    cout << a << b << endl;    a = b;    cout << a << b++ << endl;    cout << "b: " << b << endl;    return 0;}
