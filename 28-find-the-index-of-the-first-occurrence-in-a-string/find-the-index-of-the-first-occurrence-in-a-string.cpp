class Solution {
public:
    int strStr(string haystack, string needle) {
        //To find a substring within a string in C++, the std::string::find() method is typically used. This method returns the starting index of the first occurrence of the substring within the string. If the substring is not found, it returns std::string::npos, a special value indicating "not found." 

        return haystack.find(needle);
    }
};