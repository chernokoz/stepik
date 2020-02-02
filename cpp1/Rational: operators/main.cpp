struct Rational
{

    explicit Rational(int numerator = 0, int denominator = 1) : numerator_(numerator), denominator_(denominator) {};

    void add(Rational rational) {
        numerator_ = numerator_ * rational.denominator_ + rational.numerator_ * denominator_;
        denominator_ *= rational.denominator_;
    }

    void sub(Rational rational) {
        numerator_ = numerator_ * rational.denominator_ - rational.numerator_ * denominator_;
        denominator_ *= rational.denominator_;
    }

    void mul(Rational rational) {
        numerator_ *= rational.numerator_;
        denominator_ *= rational.denominator_;
    }

    void div(Rational rational) {
        numerator_ *= rational.denominator_;
        denominator_ *= rational.numerator_;
    }

    void neg() {
        numerator_ = -numerator_;
    }

    void inv() {}

    double to_double() const {
        return numerator_ / (double) denominator_;
    }

    Rational & operator+=(Rational const & right) {
        this->add(right);
        return *this;
    }

    Rational & operator+=(int const & right) {
        Rational rat_right(right, 1);
        return *this += rat_right;
    }

    Rational & operator-=(Rational const & right) {
        this->sub(right);
        return *this;
    }

    Rational & operator-=(int const & right) {
        Rational rat_right(right, 1);
        return *this -= rat_right;
    }

    Rational & operator*=(Rational const & right) {
        this->mul(right);
        return *this;
    }

    Rational & operator*=(int const & right) {
        Rational rat_right(right, 1);
        return *this *= rat_right;
    }

    Rational & operator/=(Rational const & right) {
        this->div(right);
        return *this;
    }

    Rational & operator/=(int const & right) {
        Rational rat_right(right, 1);
        return *this /= rat_right;
    }

    Rational operator-() const {
        Rational rat = *this;
        rat.neg();
        return rat;
    }

    Rational operator+() const {
        Rational rat = *this;
        return rat;
    }

    friend bool operator!=(Rational const & left, Rational const & right);
    friend bool operator==(Rational const & left, Rational const & right);
    friend bool operator<(Rational const & left, Rational const & right);
    friend bool operator>(Rational const & left, Rational const & right);
    friend bool operator<=(Rational const & left, Rational const & right);
    friend bool operator>=(Rational const & left, Rational const & right);

    operator double() const {
        return this->to_double();
    }

private:
    int numerator_;
    int denominator_;
};

Rational operator+(Rational left, Rational const & right) {
    return left += right;
}

Rational operator-(Rational left, Rational const & right) {
    return left -= right;
}

Rational operator*(Rational left, Rational const & right) {
    return left *= right;
}

Rational operator/(Rational left, Rational const & right) {
    return left /= right;
}

bool operator>(Rational const & left, Rational const & right) {
    return left.numerator_ * right.denominator_ > right.numerator_ * left.denominator_;
}

bool operator<(Rational const & left, Rational const & right) {
    return left.numerator_ * right.denominator_ < right.numerator_ * left.denominator_;
}

bool operator==(Rational const & left, Rational const & right) {
    return left.numerator_ * right.denominator_ == right.numerator_ * left.denominator_;
}

bool operator!=(Rational const & left, Rational const & right) {
    return left.numerator_ * right.denominator_ != right.numerator_ * left.denominator_;
}

bool operator<=(Rational const & left, Rational const & right) {
    return left.numerator_ * right.denominator_ <= right.numerator_ * left.denominator_;
}

bool operator>=(Rational const & left, Rational const & right) {
    return left.numerator_ * right.denominator_ >= right.numerator_ * left.denominator_;
}




#include <iostream>

using namespace std;

int main() {
    Rational a(5);
    Rational b(5, 2);
    cout << ( -a += b).to_double() << endl;
    cout << (+a -= 55).to_double() << endl;
    cout << (double)(b + a) << endl;
    return 0;
}
