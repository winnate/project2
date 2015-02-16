/** @file
 *
 *  @course CS1521
 *  @section 1
 *
 *  Header file for an array-based implementation of the ADT bag.
 *
 *  Adapted from page 99-100 in Carrano 6e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *
 *  @date $Date: 2015-01-28 16:43:15 -0600 (Wed, 28 Jan 2015) $
 *
 *  @version 6.0 $Revision: 1586 $ */

#ifndef _ARRAY_BAG
#define _ARRAY_BAG

#include "BagInterface.h"

/** @class ArrayBag ArrayBag.h "ArrayBag.h"
 *
 *  Specification of an array-based ADT bag. */
template <typename ItemType>
class ArrayBag : public BagInterface<ItemType> {
private:
   /** Maximum capacity of this bag. */
   static const int DEFAULT_CAPACITY = 6;

   /** Number of items in this bag. */
   int itemCount;

   /** Maximum capacity of this bag. */
   int maxItems;

   /** Data storage. */
   
   
   
   
   
   ItemType items[DEFAULT_CAPACITY];
   //ItemType* items = new ItemType[DEFAULT_CAPACITY];
   
   
   bool inUse[DEFAULT_CAPACITY];
   //bool* inUse = new bool[DEFAULT_CAPACITY];
   
   
   
   
   
   /** Gets the index of target in the array 'items' in this bag.
    *
    * @param target The ItemType value to retrieve the index of.
    *
    * @return The index of the element in the array 'items' that
    *         contains 'target' or -1 if the array does not contain
    *         'target'. */
   int getIndexOf(const ItemType& target) const;

public:
   /** Default constructor. */
   ArrayBag();
   
   ~ArrayBag();

   int getCurrentSize() const;

   bool isEmpty() const;

   int add(const ItemType& newEntry);

   ItemType remove(const int receipt);

   void clear();

   int getFrequencyOf(const ItemType& anEntry) const;

   bool contains(const ItemType& anEntry) const;

   vector<ItemType> toVector() const;
   
   int getNextEmptyIndex();
   
   void printInUse();
};

#include "ArrayBag.cpp"

#endif
