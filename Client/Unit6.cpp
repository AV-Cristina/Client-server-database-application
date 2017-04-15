//---------------------------------------------------------------------------
// Добавление строки в таблицу 2 (Модули и библиотеки)

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit6.h"
#include "Unit14.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm6::Button1Click(TObject *Sender)
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
    q = "Add2;"+ Edit1->Text+";"+Edit2->Text+";"+Edit3->Text+";"+DateTimePicker1->Date+";";
    Form1->ClientSocket1->Socket->SendText(q);

    Form14->ComboBox1->Items->Add(Edit1->Text); // добавление в список доступных модулей

    Edit1->Text = "";
    Edit2->Text = "";
    Edit3->Text = "";
    }
}
