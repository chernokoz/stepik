#include <cstddef> // size_t
#include <cstring> // strlen, strcpy
#include <iostream>

using namespace std;

struct String {

    /* Реализуйте этот конструктор */
    String(const char *str = "") {
        this->size = strlen(str);
        this->str = new char[size + 1];
        strcpy(this->str, str);
    }

    /* Реализуйте этот конструктор */
    String(size_t n, char c) {
        this->size = n;
        this->str = new char[size + 1];
        for (size_t i = 0; i < n; ++i) {
            str[i] = c;
        }
        str[size] = '\0';
    }

    /* и деструктор */
    ~String() {
        delete [] this->str;
    }

    void resize(size_t new_size) {
        char * tmp = this->str;
        this->str = new char [new_size + 1];
        strcpy(this->str, tmp);
        delete [] tmp;
        this->str[new_size] = '\0';
    }

    void append(String & other) {
        this->resize(other.size + this->size);
//        cout << "Resizing done." << endl;
        for (int i = 0; i < other.size; ++i) {
//            cout << "i = " << i << endl;
            this->str[this->size + i] = other.str[i];
        }
        this->size += other.size;
    }

    size_t size;
    char *str;
};

void print_str(String & a) {
    for (int i = 0; i < a.size + 1; ++i) {
        cout << a.str[i];
    }
    cout << '\n';

}

int main() {
    String s1("Hello,");
    String s2(" world!");
    print_str(s1);
    cout << s1.size << endl;
    print_str(s2);
    cout << s2. size << endl;
//    s1.resize(11);
//    s1.str[s1.size] = 'a';
//    cout << s1.str[11];
//    print_str(s1);
    s1.append(s2);
    print_str(s1);
    return 0;
}
