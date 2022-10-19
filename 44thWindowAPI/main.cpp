// WindowsAPI.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "Common.h"
#include "44thWindowAPI.h"
#include "yaApplication.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.


// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);


// int main() {}
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // 1. wndclass 정의 윈도의 기반(여러가지 속성)이 되는 클래스 정의해준다.

    // 2. 메모리상에 윈도우를 할당해야죠. CreateWindow

    // 3. showwindow 함수를 통해서 윈도우가 화면에 보여진다. (update window)

    // 4. wndclass 정의할때 함수포인터에 넣어준 loop (wndproc) 메프레임마다 실행한다.

    // 윈도우즈는 크게 3가지 라이브러리 이루어져 있는데.

    // 메모리를 관리하고 실행시키는 KERNEL 커널 
    // 유저 인터페이스와 과리하는 USER
    // 화면처리와 그래픽을 담당하는 GDI 로 이루어져있다.


    // 
    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY44THWINDOWAPI, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY44THWINDOWAPI));

    MSG msg;

    // GetMessage : 프로세스에 발생한 메시지를 메세지 큐에서 꺼내옴
    // 메세지가 있을때만 메세지를 꺼내온다.
    // 메세지 case 함수를 호출해준다.

    // PeekMessage 
    // 발생한 메세지를 가져 올때 메세지큐에서 따로 제거해줘야한다.
    // 메세지큐에 메세지가 들어있는 유/무에 관계없이 함수가 리턴됩니다.



    //while (true)
    //{
    //    update();
    //    render();
    //}

    // 기본 메시지 루프입니다:
    while (true)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (WM_QUIT == msg.message)
                break;

            if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else
        {
            // 게임 실행
            ya::Application().GetInstance().Tick();
        }
    }

    // 종료가 되었을때
    if (WM_QUIT == msg.message)
    {
        // 메모리 해제 작업
    }


    return (int)msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDC_MY44THWINDOWAPI));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_MY44THWINDOWAPI);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

    WindowData windowData;
    windowData.width = 1920;
    windowData.height = 1080;

    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    windowData.hWnd = hWnd;
    windowData.hdc = nullptr;

    if (!hWnd)
    {
        return FALSE;
    }
    SetWindowPos(hWnd, nullptr, 0, 0, windowData.width, windowData.height, 0);
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    ya::Application::GetInstance().Initialize(windowData);

    return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
    {

    }
    break;
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // 메뉴 선택을 구문 분석합니다:
        switch (wmId)
        {
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;

    case WM_KEYDOWN:
    {


        // 무효화 영역 발생시키기 ( WM_PAINT 메시지를 호출해주겠따)
        //InvalidateRect(hWnd, nullptr, false);
    }
    break;

    case WM_TIMER:
    {

    }
    break;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        //// 스톡 오브젝트
        // 화면 지우기
        HBRUSH hClearBrush = (HBRUSH)GetStockObject(DKGRAY_BRUSH);
        HBRUSH oldClearBrush = (HBRUSH)SelectObject(hdc, hClearBrush);
        Rectangle(hdc, -1, -1, 1921, 1081);


        // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
        EndPaint(hWnd, &ps);
        //문자
        //HFONT

        //HBITMAP
        //HBITMAP
        //DC 정리

        // 1. PEN BRUSH 핸들을 선언한다.
        // 2. GDI 오브젝트를 생성해준다.
        // 3. 생성된 오브젝트로 hdc 세팅해줘야한다. selectobject
        //사용하고

        // 기존의 오브젝트로 되돌린다 ( 해제 )
        // 핸들을 삭제한다.
    }
    break;
    case WM_DESTROY:
    {
        PostQuitMessage(0);
        //KillTimer(hWnd, 0);
    }
    break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
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
