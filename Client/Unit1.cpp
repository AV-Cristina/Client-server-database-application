//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
#include "Unit5.h"
#include "Unit6.h"
#include "Unit7.h"
#include "Unit8.h"
#include "Unit9.h"
#include "Unit10.h"
#include "Unit11.h"
#include "Unit13.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"


TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


//_________________ ����������� ������� ____________________________________
void __fastcall TForm1::FormCreate(TObject *Sender)
{
 if (ClientSocket1->Active==true){ClientSocket1->Close();}
 ClientSocket1->Host = "localhost";
 ClientSocket1->Port = 2000;
 ClientSocket1->Open();
}


//_________________ ����� ����������� ������� ______________________________
void __fastcall TForm1::ClientSocket1Connect(TObject *Sender,TCustomWinSocket *Socket)
{
 ShowMessage("Connected");
 // ������� ���� �������� �����
 Connect();
 // ������ ���� ������ � �������
 String c = "All0";
 ClientSocket1->Socket->SendText(c);
}


//_________________ ��������� � ��������� ������ �� ������� ________________
void __fastcall TForm1::ClientSocket1Read(TObject *Sender,
      TCustomWinSocket *Socket)
{
 //���������� ���������� ������
 String s = Socket->ReceiveText();

 //���������� ���������� �������
 String c = s.SubString(1,3);
 int i, j;

 //������������ ������ (������ ��.������ �� ����. �������)
 String r;

 //���� �������� ������  �� 1� ������� �� (����������� ���������)
 if (c == "#A1")
    {
    s.Delete(1,3);
    i=0;                           //�������
    j = StringGrid1->RowCount-1;   //������
    while (s.Pos(';')!=0)
        {
        StringGrid1->Cells[i][j]= s.SubString(1, s.Pos(';')-1);
        s.Delete(1, s.Pos(';'));
        i++;
        }
    StringGrid1->RowCount++;
    r = "All1";
    ClientSocket1->Socket->SendText(r);
    }

 //���� �������� ������ �� 2� ������� ��
 if (c == "#A2")
    {
    s.Delete(1,3);
    i=0;
    j = StringGrid2->RowCount-1;
    while (s.Pos(';')!=0)
        {
        StringGrid2->Cells[i][j]= s.SubString(1, s.Pos(';')-1);
        s.Delete(1, s.Pos(';'));
        i++;
        }
    StringGrid2->RowCount++;
    r = "All2";
    ClientSocket1->Socket->SendText(r);
    }

 //���� �������� ������ �� 3� ������� ��
 if (c == "#A3")
    {
    s.Delete(1,3);
    i=0;
    j = StringGrid3->RowCount-1;
    while (s.Pos(';')!=0)
        {
        StringGrid3->Cells[i][j]= s.SubString(1, s.Pos(';')-1);
        s.Delete(1, s.Pos(';'));
        i++;
        }
    StringGrid3->RowCount++;
    r = "All3";
    ClientSocket1->Socket->SendText(r);
    }

//_________________ ���������� ������ ����� ���������� �������� ____________
 //���� �������� ������������� ���������� �������
 //��� ���������� ������
 //��� �������� � � �
 //����� ��������� � ����������������
 if (c == "upd")
    {
    for (int l=1; l<=StringGrid1->RowCount; l++)
        {for (int k=0; k<=7; k++) {StringGrid1->Cells[k][l]="";}}
    for (int l=1; l<=StringGrid2->RowCount; l++)
        {for (int k=0; k<=4; k++) {StringGrid2->Cells[k][l]="";}}
    for (int l=1; l<=StringGrid3->RowCount; l++)
        {for (int k=0; k<=5; k++) {StringGrid3->Cells[k][l]="";}}
    StringGrid1->RowCount=2;
    StringGrid2->RowCount=2;
    StringGrid3->RowCount=2;
    // ������ ���� ������ � �������
    r = "All0";
    ClientSocket1->Socket->SendText(r);
    }

//_________________ ��������� ���������� ������ ____________________________
//���� ����� �� ��� �����������
 if (c == "000")
    {
    Form4->StringGrid1->Visible=false;
    MessageBox(NULL,"����� �� ��� �����������","�����", MB_OK);
    }

//���� �������� ������ ������ ���������� ������
 if (c=="#I1" || c=="#I2" || c=="#I3")
    {
    Form4->StringGrid1->Visible=true;
    //������� �����
    for (int l=1; l<=Form4->StringGrid1->RowCount; l++)
        {for (int k=0; k<=7; k++) {Form4->StringGrid1->Cells[k][l]="";}}
    Form4->StringGrid1->RowCount=2;
    if (c=="#I1")
       {
       Form4->StringGrid1->Cells[0][0]="������ ��� �������� ����� �������";
       Form4->StringGrid1->Cells[1][0]="���� ������ ������ ��� ��������";
       Form4->StringGrid1->Cells[2][0]="���� ��������� ������ ��� ��������";
       Form4->StringGrid1->Cells[3][0]="����������";
       Form4->StringGrid1->Cells[4][0]="��������";
       Form4->StringGrid1->Cells[5][0]="������� �������������";
       Form4->StringGrid1->Cells[6][0]="������������ ������ � ����������";
       }
    if (c=="#I2")
       {
       Form4->StringGrid1->Cells[0][0]="������ ��� ����� ������ ��� ����������";
       Form4->StringGrid1->Cells[1][0]="����������";
       Form4->StringGrid1->Cells[2][0]="������ ������������� ��������";
       Form4->StringGrid1->Cells[3][0]="���� ��������";
       }
    if (c=="#I3")
       {
       Form4->StringGrid1->Cells[0][0]="�������";
       Form4->StringGrid1->Cells[1][0]="���";
       Form4->StringGrid1->Cells[2][0]="��������";
       Form4->StringGrid1->Cells[3][0]="���������� �������";
       Form4->StringGrid1->Cells[4][0]="����� �����";
       }
    s.Delete(1,3);
    i=0;
    j = Form4->StringGrid1->RowCount-1;
    while (s.Pos(';')!=0)
        {
        Form4->StringGrid1->Cells[i][j]= s.SubString(1, s.Pos(';')-1);
        s.Delete(1, s.Pos(';'));
        i++;
        }
    Form4->StringGrid1->RowCount++;
    r = "Inp";
    ClientSocket1->Socket->SendText(r);
 }


//���� �������� ������ ���������� ������
 if (c == "Inp")
    {
    s.Delete(1,3);
    i=0;
    j = Form4->StringGrid1->RowCount-1;
    while (s.Pos(';')!=0)
        {
        Form4->StringGrid1->Cells[i][j]= s.SubString(1, s.Pos(';')-1);
        s.Delete(1, s.Pos(';'));
        i++;
        }
    Form4->StringGrid1->RowCount++;
    r = "Inp";
    ClientSocket1->Socket->SendText(r);
    }
    
}
//---------------------------------------------------------------------------



