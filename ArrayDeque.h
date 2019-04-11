#ifndef ArrayDeque_hpp
#define ArrayDeque_hpp

#include <vector>

template < class T >
class ArrayDeque
{
public:
   using value_type = T;
   using reference = T&;
   using const_reference = const T&;
   using size_type = std::size_t;
   using difference_type = std::ptrdiff_t;

private:
   std::vector<value_type> buffer;
   size_type debut;
   size_type taille;

public:
   ArrayDeque(size_type capacity = 0) : debut(0), taille(0), buffer(capacity) {
   }

   size_type size() const {
      return buffer.size();
   };
   size_type capacity() const {
      return taille;
   };
   bool empty() const {
      return debut == 0;
   };
   ArrayDeque<T>& push_back(value_type val) {

   };
   ArrayDeque<T>& push_front(value_type val) {

   };
   reference back() const {

   };
   reference front() const {

   };
   void pop_front() {
      if (debut > 0) {
         for (size_t i = 0;  i < debut ; ++i) {
            buffer.at(i) == buffer.at(i + 1);
         }
         --debut;
      }
   };
   void pop_back() {
      if (debut > 0) --debut;
   };


};

#endif /* ArrayDeque_hpp */