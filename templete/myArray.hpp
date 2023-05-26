#pragma once
#include <cstddef>
#include <memory>
#include <type_traits>
#include <vector>
// 模版特化
template <typename T> struct get_type {
  using type = T;
};
// 通过get_type类获得T类型
template <typename T> struct get_type<T *> {
  using type = T;
};
template <typename T> class MyArray {
  using iterator = T *;
  using const_iterator = const T *;

public:
  MyArray(size_t count);
  MyArray(const std::initializer_list<T> &list);
  MyArray(std::initializer_list<T> &&list);
  ~MyArray();
  iterator begin() const;
  const_iterator cbegin() const;
  T& operator[](unsigned count)const{
    return data[count];
  }

private:
  T *data;
  // std::vector<T> *data;
  std::shared_ptr<T> sharedData;
};
template <typename T> MyArray<T>::MyArray(size_t count) {
  if (count) {
    data = new T[count]();
  } else {
    data = nullptr;
  }
};
template <typename T> MyArray<T>::~MyArray() {
  if (data) {
    delete[] data;
  }
}
template <typename T> typename MyArray<T>::iterator MyArray<T>::begin() const {
  return data;
}
template <typename T>
typename MyArray<T>::const_iterator MyArray<T>::cbegin() const {
  return data;
}
template <typename T> // 左值引用
MyArray<T>::MyArray(const std::initializer_list<T> &list) {
  if (list.size()) {
    unsigned count = 0;
    data = new T[list.size()]();
    if (std::is_pointer<T>::value) {
      for (auto elem : list) {
        data[count++] = new typename get_type<T>::type(*elem);
        //此处会发生内存泄漏
      }
    } else {
      for (const auto &elem : list) {
        data[count++] = elem;
      }
    }
  } else {
    data = nullptr;
  }
}
template <typename T> MyArray<T>::MyArray(std::initializer_list<T> &&list) {
  if (list.size()) {
    unsigned count = 0;
    data = new T[list.size()]();
    for (const auto &elem : list) {
      data[count++] = elem;
    }

  } else {
    data = nullptr;
  }
}
