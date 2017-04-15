//---------------------------------------------------------------------------
// Филитрация

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

//_________________  Фун-я фильтрации ______________________________________
void __fastcall TForm5::Button1Click(TObject *Sender)
{
 if (Edit1->Text=="" && Edit2->Text=="")
    {MessageBox(NULL,"Не задано ни одиного критерия фильтрации!","Ошибка", MB_OK);}
 else
    {
    String q;      //отправляемая строка - запрос
    String AndOr;
    String f1;       //имя столбца
    String f2;       //имя столбца

    if (Form1->PageControl1->ActivePageIndex==0)
       {
       if (ComboBox1->Text=="Полное имя главного файла проекта"){f1="PROJECT_NAME";}
       if (ComboBox1->Text=="Назначение"){f1="DISTINATION";}
       if (ComboBox1->Text=="Заказчик"){f1="CUSTOMER_ID";}
       if (ComboBox1->Text=="Степень завершенности"){f1="COMPLETENESS";}
       if (ComboBox1->Text=="Используемые модули и библиотеки"){f1="MOD_AND_LIB_ID_LIST";}

       if (ComboBox2->Text=="Полное имя главного файла проекта"){f2="PROJECT_NAME";}
       if (ComboBox2->Text=="Назначение"){f2="DISTINATION";}
       if (ComboBox2->Text=="Заказчик"){f2="CUSTOMER_ID";}
       if (ComboBox2->Text=="Степень завершенности"){f2="COMPLETENESS";}
       if (ComboBox2->Text=="Используемые модули и библиотеки"){f2="MOD_AND_LIB_ID_LIST";}

       q = "Fen1;SELECT * FROM PROJECTS ";

       //----------- 2 критерия ----------------------------------------------
       if (Edit1->Text!="" && ComboBox1->Text!="" && Edit2->Text!="" && ComboBox2->Text!="" )
          {
          if (RadioButton1->Checked==true) {AndOr = " AND ";}
          if (RadioButton2->Checked==true) {AndOr = " OR ";}
          q = q + "WHERE "+f1+" LIKE '"+Edit1->Text+"%'"+AndOr+f2+" LIKE '"+Edit2->Text+"%'";
          }
       //----------- если 1й критерий -----------------------------------------
       if ((Edit1->Text!="" && ComboBox1->Text!="") && (Edit2->Text=="" || ComboBox2->Text==""))
          {q = q + "WHERE "+f1+" LIKE '"+Trim(Edit1->Text)+"%'";}
       //----------- если 2й критерий ----------------------------------
       if ((Edit1->Text=="" || ComboBox1->Text=="") && (Edit2->Text!="" && ComboBox2->Text!=""))
          {q = q + "WHERE "+f2+" LIKE '"+Trim(Edit2->Text)+"%'";}
       //----------- выполнение --------------------------------------------
       Form1->ClientSocket1->Socket->SendText(q);
       }

//__________________________________________________________________________
    if (Form1->PageControl1->ActivePageIndex==1)
       {
       if (ComboBox1->Text=="Полное имя файла модуля или библиотеки"){f1="MOD_OR_LIB_NAME";}
       if (ComboBox1->Text=="Назначение"){f1="DISTINATION";}
       if (ComboBox1->Text=="Список реализованных процедур"){f1="PROCEDURE_LIST";}

       if (ComboBox2->Text=="Полное имя файла модуля или библиотеки"){f2="MOD_OR_LIB_NAME";}
       if (ComboBox2->Text=="Назначение"){f2="DISTINATION";}
       if (ComboBox2->Text=="Список реализованных процедур"){f2="PROCEDURE_LIST";}

       q = "Fen2;SELECT * FROM MODULES_AND_LIBRARIES ";

       //----------- 2 критерия ----------------------------------------------
       if (Edit1->Text!="" && ComboBox1->Text!="" && Edit2->Text!="" && ComboBox2->Text!="" )
          {
          if (RadioButton1->Checked==true) {AndOr = " AND ";}
          if (RadioButton2->Checked==true) {AndOr = " OR ";}
          q = q + "WHERE "+f1+" LIKE '"+Edit1->Text+"%'"+AndOr+f2+" LIKE '"+Edit2->Text+"%'";
          }
       //----------- если 1й критерий -----------------------------------------
       if ((Edit1->Text!="" && ComboBox1->Text!="") && (Edit2->Text=="" || ComboBox2->Text==""))
          {q = q + "WHERE "+f1+" LIKE '"+Edit1->Text+"%'";}
       //----------- если 2й критерий ----------------------------------
       if ((Edit1->Text=="" || ComboBox1->Text=="") && (Edit2->Text!="" && ComboBox2->Text!=""))
          {q = q + "WHERE "+f2+" LIKE '"+Edit2->Text+"%'";}
       //----------- выполнение --------------------------------------------
       Form1->ClientSocket1->Socket->SendText(q);
       }

//__________________________________________________________________________
    if (Form1->PageControl1->ActivePageIndex==2)
       {
       if (ComboBox1->Text=="Фамилия"){f1="SURNAME";}
       if (ComboBox1->Text=="Имя"){f1="NAME";}
       if (ComboBox1->Text=="Отчество"){f1="PATRONUMIC";}
       if (ComboBox1->Text=="Контактный телефон"){f1="TELEPHONE";}
       if (ComboBox1->Text=="Адрес фирмы"){f1="ADDRESS";}

       if (ComboBox2->Text=="Фамилия"){f2="SURNAME";}
       if (ComboBox2->Text=="Имя"){f2="NAME";}
       if (ComboBox2->Text=="Отчество"){f2="PATRONUMIC";}
       if (ComboBox2->Text=="Контактный телефон"){f2="TELEPHONE";}
       if (ComboBox2->Text=="Адрес фирмы"){f2="ADDRESS";}

       q = "Fen3;SELECT * FROM CUSTOMERS " ;

       //----------- 2 критерия ----------------------------------------------
       if (Edit1->Text!="" && ComboBox1->Text!="" && Edit2->Text!="" && ComboBox2->Text!="" )
          {
          if (RadioButton1->Checked==true) {AndOr = " AND ";}
          if (RadioButton2->Checked==true) {AndOr = " OR ";}
          q = q + "WHERE "+f1+" LIKE '"+Edit1->Text+"%'"+AndOr+f2+" LIKE '"+Edit2->Text+"%'";
          }
       //----------- если 1й критерий -----------------------------------------
       if ((Edit1->Text!="" && ComboBox1->Text!="") && (Edit2->Text=="" || ComboBox2->Text==""))
          {q = q + "WHERE "+f1+" LIKE '"+Edit1->Text+"%'";}
       //----------- если 2й критерий ----------------------------------
       if ((Edit1->Text=="" || ComboBox1->Text=="") && (Edit2->Text!="" && ComboBox2->Text!=""))
          {q = q + "WHERE "+f2+" LIKE '"+Edit2->Text+"%'";}
       //----------- выполнение --------------------------------------------
       Form1->ClientSocket1->Socket->SendText(q);
       }
    Edit1->Text="";
    Edit2->Text="";
    }
}


//_________________ Фун-я отмены филитрации ________________________________
void __fastcall TForm5::Button2Click(TObject *Sender)
{
 if (Form1->PageControl1->ActivePageIndex==0)
    {
    // запрос на выборку всех данных у сервера
    String r = "AlS1";
    Form1->ClientSocket1->Socket->SendText(r);
    }
 if (Form1->PageControl1->ActivePageIndex==1)
    {
    String r = "AlS2";
    Form1->ClientSocket1->Socket->SendText(r);
    }
 if (Form1->PageControl1->ActivePageIndex==2)
    {
    String r = "AlS3";
    Form1->ClientSocket1->Socket->SendText(r);
    }
}



