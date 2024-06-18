#ifndef BOIDSFML_FINITEWORLD_H
#define BOIDSFML_FINITEWORLD_H
#include "World.h"

class FiniteWorld : public World{
public:
    FiniteWorld(float width, float height) : width{width}, height{height}, tree{{0.f, 0.f}, {width, height}, nullptr} {};
    [[nodiscard]] sf::Vector2f position_difference(sf::Vector2f const& v1, sf::Vector2f const & v2) const override;
    void update(sf::Time delta_time) override;
    [[nodiscard]] std::unique_ptr<NeighborIterator> make_neighbor_iterator(Animal animal, FlockMember const &member, float range, float cos_fov) const override;

    void make_sub_gui() override;
    void draw(sf::RenderTarget & target) override;

    QuadTree tree;
private:
    float width;
    float height;
    bool is_toroidal{true};
    bool show_tree{false};
    friend class QuadIterator;

    void validate_toroidal_position(sf::Vector2f & point) const;
    void validate_normal_position(sf::Vector2f & point) const;

};



#endif //BOIDSFML_FINITEWORLD_H
