#include <iostream>
using namespace std;

#include <string>

string removeOccurrences(string s, string part) {
        string st;

        for (char c : s) {
            st += c;

            if (st.size() >= part.size()) {
                if (st.compare(st.size() - part.size(), part.size(), part) == 0) {
                    st.erase(st.size() - part.size());
                }
            }
        }

        return st;
    }   