//---------------------------------------------------------------------------
// Поиск

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;


//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
        : TForm(Owner)
{
}


//__________ Фун-я поиска __________________________________________________
void __fastcall TForm4::Button1Click(TObject *Sender)
{
 if (Edit1->Text=="" && Edit2->Text=="")
    {MessageBox(NULL,"Не задано ни одиного критерия поиска!","Ошибка", MB_OK);}
 if (Edit1->Text!="" && ComboBox1->Text=="")
    {MessageBox(NULL,"Не задано имя 1го критерия поиска!","Ошибка", MB_OK);}
 if (Edit2->Text!="" && ComboBox2->Text=="")
    {MessageBox(NULL,"Не задано имя 2го критерия поиска!","Ошибка", MB_OK);}
 else
    {
    String q;       //отправляемая строка - запрос
    String f1;      //значение критерия 1
    String f2;      //значение критерия 2


    if (Form1->PageControl1->ActivePageIndex==0)
       {
       q ="Fnd1;";
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
       }

    if (Form1->PageControl1->ActivePageIndex==1)
       {
       q ="Fnd2;";
       if (ComboBox1->Text=="Полное имя файла модуля или библиотеки"){f1="MOD_OR_LIB_NAME";}
       if (ComboBox1->Text=="Назначение"){f1="DISTINATION";}
       if (ComboBox1->Text=="Список реализованных процедур"){f1="PROCEDURE_LIST";}

       if (ComboBox2->Text=="Полное имя файла модуля или библиотеки"){f2="MOD_OR_LIB_NAME";}
       if (ComboBox2->Text=="Назначение"){f2="DISTINATION";}
       if (ComboBox2->Text=="Список реализованных процедур"){f2="PROCEDURE_LIST";}
       }

    if (Form1->PageControl1->ActivePageIndex==2)
       {
       q ="Fnd3;";
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
       }


    //----------- 2 критерия ------------------------------------------------
    if (Edit1->Text!="" && ComboBox1->Text!="" && Edit2->Text!="" && ComboBox2->Text!="" )
       {
       q =q +"2;";

       if (CheckBox2->Checked==true) {q =q +"1;";}
       else {q =q +"0;";}

       //----- только слово целиком -----------------------------------------
       if (CheckBox1->Checked==true)
          {
          q =q +"1;";
          q =q + f1+";"+ f2+";"+Edit1->Text+";"+Edit2->Text+";";
          }
       //----- может включать искомое слово ---------------------------------
       if (CheckBox1->Checked==false)
          {
          q =q +"0;";
          q =q + f1+";"+ f2+";"+Edit1->Text+";"+Edit2->Text+";";
          }
       }

    //----------- если 1й критерий ------------------------------------------
    if ((Edit1->Text!="" && ComboBox1->Text!="") && (Edit2->Text=="" || ComboBox2->Text==""))
       {
       q =q +"1;";
       //----- только слово целиком -----------------------------------------
       if (CheckBox1->Checked==true)
          {
          q =q +"1;"+ f1+";"+Edit1->Text+";";
          }
       //----- может включать искомое слово ---------------------------------
       if (CheckBox1->Checked==false)
          {
          q =q +"0;"+ f1+";"+Edit1->Text+";";
          }
       }
    //----------- если 2й критерий ------------------------------------------
    if ((Edit1->Text=="" || ComboBox1->Text=="") && (Edit2->Text!="" && ComboBox2->Text!=""))
       {
       q =q +"1;";
       //----- только слово целиком -----------------------------------------
       if (CheckBox1->Checked==true)
          {q =q +"1;"+ f2+";"+Edit2->Text+";";}
       //----- может включать искомое слово ----------------------------------
       if (CheckBox1->Checked==false)
          {q =q +"0;"+ f2+";"+Edit2->Text+";";}
       }

    Form1->ClientSocket1->Socket->SendText(q);
    }
}