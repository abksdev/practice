#include <iostream>
using namespace std;

class OpOverloading{
    int a;
    public:
    OpOverloading(int x = 10):a(x){ cout << "Constructor called" << endl; }
    ~OpOverloading(){ cout << "Destructor called" << endl; }
    
    OpOverloading operator+(const OpOverloading& obj){
        cout << "addition overloaded" << endl;
        OpOverloading ob;
        ob.a = this->a + obj.a;
        return ob;
    }
    
    OpOverloading operator-(const OpOverloading& obj){
        cout << "substraction overloaded" << endl;
        OpOverloading ob;
        ob.a = this->a - obj.a;
        return ob;
    }
    
    OpOverloading operator*(const OpOverloading& obj){
        cout << "multiplication overloaded" << endl;
        OpOverloading ob;
        ob.a = this->a * obj.a;
        return ob;
    }
    
    void operator=(const OpOverloading& obj){
        cout << "assignment overloaded" << endl;
        this->a = obj.a;
    }
    
    OpOverloading& operator++(){
        cout << "pre-increment overloaded" << endl;
        this->a += 1;
        return *this;
    }
    
    OpOverloading operator++(int){
        cout << "post-increment overloaded" << endl;
        OpOverloading obj = *this;
        this->a += 1;
        return obj;
    }
    
    OpOverloading& operator--(){
        cout << "pre-decrement overloaded" << endl;
        this->a -= 1;
        return *this;
    }
    
    OpOverloading operator--(int){
        cout << "post-decrement overloaded" << endl;
        OpOverloading obj = *this;
        this->a -= 1;
        return obj;
    }
    
    OpOverloading* operator&(){
        cout << "Address Of overloaded" << endl;
        return this;
    }
    
    void operator()(){
        cout << "Parenthesis overloaded" << endl;
    }
    
    void operator[](int index){
        cout << "Subscript overloaded" << endl;
        cout << "Index = " << index <<endl;
    }
    
    void* operator new (size_t size){
        cout << "new overloaded | size = " << size << endl;
        //return ::new OpOverloading();    /* This can also be used but in this case contructor will be called twice */
        return malloc(size);
    }
    
    void operator delete (void *ptr){
        cout << "delete overloaded" << endl;
        free(ptr);
    }
    
    void* operator new[] (size_t size){
        cout << "new[] overloaded | size = " << size << endl;
        return malloc(size);
    }
    
    void operator delete[] (void *ptr){
        cout << "delete[] overloaded" << endl;
        free(ptr);
    }
    
    friend ostream& operator << (ostream& out,const OpOverloading& obj);
    friend istream& operator >> (istream& in,OpOverloading& obj);
};

ostream& operator << (ostream& out,const OpOverloading& obj){
    cout << "value: " << obj.a << endl;
}

istream& operator >> (istream& in,OpOverloading& obj){
    cout << "Enter int value: ";
    in >> obj.a;
}

int main() {
    OpOverloading *ptr = new OpOverloading[2];
    delete[] ptr;
    return 0;
}