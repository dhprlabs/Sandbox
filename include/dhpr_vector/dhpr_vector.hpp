#include <cstddef>
#include <utility>

namespace dhpr 
{
    template <typename T>
    class vector
    {
    public:
        using value_type = T;
        using size_type = std::size_t;

        vector();
        vector(const vector& other);
        explicit vector(size_type count);
        ~vector();

        T& operator[](size_type index);
        const T& operator[](size_type index) const;

        size_type size() const;
        size_type capacity() const;
        bool empty() const;

        void push_back(const T& value);
        void pop_back();

    private:
        T* data_;          // Raw heap memory
        size_t size_;      // Number of constructed objects
        size_t capacity_;  // Total space allocated
    };

    /*
    Implementation
    */
    template <typename T>
    vector<T>::vector() : data_(nullptr), size_(0), capacity_(0) {}

    template <typename T>
    vector<T>::vector(size_type count) 
        : data_(static_cast<T*>(::operator new(sizeof(T) * count))), 
          size_(count), 
          capacity_(count)
    {
        for (size_type i = 0; i < count; i++)
        {
            new(data_ + i) T();
        }
    }

    template <typename T>
    vector<T>::vector(const vector& other) : data_(nullptr), size_(0), capacity_(0)
    {
        if (other.size_ == 0) return;

        data_ = static_cast<T*>(::operator new(sizeof(T) * other.size_));
        capacity_ = other.size_;
        size_ = other.size_;

        for (size_type i = 0; i < size_; i++)
        {
            new (data_ + i) T(other.data_[i]);
        }
    }

    template <typename T>
    vector<T>::~vector() 
    {
        for (size_type i = 0; i < size_; i++)
        {
            data_[i].~T();
        }
        ::operator delete(data_);
    }

    template <typename T>
    T& vector<T>::operator[](size_type index) 
    {
        return data_[index];
    }

    template <typename T>
    const T& vector<T>::operator[](size_type index) const
    {
        return data_[index];
    }

    template <typename T>
    typename vector<T>::size_type vector<T>::size() const
    {
        return size_;
    }

    template <typename T>
    typename vector<T>::size_type vector<T>::capacity() const
    {
        return capacity_;
    }

    template <typename T>
    bool vector<T>::empty() const
    {
        return size_ == 0;
    }

    template <typename T>
    void vector<T>::push_back(const T& value)
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

    template <typename T>
    void vector<T>::pop_back()
    {
        if (size_ > 0)
        {
            --size_;
            data_[size_].~T();
        }
    }
}