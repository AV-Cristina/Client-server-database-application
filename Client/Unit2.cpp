//---------------------------------------------------------------------------
//����������

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
 //��� �������
 String f;

 if (ComboBox1->Text=="������ ��� �������� ����� �������"){f="PROJECT_NAME";}
 if (ComboBox1->Text=="���� ������ ������ ��� ��������"){f="DATE_BEG";}
 if (ComboBox1->Text=="���� ��������� ������ ��� ��������"){f="DATE_END";}
 if (ComboBox1->Text=="����������"){f="DISTINATION";}
 if (ComboBox1->Text=="��������"){f="CUSTOMER_ID";}
 if (ComboBox1->Text=="������� �������������"){f="COMPLETENESS";}
 if (ComboBox1->Text=="������������ ������ � ����������"){f="MOD_AND_LIB_ID_LIST";}

 if (ComboBox1->Text=="������ ��� ����� ������ ��� ����������"){f="MOD_OR_LIB_NAME";}
 if (ComboBox1->Text=="����������"){f="DISTINATION";}
 if (ComboBox1->Text=="������ ������������� ��������"){f="PROCEDURE_LIST";}
 if (ComboBox1->Text=="���� ��������"){f="DATE_CREATE";}

 if (ComboBox1->Text=="�������"){f="SURNAME";}
 if (ComboBox1->Text=="���"){f="NAME";}
 if (ComboBox1->Text=="��������"){f="PATRONUMIC";}
 if (ComboBox1->Text=="���������� �������"){f="TELEPHONE";}
 if (ComboBox1->Text=="����� �����"){f="ADDRESS";}

//������������ ������ (������ - �����������)
 String q;

//���������� - �� �������� DESC, �� ����������� ASC
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


