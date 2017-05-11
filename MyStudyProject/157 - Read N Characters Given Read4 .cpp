//The API : int read4(char *buf) reads 4 characters at a time from a file.
//The return value is the actual number of characters read.For example, it returns 3 if there is only 3 characters left in the file.
//By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.
//Note :
//    The read function will only be called once for each test case.

#include "Header.h";

int read4(char *buf) {
    int len = 0;
    while (buf[len] != '/0' && len <= 4) {
        len++;
    }
    return len;
}
int Solution::read(char *buf, int n) {
    int len = 0;
    int m = 0;
    while (len + 4 <= n) {
        m = read4(buf + len);
        len += m;
        if (m<4) break;
    }
    if (len == n || m<4) return len;

    char *remain = new char[5];
    int remainRead = read4(remain);
    m = remainRead < n - len ? remainRead : n - len;
    for (int i = 0; i<m; i++) buf[len++] = remain[i];
    delete remain;

    return len;
}