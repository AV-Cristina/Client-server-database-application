//---------------------------------------------------------------------------
// Добавление строки в таблицу 3 (Заказчики)

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit7.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm7 *Form7;
//---------------------------------------------------------------------------
__fastcall TForm7::TForm7(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


//_________________ Воспринимаем только цифры ______________________________
void __fastcall TForm7::Edit4KeyPress(TObject *Sender, char &Key)
{
 if (!(Key >= '0' && Key <= '9') && (Key!=VK_SPACE)) {Key=0;}
}


void __fastcall TForm7::Button1Click(TObject *Sender)
{
 //отправляемая строка (запрос - добавить)
 String q;
 bool NotEmpt = true;
 AnsiString FieldName;

 for (int i=1;i<6;i++)
     {
     if (((TEdit*)FindComponent("Edit"+String(i)))->Text=="")
        {
        if (i==1) {FieldName = "\"Фамилия заказчика\"";}
        if (i==2) {FieldName = "\"Имя заказчика\"";}
        if (i==3) {FieldName = "\"Отчество заказчика\"";}
        if (i==4) {FieldName = "\"Контактный телефон\"";}
        if (i==5) {FieldName = "\"Адрес фирмы заказчика\"";}
        ShowMessage("Не заполнено поле "+ FieldName); NotEmpt = false; break;
        }
     }

 if (NotEmpt == true)
    {
     q = "Add3;"+ Edit1->Text+";"+Edit2->Text+";"+Edit3->Text+";"+Edit4->Text+";"+Edit5->Text+";";
     Form1->ClientSocket1->Socket->SendText(q);
     Edit1->Text = "";
     Edit2->Text = "";
     Edit3->Text = "";
     Edit4->Text = "";
     Edit5->Text = "";
    }
}
