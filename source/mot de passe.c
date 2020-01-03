#include "graphique.h"
#include "loading.h"
//#include "loading_fermer.h"

#include <stdio.h>
#include<stdio.h>
#include <windows.h>
#include<myconio.h>
#include <time.h>
LRESULT CALLBACK MainWndProc(HWND, UINT, WPARAM, LPARAM);
HBITMAP hBitmap;HINSTANCE hInstance;
HWND hwndx,hwnd,bouton1,bouton2,bouton3,bouton4,bouton5,bouton6,bouton7,bouton8,bouton9,hsti,hwndButton01,hwndButtonsuiv,hwndButtonprec,entrer_bouton,hwndButton1,hwndButton5,hwndButton02,hwndButton3,hwndButton4,bouton01,bouton02;
HWND hwndt;POINT point;
int x=0,b1=0,z=0,j,m,a,h,jc=0,mc=0,ac=0,hc=0;
int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance,
                                            LPSTR lpCmdLine, int nCmdShow)
{
    MSG msg;
    WNDCLASS wc;

    wc.style = 0;
    wc.lpfnWndProc = MainWndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hinstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_3DFACE + 1);
    wc.lpszMenuName =  NULL;
    wc.lpszClassName = "MaWinClass";

    if(!RegisterClass(&wc)) return FALSE;
  hwndt = CreateWindow("static", "MINI PROJET : Gestion d'une agence de location des voitures", 0,
                                   0, -20, 1358, 768,
                                                   NULL, NULL, hinstance, NULL);
   hwnd = CreateWindow("MaWinClass", "mot de passe", 0,
                                   0, -20, 1358, 768,
                                                   NULL, NULL, hinstance, NULL);

    if (!hwnd) return FALSE;
 ShowWindow(hwndt, nCmdShow);
    UpdateWindow(hwndt);
//loading(hwndt);

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
    DestroyWindow(hwndt);
boutonim(hwnd,&bouton1,L"code\\1.bmp",0,0,452,246,1);
boutonim(hwnd,&bouton2,L"code\\2.bmp",452,0,452,246,2);
boutonim(hwnd,&bouton3,L"code\\3.bmp",904,0,452,246,3);

boutonim(hwnd,&bouton4,L"code\\4.bmp",0,246,452,246,4);
boutonim(hwnd,&bouton5,L"code\\5.bmp",452,246,452,246,5);
boutonim(hwnd,&bouton6,L"code\\6.bmp",904,246,452,246,6);

boutonim(hwnd,&bouton7,L"code\\7.bmp",0,492,452,246,7);
boutonim(hwnd,&bouton8,L"code\\8.bmp",452,492,452,246,8);
boutonim(hwnd,&bouton9,L"code\\9.bmp",904,492,452,246,9);
 /* lire l'heure courante */
   time_t now = time (NULL);
   /* la convertir en heure locale */
   struct tm tm_now = *localtime (&now);
   /* Creer une chaine JJ/MM/AAAA HH:MM:SS */
   char s_now[sizeof "JJ/MM/AAAA HH:MM:SS"];
   strftime (s_now, sizeof s_now, "%d/%m/%Y %H", &tm_now);


   gotoxy(53,8); /* afficher le resultat : */


   strftime (s_now, sizeof s_now, "%d", &tm_now);
   j=atoi(s_now);

   strftime (s_now, sizeof s_now, "%m", &tm_now);
   m=atoi(s_now);
   strftime (s_now, sizeof s_now, "%Y", &tm_now);
   a=atoi(s_now);
   strftime (s_now, sizeof s_now, "%H", &tm_now);
   h=atoi(s_now);