void TForm1::CaptionTable1()
{
 StringGrid1->Cells[0][0]="������ ��� �������� ����� �������";
 StringGrid1->Cells[1][0]="���� ������ ������ ��� ��������";
 StringGrid1->Cells[2][0]="���� ��������� ������ ��� ��������";
 StringGrid1->Cells[3][0]="����������";
 StringGrid1->Cells[4][0]="��������";
 StringGrid1->Cells[5][0]="������� �������������";
 StringGrid1->Cells[6][0]="������������ ������ � ����������";
}


void TForm1::CaptionTable2()
{
 StringGrid2->Cells[0][0]="������ ��� ����� ������ ��� ����������";
 StringGrid2->Cells[1][0]="����������";
 StringGrid2->Cells[2][0]="������ ������������� ��������";
 StringGrid2->Cells[3][0]="���� ��������";
}


void TForm1::CaptionTable3()
{
 StringGrid3->Cells[0][0]="�������";
 StringGrid3->Cells[1][0]="���";
 StringGrid3->Cells[2][0]="��������";
 StringGrid3->Cells[3][0]="���������� �������";
 StringGrid3->Cells[4][0]="����� �����";
}


void TForm1::Connect()
{
 CaptionTable1();
 CaptionTable2();
 CaptionTable3();
}


//_________________ ���������� _____________________________________________
void __fastcall TForm1::N8Click(TObject *Sender)
{
//� ����������� �� ������� �������� �������
//����������� ���������� ������ ����� �������
 Form2->ComboBox1->Clear();
 if (PageControl1->ActivePageIndex==0)
    {
    Form2->ComboBox1->Items->Add("������ ��� �������� ����� �������");
    Form2->ComboBox1->Items->Add("���� ������ ������ ��� ��������");
    Form2->ComboBox1->Items->Add("���� ��������� ������ ��� ��������");
    Form2->ComboBox1->Items->Add("����������");
    Form2->ComboBox1->Items->Add("��������");
    Form2->ComboBox1->Items->Add("������� �������������");
    Form2->ComboBox1->Items->Add("������������ ������ � ����������");
    }
 if (PageControl1->ActivePageIndex==1)
    {
    Form2->ComboBox1->Items->Add("������ ��� ����� ������ ��� ����������");
    Form2->ComboBox1->Items->Add("����������");
    Form2->ComboBox1->Items->Add("������ ������������� ��������");
    Form2->ComboBox1->Items->Add("���� ��������");
    }
 if (PageControl1->ActivePageIndex==2)   
    {
    Form2->ComboBox1->Items->Add("�������");
    Form2->ComboBox1->Items->Add("���");
    Form2->ComboBox1->Items->Add("��������");
    Form2->ComboBox1->Items->Add("���������� �������");
    Form2->ComboBox1->Items->Add("����� �����");
    }
 Form2->ShowModal();
}


