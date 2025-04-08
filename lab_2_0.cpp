#include <iostream>
#include <string>

class Weapon {
private:
    std::string name;
    int damage;
    float weight;

public:
    Weapon(const std::string& n, int d, float w)
        : name(n), damage(d), weight(w) {
        std::cout << "Weapon " << name << " created!\n";
    }

    ~Weapon() {
        std::cout << "Weapon " << name << " destroyed!\n";
    }

    void displayInfo() const {
        std::cout << "Weapon: " << name << ", Damage: " << damage
                  << ", Weight: " << weight << "kg\n";
    }
};

int main() {
    Weapon sword("Longsword", 25, 4.5f);
    Weapon bow("Bow", 15, 2.0f);
    Weapon axe("Battle Axe", 30, 6.2f);

    std::cout << "\n== Weapon Info ==\n";
    sword.displayInfo();
    bow.displayInfo();
    axe.displayInfo();

    return 0;
}
