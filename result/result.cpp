#include "result.hpp"

template <typename T, typename E>
result<T, E>::result(T ok_value): ok_(true), ok_value_(ok_value) {}

template <typename T, typename E>
result<T, E>:: result(E err_value): ok_(true), err_value_(err_value) {}


template <typename T>
ok<T>::ok(T ok_value): ok_value_(ok_value) {}

template <typename T>
template <typename U, typename E>
ok<T>::operator result<U, E>() const {
  return result<U, E>(ok_value_);
}

template <typename E>
err<E>::err(E err_value): err_value_(err_value) {}

template <typename E>
template <typename T, typename U>
err<E>::operator result<T, U>() const {
  return result<T, U>(err_value_);
}
