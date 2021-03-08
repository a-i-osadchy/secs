#ifndef SECS_ENTITY_HPP
#define SECS_ENTITY_HPP

#include <limits>

#include <utl/non_constructable.hpp>

#include "SECS/common.hpp"

class Entity {
public:
    class ID {
    public:
        inline ID();
        inline ID(Index index, Index version);

        inline Index index() const;
        inline Index version() const;

    private:
        Index m_index;
        Index m_version;

    };

    UTL_NON_CONSTRUCTABLE(Entity)

};

#endif // SECS_ENTITY_HPP

#include "impl/entity.inl"
