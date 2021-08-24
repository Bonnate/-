// 슈팅게임.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"

#include "슈팅게임.h"

#define MAX_LOADSTRING 100


// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
HWND      hWnd;                                 // 현재 윈도우핸들입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.


// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{


    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    MSG msg = { 0, };

    //초기화
    START_DEBUG_CONSOLE();  //디버그 콘솔 시작
    initGraphic(hWnd, 0, 0, WIDTH, HEIGHT);
    Random::Init();
    Time::init();

    //배경 및 초기 객체 추가하기//
    ObjectManager::instantiate(new GameBG());
    ObjectManager::instantiate(new Player(WIDTH/2 - 34, HEIGHT/2 - 45));



    // 기본 메시지 루프입니다:
    while (WM_QUIT != msg.message)
    {                                   //0, 0은 0~0까지의 메시지만 받는다.
                                        //0, 0으로 하면 모든 메시지를 받음
                                        //PM_REMOVE는 메시지를 가져온 후 지운다.
        if(PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            //윈도우..동작..//
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        //게임 동작..//
        clear(0, 0, 0);

        Time::update();                 //델타 타임 업데이트
        Input::update();                //키 입력 업데이트

        ObjectManager::update();        //오브젝트 상태 업데이트
        ObjectManager::draw();          //오브젝트 그리기

        

        render();
    }

    //종료
    STOP_DEBUG_CONSOLE();
    exitGraphic();

    return (int) msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = nullptr;
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   //윈도우 크기 조정하기
   RECT rt = { 0, 0, WIDTH, HEIGHT };

   AdjustWindowRect(&rt, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, FALSE);

   int width = rt.right - rt.left;
   int height = rt.bottom - rt.top;

   hWnd = CreateWindowW(szWindowClass, 
                             szTitle, 
                             WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU,
                             CW_USEDEFAULT, 
                             0, 
                             width,
                             height,
                             nullptr, 
                             nullptr, 
                             hInstance, 
                             nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

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
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);

            render();

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
