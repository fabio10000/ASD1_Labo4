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
   ArrayDeque& operator=(const ArrayDeque& rhs) {
      buffer = rhs.buffer;
      debut = rhs.debut;
      taille = rhs.taille;
   };

   size_type size() const {
      return buffer.size();
   };
   size_type capacity() const {
      return taille;
   };
   bool empty() const {
      return taille == 0;
   };
   void show() {
      std::cout << "[";
      for (auto elem : buffer) {
         std::cout << elem << ", ";
      }
      std::cout << "]" << std::endl;
   }
   void newVector() {
      if (size() == 0) {
         buffer.resize(1);
      } else {
         size_type nb_elems = size() - debut - 1;
         std::vector<value_type> tmp(size() * 2);
         tmp.insert(tmp.begin(), buffer.rbegin(), buffer.rend() - debut);
         tmp.insert(tmp.begin() + nb_elems, buffer.begin(), buffer.begin() + debut);
         debut = size() - 1;
         swap(tmp, buffer);
      }
   }
   ArrayDeque& push_back(value_type val) {
      if (taille == size()) {
         newVector();
      }
      size_type indice = (taille > 0) ? (size() - (taille - debut)) : 0;
      ++taille;
      buffer.at(indice) = val;
   };
   ArrayDeque& push_front(value_type val) {
      if (taille == size()) {
         newVector();
         show();
      }

      if( taille != 0) {
         ++debut;
      }
      ++taille;
      buffer.at(debut) = val;
   };
   const_reference back() const {
      return back();
   }
   reference back() {
      size_type indice = (taille > 0) ? (taille - debut - 1) : 0;
      if (indice != 0) {
         indice = size() - indice;
      }

      return buffer.at(indice);
   };

   const_reference front() const {
      return front();
   }
   reference front() {
      return buffer.at(debut);
   };
   ArrayDeque& pop_front() {
      for (size_t i = debut;  i < taille - 1 ; ++i) {
         buffer.at(i) == buffer.at(i + 1);
      }

      return *this;
   };
   ArrayDeque& pop_back() {
      if(debut > 0) {
         for (size_t i = --debut;  i < taille - 1 ; ++i) {
            buffer.at(i) == buffer.at(i + 1);
         }
      }

      return *this;
   };


};

#endif /* ArrayDeque_hpp */