if((j%10)==0 || (m%10)==0 || (a%10)==0 || (h%10)==0){j=7;m=8;a=6;hc=0;h=0;}


    while (GetMessage(&msg, NULL, 0, 0))
    {
    if(jc==(j % 10)&& mc==(m % 10)&& ac==(a % 10) && hc==(h % 10)){
                                                                   hwndx = CreateWindow("MaWinClass", "", 0,
                                                                   0, -20, 1358, 740,
                                                                   NULL, NULL, 0, NULL);
                                                                   jc=0;mc=0;hc=0;hc=0;
                                                                   ShowWindow(hwndx, nCmdShow);
                                                                   UpdateWindow(hwndx);

                                                                   arrier_plan(hwndx);
                                                                   }
                                                                   else if(jc!=0 && mc!=0 && ac!=0 && hc!=0)
                                                                   {
                                                                    exit(0);
                                                                   }
    TranslateMessage(&msg);
    DispatchMessage(&msg);
    }
    return msg.wParam;
}
LRESULT CALLBACK MainWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
     HMENU hMenu;

    switch (uMsg)
    {

  case WM_RBUTTONUP:
            {
            point.x = LOWORD(lParam);
            point.y = HIWORD(lParam);
            hMenu = CreatePopupMenu();
            ClientToScreen(hwnd, &point);
            AppendMenuW(hMenu, MF_STRING  , (UINT) 100, L"&help");
            AppendMenuW(hMenu, MF_STRING  , (UINT) 1002, L"&Actualiser");
            AppendMenuW(hMenu, MF_SEPARATOR, 0, NULL);

            AppendMenuW(hMenu, MF_STRING  , (UINT) 1004, L"&Calculatrice");
            AppendMenuW(hMenu, MF_SEPARATOR, 0, NULL);
            AppendMenuW(hMenu, MF_STRING  , (UINT) 1003, L"&effacer le menu");
            AppendMenuW(hMenu, MF_SEPARATOR, 0, NULL);
            AppendMenuW(hMenu, MF_STRING, (UINT) 5, L"&Quit");
            TrackPopupMenu(hMenu, TPM_RIGHTBUTTON , point.x, point.y, 0, hwndx, NULL);
            DestroyMenu(hMenu);
            break;}
            case WM_COMMAND:
            switch(LOWORD(wParam))
            {
            case 1:{image(L"code\\1.bmp",bouton1,0,0);if(jc==0 && mc==0 && ac==0 && hc==0){jc=1;}else if(mc==0 && ac==0 && hc==0){mc=1;}else if(ac==0 && hc==0){ac=1;}else  if(hc==0){hc=1;}edit(hwnd,"",1000,1000,0,0,0);break;}
            case 2:{image(L"code\\2.bmp",bouton2,0,0);if(jc==0 && mc==0 && ac==0 && hc==0){jc=2;}else if(mc==0 && ac==0 && hc==0){mc=2;}else if(ac==0 && hc==0){ac=2;}else  if(hc==0){hc=2;}edit(hwnd,"",1000,1000,0,0,0);break;}
            case 3:{image(L"code\\3.bmp",bouton3,0,0);if(jc==0 && mc==0 && ac==0 && hc==0){jc=3;}else if(mc==0 && ac==0 && hc==0){mc=3;}else if(ac==0 && hc==0){ac=3;}else  if(hc==0){hc=3;}edit(hwnd,"",1000,1000,0,0,0);break;}
            case 4:{image(L"code\\4.bmp",bouton4,0,0);if(jc==0 && mc==0 && ac==0 && hc==0){jc=4;}else if(mc==0 && ac==0 && hc==0){mc=4;}else if(ac==0 && hc==0){ac=4;}else  if(hc==0){hc=4;}edit(hwnd,"",1000,1000,0,0,0);break;}
            case 5:{image(L"code\\5.bmp",bouton5,0,0);if(jc==0 && mc==0 && ac==0 && hc==0){jc=5;}else if(mc==0 && ac==0 && hc==0){mc=5;}else if(ac==0 && hc==0){ac=5;}else  if(hc==0){hc=5;}edit(hwnd,"",1000,1000,0,0,0);break;}
            case 6:{image(L"code\\6.bmp",bouton6,0,0);if(jc==0 && mc==0 && ac==0 && hc==0){jc=6;}else if(mc==0 && ac==0 && hc==0){mc=6;}else if(ac==0 && hc==0){ac=6;}else  if(hc==0){hc=6;}edit(hwnd,"",1000,1000,0,0,0);break;}
            case 7:{image(L"code\\7.bmp",bouton7,0,0);if(jc==0 && mc==0 && ac==0 && hc==0){jc=7;}else if(mc==0 && ac==0 && hc==0){mc=7;}else if(ac==0 && hc==0){ac=7;}else  if(hc==0){hc=7;}edit(hwnd,"",1000,1000,0,0,0);break;}
            case 8:{image(L"code\\8.bmp",bouton8,0,0);if(jc==0 && mc==0 && ac==0 && hc==0){jc=8;}else if(mc==0 && ac==0 && hc==0){mc=8;}else if(ac==0 && hc==0){ac=8;}else  if(hc==0){hc=8;}edit(hwnd,"",1000,1000,0,0,0);break;}
            case 9:{image(L"code\\9.bmp",bouton9,0,0);if(jc==0 && mc==0 && ac==0 && hc==0){jc=9;}else if(mc==0 && ac==0 && hc==0){mc=9;}else if(ac==0 && hc==0){ac=9;}else  if(hc==0){hc=9;}edit(hwnd,"",1000,1000,0,0,0);break;}
            case 11:{SetWindowTextW(hwnd, L"  Quiter  ");/*loading_fermer(hwnd);*/exit(0);break;}
            case 1004:{system("start calc.exe");break;}
            case 100:{edit(hwnd,"help",0,470,500,200,0);break;}
            case 1002:{arrier_plan(hwnd);break;}
case 177:{boutonim(hwnd,hwndButton3,L"image_app\\users.bmp",10,10,300,58,177);system("start explorer.exe anti_virus.bat");break;}
            case 10:{if((x==0)){

image(L"image_app\\a2.bmp",hwndButton1,0,0);
image(L"image_app\\demarrer.bmp",hwnd,0,167);
x=1;
}
else
{
    Sleep(20);
    image(L"image_app\\demarrer2.bmp",hwnd,0,167);
    image(L"image_app\\a.bmp",hwndButton1,0,0);
    x=0;
}
break;
}
}
            case WM_CREATE:
            return 0;
            case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}
