#include "stats.h"

#include <cmath>

namespace h3::stats
{
uint64_t ai_value(const creatures::Creature creature, const uint32_t count)
{
    return creatures::AIValues.at(creature) * count;
}

uint64_t ai_value(const hero::Hero &hero)
{
    uint64_t strength = 0;
    for (size_t i = 0; i < hero::Hero::creatureCount; ++i)
    {
        strength += ai_value(hero.creatures[i], hero.creature_count[i]);
    }
    return strength;
}

// Formula taken from https://heroes.thelazy.net/index.php/Army_strength
uint64_t army_strength(const hero::Hero &hero)
{
    return 0;
//    const auto aiValue = ai_value(hero);
//    const auto heroFactor = std::sqrt((hero.attack * 0.05 + 1.0) * (hero.defense * 0.05 + 1.0));
//    return uint64_t(aiValue * heroFactor);
}
} //namespace h3::stats
