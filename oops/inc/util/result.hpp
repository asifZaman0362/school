#ifndef ZL_RESULT_HPP
#define ZL_RESULT_HPP

#include <exception>
#include <variant>

namespace zl {

class Unit {};

class unwrap_error : public std::exception {
   private:
    const char* _message;

   public:
    unwrap_error(const char* message) : _message(message) {}
    const char* what() const noexcept override { return _message; }
};
template <typename T, typename E>
class Result {
   protected:
    std::variant<T, E> _data;
    bool _success;

   public:
    Result() = delete;
    Result(const T& ok) : _success(true) { _data = ok; }
    Result(const E& err) : _success(false) { _data = err; }
    Result(const Result& other)
        : _data(other._data), _success(other._success) {}
    Result operator=(const Result& rhs) {
        _data = rhs._data;
        _success = rhs._success;
    }
    T unwrap() const {
        if (_success)
            return std::get<T>(_data);
        else
            throw unwrap_error("attempting to unwrap an error value!");
    }
    E err() const {
        if (!_success)
            return std::get<E>(_data);
        else
            throw unwrap_error("attempting to unwrap error on an ok value!");
    }

    bool is_ok() const { return _success; }
    bool is_err() const { return !_success; }
};

template <typename E, typename T>
Result<T, E> Ok(const T& val) {
    return Result<T, E>(val);
}

template <typename T, typename E>
Result<T, E> Err(const E& err) {
    return Result<T, E>(err);
}

class None {};

template <typename T>
class Option : public Result<T, None> {
   public:
    Option() = delete;
    Option(const T& val) : Result<T, None>(val) {}
    Option(const None&) : Result<T, None>(None{}) {}
    None err() = delete;
};

template <typename T>
Option<T> Some(const T& val) {
    return Option<T>(val);
}

}  // namespace zl

#endif
