//---------------------------------------------------------------------------
//�������������� ������� ������� 3

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit11.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm11 *Form11;
//---------------------------------------------------------------------------
__fastcall TForm11::TForm11(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm11::Button1Click(TObject *Sender)
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
    int upd_id = Form1->StringGrid1->Row; // ������ ���������� ������
    q = "Upd3;"+IntToStr(upd_id)+";";
    q = q+ Edit1->Text+";"+Edit2->Text+";"+Edit3->Text+";"+Edit4->Text+";"+Edit5->Text+";";
    Form1->ClientSocket1->Socket->SendText(q);
    Form11->Close();
    }
}



