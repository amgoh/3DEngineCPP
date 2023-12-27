#include <Windows.h>

class Window
{
public: 
    Window();
    // Initialize the window instance
    bool init();
    // 
    bool broadcast();
    // close the window instance
    bool destroy();
    // check if window running
    bool isRunning();

    virtual void onCreate()=0;
    virtual void onUpdate()=0;
    virtual void onDestroy();

    ~Window();
protected:
    HWND m_hwnd;
    bool m_is_running;
};