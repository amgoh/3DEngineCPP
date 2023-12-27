#include "Window.h"

Window* window = NULL;

Window::Window() {}

LRESULT CALLBACK WndProcW(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
    switch (msg)
    {
        case WM_CREATE:
        {
            //Window creation event
            window->onCreate();
            break;
        }
        case WM_DESTROY:
        {
            //Window destruction event
            window->onDestroy();
            PostQuitMessage(0);
            break;
        }

        default:
        {
            return DefWindowProcW(hwnd, msg, wparam, lparam);
        }
    }
    return NULL;
}

bool Window::init() {

    // declare window class and set attributes

    WNDCLASSEXW wc;
    wc.cbClsExtra = NULL;
    wc.cbSize = sizeof(WNDCLASSEXW);
    wc.cbWndExtra = NULL;
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    wc.hInstance = NULL;
    wc.lpszClassName = L"WindowClass";
    wc.lpszMenuName = L"";
    wc.style = NULL;
    wc.lpfnWndProc = &WndProcW;

    // If class registration fails, return false

    if(!RegisterClassExW(&wc)) {
        return false;
    }



    if(!window) {
        window = this;
    }

    // Create window

    RECT rc = { 0, 0, 1024, 768 };
    // AdjustWindowRect(&rc, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, false);

    m_hwnd=CreateWindowExW(
        WS_EX_OVERLAPPEDWINDOW,
        L"Amogh's Window",
        L"OpenGL Application",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        rc.right - rc.left, rc.bottom - rc.top,
        NULL,NULL,NULL,NULL
    );

    

    // If window creation fails, return false
    if(!m_hwnd) {
        return false;
    }

    ShowWindow(m_hwnd, SW_SHOW);
    UpdateWindow(m_hwnd);

    // check to make sure the window is running, for the isRunning method
    m_is_running = true;

    return true;
}

bool Window::broadcast() {
    MSG msg;

    while(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    this->onUpdate();

    Sleep(1);

    return true;
}

bool Window::destroy() {
    //Destroy the window, if present, otherwise return false
    if(!DestroyWindow(m_hwnd)) {
        return false;
    }
    return true;
}

bool Window::isRunning() {
    return m_is_running;
}

void Window::onCreate() {

}

void Window::onUpdate() {
    
}

void Window::onDestroy() {
    m_is_running = false;
}

Window::~Window() {}