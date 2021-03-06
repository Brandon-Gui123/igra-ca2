// OpenGLApplication.cpp : Defines the entry point for the application.
// Done by Brandon Gui (1828865) and Ryan Tan (1829105) from DIT/FT/2B/05

#include "OpenGLApplication.h"

#include "GameDifficulty.h" // for GameDifficulty enum class
#include "Input.h"      // for Input class
#include "MouseButton.h"// for MouseButton enum class
#include "Program.h"

#include "framework.h"
#include "Windowsx.h"   // for GET_X_LPARAM and GET_Y_LPARAM
#include <gl/GL.h>  // OpenGL 32-bit library
#include <gl/GLU.h> // OpenGL Utilities 32-bit library

#include <iostream>   // std::cout
#include <string>     // std::string, std::to_string

#define MAX_LOADSTRING 100

#define EXTRA_WIDTH 16 
#define EXTRA_HEIGHT 60

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

GLuint PixelFormat; // GLuint is an OpenGL pre-defined unsigned int type. These ensure cross-platform compatibility.
HDC hDC = NULL;     // A Handle to the Device Content (hence, HDC)
HWND hWnd = NULL;   // A Handle to the Window (hence, HWND)
HGLRC hRC = NULL;   // A Handle to an OpenGL Rendering Context (hence, HGLRC)

// Pixel Format Descriptor
static PIXELFORMATDESCRIPTOR pfd
{
    sizeof(PIXELFORMATDESCRIPTOR),
    1,                      // version number
    PFD_DRAW_TO_WINDOW |    // format must support window
    PFD_SUPPORT_OPENGL |    // format must support OpenGL
    PFD_DOUBLEBUFFER,       // must support double buffering
    PFD_TYPE_RGBA,          // request an RGBA format
    16,                     // select our colour depth, which will be 16
    0, 0, 0, 0, 0, 0,       // colour bits ignored
    0,                      // no alpha buffer
    0,                      // shift bit ignored
    0,                      // no accumulation buffer
    0, 0, 0, 0,             // accumulation bits ignored
    32,                     // 32-bit Z-Buffer (depth buffer)
    0,                      // no stencil buffer
    0,                      // no auxiliary buffer
    PFD_MAIN_PLANE,         // main drawing layer
    0,                      // reserved
    0, 0, 0                 // layer masks ignored
};

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    Credits(HWND, UINT, WPARAM, LPARAM);
void ReSizeGLScene(GLsizei width, GLsizei height);
int InitOpenGL();
void DrawGLScene();

Program program;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_OPENGLAPPLICATION, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_OPENGLAPPLICATION));

    MSG msg;

    program.InitializeScenes();

	program.Start();

    program.StartInternalTimer();
    
    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
			program.Update();
            DrawGLScene();
            SwapBuffers(hDC);
            program.ResetInputKeyUpDownStatus();
            program.ResetMouseButtonUpDownStatus();
            program.MoveNewGOsToMain();
            program.DoStartOnAddedComponents();
            program.DoDestroyCycleForPickableMeshes();
            program.DoDestroyCycle();
            program.QueryDeltaTime();

            if (program.willRestart)
            {
                program.willRestart = false;
                program.RestartProgram();
            }
        }
    }

    return (int) msg.wParam;
}

