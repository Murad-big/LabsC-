#include <iostream>
#include <string>

class Character {
private:
    std::string name;
    int health;
    int attack;
    int defense;

public:
    Character(const std::string& n, int h, int a, int d)
        : name(n), health(h), attack(a), defense(d) {}

    // Перегрузка оператора ==
    bool operator==(const Character& other) const {
        return name == other.name && health == other.health;
    }

    // Перегрузка оператора <<
    friend std::ostream& operator<<(std::ostream& os, const Character& character) {
        os << "Character: " << character.name << ", HP: " << character.health
           << ", Attack: " << character.attack << ", Defense: " << character.defense;
        return os;
    }
};

class Weapon {
private:
    std::string name;
    int damage;
    float weight;

public:
    Weapon(const std::string& n, int d, float w)
        : name(n), damage(d), weight(w) {}

    // Перегрузка оператора +
    Weapon operator+(const Weapon& other) const {
        std::string newName = name + " + " + other.name;
        int newDamage = damage + other.damage;
        float newWeight = weight + other.weight;
        return Weapon(newName, newDamage, newWeight);
    }

    // Перегрузка оператора >
    bool operator>(const Weapon& other) const {
        return damage > other.damage;
    }

    // Перегрузка оператора <<
    friend std::ostream& operator<<(std::ostream& os, const Weapon& weapon) {
        os << "Weapon: " << weapon.name << ", Damage: " << weapon.damage
           << ", Weight: " << weapon.weight << " kg";
        return os;
    }
};

int main() {
    // Демонстрация работы с классом Character
    Character hero1("Hero", 100, 20, 10);
    Character hero2("Hero", 100, 20, 10);
    Character hero3("Warrior", 150, 25, 15);

    if (hero1 == hero2) {
        std::cout << "Hero1 and Hero2 are the same!\n";
    }
    if (!(hero1 == hero3)) {
        std::cout << "Hero1 and Hero3 are different!\n";
    }

    std::cout << hero1 << std::endl << std::endl;

    // Демонстрация работы с классом Weapon
    Weapon sword("Sword", 25, 3.5);
    Weapon bow("Bow", 20, 1.8);
    Weapon axe("Axe", 30, 5.2);

    // Сложение оружия
    Weapon combined = sword + bow;
    std::cout << "Combined weapon: " << combined << std::endl;

    // Сравнение оружия
    if (sword > bow) {
        std::cout << sword.name << " is stronger than " << bow.name << std::endl;
    } else {
        std::cout << bow.name << " is stronger than " << sword.name << std::endl;
    }

    if (axe > sword) {
        std::cout << axe.name << " is stronger than " << sword.name << std::endl;
    } else {
        std::cout << sword.name << " is stronger than " << axe.name << std::endl;
    }

    return 0;
}
