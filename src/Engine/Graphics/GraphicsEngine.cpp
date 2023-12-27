#include "GraphicsEngine.h"

GraphicsEngine::GraphicsEngine() {}

bool GraphicsEngine::init() {
    D3D_DRIVER_TYPE driverTypes[] = {
        D3D_DRIVER_TYPE_HARDWARE,
        D3D_DRIVER_TYPE_WARP,
        D3D_DRIVER_TYPE_REFERENCE
    };
    UINT numDriverTypes = ARRAYSIZE(driverTypes);

    D3D_FEATURE_LEVEL featureLevels[] = {
        D3D_FEATURE_LEVEL_12_1
    };
    UINT numFeatureLevels = ARRAYSIZE(featureLevels);

    for(UINT driverTypeIndex=0; driverTypeIndex < ARRAYSIZE(driverTypes); driverTypeIndex++){   
        // D3D12CreateDevice(NULL, featureLevels[0], , NULL);
    }

    return true;
}

bool GraphicsEngine::destroy() {
    
    
    
    
    
    return true;
}


GraphicsEngine::~GraphicsEngine() {}