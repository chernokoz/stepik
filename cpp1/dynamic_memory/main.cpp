#include <algorithm>
#include <iostream>
using namespace std;

char * resize(const char *str, unsigned size, unsigned new_size)
{
    char * str_new = new char[new_size];
    for (unsigned i = 0; i < std::min(size, new_size); i++) {
        str_new[i] = str[i];
//        cout << str[i];
    }
    delete[] str;
    return str_new;
}

char *getline()
{
    int i = 0;
    size_t cur_size = 4;
    char * buffer = new char[cur_size];
    char symbol = 0;
    while(std::cin.get(symbol)) {

        if (symbol == '\n' || symbol == '\0') {
            buffer[i] = '\0';
            return resize(buffer, cur_size, i + 1);
        }

        buffer[i] = symbol;

//        cout << symbol << endl;

        if (i + 1 == cur_size) {
            buffer = resize(buffer, cur_size, cur_size * 2);
            cur_size *= 2;
        }
        i = i + 1;



    }
    buffer[i] = '\0';
    return resize(buffer, cur_size, i + 1); // Hi, Sasha!
}

void print_str(char * ch) {
    char * ptr = ch;
    while (*(ptr) != '\0') {
        cout << *ptr;
        ptr += 1;
    }
    cout << *ptr;
}

int main() {
//    cin.get();
    auto str = getline();
    print_str(str);
    delete[] str;
    return 0;
}
