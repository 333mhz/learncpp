#ifndef STL_H
#define STL_H

#include "header.h"

//2
//vector
void test021()
{
    std::vector<int> v1;
    for(int c = 0;c <6;++c)
        v1.push_back(c+1);
    
    for(int i = 0;i <6;++i)
        std::cout << v1[i] <<' ';
    std::cout << std::endl;
}
//deque
void test022()
{
    std::deque<int> d1;
    for(int c = 0;c <6;++c)
    {
        d1.push_back(c);
        d1.push_front(c+1);
    }    
    
    for(int i = 0;i <6;++i)
        std::cout << d1[i] <<' ';
    std::cout << std::endl;
}
//3
void test031()
{
    std::vector<int> v1;
    for(int c = 0;c <6;++c)
        v1.push_back(c+1);

    std::vector<int>::const_iterator it;
    it = v1.begin();
    while(it != v1.end())
    {
        std::cout << *it <<' ';
        ++it;
    }
    std::cout << '\n';
}

void test032()
{
    std::list<int> v1;
    for(int c = 0;c <6;++c)
        v1.push_back(c+1);

    std::list<int>::const_iterator it;
    it = v1.begin();
    while(it != v1.end())
    {
        std::cout << *it <<' ';
        ++it;
    }
    std::cout << '\n';
}

void test033()
{
    std::set<int> myset;
    myset.insert(7);
    myset.insert(2);
    myset.insert(-6);
    myset.insert(8);
    myset.insert(1);
    myset.insert(-4);
 
    std::set<int>::const_iterator it; // declare an iterator
    it = myset.begin(); // assign it to the start of the set
    while (it != myset.end()) // while it hasn't reach the end
    {
        std::cout << *it << " "; // print the value of the element it points to
        ++it; // and iterate to the next element
    }
 
    std::cout << '\n';
}

void test034()
{
    std::map<int, std::string> mymap;
	mymap.insert(std::make_pair(4, "apple"));
	mymap.insert(std::make_pair(2, "orange"));
	mymap.insert(std::make_pair(1, "banana"));
	mymap.insert(std::make_pair(3, "grapes"));
	mymap.insert(std::make_pair(6, "mango"));
	mymap.insert(std::make_pair(5, "peach"));
 
	auto it{ mymap.cbegin() }; // declare a const iterator and assign to start of vector
	while (it != mymap.cend()) // while it hasn't reach the end
	{
		std::cout << it->first << "=" << it->second << " "; // print the value of the element it points to
		++it; // and iterate to the next element
	}
 
	std::cout << '\n';
}

//4
void test041()
{
    std::list<int> li;
    for (int nCount=0; nCount < 6; ++nCount)
        li.push_back(nCount);
 
    std::list<int>::const_iterator it; // declare an iterator
    it = min_element(li.begin(), li.end());
        std::cout << *it << ' ';
    it = max_element(li.begin(), li.end());
        std::cout << *it << ' ';
 
	std::cout << '\n';
}

void test042()
{
    std::list<int> li;
    for (int nCount=0; nCount < 6; ++nCount)
        li.push_back(nCount);
 
    std::list<int>::iterator it; // declare an iterator
    it = find(li.begin(), li.end(), 3); // find the value 3 in the list
    li.insert(it, 8); // use list::insert to insert the value 8 before it
 
    for (it = li.begin(); it != li.end(); ++it) // for loop with iterators
        std::cout << *it << ' ';
 
	std::cout << '\n';
}

void test043()
{
    std::vector<int> vect;
    vect.push_back(7);
    vect.push_back(-3);
    vect.push_back(6);
    vect.push_back(2);
    vect.push_back(-5);
    vect.push_back(0);
    vect.push_back(4);
 
    std::sort(vect.begin(), vect.end()); // sort the list
 
    std::vector<int>::const_iterator it; // declare an iterator
    for (it = vect.begin(); it != vect.end(); ++it) // for loop with iterators
        cout << *it << ' ';
 
    std::cout << '\n';
 
    std::reverse(vect.begin(), vect.end()); // reverse the list
 
    for (it = vect.begin(); it != vect.end(); ++it) // for loop with iterators
        std::cout << *it << ' ';
 
	std::cout << '\n';
}
#endif