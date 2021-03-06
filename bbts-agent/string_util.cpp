#include "bbts-agent/string_util.h"

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

using std::string;
using std::vector;
using std::set;

namespace bbts {

string StringUtil::bytes_to_readable(int64_t bytes) {
    assert(bytes >= 0);
    int64_t div = 1LL;
    const char *unit = "B";
    if (bytes >= 1024LL * 1024 * 1024 * 1024) {
        div = 1024LL * 1024 * 1024 * 1024;
        unit = "TB";
    } else if (bytes >= 1024LL * 1024 * 1024) {
        div = 1024LL * 1024 * 1024;
        unit = "GB";
    } else if (bytes >= 1024LL * 1024) {
        div = 1024LL * 1024;
        unit = "MB";
    } else if (bytes >= 1024LL) {
        div = 1024LL;
        unit = "KB";
    }

    double result = static_cast<double>(bytes) / div;
    char buf[20] = { 0 };
    snprintf(buf, sizeof(buf), "%.2f%s", result, unit);
    return string(buf);
}

int64_t StringUtil::readable_to_bytes(const std::string &bytes_string, int64_t unit) {
    int64_t bytes;
    if (bytes_string.empty()) {
        bytes = 0LL;
    }
    switch (*bytes_string.rbegin()) {
    case 'M':
        // fall through
    case 'm': {
        unit = 1024LL * 1024;
        break;
    }

    case 'K':
        // fall through
    case 'k': {
        unit = 1024LL;
        break;
    }

    case 'G':
        // fall through
    case 'g': {
        unit = 1024LL * 1024 * 1024;
        break;
    }

    case 'T':
        // fall through
    case 't': {
        unit = 1024LL * 1024 * 1024 * 1024;
        break;
    }

    case 'B':
        // fall through
    case 'b': {
        unit = 1;
        break;
    }

    default: {
        break;
    }
    }
    // atof自动忽略数字后面的字母后缀
    bytes = static_cast<int64_t>(atof(bytes_string.c_str()) * unit);
    return bytes;
}

void StringUtil::slipt(const string &str, const string &delimiter, vector<string> *v) {
    assert(v);
    if (str.empty()) {
        return;
    }
    v->clear();
    string::size_type start_pos(0), end_pos(string::npos);
    while ((end_pos = str.find_first_of(delimiter, start_pos)) != string::npos) {
        if (end_pos != start_pos) {
            v->push_back(str.substr(start_pos, end_pos - start_pos));
        }
        start_pos = end_pos + 1;
    }
    if (start_pos < str.length()) {
        v->push_back(str.substr(start_pos));
    }
}

}  // namespace bbts