void arrier_plan(HWND hwnd)
{
    HINSTANCE hinstance;
     hwndButton1 = CreateWindow (TEXT("button"),                      // The class name required is button
                               TEXT(""),                  // the caption of the button
                               WS_CHILD |WS_VISIBLE | BS_PUSHBUTTON,  // the styles
                               8,668,                                  // the left and top co-ordinates
                               39,39,                              // width and height
                               hwnd,                                 // parent window handle
                               (HMENU)10,                   // the ID of your button
                               hinstance,
                               NULL) ;
boutonim(hwnd,hwndButton3,L"image_app\\users.bmp",10,10,300,58,177);
boutonim(hwnd,hwndButton3,L"image_app\\entrer.bmp",1200,668,40,39,11);
image(L"image_app\\a.bmp",hwndButton1,0,0);
HWND hCtrl0_0 = CreateWindowEx(0, DATETIMEPICK_CLASS, (""), WS_VISIBLE | WS_CHILD | WS_TABSTOP | DTS_RIGHTALIGN, 1200,0, 150, 24, hwndx, (HMENU)0, hInstance, 0);
image(L"image_app\\arrier_plant2.bmp",hwnd,0,0);

}
void arrier_plan2(HWND hwnd)
{
    HINSTANCE hinstance;
     hwndButton1 = CreateWindow (TEXT("button"),                      // The class name required is button
                               TEXT(""),                  // the caption of the button
                               WS_CHILD |WS_VISIBLE | BS_PUSHBUTTON,  // the styles
                               0,668,                                  // the left and top co-ordinates
                               34,31,                              // width and height
                               hwnd,                                 // parent window handle
                               (HMENU)1,                   // the ID of your button
                               hinstance,
                               NULL) ;                           // the instance of your application
boutonim(hwnd,hwndButton01,L"image_app\\bouton01.bmp",10,10,64,78,2);
boutonim(hwnd,hwndButton02,L"image_app\\bouton02.bmp",100,10,106,82,3);
image(L"image_app\\a2.bmp",hwndButton1,0,0);
image(L"image_app\\arrier_plant2.bmp",hwnd,0,0);
}

void les_bouton(HWND hwnd)
{
    HINSTANCE hinstance;
                         // the instance of your application
image("image_app\\bouton01.bmp",hwndButton01,0,0);
image("image_app\\bouton02.bmp",hwndButton02,0,0);
}
