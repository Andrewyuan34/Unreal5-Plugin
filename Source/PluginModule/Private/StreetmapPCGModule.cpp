#include "StreetmapPCGModule.h"
#include "Modules/ModuleManager.h"

#define LOCTEXT_NAMESPACE "FStreetmapPCGModule"

void FStreetmapPCGModule::StartupModule()
{
    // This code will execute after your module is loaded into memory
}

void FStreetmapPCGModule::ShutdownModule()
{
    // This function may be called during shutdown to clean up your module
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FStreetmapPCGModule, StreetmapPCG) 