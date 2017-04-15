//---------------------------------------------------------------------------
//Редактирование записей таблицы 1

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit9.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm9 *Form9;
//---------------------------------------------------------------------------
__fastcall TForm9::TForm9(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm9::FormCreate(TObject *Sender)
{
//
}


//_________________ Редактирование строк ___________________________________
void __fastcall TForm9::Button1Click(TObject *Sender)
{
 //отправляемая строка (запрос - добавить)
 String q;
 //проверка на заполненость всех полей
 bool NotEmpt = true;
 AnsiString FieldName;

 for (int i=1;i<6;i++)
     {
     if (((TEdit*)FindComponent("Edit"+String(i)))->Text=="")
        {
        if (i==1) {FieldName = "\"Полное имя главного файла проекта\"";}
        if (i==2) {FieldName = "\"Назначение\"";}
        if (i==3) {FieldName = "\"Номер заказчика\"";}
        if (i==4) {FieldName = "\"Степень завершености проекта\"";}
        if (i==5) {FieldName = "\"Используемые модули и библиотеки\"";}
        ShowMessage("Не заполнено поле "+ FieldName);
        NotEmpt = false; break;
        }
     }

 if (NotEmpt == true)
    {
    int upd_id = Form1->StringGrid1->Row; // индекс выделенной строки
    q = "Upd1;"+IntToStr(upd_id)+";";
    q = q + Edit1->Text+";"+DateTimePicker1->Date+";"+DateTimePicker2->Date+";"+Edit2->Text+";"+Edit3->Text+";"+Edit4->Text+";"+Edit5->Text+";";
    Form1->ClientSocket1->Socket->SendText(q);
    Form9->Close();
    }
}
