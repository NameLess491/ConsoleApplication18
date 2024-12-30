// Пространство имен для игровых единиц
namespace GameUnits {
    class Position {
    public:
        int x, y;
        Position(int x = 0, int y = 0) : x(x), y(y) {}
    };

    class Weapon {
    public:
        std::string name;
        int damage;
        Weapon(std::string name, int damage) : name(name), damage(damage) {}
    };

    class Unit {
    public:
        std::string name;
        Position position;
        Weapon weapon;

        Unit(std::string name, Position position, Weapon weapon)
            : name(name), position(position), weapon(weapon) {}
    };
}

// Пространство имен для механик сражений
namespace GameBattle {
    class Team {
    public:
        std::string teamName;
        std::vector<GameUnits::Unit> units;

        Team(std::string teamName) : teamName(teamName) {}

        void addUnit(const GameUnits::Unit& unit) {
            units.push_back(unit);
        }
    };
}

// Пространство имен для утилит
namespace Utility {
    template <typename T>
    class Array {
    private:
        std::vector<T> elements;

    public:
        void add(const T& element) {
            elements.push_back(element);
        }

        void print() const {
            for (const auto& elem : elements) {
                std::cout << elem << " ";
            }
            std::cout << std::endl;
        }
    };

    struct IPrint {
        virtual void print() const = 0;
    };
}
