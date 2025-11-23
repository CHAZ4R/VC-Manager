#ifndef NAME_GENERATOR_HPP
#define NAME_GENERATOR_HPP

#include <string>
#include <vector>
#include <random>
#include <memory>
#include <map>

enum class BuildingType {
    House,
    Apartment,
    Park,
    PowerPlant,
    WaterTreatmentPlant,
    Commercial,
    Industrial
};

class NameGenerator {
private:
    std::mt19937 rng;
    std::map<BuildingType, std::vector<std::string>> prefixes;
    std::map<BuildingType, std::vector<std::string>> suffixes;
    std::map<BuildingType, std::vector<std::string>> fullNames;
    
    void initializeData();
    
public:
    NameGenerator();
    explicit NameGenerator(unsigned int seed);
    
    std::string generateBuildingName(BuildingType type);
    std::string generateBuildingName(BuildingType type, const std::string& district);
    
    static NameGenerator& getInstance();
};

#endif
