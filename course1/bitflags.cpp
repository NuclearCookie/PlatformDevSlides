// Example program
#include <iostream>
#include <string>

enum Resistance : uint8_t
{
    Wind = 0x1,
    Earth = 0x2,
    Fire = 0x4,
    Water = 0x8,
    Poison = 0x10,
    Lightning = 0x20
};


class Monster
{
private:
    uint8_t m_Resistance;
    int life = 100;

public:

    bool damage( Resistance type )
    {
        if(m_Resistance & type)
        {
            life -= 10;
            return true;
        }
        return false;
    }

    Monster( int resistanceMask )
        : m_Resistance(resistanceMask)
    {

    }


};

void damageMonster( Monster * monster, Resistance type, const std::string & name, const std::string & resistanceName )
{
    std::cout << name;
    if( monster->damage(type) )
    {
        std::cout << " was damaged by ";
    }
    else
    {
        std::cout << " was NOT damaged by ";
    }

    std::cout << resistanceName << std::endl;
}

int main()
{
    Monster * monster1 = new Monster( Resistance::Wind | Resistance::Lightning );
    Monster * monster2 = new Monster( Resistance::Water | Resistance::Poison );
    Monster * monster3 = new Monster( Resistance::Fire );

    damageMonster( monster1, Resistance::Earth, "monster1", "Earth" );
    damageMonster( monster1, Resistance::Wind, "monster1", "Wind" );
    damageMonster( monster1, Resistance::Lightning, "monster1", "Lightning" );
    damageMonster( monster1, Resistance::Poison, "monster1", "Poison" );

    std::cout << std::endl;

    damageMonster( monster2, Resistance::Earth, "monster2", "Earth" );
    damageMonster( monster2, Resistance::Wind, "monster2", "Wind" );
    damageMonster( monster2, Resistance::Lightning, "monster2", "Lightning" );
    damageMonster( monster2, Resistance::Poison, "monster2", "Poison" );

    std::cout << std::endl;

    damageMonster( monster3, Resistance::Earth, "monster3", "Earth" );
    damageMonster( monster3, Resistance::Wind, "monster3", "Wind" );
    damageMonster( monster3, Resistance::Lightning, "monster3", "Lightning" );
    damageMonster( monster3, Resistance::Poison, "monster3", "Poison" );

    delete monster1;
    delete monster2;
    delete monster3;
}
