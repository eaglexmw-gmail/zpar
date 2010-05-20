#ifndef _HASH_FUNCTION_UTIL_H
#define _HASH_FUNCTION_UTIL_H

#include "definitions.h"

// The idea here is to provide a global hash function for basic types
// but for all types defined in my code they are give a hash() member
// so that the inline hash functions are always there.

inline unsigned long hash(const unsigned int &i) {return i;}
inline unsigned long hash(const int &i) {return i>0?i:-i;}

inline const unsigned long &hash(const unsigned long &i) {return i;}
inline unsigned long hash(const long &i) {return i>0?i:-i;}

inline unsigned long hash(const long long &i) {return i>0?i:-i;}
inline unsigned long hash(const unsigned long long &i) {return i;}

inline unsigned long hash(const string &s) {unsigned long retval=0; for (unsigned long i=0; i<s.size(); ++i) retval=retval*37+(static_cast<unsigned char>(s[i])&127); return retval;}

template<typename T>
inline unsigned long hash(const T& t) { return t.hash(); }

template<typename T1, typename T2>
//inline unsigned long hash(const pair<T1, T2> &o) { return hash(o.first)*29 + hash(o.second) ; }
inline unsigned long hash(const pair<T1, T2> &o) { 
   return (hash(o.first)<<8) + hash(o.first) + hash(o.second); 
}

#endif
