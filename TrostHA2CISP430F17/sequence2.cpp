//  Hannah Trost
//  CISP 430 A2 Fall 2017
//  TrostHA2CISP43017F
//  FILE: sequence2.cpp
//  CLASS IMPLEMENTED: sequence class

#include <cassert>
#include "sequence2.h"
using namespace std;

namespace CISP430_A2
{

    //basic constructor constructs to given initial size, default 30
sequence::sequence(size_type initial_size)
{
    used = 0;
    capacity = initial_size;
    current_index = 0;
    data = new value_type[capacity];
};

    
sequence::sequence(const sequence& entry)
{
    data = new value_type[entry.capacity];
    capacity = entry.capacity;
    used = entry.used;
    current_index = entry.current_index;
    for (size_type i = 0; i < used; i++)
        data[i] = entry.data[i];
}

void sequence::start( )
{
    current_index = 0;
}

void sequence::advance()
{
    current_index++;
}

void sequence::insert(const value_type& entry)
{
    size_type i;
    if(used == capacity)
        resize(capacity * 1.1);
    if(!is_item())
        current_index = 0;
    used++;
    for(i = used - 1; i > current_index; i--) //iterate backwards to shift items forward
    {
        data[i] = data[i-1];
    }
    data[current_index] = entry;
}

void sequence::attach(const value_type& entry)
{
    size_type i;
    if(used == capacity)
        resize(capacity*1.1);
    if(current_index >= used && used != 0)
        current_index = used - 1;
    used++;
    if(used == 1)
    {
        data[0] = entry;
        return;
    }
    for(i = used - 1; i > current_index + 1; i--)
    data[i] = data[i-1];
    current_index++;
    data[current_index] = entry;
}

void sequence::remove_current( )
{
    size_type i;
    assert(is_item( ));
    for(i = current_index; i < used - 1; i++)
        data[i] = data[i+1];
    used--;
}

void sequence::resize(size_type new_capacity)
{
    value_type *thing;
    thing = new value_type[new_capacity];
    for(size_type i = 0; i < capacity; i++)
        thing[i] = data[i];
    delete[] data;
    data = thing;
    capacity = new_capacity;
}

void sequence::operator =(const sequence& entry)
{
    if(capacity < entry.capacity)
        resize(entry.capacity);
    used = entry.used;
    current_index = entry.current_index;
    for (int i = 0; i < used; i++)
        data[i] = entry.data[i];
}

sequence::size_type sequence::size( ) const
{
    return used;
}

bool sequence::is_item( ) const
{
    if(current_index < used)
        return true;
    else
        return false;
}

sequence::value_type sequence::current( ) const
{
    assert(is_item( ));
    return data[current_index];
}

sequence::~sequence( )
{
    delete [] data;
}
    
}
