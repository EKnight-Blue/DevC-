#include "gtest/gtest.h"

#include "Creatures/Flock.h"
#include "World/QuadTree.h"
// So that we have at least one test
TEST(Hey, JASON) { ASSERT_TRUE(true); }

TEST(arbre_quaternaire, basique) {
    QuadTree arbre =
        QuadTree{sf::Vector2f{0, 0}, sf::Vector2f{100, 100}, nullptr};
    arbre.insert({
        .animal = Animal::Rabbit,
        .position = sf::Vector2f{0, 0},
        .flock_index = 0,
        .member_index = 0,
    });
    EXPECT_EQ(arbre.cnt, 1);
    EXPECT_EQ(arbre.children.size(), 0);
}
TEST(arbre_quaternaire, agrandissement) {
    QuadTree arbre =
        QuadTree{sf::Vector2f{0, 0}, sf::Vector2f{100, 100}, nullptr};
    for (int i = 0; i < QuadTreeSize + 1; i++) {
        arbre.insert({
            .animal = Animal::Rabbit,
            .position = sf::Vector2f{0, 0},
            .flock_index = 0,
            .member_index = 0,
        });
    }
    EXPECT_EQ(arbre.children.size(), 4);
}
