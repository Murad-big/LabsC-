#include <iostream>
#include <string>
#include <memory>
#include <vector>

class Entity {
protected:
    std::string name;
    int health;

public:
    Entity(const std::string& n, int h) : name(n), health(h) {}
    virtual ~Entity() {}
    virtual void displayInfo() const = 0;
};

class Player : public Entity {
    int experience;
public:
    Player(const std::string& n, int h, int exp) 
        : Entity(n, h), experience(exp) {}
    
    void displayInfo() const override {
        std::cout << "Player: " << name << ", HP: " << health 
                  << ", Exp: " << experience << std::endl;
    }
};

class Enemy : public Entity {
    std::string type;
public:
    Enemy(const std::string& n, int h, const std::string& t) 
        : Entity(n, h), type(t) {}
    
    void displayInfo() const override {
        std::cout << "Enemy: " << name << ", HP: " << health 
                  << ", Type: " << type << std::endl;
    }
};

class Inventory {
    std::vector<std::unique_ptr<std::string>> items;

public:
    void addItem(const std::string& item) {
        items.push_back(std::make_unique<std::string>(item));
    }

    void displayInventory() const {
        std::cout << "Inventory contents:\n";
        for (const auto& item : items) {
            std::cout << "- " << *item << "\n";
        }
    }
};

int main() {
    // 1. Демонстрация работы с Entity через умные указатели
    std::unique_ptr<Entity> entities[] = {
        std::make_unique<Player>("Hero", 100, 0),
        std::make_unique<Enemy>("Goblin", 50, "Goblin")
    };

    std::cout << "Entities:\n";
    for (const auto& entity : entities) {
        entity->displayInfo();
    }

    // 2. Демонстрация работы Inventory
    Inventory inv;
    inv.addItem("Sword of Justice");
    inv.addItem("Health Potion");
    inv.addItem("Magic Scroll");

    std::cout << "\n";
    inv.displayInventory();

    return 0;
}
