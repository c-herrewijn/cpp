// Note: .tpp files are included at the bottom of the corersponding .hpp file!
#include <stdexcept>
#include <string>

template<typename T>
Array<T>::Array() : _size(0), _data(nullptr) {}

template<typename T>
Array<T>::Array(unsigned int n) : _size(n), _data(new T[this->_size] {}) {}

template<typename T>
Array<T>::Array(const Array<T> &obj) :
    _size(obj.size()),
    _data(_initCopy(obj))
{}

template<typename T>
T *Array<T>::_initCopy(const Array<T> &obj)
{
    T *copyData = new T[this->_size];
    for (size_t i=0; i<this->_size; i++) {
        copyData[i] = obj._data[i];
    }
    return (copyData);
}

template<typename T>
Array<T>::~Array()
{
    delete [] this->_data;
}

template<typename T>
Array<T> &Array<T>::operator=(const Array<T> &object)
{
    for (size_t i=0; i<object.size(); i++) {
        this->_data[i] = object._data[i];
    }
    return *this;
}

template<typename T>
T &Array<T>::operator[](size_t index) const
{
    if (index >= this->_size) {
        std::string errMsg = "index (" + std::to_string(index) + ") out of range";
        throw std::out_of_range(errMsg);
    }
    return this->_data[index];
}

template<typename T>
size_t Array<T>::size(void) const
{
    return (this->_size);
}
