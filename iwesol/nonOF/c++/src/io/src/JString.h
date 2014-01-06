/**
 * @file String.h
 * @brief This file defines/implements the class String.
 *
 */

#ifndef JSTRING_H_
#define JSTRING_H_

#include <string>
#include <sstream>
#include <iostream>
#include <vector>

namespace jlib {

/**
 * @class String
 * @brief A basic string that also knows about standard casting.
 *
 */
class String: public std::string {

public:

	/************************************
	 *
	 *     Static member functions:
	 *
	 ************************************/

	/// Returns position of the string s in vs or -1
	static int scontains(const std::vector<std::string> & vs, const std::string & s);


	/************************************
	 *
	 *     Non-static member functions:
	 *
	 ************************************/

	/// Constructor
	String(){}

	/// Constructor
	String(const std::string & s):std::string(s){}

	/// Constructor
	String(const String & s):std::string(s.s()){}

	/// Constructor
	String(const char* s):std::string(s){}

	/// Constructor
	String(int ac,char* av[]);

	/// Constructor
	String(const double & d);

	/// Constructor
	String(const float & f);

	/// Constructor
	String(const int & i);

	/// Constructor
	String(const char & c);

	/// Constructor
	String(const std::vector<std::string> & vs);

	/// Constructor
	String(const std::vector<String> & vS);

	/// Constructor
	String(const std::vector<int> & vi);

	/// Constructor
	String(const std::vector<double> & vd);

	/// Constructor
	String(const std::vector<float> & vf);

	/// Constructor
	template <class T>
	String(const T& t);

	/// Constructor
	template <class T>
	String(const std::vector<T>& vt);

	/// Destructor
	virtual ~String(){}

	/// Generic cast to data T
	template <class T>
	bool read(T& t,
			std::ios_base& (*f)(std::ios_base&) = std::dec  /**< Either dec or oct or hex */
			) const;

	/// Casts to string
	std::string s() const { return *this; }

	/// Casts to double
	double d() const;

	/// Casts to float
	float f() const;

	/// Casts to int
	int i() const;

	/// Casts to char
	char c() const;

	/// Casts to std::vector<double>
	std::vector<double> vd(int maxout = 0) const;

	/// Casts to std::vector<int>
	std::vector<int> vi(int maxout = 0) const;

	/// Casts to std::vector<string>
	std::vector<std::string> vs(int maxwords = 0) const;

	/// Casts to std::vector<String>
	std::vector<String> vS(int maxwords = 0) const;

	/// Casts to std::vector<char>
	std::vector<char> vc(int maxwords = 0) const;

	/// Filters out comment, following the marker
	String & filterComments(const std::string & marker = "//");

	/// Erases seperators
	String & eraseSeperators(
			const std::string & seperators /*! The seperator, seperated by blanks*/
			);

	/// strip string
	String & strip(
			char seperator,
			int howMany = 1,
			bool fromLeft = false
			);

	/// returns vector of strings, originally separated
	std::vector<std::string> list(const std::string & seperators);

	/// returns vector of strings, originally separated
	std::vector<String> listS(const std::string & seperators);

	/// Erases pre and post blanks
	String & erasePrePostBlanks();

	//! Converts string-character to uppercase, is limited to 600 characters
	String & upcase();

	/// Counts the words, ie., (multiple) blanks + 1.
	int countWords() const;

};

template <class T>
inline bool String::read(T& t,
		std::ios_base& (*f)(std::ios_base&)
		) const{
	  std::istringstream iss(*this);
	  return !(iss >> f >> t).fail();
}

template <class T>
inline String::String(const T& t){
	std::stringstream ss;
	ss << t;
	*this = std::string(ss.str());
}

template <class T>
inline String::String(const std::vector<T>& vt){
	std::stringstream ss;
	for(unsigned int i = 0; i < vt.size(); i++){
		ss << vt[i];
		if(i < vt.size() - 1) ss << '\n';
	}
	*this = std::string(ss.str());
}

inline int String::scontains(const std::vector<std::string> & vs, const std::string & s) {
	if (vs.empty() || s.empty())
		return -1;
	for (unsigned int i = 0; i < vs.size(); i++) {

		if (vs.at(i).compare(s) == 0)
			return i;
	}
	return -1;
}

inline double String::d() const{
	double d;
	std::ios_base& (*f)(std::ios_base&) = std::dec;
	std::istringstream iss(*this);
	if ((iss >> f >> d).fail())
		return 0;
	return d;
}

inline float String::f() const{
	float ff;
	std::ios_base& (*f)(std::ios_base&) = std::dec;
	std::istringstream iss(*this);
	if ((iss >> f >> ff).fail())
		return 0;
	return ff;
}

inline int String::i() const{
	int i;
	std::ios_base& (*f)(std::ios_base&) = std::dec;
	std::istringstream iss(*this);
	if ((iss >> f >> i).fail())
		return 0;
	return i;
}

inline char String::c() const{
	char c;

	std::ios_base& (*f)(std::ios_base&) = std::dec;
	std::istringstream iss(*this);
	if ((iss >> f >> c).fail())
		return 0;
	return c;
}

inline String::String(const std::vector<std::string> & vs) {

	std::string out = "";

	for (unsigned int i = 0; i < vs.size(); i++) {
		if (i > 0)
			out += " ";
		out += vs[i];
	}

	*this = out;
}

inline String::String(const std::vector<int> & vi) {

	String out = "";

	for (unsigned int i = 0; i < vi.size(); i++) {
		if (i > 0)
			out += " ";
		out += String(vi[i]);
	}

	*this = out;
}

inline String::String(const std::vector<double> & vd) {

	String out = "";

	for (unsigned int i = 0; i < vd.size(); i++) {
		if (i > 0)
			out += " ";
		out += String(vd[i]);
	}

	*this = out;
}

inline String::String(const std::vector<float> & vf) {

	String out = "";

	for (unsigned int i = 0; i < vf.size(); i++) {
		if (i > 0)
			out += " ";
		out += String(vf[i]);
	}

	*this = out;
}



inline String::String(const double & value) {

	std::stringstream ss;
	ss << value;

	*this =  ss.str();
}

inline String::String(const float & value) {

	std::stringstream ss;
	ss << value;

	*this = ss.str();
}

inline String::String(const int & value) {

	std::stringstream ss;
	ss << value;

	*this = ss.str();
}

inline String::String(const char & c) {

	std::stringstream ss;
	ss << c;

	*this = ss.str();
}

inline String::String(int ac, char* av[]) {

	std::string out = "";

	for (int i = 0; i < ac; i++) {

		std::string s(av[i]);
		out += " " + s;

	}

	*this = out;
}

inline std::vector<std::string> String::list(const std::string & seperators){
	String s(*this);
	return String(s.eraseSeperators(seperators)).vs();
}

inline std::vector<String> String::listS(const std::string & seperators){
	String s(*this);
	return String(s.eraseSeperators(seperators)).vS();
}

}

#endif /* JSTRING_H_ */
