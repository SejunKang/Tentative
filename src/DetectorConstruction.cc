#include "DetectorConstruction.hh"
#include "G4SystemOfUnits.hh"
#include "G4NistManager.hh"
#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4Colour.hh"
#include "G4VisAttributes.hh"
#include "G4LogicalBorderSurface.hh"
#include "G4Box.hh"
#include "G4ThreeVector.hh"

DetectorConstruction::DetectorConstruction()
{
}

DetectorConstruction::~DetectorConstruction()
{
}

G4VPhysicalVolume *DetectorConstruction::Construct()
{

G4Box *WorldSol = new G4Box("WorldSol", 5*m, 5*m, 5*m);
G4LogicalVolume *WorldLog = new G4LogicalVolume(WorldSol, nullptr, "WorldLog");
G4PVPlacement *WorldPhy = new G4PVPlacement(nullptr, G4ThreeVector(0.,0.,0.), WorldLog, "WorldPhy", nullptr, false, 0);

return WorldPhy;
}
