 #include "G4RunManagerFactory.hh"
 #include "G4UImanager.hh"
 #include "DetectorConstruction.hh" 
 #include "ActionInitialization.hh"
 #include "G4VisExecutive.hh"
 #include "G4UIExecutive.hh"
 #include "QGSP_BERT.hh"
 #include "G4EmStandardPhysics.hh"
 #include "G4OpticalPhysics.hh"

 int main(int argc, char **argv)
 {
     // Detect interactive mode (if no arguments) and define UI session
     G4UIExecutive *ui = nullptr;
     if (argc == 1)
         ui = new G4UIExecutive(argc, argv);

     // Set random seed number
     G4Random::setTheSeed(time(nullptr));

     // Construct the default run manager
     auto runManager = G4RunManagerFactory::CreateRunManager(G4RunManagerType::Serial);

     // Physics lists
     G4VModularPhysicsList* PL = new QGSP_BERT;
     PL -> SetVerboseLevel(0);
     PL -> ReplacePhysics(new G4EmStandardPhysics());
     PL -> RegisterPhysics(new G4OpticalPhysics());
     runManager -> SetUserInitialization(PL);

     // Set mandatory initialization classes
     runManager->SetUserInitialization(new DetectorConstruction);
     runManager->SetUserInitialization(new ActionInitialization);

     // Initialize G4 kernel
     runManager->Initialize();

     // Initialize visualization
     auto visManager = new G4VisExecutive;
     visManager->Initialize();
    
     // Get the pointer to the User Interface manager
     auto UImanager = G4UImanager::GetUIpointer();
		 
	// Process macro or start UI session
     if (ui)
     {
         // interactive mode
         UImanager->ApplyCommand("/control/execute vis.mac");
         ui->SessionStart();
         delete ui;
     }
     else
     {
         // batch mode
         G4String command = "/control/execute ";
         G4String filename = argv[1];
         UImanager->ApplyCommand(command + filename);
     }
     delete runManager;

     return 0;
 }

