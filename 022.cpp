#include <iostream>
#include <variant>

struct Fluid { };
struct LightItem { };
struct HeavyItem { };
struct FragileItem { };

struct VisitPackage {
    void operator()(Fluid&) { std::cout << "fluid\n"; }
    void operator()(LightItem&) { std::cout << "light item\n"; }
    void operator()(HeavyItem&) { std::cout << "heavy item\n"; }
    void operator()(FragileItem&) { std::cout << "fragile\n"; }
};

int main() {
    std::variant<Fluid, LightItem, HeavyItem, FragileItem> package{
        Fluid()
    };

    std::visit(VisitPackage(), package);
}