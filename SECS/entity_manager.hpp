#ifndef SECS_ENTITY_MANAGER_HPP
#define SECS_ENTITY_MANAGER_HPP

#include "SECS/collections/sparse_map.hpp"
#include "engine.hpp"
#include "entity.hpp"

class EntityManager {
public:
    Entity::ID create();
    void destroy(const Entity::ID &id);

    Entity::Reference entity(const Entity::ID &id);

private:

};

#ifndef SECS_ENTITY_MANAGER_INL
#include "impl/entity_manager.inl"
#endif

#endif // SECS_ENTITY_MANAGER_HPP
