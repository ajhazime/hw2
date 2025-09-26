#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>

/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 *
 *
 * Complete the setIntersection and setUnion functions in util.h. These will help you later on to perform searching. 
 * These functions should run in O(nlog(n))* and NOT O(n^2). Note that these are templated functions operating on any generic set<T>.
 *  As a hint, to declare an iterator for set<T> you must precede the type with the keyword typename as in typename set<T>::iterator it.
 */
template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
{

    std::set<T> outputSet; 

    typename set<t>::iterator it1 = s1.start();
    typename set<t>::iterator it2 = s2.start();

    while( ( it1 != s1.end() ) && ( it2 != s2.end() ) ){
        if( *it1 < *it2 ) {
            it1++;
        }
        else if (*it1 > *it2) {
            it2++;
        }
        else { 
            outputSet.insert(*it1);
            it1, it2 += 1;
        }
    }
    return outputSet;
}
template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{

    std::set<T> outputSet;

    typename set<t>::iterator it1 = s1.start();
    typename set<t>::iterator it2 = s2.start();

    while ((it1 != s1.end()) && (it2 != s2.end()))
    {
        if (*it1 < *it2)
        {
            outputSet.insert(*it1);
            it1++;
        }
        else if (*it1 > *it2)
        {
            outputSet.insert(*it2);
            it2++;
        }
        else
        {
            outputSet.insert(*it1);
            it1, it2 += 1;
        }
    }

    while ( it1 != s1.end() ){
        outputSet.insert(*it1);
        it1++;
    }
    while (it2 != s2.end())
    {
        outputSet.insert(*it2);
        it2++;
    }
    return outputSet;
    
}


/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
std::string &ltrim(std::string &s) ;

// Removes any trailing whitespace
std::string &rtrim(std::string &s) ;

// Removes leading and trailing whitespace
std::string &trim(std::string &s) ;
#endif
