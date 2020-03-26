#ifndef SECS_TYPE_ID_HPP
#define SECS_TYPE_ID_HPP

template <typename Family, typename Index = unsigned short int>
class TypeID {
public:
    TypeID();
    Index index() const;

    bool operator==(const TypeID &another) const;
    bool operator!=(const TypeID &another) const;

    template <typename T>
    static TypeID get();

private:
    explicit TypeID(Index index);

    Index m_index;
    static Index s_next_type_index;

};

#ifndef SECS_TYPE_ID_INL
#include "impl/type_id.inl"
#endif

#endif // SECS_TYPE_ID_HPP
