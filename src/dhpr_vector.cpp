#include "dhpr_vector/dhpr_vector.hpp"

/*
constructors
*/
template <typename T>
dhpr::vector<T>::vector() : data_(nullptr), size_(0), capacity_(0) {};

template <typename T>
dhpr::vector<T>::vector(size_type count) : data_(static_cast<T*>(::operator new(sizeof(T) * count))), 
                                           size_(count), 
                                           capacity_(count)
{
    for (size_type i = 0; i < count; i++)
    {
        new(data_ + i) T();
    }
}

/*
destructor
*/
template <typename T>
dhpr::vector<T>::~vector() 
{
    for (size_type i = 0; i < size_; i++)
    {
        data_[i].~T();
    }
    ::operator delete(data_);
}

/*
[] method
*/
template <typename T>
T& dhpr::vector<T>::operator[](size_type index) 
{
    return data_[index];
}

template <typename T>
const T& dhpr::vector<T>::operator[](size_type index) const
{
    return data_[index];
}

/*
size()
*/
template <typename T>
typename dhpr::vector<T>::size_type dhpr::vector<T>::size() const
{
    return size_;
}

/*
capacity()
*/
template <typename T>
typename dhpr::vector<T>::size_type dhpr::vector<T>::capacity() const
{
    return capacity_;
}

/*
empty()
*/
template <typename T>
bool dhpr::vector<T>::empty() const
{
    return size_ == 0;
}

/*
push_back()
*/
template <typename T>
void dhpr::vector<T>::push_back(const T& value)
{
    if (size_ == capacity_)
    {
        size_type new_cap = (capacity_ == 0) ? 1 : capacity_ * 2;
        T* new_data = static_cast<T*>(::operator new(sizeof(T) * new_cap));

        for (size_type i = 0; i < size_; i++)
        {
            new (new_data + i) T(std::move(data_[i]));
            data_[i].~T();
        }
        
        ::operator delete(data_);
        data_ = new_data;
        capacity_ = new_cap;
    }
    
    new (data_ + size_) T(value);
    ++size_;
}

/*
pop_back()
*/
template <typename T>
void dhpr::vector<T>::pop_back()
{
    if (size_ > 0)
    {
        --size_;
        data_[size_].~T();
    }
    
}