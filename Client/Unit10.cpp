//---------------------------------------------------------------------------
//Редактирование записей таблицы 2

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit10.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm10 *Form10;
//---------------------------------------------------------------------------
__fastcall TForm10::TForm10(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm10::Button1Click(TObject *Sender)
{
 //отправляемая строка (запрос - добавить)
 String q;
 bool NotEmpt = true;
 AnsiString FieldName;

 for (int i=1;i<4;i++)
     {
     if (((TEdit*)FindComponent("Edit"+String(i)))->Text=="")
        {
        if (i==1) {FieldName = "\"Полное имя файла библиотеки или модуля\"";}
        if (i==2) {FieldName = "\"Назначение\"";}
        if (i==3) {FieldName = "\"Реализованные процедуры\\функции\"";}
        ShowMessage("Не заполнено поле "+ FieldName); NotEmpt = false; break;
        }
     }

 if (NotEmpt == true)
    {
    int upd_id = Form1->StringGrid1->Row; // индекс выделенной строки
    q = "Upd2;"+IntToStr(upd_id)+";";
    // for (int i=0; i<4; i++) {q = q + Form1->StringGrid1->Cells[i][upd_id]+";";}
    q = q+ Edit1->Text+";"+Edit2->Text+";"+Edit3->Text+";"+DateTimePicker1->Date+";";
    Form1->ClientSocket1->Socket->SendText(q);
    }
}




