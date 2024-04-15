// Note: .tpp files are included at the bottom of the corersponding hpp file!

template<typename T>
Array<T>::Array() {}

template<typename T>
Array<T>::Array(unsigned int n) {
    this->_data = new T[n];
}

template<typename T>
Array<T>::~Array() {
    delete [] this->_data;
}

template<typename T>
Array<T>::Array(Array<T> &object) {}

template<typename T>
Array<T> &Array<T>::operator=(Array<T> const &object) {}

template<typename T>
Array<T> &Array<T>::operator[](int index) {
    return (this->_data[index]);
}

template<typename T>
unsigned int Array<T>::size(void) const {
    return (this->_size);
}
