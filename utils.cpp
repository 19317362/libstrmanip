#include "utils.h"
/////////////////////////////////////////////////
std::vector<std::string> split(char pivot, const std::string& str) {
    std::vector<std::string> result;

    int last = 0;
    int len = 0;

    for (unsigned int i = 0; i < str.length(); i++) {
        if (str[i] == pivot) {
            len = i - last;
            std::string token = str.substr(last, len);
            result.push_back(token);
            last = i + 1;
        }
    }

    len = str.size() - last;
    std::string token = str.substr(last, len);
    result.push_back(token);

    return result;
}
/////////////////////////////////////////////////
void debug(const std::string & str) {
    time_t seconds = time(NULL);
    std::cerr << seconds << " [threadsocket] " << str << std::endl;
}
/////////////////////////////////////////////////
void deWhiteSpace(std::string &str) {
    // we check from the back whether we have crlf
    //

    if (str.empty() )
        return;

    for (int i = str.length() - 1; i >= 0; i--) {
        if (str[i] == '\r' || str[i] == '\n' || str[i] == ' ') {
            str.erase(i);
            i = str.length();
        }
        else {
            break;
        }
    }
}
/////////////////////////////////////////////////
std::queue<std::string> vectorToQueue(const std::vector<std::string> &v) {
    std::queue<std::string> q;

    for (unsigned int i = 0; i < v.size(); i++) {
        q.push(v[i]);
    }

    return q;
}
/////////////////////////////////////////////////
std::string replace(char t, char d, const std::string & str) {
    std::string result(str);

    if (result.empty() )
        return result;

    for (unsigned int i = 0; i < result.length(); i++) {
        if (result[i] == t) {
            result[i] = d;
        }
    }

    return result;
}
/////////////////////////////////////////////////
