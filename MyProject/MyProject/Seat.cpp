#include <iostream>

class Seat {
public:
    int& row() { return row_; }
    int& number() { return number_; }
    // Default constructor
    Seat() : row_(1), number_(1), is_available_(false) {}

    // Constructor with parameters
    Seat(int row, int number, bool is_available = true) : row_(row), number_(number), is_available_(is_available) {}

    // Copy constructor
    Seat(const Seat& other) : row_(other.row_), number_(other.number_), is_available_(other.is_available_) {}

    // Destructor
    ~Seat() {}

    // Accessors
    int row() const { return row_; }
    int number() const { return number_; }
    bool is_available() const { return is_available_; }

    // Mutators
    void set_row(int row) { row_ = row; }
    void set_number(int number) { number_ = number; }
    void set_is_available(bool is_available) { is_available_ = is_available; }

    // Input operator
    friend std::istream& operator>>(std::istream& in, Seat& seat) {
        std::cout << "Please enter the seat row: ";
        in >> seat.row_;
        std::cout << "Please enter the seat number: ";
        in >> seat.number_;
        return in;
    }

    // Output operator
    friend std::ostream& operator<<(std::ostream& out, const Seat& seat) {
        out << "row " << seat.row_ << "number" << seat.number_;
        return out;
    }

private:
    int row_;
    int number_;
    bool is_available_;
};