//_________________ ������ _________________________________________________
void __fastcall TForm1::N9Click(TObject *Sender)
{
 Form5->ComboBox1->Items->Clear();
 Form5->ComboBox2->Items->Clear();
 if (PageControl1->ActivePageIndex==0)
    {
    Form5->ComboBox1->Items->Add("������ ��� �������� ����� �������");
    Form5->ComboBox1->Items->Add("����������");
    Form5->ComboBox1->Items->Add("��������");
    Form5->ComboBox1->Items->Add("������� �������������");
    Form5->ComboBox1->Items->Add("������������ ������ � ����������");
    Form5->ComboBox2->Items->Add("������ ��� �������� ����� �������");
    Form5->ComboBox2->Items->Add("����������");
    Form5->ComboBox2->Items->Add("��������");
    Form5->ComboBox2->Items->Add("������� �������������");
    Form5->ComboBox2->Items->Add("������������ ������ � ����������");
    }
 if (PageControl1->ActivePageIndex==1)
    {
    Form5->ComboBox1->Items->Add("������ ��� ����� ������ ��� ����������");
    Form5->ComboBox1->Items->Add("����������");
    Form5->ComboBox1->Items->Add("������ ������������� ��������");
    Form5->ComboBox2->Items->Add("������ ��� ����� ������ ��� ����������");
    Form5->ComboBox2->Items->Add("����������");
    Form5->ComboBox2->Items->Add("������ ������������� ��������");
    }
 if (PageControl1->ActivePageIndex==2)
    {
    Form5->ComboBox1->Items->Add("�������");
    Form5->ComboBox1->Items->Add("���");
    Form5->ComboBox1->Items->Add("��������");
    Form5->ComboBox1->Items->Add("���������� �������");
    Form5->ComboBox1->Items->Add("����� �����");
    Form5->ComboBox2->Items->Add("�������");
    Form5->ComboBox2->Items->Add("���");
    Form5->ComboBox2->Items->Add("��������");
    Form5->ComboBox2->Items->Add("���������� �������");
    Form5->ComboBox2->Items->Add("����� �����");
    }
 Form5->RadioButton1->Checked = true;
 Form5->ShowModal();
}


//_________________ ����� __________________________________________________
void __fastcall TForm1::N10Click(TObject *Sender)
{
//� ����������� �� ������� �������� �������
//����������� ���������� ������ ����� �������
 Form4->ComboBox1->Items->Clear();
 Form4->ComboBox2->Items->Clear();
 if (PageControl1->ActivePageIndex==0)
    {
    Form4->ComboBox1->Items->Add("������ ��� �������� ����� �������");
    Form4->ComboBox1->Items->Add("����������");
    Form4->ComboBox1->Items->Add("��������");
    Form4->ComboBox1->Items->Add("������� �������������");
    Form4->ComboBox1->Items->Add("������������ ������ � ����������");
    Form4->ComboBox2->Items->Add("������ ��� �������� ����� �������");
    Form4->ComboBox2->Items->Add("����������");
    Form4->ComboBox2->Items->Add("��������");
    Form4->ComboBox2->Items->Add("������� �������������");
    Form4->ComboBox2->Items->Add("������������ ������ � ����������");
    }
 if (PageControl1->ActivePageIndex==1)
    {
    Form4->ComboBox1->Items->Add("������ ��� ����� ������ ��� ����������");
    Form4->ComboBox1->Items->Add("����������");
    Form4->ComboBox1->Items->Add("������ ������������� ��������");
    Form4->ComboBox2->Items->Add("������ ��� ����� ������ ��� ����������");
    Form4->ComboBox2->Items->Add("����������");
    Form4->ComboBox2->Items->Add("������ ������������� ��������");
    }
 if (PageControl1->ActivePageIndex==2)
    {
    Form4->ComboBox1->Items->Add("�������");
    Form4->ComboBox1->Items->Add("���");
    Form4->ComboBox1->Items->Add("��������");
    Form4->ComboBox1->Items->Add("���������� �������");
    Form4->ComboBox1->Items->Add("����� �����");
    Form4->ComboBox2->Items->Add("�������");
    Form4->ComboBox2->Items->Add("���");
    Form4->ComboBox2->Items->Add("��������");
    Form4->ComboBox2->Items->Add("���������� �������");
    Form4->ComboBox2->Items->Add("����� �����");
    }
 Form4->ShowModal();
}


