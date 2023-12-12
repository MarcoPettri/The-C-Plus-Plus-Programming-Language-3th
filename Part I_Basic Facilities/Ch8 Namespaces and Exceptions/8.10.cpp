// Exercise 8.10
/*

		Write plus(), minus(), multiply(), and divide() functions that check for possible 
		overflow and underflow and that throw exceptions if such errors happen. 
*/



#include <limits>
#include <stdexcept>

namespace {

    template<typename T>
    using LIMIT = std::numeric_limits<T>;

    using std::overflow_error;
    using std::underflow_error;

    template<typename T> 
    inline T abs(T arg) { return (arg < 0 ? -arg : arg); }

    template<typename T>
    double plus(T lhs, T rhs) {


        if (lhs > LIMIT<T>::max() - rhs || lhs < LIMIT<T>::min() - rhs)  {
            throw overflow_error("Overflow Error");
        }
        
       return lhs + rhs;
    }

    template<typename T>
    inline double minus(T lhs, T rhs) { return plus(lhs, -rhs); }

    template<typename T>
    double multiply(T lhs, T rhs) {

        T rhs_abs = abs(rhs);
        T lhs_abs = abs(lhs);

        if (rhs_abs > 1.0 && lhs_abs > LIMIT<T>::max() / rhs_abs) {

            throw overflow_error("Overflow Error");
        }

        T result = lhs * rhs;

        if (!result && lhs && rhs ) {

            throw underflow_error("Underflow Error");
        }

        return result;
    }

    template<typename T>
    double divide(T lhs, T rhs) {
        

        if (!rhs) { throw std::domain_error("ZeroDivisionError"); }

        T rhs_abs = abs(rhs);
        T lhs_abs = abs(lhs);
        

        if (rhs_abs < 1.0 && lhs_abs > LIMIT<T>::max() * rhs_abs) {

            throw overflow_error("Overflow Error");
        }

        T result = lhs / rhs;

        if (!result && lhs) {

            throw std::underflow_error("Underflow Error");
        }

        return result;
    }

}