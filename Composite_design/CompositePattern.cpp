#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>

using namespace std;

class FileSystemItem {

public:
    virtual ~FileSystemItem() {}
    virtual void ls(int indent = 0) = 0;
    
}