#include <iostream>
#include <string>

class Movie {
public:
    // Default constructor
    Movie() : date_("Date: 23/10/2023"), time_("Time: 20:00"), name_("Name: Fast and Furious 23") {}

    // Copy constructor
    Movie(const Movie& other) : date_(other.date_), time_(other.time_), name_(other.name_) {}

    // Destructor
    ~Movie() {}

    // Accessor for date_
    const std::string& GetDate() const { return date_; }

    // Mutator for date_
    void SetDate(const std::string& date) { date_ = date; }

    // Accessor for time_
    const std::string& GetTime() const { return time_; }

    // Mutator for time_
    void SetTime(const std::string& time) { time_ = time; }

    // Accessor for name_
    const std::string& GetName() const { return name_; }

    // Mutator for name_
    void SetName(const std::string& name) { name_ = name; }

    // Input operator
    friend std::istream& operator>>(std::istream& in, Movie& movie) {
        in  >>  movie.date_ >> movie.time_ >> movie.name_;
        return in;
    }

    // Output operator
    friend std::ostream& operator<<(std::ostream& out, const Movie& movie) {
        out << movie.date_ << movie.time_ << movie.name_;
        return out;
    }

private:
    std::string date_;
    std::string time_;
    std::string name_;
};
