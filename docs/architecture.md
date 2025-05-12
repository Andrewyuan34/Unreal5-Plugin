
# Architecture for StreetMap project:
## Data Processing Flow:
OSM File → FOSMFile Parser → UStreetMap Data → UStreetMapComponent Rendering

## Rendering Pipeline:
UStreetMapComponent → FStreetMapSceneProxy → Rendering Thread

## Editor:
Resource Factory → Editor UI → Component Details Panel

### OSMFile.h Parser Model Class
OSM XML File: OpenStreetMap format map data file containing: 
- Nodes: Geographic points with latitude and longitude coordinates 
- Ways: Ordered lists of nodes representing roads, paths, or building outlines 
- Tags: Key-value pairs describing the properties of nodes and ways

Basically this class is built to convert format in a readable format for this Plugin

### UStreetMapFactory
 - This class is an Unreal Engine asset factory that converts OpenStreetMap XML data into UE-compatible "UStreetMap" assets. 
 - It implements geographic coordinate transformation, road network construction, and building data processing, while optimizing data structures for efficient rendering and navigation. 
 - The factory integrates with UE's asset import system through the “UFactory” interface, supporting map data import, update, and validation.

 ### UStreetMapReimportFactory
 Basically derive the interface class that Unreal provided and write customized logic to override it.
```cpp
 virtual bool CanReimport(UObject* Obj, TArray<FString>& OutFilenames) = 0;

 virtual void SetReimportPaths(UObject* Obj, const TArray<FString>& NewReimportPaths) = 0;

 virtual EReimportResult::Type Reimport(UObject* Obj) = 0;

 virtual int32 GetPriority() const = 0;
```
https://dev.epicgames.com/documentation/en-us/unreal-engine/API/Editor/UnrealEd/FReimportHandler

### FStreetMapImportingModule
The FStreetMapImportingModule serves as an Editor-Runtime Bridge for this plugin. It manages the StreetMap asset type in the content browser, initializes custom UI styles, and sets up property panel customization for the StreetMap component. 

This is standard way for any Unreal plugin to integrate with the engine. It handles module lifecycle (StartupModule/ShutdownModule/PostLoadCallback).

https://dev.epicgames.com/documentation/en-us/unreal-engine/API/Runtime/Core/Modules/IModuleInterface

 ### Final Output(combined with factory class) 
UStreetMap Object: A structured data object containing:
- Roads: Collection of road data 
- Nodes: Collection of intersection points 
- Buildings: Collection of building data 
- Bounds: Map boundary information 
