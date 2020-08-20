#ifndef SECS_VECTOR_HPP
#define SECS_VECTOR_HPP

#include "SECS/utility.hpp"

template <typename T>
class Vector {
public:
    using Iterator = T *;
    using ConstIterator = const T *;

    explicit Vector(Index initial_capacity, double scale_factor = 2.0);
    Vector(const Vector &another);
    Vector(Vector &&another) noexcept;
    ~Vector();

    template <typename ...Args>
    inline T &append(Args&& ...args);
    inline void pop();

    inline T &at(Index index);
    inline const T &at(Index index) const;

    inline Index size() const;
    void reserve(Index count);

    Iterator begin();
    Iterator end();
    ConstIterator begin() const;
    ConstIterator end() const;

private:
    Index m_reserved;
    Index m_size;
    T *m_data;
    double m_scale_factor;

};

#endif // SECS_VECTOR_HPP

#ifndef SECS_VECTOR_INL
#include "impl/vector.inl"
#endif
