#pragma once

template <typename T, typename E>
class result{
  private:
    const bool ok_;
    union {
      T ok_value_;
      E err_value_;
    };

  public:
  result(T ok_value);
  result(E err_value);
};

template <typename T>
class ok {
  private:
  const T ok_value_;

  public:
  explicit ok(T ok_value);

  template <typename U, typename E>
  operator result<U, E>() const;
};

template <typename E>
class err {
  private:
  const E err_value_;

  public:
  explicit err(E err_value);

  template <typename T, typename U>
  operator result<T, U>() const;
};