//_________________ ���������� ����� _______________________________________
void __fastcall TForm1::N1Click(TObject *Sender)
{
 //� ����������� �� ������� �������� �������
 //����������� ������������ �����
 if (PageControl1->ActivePageIndex==0) {Form3->ShowModal();}
 if (PageControl1->ActivePageIndex==1) {Form6->ShowModal();}
 if (PageControl1->ActivePageIndex==2) {Form7->ShowModal();}
}


//_________________ �������� ����� _________________________________________
void __fastcall TForm1::N11Click(TObject *Sender)
{
 Form8->ShowModal();
}


//_________________ �������������� ����� ___________________________________
void __fastcall TForm1::N12Click(TObject *Sender)
{
 if (PageControl1->ActivePageIndex==0)
    {
    int upd_id = StringGrid1->Row; // ������ ���������� ������
    Form9->Edit1->Text =  StringGrid1->Cells[0][upd_id];
    Form9->DateTimePicker1->Date = DateToStr(StringGrid1->Cells[1][upd_id]);
    Form9->DateTimePicker2->Date = DateToStr(StringGrid1->Cells[2][upd_id]);
    Form9->Edit2->Text = StringGrid1->Cells[3][upd_id];
    Form9->Edit3->Text = StringGrid1->Cells[4][upd_id];
    Form9->Edit4->Text = StringGrid1->Cells[5][upd_id];
    Form9->Edit5->Text = StringGrid1->Cells[6][upd_id];
    Form9->ShowModal();
    }

 if (PageControl1->ActivePageIndex==1)
    {
    int upd_id = StringGrid2->Row; // ������ ���������� ������
    Form10->Edit1->Text = StringGrid2->Cells[0][upd_id];
    Form10->Edit2->Text = StringGrid2->Cells[1][upd_id];
    Form10->Edit3->Text = StringGrid2->Cells[2][upd_id];
    Form10->DateTimePicker1->Date = DateToStr(StringGrid2->Cells[3][upd_id]);
    Form10->ShowModal();
    }

 if (PageControl1->ActivePageIndex==2)
    {
    int upd_id = StringGrid3->Row; // ������ ���������� ������
    Form11->Edit1->Text = StringGrid3->Cells[0][upd_id];
    Form11->Edit2->Text = StringGrid3->Cells[1][upd_id];
    Form11->Edit3->Text = StringGrid3->Cells[2][upd_id];
    Form11->Edit4->Text = StringGrid3->Cells[3][upd_id];
    Form11->Edit5->Text = StringGrid3->Cells[4][upd_id];
    Form11->ShowModal();
    }
}


//_________________ ������ ���������� ______________________________________
void __fastcall TForm1::N13Click(TObject *Sender)
{
 if (PageControl1->ActivePageIndex==0)
    {
    // ������ �� ������� ���� ������ � �������
    String r = "AlS1";
    ClientSocket1->Socket->SendText(r);
    }
 if (PageControl1->ActivePageIndex==1)
    {
    String r = "AlS2";
    ClientSocket1->Socket->SendText(r);
    }
 if (PageControl1->ActivePageIndex==2)
    {
    String r = "AlS3";
    ClientSocket1->Socket->SendText(r);
    }
}


//_________________ �������� ����������� ������������ ______________________
void __fastcall TForm1::N3Click(TObject *Sender)
{
 AnsiString ss =  GetCurrentDir()+"\\Doc\\ReadMe.doc";
 char* str = new char[(GetCurrentDir().Length())];
 strcpy(str, ss.c_str());
 ShellExecute(Form1->Handle, "open", str, NULL, NULL, SW_SHOWNORMAL);
}


//_________________ �������� ������ ________________________________________
void __fastcall TForm1::N4Click(TObject *Sender)
{
 AnsiString ss =  GetCurrentDir()+"\\Doc\\Report.doc";
 char* str = new char[(GetCurrentDir().Length())];
 strcpy(str, ss.c_str());
 ShellExecute(Form1->Handle, "open", str, NULL, NULL, SW_SHOWNORMAL);
}


//_________________ � ��������� ________________________________________
void __fastcall TForm1::N5Click(TObject *Sender)
{
 MessageBox(NULL,"���������� ���������� \n��������� ���������� �. �. \n28 ������� 2010�.","� ���������", MB_OK);
}


void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
 //ClientSocket1->Close();
}

