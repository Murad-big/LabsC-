#include <iostream>
#include <vector>
#include <memory>
#include <queue>
#include <stdexcept>

class Entity {
protected:
    std::string name;
    int health;
public:
    Entity(const std::string& n, int h) : name(n), health(h) {}
    virtual ~Entity() {}
    virtual void displayInfo() const = 0;
    int getHealth() const { return health; }
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

template <typename T>
class GameManager {
private:
    std::vector<std::unique_ptr<T>> entities;

public:
    void addEntity(T* entity) {
        if (entity == nullptr) {
            throw std::invalid_argument("Cannot add null entity");
        }
        if (entity->getHealth() <= 0) {
            throw std::invalid_argument("Entity has invalid health (must be positive)");
        }
        entities.emplace_back(entity);
    }

    void displayAll() const {
        for (const auto& entity : entities) {
            entity->displayInfo();
        }
    }
};

template <typename T>
class Queue {
private:
    std::queue<T> items;

public:
    void push(const T& item) {
        items.push(item);
    }

    void pop() {
        if (items.empty()) {
            throw std::runtime_error("Cannot pop from empty queue");
        }
        items.pop();
    }

    void display() const {
        if (items.empty()) {
            std::cout << "Queue is empty" << std::endl;
            return;
        }
        
        std::queue<T> temp = items;
        std::cout << "Queue contents: ";
        while (!temp.empty()) {
            std::cout << temp.front() << " ";
            temp.pop();
        }
        std::cout << std::endl;
    }
};

int main() {
    // Тестирование GameManager с исключениями
    try {
        GameManager<Entity> manager;
        
        // Корректные сущности
        manager.addEntity(new Player("Hero", 100, 0));
        manager.addEntity(new Enemy("Goblin", 50, "Goblin"));
        
        // Вызовет исключение - отрицательное здоровье
        manager.addEntity(new Player("Invalid", -100, 0));
        
    } catch (const std::invalid_argument& e) {
        std::cerr << "GameManager error: " << e.what() << std::endl;
    }

    std::cout << "\n";

    // Тестирование Queue с исключениями
    try {
        Queue<std::string> stringQueue;
        
        // Корректные операции
        stringQueue.push("First");
        stringQueue.push("Second");
        stringQueue.display();
        
        stringQueue.pop();
        stringQueue.display();
        
        // Вызовет исключение - попытка удалить из пустой очереди
        stringQueue.pop();
        stringQueue.pop();
        
    } catch (const std::runtime_error& e) {
        std::cerr << "Queue error: " << e.what() << std::endl;
    }

    return 0;
}
