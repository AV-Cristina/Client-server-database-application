//---------------------------------------------------------------------------
// �����

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


//__________ ���-� ������ __________________________________________________
void __fastcall TForm4::Button1Click(TObject *Sender)
{
 if (Edit1->Text=="" && Edit2->Text=="")
    {MessageBox(NULL,"�� ������ �� ������� �������� ������!","������", MB_OK);}
 if (Edit1->Text!="" && ComboBox1->Text=="")
    {MessageBox(NULL,"�� ������ ��� 1�� �������� ������!","������", MB_OK);}
 if (Edit2->Text!="" && ComboBox2->Text=="")
    {MessageBox(NULL,"�� ������ ��� 2�� �������� ������!","������", MB_OK);}
 else
    {
    String q;       //������������ ������ - ������
    String f1;      //�������� �������� 1
    String f2;      //�������� �������� 2


    if (Form1->PageControl1->ActivePageIndex==0)
       {
       q ="Fnd1;";
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
       }

    if (Form1->PageControl1->ActivePageIndex==1)
       {
       q ="Fnd2;";
       if (ComboBox1->Text=="������ ��� ����� ������ ��� ����������"){f1="MOD_OR_LIB_NAME";}
       if (ComboBox1->Text=="����������"){f1="DISTINATION";}
       if (ComboBox1->Text=="������ ������������� ��������"){f1="PROCEDURE_LIST";}

       if (ComboBox2->Text=="������ ��� ����� ������ ��� ����������"){f2="MOD_OR_LIB_NAME";}
       if (ComboBox2->Text=="����������"){f2="DISTINATION";}
       if (ComboBox2->Text=="������ ������������� ��������"){f2="PROCEDURE_LIST";}
       }

    if (Form1->PageControl1->ActivePageIndex==2)
       {
       q ="Fnd3;";
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
       }


    //----------- 2 �������� ------------------------------------------------
    if (Edit1->Text!="" && ComboBox1->Text!="" && Edit2->Text!="" && ComboBox2->Text!="" )
       {
       q =q +"2;";

       if (CheckBox2->Checked==true) {q =q +"1;";}
       else {q =q +"0;";}

       //----- ������ ����� ������� -----------------------------------------
       if (CheckBox1->Checked==true)
          {
          q =q +"1;";
          q =q + f1+";"+ f2+";"+Edit1->Text+";"+Edit2->Text+";";
          }
       //----- ����� �������� ������� ����� ---------------------------------
       if (CheckBox1->Checked==false)
          {
          q =q +"0;";
          q =q + f1+";"+ f2+";"+Edit1->Text+";"+Edit2->Text+";";
          }
       }

    //----------- ���� 1� �������� ------------------------------------------
    if ((Edit1->Text!="" && ComboBox1->Text!="") && (Edit2->Text=="" || ComboBox2->Text==""))
       {
       q =q +"1;";
       //----- ������ ����� ������� -----------------------------------------
       if (CheckBox1->Checked==true)
          {
          q =q +"1;"+ f1+";"+Edit1->Text+";";
          }
       //----- ����� �������� ������� ����� ---------------------------------
       if (CheckBox1->Checked==false)
          {
          q =q +"0;"+ f1+";"+Edit1->Text+";";
          }
       }
    //----------- ���� 2� �������� ------------------------------------------
    if ((Edit1->Text=="" || ComboBox1->Text=="") && (Edit2->Text!="" && ComboBox2->Text!=""))
       {
       q =q +"1;";
       //----- ������ ����� ������� -----------------------------------------
       if (CheckBox1->Checked==true)
          {q =q +"1;"+ f2+";"+Edit2->Text+";";}
       //----- ����� �������� ������� ����� ----------------------------------
       if (CheckBox1->Checked==false)
          {q =q +"0;"+ f2+";"+Edit2->Text+";";}
       }

    Form1->ClientSocket1->Socket->SendText(q);
    }
}

