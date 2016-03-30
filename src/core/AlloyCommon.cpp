/*
* Copyright(C) 2015, Blake C. Lucas, Ph.D. (img.science@gmail.com)
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*/
#include "AlloyCommon.h"
namespace aly {
	std::vector<std::string> Split(const std::string &str, char delim) {
		std::stringstream ss;
		std::vector<std::string> elems;
		std::string delimString = "";
		delimString += delim;
		std::string comp;
		for (char c : str) {
			if (c == delim) {
				comp = ss.str();
				if (comp.size() > 0) {
					elems.push_back(comp);
					ss.str("");
				}
				elems.push_back(delimString);
			}
			else {
				ss << c;
			}
		}
		comp = ss.str();
		if (comp.size() > 0) {
			elems.push_back(comp);
		}
		return elems;

	}
	bool Contains(const std::string& str, const std::string& pattern) {
		return (str.find(pattern) != std::string::npos);
	}
	std::string ToLower(const std::string& str) {
		std::stringstream ss;
		static const std::locale local;
		for (char c : str) {
			ss << std::tolower(c, local);
		}
		return ss.str();
	}
	std::string ToUpper(const std::string& str) {
		std::stringstream ss;
		static const std::locale local;
		for (char c : str) {
			ss << std::toupper(c, local);
		}
		return ss.str();
	}
	bool ContainsIgnoreCase(const std::string& str, const std::string& pattern) {
		std::string strl = ToLower(str);
		std::string patternl = ToLower(pattern);
		return (strl.find(patternl) != std::string::npos);
	}
}