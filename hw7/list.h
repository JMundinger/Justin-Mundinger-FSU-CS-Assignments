// Fig. 21.4: list.h
// Template List class definition.
#ifndef LIST_H
#define LIST_H

#include <iostream>

using std::cout;

#include <new>
#include "listnode.h"  // ListNode class definition

template< class NODETYPE >
class List {

public:
   List();      // constructor
   ~List();     // destructor
   void insertAtFront( const NODETYPE & );
   void insertAtBack( const NODETYPE & );
   void insertMiddle( const NODETYPE &, int );
   bool removeMiddle( NODETYPE &, int );
   bool removeFromFront( NODETYPE & );
   bool removeFromBack( NODETYPE & );
   bool isEmpty() const;
   void print() const;

private:
   ListNode< NODETYPE > *firstPtr;  // pointer to first node
   ListNode< NODETYPE > *lastPtr;   // pointer to last node
   // utility function to allocate new node
   ListNode< NODETYPE > *getNewNode( const NODETYPE & );
   int size;
}; // end class List

// default constructor
template< class NODETYPE >
List< NODETYPE >::List()
   : firstPtr( 0 ),
     lastPtr( 0 )
{
  size = 0;
   // empty body

} // end List constructor

// destructor
template< class NODETYPE >
List< NODETYPE >::~List()
{
   if ( !isEmpty() ) {    // List is not empty
//      cout << "Destroying nodes ...\n";

      ListNode< NODETYPE > *currentPtr = firstPtr;
      ListNode< NODETYPE > *tempPtr;

      while ( currentPtr != 0 )         // delete remaining nodes
      {
         tempPtr = currentPtr;

// commented out the output -- no need to print what we are deallocating
//         cout << tempPtr->data << '\n';

         currentPtr = currentPtr->nextPtr;
         delete tempPtr;

      }

   }

//   cout << "All nodes destroyed\n\n";

} // end List destructor

// insert node at front of list
template< class NODETYPE >
void List< NODETYPE >::insertAtFront( const NODETYPE &value )
{
   ListNode< NODETYPE > *newPtr = getNewNode( value );

   if ( isEmpty() )  // List is empty
      firstPtr = lastPtr = newPtr;

   else {  // List is not empty
      newPtr->nextPtr = firstPtr;
      firstPtr = newPtr;

   } // end else
  size++;
} // end function insertAtFront

// insert node at back of list
template< class NODETYPE >
void List< NODETYPE >::insertAtBack( const NODETYPE &value )
{
   ListNode< NODETYPE > *newPtr = getNewNode( value );

   if ( isEmpty() )  // List is empty
      firstPtr = lastPtr = newPtr;

   else {  // List is not empty
      lastPtr->nextPtr = newPtr;
      lastPtr = newPtr;

   } // end else
  size++;
} // end function insertAtBack
template< class NODETYPE >
void List< NODETYPE >::insertMiddle( const NODETYPE &value, int x)
{
  ListNode< NODETYPE > *newPtr = getNewNode(value);
  if( isEmpty() )
    firstPtr = lastPtr = newPtr;
  else
  {
    if(x > size)
      insertAtBack(value);
    else if(x <= 1)
      insertAtFront(value);
    else
    {
      ListNode< NODETYPE > *currentPtr = firstPtr;
      int i = 1;
      while(i < x-1)
      {
        currentPtr = currentPtr->nextPtr;
        ++i;
      }
      newPtr->nextPtr = currentPtr->nextPtr;
      currentPtr->nextPtr = newPtr;
    }
  }
  size++;
}
template< class NODETYPE >
bool List< NODETYPE >::removeMiddle( NODETYPE &value, int x)
{
  if(isEmpty() )
    return false;
  else if(x > size || x <= 0)
    return false;
  else
  {
    ListNode< NODETYPE > *tempPtr = firstPtr;
    if(firstPtr == lastPtr)
      firstPtr = lastPtr = 0;
    else if(x == 1)
    {
      removeFromFront(value);
      return true;
    }
    else if(x == size)
    {
      removeFromBack(value);
      return true;
    }
    else
    {
      ListNode< NODETYPE > *currentPtr = firstPtr;
      ListNode< NODETYPE > *previous = firstPtr;
      ListNode< NODETYPE > *next = firstPtr;
      int i = 1;
      while(i < x)
      {
        tempPtr = currentPtr;
        currentPtr = currentPtr->nextPtr;
        ++i;
      }
      for(int j=1; j < x-1; j++)
        previous= previous->nextPtr;
      for(int k=1; k <= x; k++)
        next = next->nextPtr;
      tempPtr = tempPtr->nextPtr;
      currentPtr->nextPtr = 0;
      previous->nextPtr = currentPtr->nextPtr = next;
    }
    value = tempPtr->data;
    delete tempPtr;
    return true;
    size--;
  }
}
// delete node from front of list
template< class NODETYPE >
bool List< NODETYPE >::removeFromFront( NODETYPE &value )
{
   if ( isEmpty() )  // List is empty
      return false;  // delete unsuccessful

   else {
      ListNode< NODETYPE > *tempPtr = firstPtr;

      if ( firstPtr == lastPtr )
         firstPtr = lastPtr = 0;
      else
         firstPtr = firstPtr->nextPtr;

      value = tempPtr->data;  // data being removed
      delete tempPtr;

      return true;  // delete successful

   } // end else
  size--;
} // end function removeFromFront

// delete node from back of list
template< class NODETYPE >
bool List< NODETYPE >::removeFromBack( NODETYPE &value )
{
   if ( isEmpty() )
      return false;  // delete unsuccessful

   else {
      ListNode< NODETYPE > *tempPtr = lastPtr;

      if ( firstPtr == lastPtr )
         firstPtr = lastPtr = 0;
      else {
         ListNode< NODETYPE > *currentPtr = firstPtr;

         // locate second-to-last element
         while ( currentPtr->nextPtr != lastPtr )
            currentPtr = currentPtr->nextPtr;

         lastPtr = currentPtr;
         currentPtr->nextPtr = 0;

      } // end else

      value = tempPtr->data;
      delete tempPtr;

      return true;  // delete successful

   } // end else
  size--;
} // end function removeFromBack

// is List empty?
template< class NODETYPE >
bool List< NODETYPE >::isEmpty() const
{
   return firstPtr == 0;
} // end function isEmpty

// return pointer to newly allocated node
template< class NODETYPE >
ListNode< NODETYPE > *List< NODETYPE >::getNewNode(
   const NODETYPE &value )
{
   return new ListNode< NODETYPE >( value );

} // end function getNewNode

// display contents of List
template< class NODETYPE >
void List< NODETYPE >::print() const
{
   if ( isEmpty() ) {
      cout << "The list is empty\n\n";
      return;

   } // end if

   ListNode< NODETYPE > *currentPtr = firstPtr;

   cout << "The list is: ";

   while ( currentPtr != 0 ) {
      cout << currentPtr->data << ' ';
      currentPtr = currentPtr->nextPtr;

   } // end while

   cout << "\n\n";

} // end function print

#endif
