//---------------------------------------------------------------------------
// Удаление строк

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit8.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm8 *Form8;
//---------------------------------------------------------------------------
__fastcall TForm8::TForm8(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm8::Button1Click(TObject *Sender)
{
 //отправляемая строка (запрос - добавить)
 String q;

//----------------- Таблица "Программные проекты" --------------------------
 if (Form1->PageControl1->ActivePageIndex==0)
    {
    int cur = Form1->StringGrid1->Row; // выбранная строка
    q = "Del1;";
    for (int i=0; i<7; i++) {q = q + Form1->StringGrid1->Cells[i][cur]+";";}
    Form1->ClientSocket1->Socket->SendText(q);
    }

//----------------- Таблица "Модули и библиотеки" --------------------------
 if (Form1->PageControl1->ActivePageIndex==1)
    {
    int cur = Form1->StringGrid2->Row; // выбранная строка
    q = "Del2;";
    for (int i=0; i<4; i++) {q = q + Form1->StringGrid2->Cells[i][cur]+";";}
    Form1->ClientSocket1->Socket->SendText(q);
    }

//----------------- Таблица "Заказчики" ------------------------------------
 if (Form1->PageControl1->ActivePageIndex==2)
    {
    int cur = Form1->StringGrid3->Row; // выбранная строка
    q = "Del3;";
    for (int i=0; i<5; i++) {q = q + Form1->StringGrid3->Cells[i][cur]+";";}
    Form1->ClientSocket1->Socket->SendText(q);
    }

 Form8->Close(); 
}


//_________________ Отмена удаления ________________________________________
void __fastcall TForm8::Button2Click(TObject *Sender)
{
 Form8->Close();
}