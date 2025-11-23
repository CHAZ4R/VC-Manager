#ifndef BATIMENT
#define BATIMENT

#include "../utils.hpp"
#include "../ville/ville.hpp"
#include <string>
#include "../utils/name_generator.hpp"

using namespace std;

class Batiment {
public:
  TypeBatiment type;
  Surface surface;
  Position position;
  Ville *ville;

  // Constructors
  Batiment(int id, Ville *ville, TypeBatiment type,
         int effectSatisfication, double cost, unsigned int Employees,
         unsigned int EmployeesNeeded, double consommationEau,
         double consommationElectricite, float polution, int x, int y,
         int largeur, int longeur,
         const std::string& nom = "");

  Batiment(int id, const string &nom, Ville *ville, TypeBatiment type,
           int effectSatisfication, double cost, unsigned int Employees,
           unsigned int EmployeesNeeded, double consommationEau,
           double consommationElectricite, float polution, Position position,
           Surface surface);
  virtual ~Batiment() = default; // For the Polymorphic deletion

  virtual void afficheDetails() const;
  int calculerImpactRessources();

  // Getters
  int getID();
  int getSatisfaction();
  float getPolution();
  Resources getConsummation();

protected:
  int id;
  string nom;
  Resources consommation;
  float polution;
  int effectSatisfication;
  unsigned int EmployeesNeeded;
  unsigned int Employees;
  double cost;
};

#endif // !BATIMENT

