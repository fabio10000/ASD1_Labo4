#include <iostream>
#include "ArrayDeque.h"

using namespace std;

void testAPI() {
   cout << "Test API" << endl;

   ArrayDeque<int> dq(10);

   std::cerr << "1.1" << std::endl;
   cout << " size " << dq.size() << endl;
   std::cerr << "1.2" << std::endl;
   cout << " capacity " << dq.capacity() << endl;
   std::cerr << "1.3" << std::endl;
   cout << " empty " << boolalpha << dq.empty() << endl;
   std::cerr << "1.4" << std::endl;
   dq.push_back(0);
   std::cerr << "1.5" << std::endl;
   cout << " back " << dq.back() << endl;
   std::cerr << "1.6" << std::endl;
   dq.back() = 1;
   std::cerr << "1.7" << std::endl;
   dq.push_front(0);
   std::cerr << "1.8" << std::endl;
   cout << " front " << dq.front() << endl;
   dq.front() = 2;
   dq.pop_front();
   dq.pop_back();
}

void testConstAPI()
{
   cout << endl << "Test const API" << endl;

   ArrayDeque<int> dq(10);
   std::cerr << "2.1" << std::endl;
   dq.push_back(0);
   std::cerr << "2.2" << std::endl;
   const ArrayDeque<int> cdq = dq;
   std::cerr << "2.3" << std::endl;
   cout << " size " << cdq.size() << endl;
   std::cerr << "2.4" << std::endl;
   cout << " capacity " << cdq.capacity() << endl;
   std::cerr << "2.5" << std::endl;
   cout << " empty " << boolalpha << cdq.empty() << endl;
   std::cerr << "2.6" << std::endl;
   cout << " front " << cdq.front() << endl;
   std::cerr << "2.7" << std::endl;
   cout << " back " << cdq.back() << endl;
   std::cerr << "2.8" << std::endl;
}

void fillDeque(ArrayDeque<int>& dq, size_t n)
{
   size_t cap = dq.capacity();
   for(int i = 0; i < n; ++i) {
      if(i%2)
         dq.push_front(i);
      else
         dq.push_back(i);

      if(cap != dq.capacity()) {
         cout << " capacity changed: " << cap << " -> " << dq.capacity() << endl;
         cap = dq.capacity();
      }
   }
}

void emptyDequeFromFront(ArrayDeque<int>& dq)
{
   cout << " Using " << dq.size() << "/" << dq.capacity() << endl;
   cout << " Empty from front: ";
   while(not dq.empty()) {
      cout << dq.front() << " ";
      dq.pop_front();
   }
   cout << endl;
}

void emptyDequeFromBack(ArrayDeque<int>& dq)
{
   cout << " Using " << dq.size() << "/" << dq.capacity() << endl;
   cout << " Empty from back: ";

   while(not dq.empty()) {
      cout << dq.back() << " ";
      dq.pop_back();
   }
   cout << endl;
}

void testConstantCapacity() {
   cout << endl << "Test constant capacity" << endl;

   ArrayDeque<int> dq(20);
   fillDeque(dq, 12);
   emptyDequeFromFront(dq);
   fillDeque(dq, 12);
   emptyDequeFromBack(dq);
}

void testVariableCapacity() {
   cout << endl << "Test variable capacity" << endl;

   ArrayDeque<int> dq;
   fillDeque(dq,7);
   emptyDequeFromFront(dq);
   fillDeque(dq,17);
   emptyDequeFromBack(dq);
}
void showVector(vector<int>& v) {
   cout << "[";
   for (auto elem: v) {
      cout << elem << ", ";
   }
   cout << "]" << endl;
}
int main() {
   std::cerr << "1" << std::endl;
   testAPI();
   std::cerr << "2" << std::endl;
   testConstAPI();
   std::cerr << "3" << std::endl;
   testConstantCapacity();
   std::cerr << "4" << std::endl;
   testVariableCapacity();
   std::cerr << "5" << std::endl;
   /*ArrayDeque<int> dq;
   size_t cap = dq.capacity();
   dq.push_front(2);
   dq.push_front(5);
   dq.push_front(6);
   dq.push_front(7);
   dq.push_back(9);
   dq.push_back(8);
   dq.push_back(10);
   dq.push_front(11);
   dq.push_front(12);
   dq.show();

   cout << "front : " << dq.front() << " | back : " << dq.back() << endl;*/
}