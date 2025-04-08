#include <iostream>
#include <string>

class Character {
private:
    std::string name;
    int health;
    int attack;
    int defense;
    const int maxHealth = 100;

public:
    Character(const std::string& n, int h, int a, int d)
        : name(n), health(h), attack(a), defense(d) {}

    int getHealth() const {
        return health;
    }

    void displayInfo() const {
        std::cout << "Name: " << name
                  << ", HP: " << health
                  << ", Attack: " << attack
                  << ", Defense: " << defense << std::endl;
    }

    void attackEnemy(Character& enemy) {
        int damage = attack - enemy.defense;
        if (damage > 0) {
            enemy.takeDamage(damage);
            std::cout << name << " attacks " << enemy.name
                      << " for " << damage << " damage!" << std::endl;
        } else {
            std::cout << name << " attacks " << enemy.name
                      << ", but it has no effect!" << std::endl;
        }
    }

    void heal(int amount) {
        if (amount > 0) {
            health += amount;
            if (health > maxHealth)
                health = maxHealth;
            std::cout << name << " heals for " << amount
                      << " HP. Current HP: " << health << std::endl;
        }
    }

    void takeDamage(int amount) {
        if (amount > 0) {
            health -= amount;
            if (health < 0)
                health = 0;
            std::cout << name << " takes " << amount
                      << " damage. Current HP: " << health << std::endl;
        }
    }
};

int main() {
    Character hero("Hero", 100, 20, 10);
    Character monster("Goblin", 50, 15, 5);

    std::cout << "\n== Initial Info ==" << std::endl;
    hero.displayInfo();
    monster.displayInfo();

    std::cout << "\n== Hero Attacks Goblin ==" << std::endl;
    hero.attackEnemy(monster);

    std::cout << "\n== Goblin Heals ==" << std::endl;
    monster.heal(20);

    std::cout << "\n== Goblin Takes Damage ==" << std::endl;
    monster.takeDamage(30);

    std::cout << "\n== Final Info ==" << std::endl;
    hero.displayInfo();
    monster.displayInfo();

    return 0;
}
