//---------------------------------------------------------------------------
// ���������� ������ 3

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


//_________________ ������������ ������ ����� ______________________________
void __fastcall TForm7::Edit4KeyPress(TObject *Sender, char &Key)
{
 if (!(Key >= '0' && Key <= '9') && (Key!=VK_SPACE)) {Key=0;}
}


void __fastcall TForm7::Button1Click(TObject *Sender)
{
 //������������ ������ (������ - ��������)
 String q;
 bool NotEmpt = true;
 AnsiString FieldName;

 for (int i=1;i<6;i++)
     {
     if (((TEdit*)FindComponent("Edit"+String(i)))->Text=="")
        {
        if (i==1) {FieldName = "\"������� ���������\"";}
        if (i==2) {FieldName = "\"��� ���������\"";}
        if (i==3) {FieldName = "\"�������� ���������\"";}
        if (i==4) {FieldName = "\"���������� �������\"";}
        if (i==5) {FieldName = "\"����� ����� ���������\"";}
        ShowMessage("�� ��������� ���� "+ FieldName); NotEmpt = false; break;
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



