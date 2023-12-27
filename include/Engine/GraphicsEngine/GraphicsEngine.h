#include <d3d12.h>
class GraphicsEngine{
public:
    GraphicsEngine();
    ~GraphicsEngine();
    // Initializes the graphics engine
    bool init();
    // Destroys the graphics engine
    bool destroy();
};