//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Класс для вывода изображения типа DIB и считывания изображения с экрана.

class clBmpPict {

HDC hdc; HBITMAP hBitmap,hBitmapOld; HFONT hFont;

void Zero(void); // Обнуление указателей и инициализация параметров.
void ZeroDC(void); // Обнуление указателей на старый битовый образ и DC.
void ZeroBmp(void); // Обнуление указателей и инициализация параметров для битового изображения.
void FreeBmp(void); // Освобождение памяти от битового изображения.
BYTE SetPix(int cx,int cy,BYTE *CC); // Рисование пиксела.

public:

BYTE typBmp,*pvBits; SHRT nCol; int dx,dy; UINT dxB;

clBmpPict(void);
~clBmpPict(void);
BYTE IsOK(void); // Проверки битового изображения и параметров.
BYTE IsOKB(void); // Проверки битового изображения и параметров.
BYTE Clear(void); // Заполнение битового изображения нулевым цветом.
BYTE Clear(COLORREF Col); // Заполнение битового изображения заданным цветом.
HDC GetDC(HDC hdc_); // Создание DC и выбор битового изображения в этом DC.
void FreeDC(void); // Выбор старого битового изображения и уничтожение DC.
void Free(void); // Освобождение памяти.
BYTE Init(int dx_,int dy_,BYTE typBmp_,DWORD *NCol,SHRT nCol_,HFONT hFont_); // Задание параметров.
BYTE Image(HDC hdcD,int xiD,int yiD,int dxD,int dyD,int xiS,int yiS,int dxS,int dyS,BYTE stretch); // Вывод изображения.
BYTE GetImg(HDC hdc_,int xi_,int yi_,int dx_,int dy_); // Получение изображения.
BYTE Save(HANDLE File,DWORD *NCol,SHRT nCol); // Сохранение изображения в файле '*.bmp'.
};
