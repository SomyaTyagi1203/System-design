#include<bits/stdc++.h>
using namespace std;

class Singleton {

private:
    static Singleton* instance;

    Singleton(){
        cout<<"Singleton Constructor called. New Object created"<<endl;                  // We have created the Constructor as private such that no one can create the object using the new keyword
    }
public:
    static Singleton* getInstance(){                          // static function to get the single instance such that the object is created once 
        if(instance == nullptr){
            instance = new Singleton();
        }
        return instance;
    }
};

Singleton* Singleton::instance = nullptr;

int main(){
    Singleton* s1 = Singleton::getInstance();                   
    Singleton* s2 = Singleton::getInstance();

    cout<< (s1==s2) <<endl;
}

// This code is not thread safe as two threads can enter the getInstance() function at the same time and two objects will be createc and in this way idea
// for Singleton design pattern will be voilated 


