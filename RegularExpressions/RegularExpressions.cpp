#include "RegularExpressions.h"

RegularExpressions::RegularExpressions() {};


bool RegularExpressions::isMatch(std::string s, std::string p)
{
    int size;
    if (p.size() >= s.size()) {
        size = p.size();
    }
    else {
        size = s.size();
    }
    
    int sIndex = 0;
    int pIndex = 0;
    for (pIndex; pIndex < size; pIndex++) {
        if (sIndex < s.size() && pIndex < p.size()) {
            if(s[sIndex] != p[pIndex]){
                if (p[pIndex] == '.') {
                    // do nothing
                }
                else if (p[pIndex] == '*') {
                    if (pIndex - 1 >= 0) {
                        if (p[pIndex - 1] == '*') {
                            return false;
                        }
                        if (p[pIndex - 1] == s[sIndex]) {
                            if (p[pIndex + 1] == s[sIndex]) {
                                // do nothing
                            }
                            else if (p[pIndex + 1] != s[sIndex]) {
                                int subpIndex = pIndex;
                                while (p[subpIndex + 1] != s[sIndex]) {
                                    if (subpIndex + 2 < p.size()) {
                                        if (p[subpIndex + 1] != '*' && p[subpIndex + 2] == '*') {
                                            //pIndex = subpIndex + 2;
                                            subpIndex = subpIndex + 2;
                                        }
                                        else {
                                            break;
                                        }
                                    } 
                                    else {
                                        break;
                                    }
                                }
                                while (p[pIndex - 1] == s[sIndex]) {
                                    if (sIndex < s.size()) {
                                        sIndex++;
                                    }
                                    else {
                                        break;
                                    }
                                }
                                sIndex--;
                            }

                        }
                        else {
                            if (p[pIndex - 1] != '.') {
                                sIndex--;
                            }
                        }
                    }
                    else {
                        sIndex--;
                    }
                }
                else if (pIndex < p.size()) {
                    if (p[pIndex + 1] != '*') {
                        return false;
                    }
                    else {
                        sIndex--;
                    }
                } else {
                    return false;

                }
            }
        }
        else if (sIndex < s.size() && pIndex >= p.size()) {
            return false;
        }
        else if (sIndex >= s.size() && pIndex < p.size()) {
            return false;
        }
        sIndex++;
    }
    if (sIndex < s.size() && pIndex >= p.size()) {
        return false;
    }
    if (sIndex >= s.size() && pIndex < p.size()) {
        return false;
    }
    return true;
 
};
