//---------------------------------------------------------------------------
// ���������� ������ 1

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit3.h"
#include "Unit14.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "ToolEdit"
#pragma link "ToolEdit"
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


//___________ ������������ ������ ����� ____________________________________
void __fastcall TForm3::Edit3KeyPress(TObject *Sender, char &Key)
{
 if (!(Key >= '0' && Key <= '9') && (Key!=VK_SPACE)) {Key=0;}
}


void __fastcall TForm3::Button1Click(TObject *Sender)
{
 //������������ ������ (������ - ��������)
 String q;
 bool NotEmpt = true;
 AnsiString FieldName;

 for (int i=1;i<6;i++)
     {
     if (((TEdit*)FindComponent("Edit"+String(i)))->Text=="")
        {
        if (i==1) {FieldName = "\"������ ��� �������� ����� �������\"";}
        if (i==2) {FieldName = "\"����������\"";}
        if (i==3) {FieldName = "\"����� ���������\"";}
        if (i==4) {FieldName = "\"������� ������������ �������\"";}
        if (i==5) {FieldName = "\"������������ ������ � ����������\"";}
        ShowMessage("�� ��������� ���� "+ FieldName); NotEmpt = false; break;
        }
     }

 if (NotEmpt == true)
    {
    q = "Add1;"+ Edit1->Text+";"+DateTimePicker1->Date+";"+DateTimePicker2->Date+";"+Edit2->Text+";"+Edit3->Text+";"+Edit4->Text+";"+Edit5->Text+";";
    Form1->ClientSocket1->Socket->SendText(q);
    //---------- ������� ����� ����� ���������� ������ -------------------------
    Edit1->Text = "";
    Edit2->Text = "";
    Edit3->Text = "";
    Edit4->Text = "";
    Edit5->Text = "";
    }
}


//___________ ���������� ������� � ���������� ______________________________
void __fastcall TForm3::Button2Click(TObject *Sender)
{
 int i=0;   //�������, � ������� ��� ������
 for (int j=1; j<=Form1->StringGrid2->RowCount; j++)
     {
     Form14->ComboBox1->Items->Add(Form1->StringGrid2->Cells[i][j]);
     }
 Form14->ShowModal();
}

