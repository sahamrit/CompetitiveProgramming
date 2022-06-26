#include<iostream>
using namespace std;
class Box {
public:
    Box(int width, int length, int height){
       m_width = width;
       m_length = length;
       m_height = height;
    }


    int m_width;
    int m_length;
    int m_height;
};

class StorageBox : public Box {
public:
    StorageBox(int width, int length, int height,  string const &label) : Box(width, length, height),m_label(label){

    }

    string m_label;
};

int main(){

    const string aLabel = "aLabel";
    StorageBox sb(1, 2, 3, aLabel);
    cout<<sb.m_label<<endl<<sb.m_height<<endl<<sb.m_length<<endl<<sb.m_width;
}
