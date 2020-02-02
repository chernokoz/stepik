#include <iostream>

using namespace std;

struct Expression
{
    virtual double evaluate() const = 0;

    virtual ~Expression() {};
};

struct Number : Expression
{
    Number(double value)
            : value(value)
    {}

    ~Number() {};

    double evaluate() const {
        return value;
    }

private:
    double value;
};

struct BinaryOperation : Expression
{
    /*
      Здесь op это один из 4 символов: '+', '-', '*' или '/', соответствующих операциям,
      которые вам нужно реализовать.
     */
    BinaryOperation(Expression const * left, char op, Expression const * right)
            : left(left), right(right), op(op)
    { }

    ~BinaryOperation() {
        delete left;
        delete right;
    }

    double evaluate() const {
        if (op == '+') {
            return (left->evaluate() + right->evaluate());
        }
        if (op == '-') {
            return (left->evaluate() - right->evaluate());
        }
        if (op == '*') {
            return (left->evaluate() * right->evaluate());
        }
        if (op == '/') {
            return (left->evaluate() / right->evaluate());
        }
    }

private:
    Expression const * left;
    Expression const * right;
    char op;
};
struct SharedPtr
{
    // реализуйте следующие методы
    //
     explicit SharedPtr(Expression *ptr = 0) : ptr_(ptr), count(0) {
         count = new int(1);
     }

     ~SharedPtr() {
         if (count && --*count == 0) {
             delete ptr_;
             delete count;
         }
     }

     SharedPtr(const SharedPtr & right) : ptr_(right.ptr_), count(right.count) {
         if (count) {
             ++*count;
         }
     }

     SharedPtr& operator=(const SharedPtr & right) {
         if (--*count == 0) {
             delete ptr_;
             delete count;
         }
         this->count = right.count;
         this->ptr_ = right.ptr_;
         ++*count;
     }

     Expression* get() const {
         return ptr_;
     }

      void reset(Expression *ptr = 0) {
         --*count;
         if (*count == 0) {
             delete ptr_;
             delete count;
             ptr_ = ptr;
             count = new int;
             *count = 1;
         }
         else {
             ptr_ = ptr;
             count = new int;
             *count = 1;
         }
     }

     Expression& operator*() const {
         return *ptr_;
     }

     Expression* operator->() const {
         return ptr_;
     }

private:
    int * count;
    Expression * ptr_;
};

//struct SharedBuffer {
//    SharedBuffer(Expression * ptr) {
//        count = 1;
//        ptr_ = ptr;
//    }
//
//    ~SharedBuffer() {
//        delete this->ptr_;
//    }
//
//    Expression * ptr get() {
//        return this->ptr;
//    }
//
//    friend SharedPtr;
//
//private:
//    Expression * ptr_;
//    int count;
//};


int main() {
    // сначала создаём объекты для подвыражения 4.5 * 5
    Expression * sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
// потом используем его в выражении для +
    Expression * expr = new BinaryOperation(new Number(3), '+', sube);

// вычисляем и выводим результат: 25.5
    std::cout << expr->evaluate() << std::endl;

// тут освобождаются *все* выделенные объекты
// (например, sube будет правым операндом expr, поэтому его удалять не нужно)
    delete expr;
    SharedPtr A(sube);
    SharedPtr B(expr);
    SharedPtr C(A);
    cout << (A.get() == C.get()) << endl;
    C = B;
    cout << (A.get() == C.get()) << endl;
    return 0;
}
