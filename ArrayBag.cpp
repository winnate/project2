/** @file
 *
 *  @course CS1521
 *  @section 1
 *
 *  Implementation file for the class ArrayBag.
 *
 *  Adapted from pages 100-111 in Carrano 6e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *
 *  @date $Date: 2015-01-14 16:55:51 -0600 (Wed, 14 Jan 2015) $
 *
 *  @version 6.0 $Revision: 1461 $ */

template <typename ItemType>
ArrayBag<ItemType>::ArrayBag()
   : itemCount(0),
     maxItems(DEFAULT_CAPACITY),
	 inUse()
	 {
		 cout << "Constructor Called"  << endl;
}

template <typename ItemType>
ArrayBag<ItemType>::~ArrayBag(){
	// delete [] inUse;
	// delete [] items;
}

template <typename ItemType>
int ArrayBag<ItemType>::getCurrentSize() const {

   return itemCount;
}

template <typename ItemType>
bool ArrayBag<ItemType>::isEmpty() const {

   return itemCount == 0;
}

template <typename ItemType>
int ArrayBag<ItemType>::add(const ItemType& newEntry) {
	
	int emptyIndex = getNextEmptyIndex();
	if (emptyIndex >= 0 && (itemCount < maxItems))
	{
		items[emptyIndex] = newEntry;
		inUse[emptyIndex] = true;
		itemCount++;
	}
	return emptyIndex;
}

template <typename ItemType>
ItemType ArrayBag<ItemType>::remove(const int receipt) {

	ItemType removedObject;
	if (inUse[receipt])
	{
		removedObject = items[receipt];
		items[receipt] = items[itemCount - 1];
		items[itemCount - 1] = "";
		inUse[itemCount - 1] = false;
		itemCount--;
	}
	return removedObject;
}

template <typename ItemType>
void ArrayBag<ItemType>::clear() {

   itemCount = 0;
}

template <typename ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const {

   bool found = false;
   int curIndex = 0;

   while (!found && curIndex < itemCount) {
      if (anEntry == items[curIndex]) {
         found = true;
      }
      ++curIndex;
   }

   return found;
}

template <typename ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const {

   int frequency = 0;
   int curIndex = 0;

   while (curIndex < itemCount) {
      if (items[curIndex] == anEntry) {
         ++frequency;
      }
      ++curIndex;
   }

   return frequency;
}

template <typename ItemType>
vector<ItemType> ArrayBag<ItemType>::toVector() const {

   vector<ItemType> bagContents;

   for (int i = 0; i < itemCount; ++i) {
      bagContents.push_back(items[i]);
   }

   return bagContents;
}

template <typename ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const {

   bool found = false;
   int result = -1;
   int searchIndex = 0;

   while (!found && searchIndex < itemCount) {
      if (items[searchIndex] == target) {
         found = true;
         result = searchIndex;
      }
      else {
         ++searchIndex;
      }
   }

   return result;
}


template <typename ItemType>
int ArrayBag<ItemType>::getNextEmptyIndex(){
	int i = 0;
	bool found = false;
	int emptyIndex = -1;
	while (!found)
	{
		if(inUse[i] == 0)
		{
			emptyIndex = i;
			found = true;
		}
		else
			i++;
	}
	return emptyIndex;
}

template <typename ItemType>
void ArrayBag<ItemType>::printInUse(){
	for (int i = 0; i < DEFAULT_CAPACITY; i++)
		cout << inUse[i];
}