
#include <iostream>
using namespace std;

class Box {
   public:
      double getVolume(void) {
         return length * breadth * height;
      }

      Box(){}

      Box(int a,int b,int c):length(a),breadth(b),height(c){}

      Box(const Box&p):length(p.length),breadth(p.breadth),height(p.height){}
      // Overload + operator to add two Box objects.
 friend   Box operator+(const Box&,const Box&);

   private:
      double length;      // Length of a box
      double breadth;     // Breadth of a box
      double height;      // Height of a box
};
  Box operator+(const Box& a,const Box& b) {
        return Box(a.length+b.length,a.breadth+b.breadth,a.height+b.height);
      }


// Main function for the program
int main() {
   Box Box1(6.0,7.0,5.0);                // Declare Box1 of type Box
   Box Box2(12.0,13.0,10.0);                // Declare Box2 of type Box
   Box Box3;                // Declare Box3 of type Box
   double volume = 0.0;     // Store the volume of a box here


   // volume of box 1
   volume = Box1.getVolume();
   cout << "Volume of Box1 : " << volume <<endl;

   // volume of box 2
   volume = Box2.getVolume();
   cout << "Volume of Box2 : " << volume <<endl;

   // Add two object as follows:
   Box3 = Box1 + Box2;

   // volume of box 3
   volume = Box3.getVolume();
   cout << "Volume of Box3 : " << volume <<endl;

   return 0;
}
