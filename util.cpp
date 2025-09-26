#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}
/*

Complete the parseStringToWords() in util.cpp according to the specification given 
above for taking a string of many words and splitting them into individual keywords 
(split at punctuation, with at least 2 character words)
*/
/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
    set<std::string> parsedWords;

    std::string parsedString = trim(rawWords);
    std::string currSubstring = "";

    for(char c : parsedString){ //iterate through words
        if(isalpha(c)){
            currSubstring += c;
        } else {
            if( currSubstring.length() >= 2){
                parsedWords.insert(currSubstring);
            }
            currSubstring = "";
        }
    }

    if (currSubstring.length() >= 2){
        parsedWords.insert(currSubstring);
    }

    return parsedWords;
    

    /*
    start from the first letter. walk through checking if there is a 
    */
    

}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
