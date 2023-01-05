#include <iostream>

class VIP {
public:
    // Default constructor
    VIP() : isVIP_(false), price_(50) {}

    // Copy constructor
    VIP(const VIP& other) : isVIP_(other.isVIP_), price_(other.price_) {}

    // Destructor
    ~VIP() {}

    // Accessor for isVIP_
    bool IsVIP() const { return isVIP_; }

    // Mutator for isVIP_
    void SetVIP(bool isVIP) { isVIP_ = isVIP; }

    // Accessor for price_
    double GetPrice() const { return price_; }

    // Mutator for price_
    void SetPrice(double price) { price_ = price; }

    // Input operator
    friend std::istream& operator>>(std::istream& in, VIP& vip) {
        in >> vip.isVIP_;
        return in;
    }

    // Output operator
    friend std::ostream& operator<<(std::ostream& out, const VIP& vip) {
        out << vip.isVIP_;
        return out;
    }

private:
    bool isVIP_;
    double price_;
};
