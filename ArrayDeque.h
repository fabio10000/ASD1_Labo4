/**
 * @authors Basset Nils, Limem Wènes, Marques Fabio
 * @file    ArrayDeque.h
 * @date    24 April 2019
 *
 * Labo 4:  Création d'une structure de données Array Deque qui permet les opérations
 *          write/read des deux côtés toujours en O(1), sauf lors de dépassements de capacités.
 *          Cette structure doit implémenter les 4 opérations suivantes : push, pop, back, front
 */
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
   ArrayDeque(size_type capacity = 0) : debut(0), taille(0), buffer(capacity) {}

   /**
    * @return nb elements dans le buffer
    */
   size_type size() const {
      return taille;
   }

   /**
    * @return nb elements que peut contenir le buffer
    */
   size_type capacity() const {
      return buffer.size();
   }

   /**
    * @return si le buffer est vide
    */
   bool empty() const {
      return taille == 0;
   }

   /**
    * @return index physique du dernier élément de buffer
    */
   size_type getLastElemIndex() const {
      return !empty() ? (debut + taille - 1) % capacity() : 0;;
   }

   /**
    * Double la taille de buffer, sauf si ça taille = 0 et dans ce cas la taille devient = 1
    */
   void resizeVector() {
      if (capacity() == 0) {
         buffer.resize(1);
      } else {
         std::vector<value_type> tmp(capacity() * 2);

         for (size_type i = 0; i < capacity(); ++i) {
            tmp.at(i) = buffer.at((i + debut) % capacity());
         }

         debut = 0;
         swap(tmp, buffer);
      }
   }

   /**
    * insére un élément a la fin de buffer
    * @param val : valeur a insérer
    * @return l'objet lui même pour pouvoir chainer les appels
    */
   ArrayDeque& push_back(value_type val) {
      if (taille == capacity()) {
         resizeVector();
      }

      buffer.at((getLastElemIndex() + 1) % capacity()) = val;
      ++taille;

      return *this;
   }

   /**
    * insére un élément en première position de buffer
    * @param val : valeur a insérer
    * @return l'objet lui même pour pouvoir chainer les appels
    */
   ArrayDeque& push_front(value_type val) {
      if (taille == capacity()) {
         resizeVector();
      }

      if(!empty()) {
         debut == 0 ? debut = capacity() - 1 : --debut;
      }
      ++taille;
      buffer.at(debut) = val;

      return *this;
   }

   /**
    * @return reference vers le dernier élément de buffer
    */
   const_reference back() const {
      return buffer.at(getLastElemIndex());
   }
   /**
    * @return reference vers le dernier élément de buffer
    */
   reference back() {
      return const_cast<reference>(const_cast<const ArrayDeque*>(this)->back());
   }

   /**
    * @return reference vers le premier élément de buffer
    */
   const_reference front() const {
      return buffer.at(debut);
   }
   /**
    * @return reference vers le premier élément de buffer
    */
   reference front() {
      return const_cast<reference>(const_cast<const ArrayDeque*>(this)->front());
   }

   /**
    * Supprime le premier élément de buffer
    * @return l'objet lui même pour pouvoir chainer les appels
    */
   ArrayDeque& pop_front() {
      if (!empty()) {
         debut + 1 == capacity() ? debut = 0 : ++debut;
         --taille;
      }

      return *this;
   }

   /**
    * Supprime le dernier élément de buffer
    * @return l'objet lui même pour pouvoir chainer les appels
    */
   ArrayDeque& pop_back() {
      if (!empty())
         --taille;

      return *this;
   }

};

#endif /* ArrayDeque_hpp */