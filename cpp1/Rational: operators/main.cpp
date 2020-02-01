struct Rational
{

    Rational(int numerator = 0, int denominator = 1) : numerator_(numerator), denominator_(denominator) {};

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

    Rational operator+=(Rational const & right) {
        this->add(right);
        return *this;
    }

    Rational operator+=(int const & right) {
        Rational rat_right(right);
        return *this += right;
    }

    Rational operator-=(Rational const & right) {
        this->sub(right);
        return *this;
    }

    Rational operator-=(int const & right) {
        Rational rat_right(right);
        return *this -= right;
    }

    Rational operator*=(Rational const & right) {
        this->mul(right);
        return *this;
    }

    Rational operator*=(int const & right) {
        Rational rat_right(right);
        return *this *= right;
    }

    Rational operator/=(Rational const & right) {
        this->div(right);
        return *this;
    }

    Rational operator/=(int const & right) {
        Rational rat_right(right);
        return *this /= right;
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

const Rational operator-(Rational rat) {
    rat.neg();
    return rat;
}

const Rational operator+(Rational rat) {
    return rat;
}

#include <iostream>

using namespace std;

int main() {
    Rational a(5);
    Rational b(5, 2);
    cout << ( 234 + b).to_double() << endl;
    cout << (-a + 55).to_double() << endl;
    return 0;
}