//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_OPENGLAPPLICATION));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_OPENGLAPPLICATION);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   //hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW, 0, 0, Program::initialWindowWidth, Program::initialWindowHeight, nullptr, nullptr, hInstance, nullptr);

   // uncomment and comment the text above to create a window suitable for mouse input
   hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW, 0, 0, Program::initialWindowWidth + EXTRA_WIDTH, Program::initialWindowHeight + EXTRA_HEIGHT, nullptr, nullptr, hInstance, nullptr);

   InitOpenGL();

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   ReSizeGLScene(Program::initialWindowWidth, Program::initialWindowHeight);
   SetTimer(hWnd, NULL, USER_TIMER_MINIMUM, NULL);
   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;

            case ID_INFO_CREDITS:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_CREDITS), hWnd, Credits);
                break;

            case ID_GAME_PAUSE:
                Time::SetTimeScale(0.0);
                break;

            case ID_GAME_RESUME:
                Time::SetTimeScale(1.0);
                break;

            case ID_GAME_STOP:
            {
                Time::SetTimeScale(0.0);
                std::wstring gameStopMessage{L"Game ended with a score of "};
                std::wstring points{std::to_wstring(program.score)};
				MessageBox(NULL, (gameStopMessage + points).c_str(), L"Game Stopped", MB_OK);
                program.willRestart = true;
                Time::SetTimeScale(1.0);
                break;
            }

            case ID_START_EASY:
                program.currentDifficulty = GameDifficulty::Easy;
                program.willRestart = true;
                break;

            case ID_START_NORMAL:
                program.currentDifficulty = GameDifficulty::Normal;
                program.willRestart = true;
                break;

            case ID_START_HARD:
                program.currentDifficulty = GameDifficulty::Hard;
                program.willRestart = true;
                break;

            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_SIZE:
        {
            ReSizeGLScene(Program::initialWindowWidth, Program::initialWindowHeight);
            break;
        }
    case WM_KEYDOWN:
    {
        program.SendKeyDown(wParam);
        break;
    }
    case WM_KEYUP:
    {
        program.SendKeyUp(wParam);
        break;
    }
    case WM_MOUSEMOVE:
    {
        program.SendMousePosition(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
        break;
    }
    case WM_LBUTTONDOWN:
    {
        program.SendMouseButtonDown(MouseButton::Left);
        program.DrawPickableMeshes();
        break;
    }
    case WM_LBUTTONUP:
    {
        program.SendMouseButtonUp(MouseButton::Left);
        break;
    }
    case WM_MBUTTONDOWN:
    {
        program.SendMouseButtonDown(MouseButton::Middle);
        break;
    }
    case WM_MBUTTONUP:
    {
        program.SendMouseButtonUp(MouseButton::Middle);
        break;
    }
    case WM_RBUTTONDOWN:
    {
        program.SendMouseButtonDown(MouseButton::Right);
        break;
    }
    case WM_RBUTTONUP:
    {
        program.SendMouseButtonUp(MouseButton::Right);
        break;
    }
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

INT_PTR CALLBACK Credits(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
        case WM_INITDIALOG:
            return (INT_PTR)TRUE;

        case WM_COMMAND:
            if (LOWORD(wParam) == IDCLOSE || LOWORD(wParam) == IDCANCEL)
            {
                EndDialog(hDlg, LOWORD(wParam));
                return (INT_PTR)TRUE;
            }
            break;
    }
    return (INT_PTR)FALSE;
}

void ReSizeGLScene(GLsizei width, GLsizei height)
{
    // prevent a division by zero error by setting the height to 1
    if (height == 0)
        height = 1;

    // reset the current viewport
    glViewport(0, 0, width, height);

    // select the projection matrix
    glMatrixMode(GL_PROJECTION);

    // reset the projection matrix
    glLoadIdentity();

    gluPerspective(45.0f, (GLfloat) width / (GLfloat) height, 0.1f, 100.0f);

    // orthographic view - uncomment for use with 2D or with 3D isometric
    // gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int InitOpenGL()
{
    // get device context
    if (!(hDC = GetDC(hWnd)))
    {
        MessageBox(
            NULL,
            L"Can't create a GL device context!",
            L"ERROR",
            MB_OK | MB_ICONEXCLAMATION
        );
        return 0;
    }

    // check if Windows can find a matching pixel format
    if (!(PixelFormat = ChoosePixelFormat(hDC, &pfd)))
    {
        MessageBox(
            NULL,
            L"Can't find a suitable pixel format!",
            L"ERROR",
            MB_OK | MB_ICONEXCLAMATION
        );
        return 0;
    }

    // try to set the pixel format
    if (!SetPixelFormat(hDC, PixelFormat, &pfd))
    {
        MessageBox(
            NULL,
            L"Can't create a GL rendering context!",
            L"ERROR",
            MB_OK | MB_ICONEXCLAMATION
        );
        return 0;
    }

    // get a rendering context
    if (!(hRC = wglCreateContext(hDC)))
    {
        MessageBox(
            NULL,
            L"Can't set the pixel format!",
            L"ERROR",
            MB_OK | MB_ICONEXCLAMATION
        );
        return 0;
    }

    // activate rendering context
    if (!wglMakeCurrent(hDC, hRC))
    {
        MessageBox(
            NULL,
            L"Can't activate the GL rendering context!",
            L"ERROR",
            MB_OK | MB_ICONEXCLAMATION
        );
        return 0;
    }

    // for solving the depth-buffer issue
    glClearDepth(1.0f);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	program.SetupLight();
	Program::CreateWoodTexture();
    return 1;
}

double test{};

void DrawGLScene()
{
    //test += Time::GetDeltaTime();

	//SetWindowTextA(hWnd, std::to_string(test).c_str()); // Debug to show the time elapsed

    program.Draw();

	//SetWindowTextA(hWnd, std::to_string(Time::GetGameTime()).c_str()); // Debug to show the time elapsed

    SetWindowTextA(hWnd, ("Lilypad Jump - Score: " + std::to_string(program.score)).c_str());
}