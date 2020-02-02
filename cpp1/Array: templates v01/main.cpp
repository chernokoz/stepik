#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Array
{
public:
    // Список операций:
    //
    explicit Array(size_t size = 0, const T & value = T()) {
        data = new T [size];
        size_ = size;
        for (int i = 0; i < size; ++i) {
            data[i] = value;
        }
    }
    //   конструктор класса, который создает
    //   Array размера size, заполненный значениями
    //   value типа T. Считайте что у типа T есть
    //   конструктор, который можно вызвать без
    //   без параметров, либо он ему не нужен.
    //

    void prnt()
    {
        for (size_t i = 0; i < size_; ++i)
            cout << *(data+i);
        cout << endl;
    }

    Array(const Array & right) {
        size_ = right.size_;
        data = new T [size_];
        for (int i = 0; i < size_; ++i) {
            data[i] = right.data[i];
        }
    }
    //   конструктор копирования, который создает
    //   копию параметра. Считайте, что для типа
    //   T определен оператор присваивания.
    //
    ~Array() {
        delete [] data;
    }
    //   деструктор, если он вам необходим.
    //
    Array & operator=(Array const & right) {
        Array<T> tmp(right);
        tmp.swap(*this);
        return *this;
    }
    //   оператор присваивания.
    //
    size_t size() const {
        return size_;
    }
    //   возвращает размер массива (количество
    //                              элементов).
    //
    T & operator[](size_t ind) {
        return data[ind];
    }
    const T & operator[](size_t ind) const {
        return data[ind];
    }
    //   две версии оператора доступа по индексу.

private:

    void swap(Array & right) {
        std::swap(right.size_, this->size_);
        std::swap(right.data, this->data);
    }

    size_t size_;
    T * data;
};

using namespace std;

/// Add prnt() to Array class public methods:

/******************************T E S T S*********************/
void test0();
void test1();
void test2();
void test3();
void test4();
void test5();
void test6();

int main(int c, char** v)
{
    setlocale(LC_ALL, "");
    test0();
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();

    return 0;
}

void test0()
{
    {
        cout << endl << "*****Test 0**********" << endl;
        cout << endl << "*****CHAR**********" << endl;
        Array<char> ar(size_t(5), '0');
        Array<char> x(size_t(4), '4');
        ar = x;
        ar.prnt();

        Array<char> x2(size_t(6), '6');
        ar = x2;
        ar.prnt();
    }
    {
        cout << endl << "*****STRING**********" << endl;
        Array<string> cr(size_t(5), "0");
        Array<string> cx(size_t(4), "4");
        cr = cx;
        cr.prnt();

        Array<string> cx2(size_t(6), "6");
        cr = cx2;
        cr.prnt();
    }
    {
        cout << endl << "*****INT**********" << endl;
        Array<int> ir(size_t(5), 0);
        Array<int> ix(size_t(4), 4);
        ir = ix;
        ir.prnt();

        Array<int> ix2(size_t(6), 6);
        ir = ix2;
        ir.prnt();
    }

    {
        cout << endl << "*****DOUBLE**********" << endl;
        Array<double> dr(size_t(5), 0.0);
        Array<double> dx(size_t(4), 4.0);
        dr = dx;
        dx.prnt();

        Array<double> ix2(size_t(6), 6.0);
        dr = ix2;
        dr.prnt();
    }
    return;
}


void test1()
{
    {
        cout << endl << "*****Test 1(assigment)**********" << endl;
        Array<char> ar(size_t(100), '0');
        Array<char> x(size_t(0), '1');
        ar = x;
        ar.prnt();
    }
    {
        cout <<  "*****STRING**********" << endl;
        Array<string> cr(size_t(100), "0");
        Array<string> cx(size_t(0), "1");
        cr = cx;
        cr.prnt();

        Array<string> cx2(size_t(2), "55");
        cr = cx2;
        cr.prnt();
    }
    {
        cout << "*****INT**********" << endl;
        Array<int> cr(size_t(100), 0);
        Array<int> cx(size_t(0), 15);
        cr = cx;
        cr.prnt();

        Array<int> cx2(size_t(2), 55);
        cr = cx2;
        cr.prnt();
    }
    return;
}
void test2()
{
    cout << endl << "*****Test 2(copy constructor)**********" << endl;
    {
        cout << "*****CHAR**********" << endl;
        Array<char> x(size_t(3), '3');
        Array<char> ar(x);
        ar.prnt();
    }
    {
        cout << "*****STRING**********" << endl;
        Array<string> x(size_t(3), "333");
        Array<string> ar(x);
        ar.prnt();
    }

    return;
}

void test3()
{
    cout << endl << "*****Test 3(Empty)**********" << endl;
    {
        cout << "*****CHAR**********" << endl;
        Array<char> ar(size_t(0), '0');
        ar = ar;
        ar.prnt();
    }
    {
        cout << "*****STRING**********" << endl;
        Array<string> ar(size_t(0), "0");
        ar = ar;
        ar.prnt();
    }
    return;
}

void test4()
{
    cout << endl << "*****Test 4(assigment A=A) **********" << endl;
    {
        Array<char> ar(size_t(4), '0');
        ar = ar;
        ar.prnt();
    }
    return;
}
void test5()
{
    cout << endl << "*****Test 5(out bound)**********" << endl;
    {
        cout << "*****more**********" << endl;
        Array<char> ar(size_t(4), '0');
        cout << ar[10] << endl;
    }
    {
        cout << "*****less**********" << endl;
        Array<char> ar(size_t(4), '0');
        cout << ar[-10] << endl;
    }
    return;
}

void test6()
{
    cout << endl << "*****Test 6(pointer)**********" << endl;
    {
        Array<char> *ar = new Array<char>(size_t(4), '4');
        ar->prnt();
        delete ar;
    }
    {
        Array<char> *ar = new Array<char>(size_t(5), '5');
        ar->prnt();
        Array<char> *xr = ar;
        xr->prnt();
        delete ar;
    }
    return;
}
