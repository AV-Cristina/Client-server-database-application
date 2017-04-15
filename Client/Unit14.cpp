//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit14.h"
#include "Unit6.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm14 *Form14;
//---------------------------------------------------------------------------
__fastcall TForm14::TForm14(TComponent* Owner)
        : TForm(Owner)
{
}


//__________ Добавление модуля в проект ____________________________________
void __fastcall TForm14::Button1Click(TObject *Sender)
{
 bool NotExist = true;
 for (int i=0; i<Memo1->Lines->Count;i++)
     {
     if (Memo1->Lines->Strings[i]==ComboBox1->Items->Strings[ComboBox1->ItemIndex])
        {
        NotExist = false;  break;
        }
     }
 if (NotExist == true) {Memo1->Lines->Add(ComboBox1->Items->Strings[ComboBox1->ItemIndex]);}
 else {MessageBox(NULL,"Модуль или библиотека с таким именем уже добавлена к проекту!","Ошибка", MB_OK);}
}


//__________ Добавление нового модуля ______________________________________
void __fastcall TForm14::Button2Click(TObject *Sender)
{
 Form6->ShowModal();
}


//__________ Ввод данных в форму "Проекты" _________________________________
void __fastcall TForm14::Button3Click(TObject *Sender)
{
 for (int i=0; i<Memo1->Lines->Count;i++)
     {
     if (i!= Memo1->Lines->Count-1)
        {Form3->Edit5->Text = Form3->Edit5->Text+ Memo1->Lines->Strings[i]+", ";}
     else
        {Form3->Edit5->Text = Form3->Edit5->Text+ Memo1->Lines->Strings[i];}
     }
 Form14->Close();
}


//__________ Удаление модуля из проекта ____________________________________
void __fastcall TForm14::Button4Click(TObject *Sender)
{
 for (int i=0; i<Memo1->Lines->Count;i++)
     {
     if (Memo1->Lines->Strings[i]==ComboBox1->Items->Strings[ComboBox1->ItemIndex])
        {
        Memo1->Lines->Delete(i);
        }
     }
}


