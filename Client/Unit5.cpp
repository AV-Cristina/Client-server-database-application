//---------------------------------------------------------------------------
// ����������

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

//_________________  ���-� ���������� ______________________________________
void __fastcall TForm5::Button1Click(TObject *Sender)
{
 if (Edit1->Text=="" && Edit2->Text=="")
    {MessageBox(NULL,"�� ������ �� ������� �������� ����������!","������", MB_OK);}
 else
    {
    String q;      //������������ ������ - ������
    String AndOr;
    String f1;       //��� �������
    String f2;       //��� �������

    if (Form1->PageControl1->ActivePageIndex==0)
       {
       if (ComboBox1->Text=="������ ��� �������� ����� �������"){f1="PROJECT_NAME";}
       if (ComboBox1->Text=="����������"){f1="DISTINATION";}
       if (ComboBox1->Text=="��������"){f1="CUSTOMER_ID";}
       if (ComboBox1->Text=="������� �������������"){f1="COMPLETENESS";}
       if (ComboBox1->Text=="������������ ������ � ����������"){f1="MOD_AND_LIB_ID_LIST";}

       if (ComboBox2->Text=="������ ��� �������� ����� �������"){f2="PROJECT_NAME";}
       if (ComboBox2->Text=="����������"){f2="DISTINATION";}
       if (ComboBox2->Text=="��������"){f2="CUSTOMER_ID";}
       if (ComboBox2->Text=="������� �������������"){f2="COMPLETENESS";}
       if (ComboBox2->Text=="������������ ������ � ����������"){f2="MOD_AND_LIB_ID_LIST";}

       q = "Fen1;SELECT * FROM PROJECTS ";

       //----------- 2 �������� ----------------------------------------------
       if (Edit1->Text!="" && ComboBox1->Text!="" && Edit2->Text!="" && ComboBox2->Text!="" )
          {
          if (RadioButton1->Checked==true) {AndOr = " AND ";}
          if (RadioButton2->Checked==true) {AndOr = " OR ";}
          q = q + "WHERE "+f1+" LIKE '"+Edit1->Text+"%'"+AndOr+f2+" LIKE '"+Edit2->Text+"%'";
          }
       //----------- ���� 1� �������� -----------------------------------------
       if ((Edit1->Text!="" && ComboBox1->Text!="") && (Edit2->Text=="" || ComboBox2->Text==""))
          {q = q + "WHERE "+f1+" LIKE '"+Trim(Edit1->Text)+"%'";}
       //----------- ���� 2� �������� ----------------------------------
       if ((Edit1->Text=="" || ComboBox1->Text=="") && (Edit2->Text!="" && ComboBox2->Text!=""))
          {q = q + "WHERE "+f2+" LIKE '"+Trim(Edit2->Text)+"%'";}
       //----------- ���������� --------------------------------------------
       Form1->ClientSocket1->Socket->SendText(q);
       }

//__________________________________________________________________________
    if (Form1->PageControl1->ActivePageIndex==1)
       {
       if (ComboBox1->Text=="������ ��� ����� ������ ��� ����������"){f1="MOD_OR_LIB_NAME";}
       if (ComboBox1->Text=="����������"){f1="DISTINATION";}
       if (ComboBox1->Text=="������ ������������� ��������"){f1="PROCEDURE_LIST";}

       if (ComboBox2->Text=="������ ��� ����� ������ ��� ����������"){f2="MOD_OR_LIB_NAME";}
       if (ComboBox2->Text=="����������"){f2="DISTINATION";}
       if (ComboBox2->Text=="������ ������������� ��������"){f2="PROCEDURE_LIST";}

       q = "Fen2;SELECT * FROM MODULES_AND_LIBRARIES ";

       //----------- 2 �������� ----------------------------------------------
       if (Edit1->Text!="" && ComboBox1->Text!="" && Edit2->Text!="" && ComboBox2->Text!="" )
          {
          if (RadioButton1->Checked==true) {AndOr = " AND ";}
          if (RadioButton2->Checked==true) {AndOr = " OR ";}
          q = q + "WHERE "+f1+" LIKE '"+Edit1->Text+"%'"+AndOr+f2+" LIKE '"+Edit2->Text+"%'";
          }
       //----------- ���� 1� �������� -----------------------------------------
       if ((Edit1->Text!="" && ComboBox1->Text!="") && (Edit2->Text=="" || ComboBox2->Text==""))
          {q = q + "WHERE "+f1+" LIKE '"+Edit1->Text+"%'";}
       //----------- ���� 2� �������� ----------------------------------
       if ((Edit1->Text=="" || ComboBox1->Text=="") && (Edit2->Text!="" && ComboBox2->Text!=""))
          {q = q + "WHERE "+f2+" LIKE '"+Edit2->Text+"%'";}
       //----------- ���������� --------------------------------------------
       Form1->ClientSocket1->Socket->SendText(q);
       }

//__________________________________________________________________________
    if (Form1->PageControl1->ActivePageIndex==2)
       {
       if (ComboBox1->Text=="�������"){f1="SURNAME";}
       if (ComboBox1->Text=="���"){f1="NAME";}
       if (ComboBox1->Text=="��������"){f1="PATRONUMIC";}
       if (ComboBox1->Text=="���������� �������"){f1="TELEPHONE";}
       if (ComboBox1->Text=="����� �����"){f1="ADDRESS";}

       if (ComboBox2->Text=="�������"){f2="SURNAME";}
       if (ComboBox2->Text=="���"){f2="NAME";}
       if (ComboBox2->Text=="��������"){f2="PATRONUMIC";}
       if (ComboBox2->Text=="���������� �������"){f2="TELEPHONE";}
       if (ComboBox2->Text=="����� �����"){f2="ADDRESS";}

       q = "Fen3;SELECT * FROM CUSTOMERS " ;

       //----------- 2 �������� ----------------------------------------------
       if (Edit1->Text!="" && ComboBox1->Text!="" && Edit2->Text!="" && ComboBox2->Text!="" )
          {
          if (RadioButton1->Checked==true) {AndOr = " AND ";}
          if (RadioButton2->Checked==true) {AndOr = " OR ";}
          q = q + "WHERE "+f1+" LIKE '"+Edit1->Text+"%'"+AndOr+f2+" LIKE '"+Edit2->Text+"%'";
          }
       //----------- ���� 1� �������� -----------------------------------------
       if ((Edit1->Text!="" && ComboBox1->Text!="") && (Edit2->Text=="" || ComboBox2->Text==""))
          {q = q + "WHERE "+f1+" LIKE '"+Edit1->Text+"%'";}
       //----------- ���� 2� �������� ----------------------------------
       if ((Edit1->Text=="" || ComboBox1->Text=="") && (Edit2->Text!="" && ComboBox2->Text!=""))
          {q = q + "WHERE "+f2+" LIKE '"+Edit2->Text+"%'";}
       //----------- ���������� --------------------------------------------
       Form1->ClientSocket1->Socket->SendText(q);
       }
    Edit1->Text="";
    Edit2->Text="";
    }
}


//_________________ ���-� ������ ���������� ________________________________
void __fastcall TForm5::Button2Click(TObject *Sender)
{
 if (Form1->PageControl1->ActivePageIndex==0)
    {
    // ������ �� ������� ���� ������ � �������
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



