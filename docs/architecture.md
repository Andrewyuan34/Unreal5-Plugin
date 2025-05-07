
# Architecture for StreetMap project:
## Data Processing Flow:
OSM File → FOSMFile Parser → UStreetMap Data → UStreetMapComponent Rendering

## Rendering Pipeline:
UStreetMapComponent → FStreetMapSceneProxy → Rendering Thread

## Editor:
Resource Factory → Editor UI → Component Details Panel

### OSMFile.h Parser Model Class
#### Input 
OSM XML File: OpenStreetMap format map data file containing: 
- Nodes: Geographic points with latitude and longitude coordinates 
- Ways: Ordered lists of nodes representing roads, paths, or building outlines 
- Tags: Key-value pairs describing the properties of nodes and ways

#### Final Output(combined with factory class) 
UStreetMap Object: A structured data object containing:
- Roads: Collection of road data 
- Nodes: Collection of intersection points 
- Buildings: Collection of building data 
- Bounds: Map boundary information 
