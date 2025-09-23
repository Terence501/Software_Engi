#ifndef dyn_array_h
#define dyn_array_h

#include <iostream>
#include <assert.h>

template <class T> class DynArray {
public:
	DynArray();
	~DynArray();

	int size() const;
	int push_back(const T& item);
	const T& operator[](int index) const;
	DynArray<T>& operator=(const DynArray<T>& rhs);
	T& operator[](int index);

private:
	int size_;
	int capacity_;
	T* elements_;
};

template <class T> DynArray<T>::DynArray()
	: size_{0}, capacity_{2}, elements_{new T[2]} { 
	std::cout << "DynArray::DynArray()" << std::endl;
	// elements_ = new T[capacity_];
}
template <class T> DynArray<T>::~DynArray() {
	std::cout << "DynArray::~DynArray()" << std::endl;
	delete[] elements_;
}
template <class T> int DynArray<T>::size() const {
	return size_;
}
template <class T> int DynArray<T>::push_back(const T& item) {
	std::cout << "DynArray::push_back" << std::endl;
	if(size_ == capacity_ ) {
		std::cout << "Reallocation..." << std::endl;
		capacity_ *= 2;
		T* bigger_array = new T[capacity_];
		for(int i=0; i <size_; ++i) {
			bigger_array[i] = elements_[i];
		}
		delete[] elements_;
		elements_ = bigger_array;
	}
	elements_[size_] = item;
	++size_;
	return size_ - 1;
}
template <class T> const T& DynArray<T>::operator[](int index) const {
	assert(index > -1);
	assert(index < size_);
	return elements_[index];
}
template <class T> T& DynArray<T>::operator[](int index) {
	assert(index > -1);
	assert(index < size_);
	return elements_[index];
}

template <class T> DynArray<T>& DynArray<T>::operator=(const DynArray<T>& rhs) {
	if (this!=&rhs){
		delete[]elements_; 
		size_=rhs.size_;
		capacity_=rhs.capacity;
		elements_=new T[capacity_];
		for (int i = 0 ; i < rhs.size_;++i){
			elements_[i]=rhs.elements[i];
			}
	}
	return *this;


}
	
#endif

