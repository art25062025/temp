#pragma once

#include <cstdlib>

// Реализуйте шаблон SimpleVector
template <typename T>
class SimpleVector {
public:
  SimpleVector(){
	  data = nullptr;
	  //_size = 0;
	  capacity = 0;
	  _end = data;

  }
  explicit SimpleVector(size_t size){
	  data = new T[size];
	  //_size = size;
	  _end = data + size;
	  capacity = size;
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
	  return _end;
  }

  size_t Size() const{
	  return _end - data;
  }
  size_t Capacity() const{
	  return capacity;
  }


  void PushBack(const T& value){
	  if(isFirst){
		  capacity = 1;
		  data = new T[capacity];
		  *data = value;
		  _end = data + 1;
		 isFirst = false;
		 return;

	  }else{
		  if(Size() == Capacity()){
			  capacity = 2 * Capacity();
			  int t = Size();
			  T* tp = data;
			  T* data = new T[capacity];
			  for(size_t i = 0; i < Size(); ++i){
				  *(data + i) = *(tp + i);
			  }

			  _end = data + t;
			  *(_end + 1) = value;
			  ++ _end;

		  }else{
			  *(_end + 1) = value;
			  ++_end;

		  }

	  }

  }


private:
  // Добавьте поля для хранения данных вектора
  T* data;
  T* _end;
  //size_t _size;
  size_t capacity;
  bool isFirst = true;
};
