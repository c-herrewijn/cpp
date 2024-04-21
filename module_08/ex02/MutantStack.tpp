template<typename T>
MutantStack<T>::MutantStack() {}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack &obj)
{
    *this = obj;
}

template<typename T>
MutantStack<T>::~MutantStack() {}

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &obj)
{
    this->_data = obj.data;
    return *this;
}

template<typename T>
const T &MutantStack<T>::top() const
{
    return (this->_data.front());
}

template<typename T>
bool MutantStack<T>::empty() const
{
    return (this->_data.empty());
}

template<typename T>
size_t MutantStack<T>::size() const
{
    return (this->_data.size());
}

template<typename T>
void MutantStack<T>::push(const T &value)
{
    this->_data.push_front(value);
}

template<typename T>
void MutantStack<T>::pop()
{
    this->_data.pop_front();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{

    MutantStack<T>::iterator it(&(this->_data.front()));
    return it;
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{

    MutantStack<T>::iterator it(&(this->_data.back()));
    return it;
}

// ITERATOR //

template<typename T>
MutantStack<T>::iterator::iterator(T *ptr) : _ptr(ptr) {} // constructor

template<typename T>
T &MutantStack<T>::iterator::operator*() const
{
    return (*(this->_ptr));
}
