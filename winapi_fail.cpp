#include<windows.h>
#include <tchar.h>

// WinMain == main
/*
int WINAPI WinMain(HINSTANCE hInst , HINSTANCE hPrevInst, LPSTR args, int ncmdshow){
    //MessageBox == 경고창 ( 0 , 본문 , 제목 , OK버튼호출 )
    MessageBox(NULL,"Hello","My first GUI",MB_OK);
    return 0;
}
*/

LRESULT CALLBACK Windowprocedure(HWND,UINT,WPARAM,LPARAM);

int WINAPI WinMain(HINSTANCE hInst , HINSTANCE hPrevInst, LPSTR args, int ncmdshow){
    WNDCLASSEXW wc = {0};

    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL,IDC_ARROW);
    wc.hInstance = hInst;
    wc.lpszClassName = L"myWindowClass";
    wc.lpfnWndProc = Windowprocedure;
    
    if(!RegisterClassW(&wc))
        return -1;
    
    CreateWindowW(L"myWindowClass",L"My Window",WS_OVERLAPPEDWINDOW | WS_VISIBLE,100,100,500,500,NULL,NULL,NULL,NULL);

    MSG msg = {0};
    while(GetMessage(&msg,NULL,NULL,NULL)){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}

LRESULT CALLBACK Windowprocedure(HWND hWnd,UINT msg,WPARAM wp,LPARAM lp){
    switch(msg){
        case WM_DESTROY:
            PostQuitMessage (0);
            break;
        default:
        return DefWindowProc(hWnd,msg,wp,lp);
    }
}