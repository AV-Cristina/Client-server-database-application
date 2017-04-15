//---------------------------------------------------------------------------
//Сортировка

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender)
{
 //имя столбца
 String f;

 if (ComboBox1->Text=="Полное имя главного файла проекта"){f="PROJECT_NAME";}
 if (ComboBox1->Text=="Дата начала работы над проектом"){f="DATE_BEG";}
 if (ComboBox1->Text=="Дата окончания работы над проектом"){f="DATE_END";}
 if (ComboBox1->Text=="Назначение"){f="DISTINATION";}
 if (ComboBox1->Text=="Заказчик"){f="CUSTOMER_ID";}
 if (ComboBox1->Text=="Степень завершенности"){f="COMPLETENESS";}
 if (ComboBox1->Text=="Используемые модули и библиотеки"){f="MOD_AND_LIB_ID_LIST";}

 if (ComboBox1->Text=="Полное имя файла модуля или библиотеки"){f="MOD_OR_LIB_NAME";}
 if (ComboBox1->Text=="Назначение"){f="DISTINATION";}
 if (ComboBox1->Text=="Список реализованных процедур"){f="PROCEDURE_LIST";}
 if (ComboBox1->Text=="Дата создания"){f="DATE_CREATE";}

 if (ComboBox1->Text=="Фамилия"){f="SURNAME";}
 if (ComboBox1->Text=="Имя"){f="NAME";}
 if (ComboBox1->Text=="Отчество"){f="PATRONUMIC";}
 if (ComboBox1->Text=="Контактный телефон"){f="TELEPHONE";}
 if (ComboBox1->Text=="Адрес фирмы"){f="ADDRESS";}

//отправляемая строка (запрос - сортировать)
 String q;

//сортировка - по убыванию DESC, по возрастанию ASC
 String direct = ComboBox2->ItemIndex == 1 ? "DESC" : "ASC";

 if (Form1->PageControl1->ActivePageIndex==0)
    {
    q = "Srt1;SELECT * FROM PROJECTS ORDER BY "+ f + " " + direct;
    }

 if (Form1->PageControl1->ActivePageIndex==1)
    {
    q = "Srt2;SELECT * FROM MODULES_AND_LIBRARIES ORDER BY " + f + " " + direct;
    }

 if (Form1->PageControl1->ActivePageIndex==2)
    {
    q = "Srt3;SELECT * FROM CUSTOMERS ORDER BY " + f + " " + direct;
    }

  Form1->ClientSocket1->Socket->SendText(q);
}


