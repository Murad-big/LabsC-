#include <iostream>
#include <vector>
#include <memory>
#include <queue>

// Базовый класс Entity и его производные
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

// Шаблонный класс GameManager
template <typename T>
class GameManager {
private:
    std::vector<std::unique_ptr<T>> entities;

public:
    void addEntity(T* entity) {
        entities.emplace_back(entity);
    }

    void displayAll() const {
        for (const auto& entity : entities) {
            entity->displayInfo();
        }
    }
};

// Шаблонный класс Queue
template <typename T>
class Queue {
private:
    std::queue<T> items;

public:
    void push(const T& item) {
        items.push(item);
    }

    void pop() {
        if (!items.empty()) {
            items.pop();
        }
    }

    void display() const {
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
    // 1. Демонстрация GameManager с умными указателями
    GameManager<Entity> manager;
    manager.addEntity(new Player("Hero", 100, 0));
    manager.addEntity(new Enemy("Goblin", 50, "Goblin"));
    manager.addEntity(new Enemy("Dragon", 200, "Boss"));

    std::cout << "Game entities:\n";
    manager.displayAll();
    std::cout << "\n";

    // 2. Демонстрация шаблонной Queue для разных типов
    Queue<std::string> stringQueue;
    stringQueue.push("First");
    stringQueue.push("Second");
    stringQueue.push("Third");
    stringQueue.display();

    stringQueue.pop();
    stringQueue.display();
    stringQueue.push("Fourth");
    stringQueue.display();

    Queue<int> intQueue;
    intQueue.push(10);
    intQueue.push(20);
    intQueue.push(30);
    intQueue.display();

    intQueue.pop();
    intQueue.display();

    return 0;
}
