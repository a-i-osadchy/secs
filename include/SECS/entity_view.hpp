#ifndef SECS_ENTITY_VIEW_HPP
#define SECS_ENTITY_VIEW_HPP

#include <type_traits>
#include <utility>
#include <variant>

#include "SECS/component.hpp"
#include "SECS/entity.hpp"


template <typename Engine, typename... C>
class EntityView {
private:
    class EndGuard {};

    template <bool IS_CONST>
    class GenericIterator {
    private:
        using Components = typename Engine::Components;

        template <typename T>
        using Pool = std::conditional_t<
            IS_CONST,
            const typename Components::template Pool<T>,
            typename Components::template Pool<T>
        >;

        template <typename T>
        using PoolIterator = decltype(std::declval<Pool<T>>().begin());

        template <typename T>
        using PoolEnd = decltype(std::declval<Pool<T>>().end());

    public:
        GenericIterator();

        template <typename P>
        GenericIterator(Engine &engine, P &pool);

        auto &operator++();
        decltype(auto) operator*();
        bool operator!=(const EndGuard &end) const;

    private:
        Entity::ID get_current_entity() const;
        void find_next_entity();
        void step();
        bool reached_end() const;

        Engine *m_engine;
        std::variant<PoolIterator<C>...> m_iterator;
        std::variant<PoolEnd<C>...> m_end;

    };

public:
    using Iterator = GenericIterator<std::is_const_v<Engine>>;
    using ConstIterator = GenericIterator<true>;
    using End = EndGuard;
    using ConstEnd = EndGuard;

    explicit EntityView(Engine &engine);

    Iterator begin();
    End end();

    ConstIterator begin() const;
    ConstEnd end() const;

private:
    template <typename R, typename First, typename... Rest>
    static R get_pool_iterator_by_index(Engine &engine, Index index);

    static Index get_shortest_pool_index(Engine &engine);

    Engine *m_engine;

};

#endif // SECS_ENTITY_VIEW_HPP
