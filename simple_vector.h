#pragma once

#include <cstdlib>

// Реализуйте шаблон SimpleVector
template <typename T>
class SimpleVector {
public:
  SimpleVector();
  explicit SimpleVector(size_t size){
	  data = new T[size];
	  end_ = data + size;
  }
  ~SimpleVector(){
	  delete[] data;
  }

  T& operator[](size_t index){
	  return data[index];
  }

  T* begin(){
	  return data;
  }
  T* end(){
	  return end_;
  }

  size_t Size() const{
	  return end_ - data;
  }
  size_t Capacity() const;
  void PushBack(const T& value);

private:
  // Добавьте поля для хранения данных вектора
  T* data;
  T* end_;
};
