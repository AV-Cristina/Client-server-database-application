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


//_________________ Подключение клиента ____________________________________
void __fastcall TForm1::FormCreate(TObject *Sender)
{
 if (ClientSocket1->Active==true){ClientSocket1->Close();}
 ClientSocket1->Host = "localhost";
 ClientSocket1->Port = 2000;
 ClientSocket1->Open();
}


//_________________ После подключения клиента ______________________________
void __fastcall TForm1::ClientSocket1Connect(TObject *Sender,TCustomWinSocket *Socket)
{
 ShowMessage("Connected");
 // подпись имен столбцов сетки
 Connect();
 // запрос всех данных у сервера
 String c = "All0";
 ClientSocket1->Socket->SendText(c);
}


//_________________ Получение и обработка данных от сервера ________________
void __fastcall TForm1::ClientSocket1Read(TObject *Sender,
      TCustomWinSocket *Socket)
{
 //сохранение присланной строки
 String s = Socket->ReceiveText();

 //сохранение присланной команды
 String c = s.SubString(1,3);
 int i, j;

 //отправляемая строка (запрос сл.строки из указ. таблицы)
 String r;

 //Если прислана строка  из 1й таблицы БД (присылаются построчно)
 if (c == "#A1")
    {
    s.Delete(1,3);
    i=0;                           //столбец
    j = StringGrid1->RowCount-1;   //строка
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

 //Если прислана строка из 2й таблицы БД
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

 //Если прислана строка из 3й таблицы БД
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

//_________________ Обновление данных после выполнения запросов ____________
 //Если прислано подтверждение сортировки записей
 //или добавления записи
 //или удаления и т д
 //сетки очищаются и перезаписываются
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
    // запрос всех данных у сервера
    r = "All0";
    ClientSocket1->Socket->SendText(r);
    }

//_________________ Получение результата поиска ____________________________
//Если поиск не дал результатов
 if (c == "000")
    {
    Form4->StringGrid1->Visible=false;
    MessageBox(NULL,"Поиск не дал результатов","Поиск", MB_OK);
    }

//Если прислана первая строка результата поиска
 if (c=="#I1" || c=="#I2" || c=="#I3")
    {
    Form4->StringGrid1->Visible=true;
    //очистка сетки
    for (int l=1; l<=Form4->StringGrid1->RowCount; l++)
        {for (int k=0; k<=7; k++) {Form4->StringGrid1->Cells[k][l]="";}}
    Form4->StringGrid1->RowCount=2;
    if (c=="#I1")
       {
       Form4->StringGrid1->Cells[0][0]="Полное имя главного файла проекта";
       Form4->StringGrid1->Cells[1][0]="Дата начала работы над проектом";
       Form4->StringGrid1->Cells[2][0]="Дата окончания работы над проектом";
       Form4->StringGrid1->Cells[3][0]="Назначение";
       Form4->StringGrid1->Cells[4][0]="Заказчик";
       Form4->StringGrid1->Cells[5][0]="Степень завершенности";
       Form4->StringGrid1->Cells[6][0]="Используемые модули и библиотеки";
       }
    if (c=="#I2")
       {
       Form4->StringGrid1->Cells[0][0]="Полное имя файла модуля или библиотеки";
       Form4->StringGrid1->Cells[1][0]="Назначение";
       Form4->StringGrid1->Cells[2][0]="Список реализованных процедур";
       Form4->StringGrid1->Cells[3][0]="Дата создания";
       }
    if (c=="#I3")
       {
       Form4->StringGrid1->Cells[0][0]="Фамилия";
       Form4->StringGrid1->Cells[1][0]="Имя";
       Form4->StringGrid1->Cells[2][0]="Отчество";
       Form4->StringGrid1->Cells[3][0]="Контактный телефон";
       Form4->StringGrid1->Cells[4][0]="Адрес фирмы";
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


//Если прислана строка результата поиска
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
 StringGrid1->Cells[0][0]="Полное имя главного файла проекта";
 StringGrid1->Cells[1][0]="Дата начала работы над проектом";
 StringGrid1->Cells[2][0]="Дата окончания работы над проектом";
 StringGrid1->Cells[3][0]="Назначение";
 StringGrid1->Cells[4][0]="Заказчик";
 StringGrid1->Cells[5][0]="Степень завершенности";
 StringGrid1->Cells[6][0]="Используемые модули и библиотеки";
}


void TForm1::CaptionTable2()
{
 StringGrid2->Cells[0][0]="Полное имя файла модуля или библиотеки";
 StringGrid2->Cells[1][0]="Назначение";
 StringGrid2->Cells[2][0]="Список реализованных процедур";
 StringGrid2->Cells[3][0]="Дата создания";
}


void TForm1::CaptionTable3()
{
 StringGrid3->Cells[0][0]="Фамилия";
 StringGrid3->Cells[1][0]="Имя";
 StringGrid3->Cells[2][0]="Отчество";
 StringGrid3->Cells[3][0]="Контактный телефон";
 StringGrid3->Cells[4][0]="Адрес фирмы";
}


void TForm1::Connect()
{
 CaptionTable1();
 CaptionTable2();
 CaptionTable3();
}


//_________________ Сортировка _____________________________________________
void __fastcall TForm1::N8Click(TObject *Sender)
{
//в зависимости от индекса открытой вкладки
//заполняется выпадающий список полей таблицы
 Form2->ComboBox1->Clear();
 if (PageControl1->ActivePageIndex==0)
    {
    Form2->ComboBox1->Items->Add("Полное имя главного файла проекта");
    Form2->ComboBox1->Items->Add("Дата начала работы над проектом");
    Form2->ComboBox1->Items->Add("Дата окончания работы над проектом");
    Form2->ComboBox1->Items->Add("Назначение");
    Form2->ComboBox1->Items->Add("Заказчик");
    Form2->ComboBox1->Items->Add("Степень завершенности");
    Form2->ComboBox1->Items->Add("Используемые модули и библиотеки");
    }
 if (PageControl1->ActivePageIndex==1)
    {
    Form2->ComboBox1->Items->Add("Полное имя файла модуля или библиотеки");
    Form2->ComboBox1->Items->Add("Назначение");
    Form2->ComboBox1->Items->Add("Список реализованных процедур");
    Form2->ComboBox1->Items->Add("Дата создания");
    }
 if (PageControl1->ActivePageIndex==2)   
    {
    Form2->ComboBox1->Items->Add("Фамилия");
    Form2->ComboBox1->Items->Add("Имя");
    Form2->ComboBox1->Items->Add("Отчество");
    Form2->ComboBox1->Items->Add("Контактный телефон");
    Form2->ComboBox1->Items->Add("Адрес фирмы");
    }
 Form2->ShowModal();
}


//_________________ Фильтр _________________________________________________
void __fastcall TForm1::N9Click(TObject *Sender)
{
 Form5->ComboBox1->Items->Clear();
 Form5->ComboBox2->Items->Clear();
 if (PageControl1->ActivePageIndex==0)
    {
    Form5->ComboBox1->Items->Add("Полное имя главного файла проекта");
    Form5->ComboBox1->Items->Add("Назначение");
    Form5->ComboBox1->Items->Add("Заказчик");
    Form5->ComboBox1->Items->Add("Степень завершенности");
    Form5->ComboBox1->Items->Add("Используемые модули и библиотеки");
    Form5->ComboBox2->Items->Add("Полное имя главного файла проекта");
    Form5->ComboBox2->Items->Add("Назначение");
    Form5->ComboBox2->Items->Add("Заказчик");
    Form5->ComboBox2->Items->Add("Степень завершенности");
    Form5->ComboBox2->Items->Add("Используемые модули и библиотеки");
    }
 if (PageControl1->ActivePageIndex==1)
    {
    Form5->ComboBox1->Items->Add("Полное имя файла модуля или библиотеки");
    Form5->ComboBox1->Items->Add("Назначение");
    Form5->ComboBox1->Items->Add("Список реализованных процедур");
    Form5->ComboBox2->Items->Add("Полное имя файла модуля или библиотеки");
    Form5->ComboBox2->Items->Add("Назначение");
    Form5->ComboBox2->Items->Add("Список реализованных процедур");
    }
 if (PageControl1->ActivePageIndex==2)
    {
    Form5->ComboBox1->Items->Add("Фамилия");
    Form5->ComboBox1->Items->Add("Имя");
    Form5->ComboBox1->Items->Add("Отчество");
    Form5->ComboBox1->Items->Add("Контактный телефон");
    Form5->ComboBox1->Items->Add("Адрес фирмы");
    Form5->ComboBox2->Items->Add("Фамилия");
    Form5->ComboBox2->Items->Add("Имя");
    Form5->ComboBox2->Items->Add("Отчество");
    Form5->ComboBox2->Items->Add("Контактный телефон");
    Form5->ComboBox2->Items->Add("Адрес фирмы");
    }
 Form5->RadioButton1->Checked = true;
 Form5->ShowModal();
}


//_________________ Поиск __________________________________________________
void __fastcall TForm1::N10Click(TObject *Sender)
{
//в зависимости от индекса открытой вкладки
//заполняется выпадающий список полей таблицы
 Form4->ComboBox1->Items->Clear();
 Form4->ComboBox2->Items->Clear();
 if (PageControl1->ActivePageIndex==0)
    {
    Form4->ComboBox1->Items->Add("Полное имя главного файла проекта");
    Form4->ComboBox1->Items->Add("Назначение");
    Form4->ComboBox1->Items->Add("Заказчик");
    Form4->ComboBox1->Items->Add("Степень завершенности");
    Form4->ComboBox1->Items->Add("Используемые модули и библиотеки");
    Form4->ComboBox2->Items->Add("Полное имя главного файла проекта");
    Form4->ComboBox2->Items->Add("Назначение");
    Form4->ComboBox2->Items->Add("Заказчик");
    Form4->ComboBox2->Items->Add("Степень завершенности");
    Form4->ComboBox2->Items->Add("Используемые модули и библиотеки");
    }
 if (PageControl1->ActivePageIndex==1)
    {
    Form4->ComboBox1->Items->Add("Полное имя файла модуля или библиотеки");
    Form4->ComboBox1->Items->Add("Назначение");
    Form4->ComboBox1->Items->Add("Список реализованных процедур");
    Form4->ComboBox2->Items->Add("Полное имя файла модуля или библиотеки");
    Form4->ComboBox2->Items->Add("Назначение");
    Form4->ComboBox2->Items->Add("Список реализованных процедур");
    }
 if (PageControl1->ActivePageIndex==2)
    {
    Form4->ComboBox1->Items->Add("Фамилия");
    Form4->ComboBox1->Items->Add("Имя");
    Form4->ComboBox1->Items->Add("Отчество");
    Form4->ComboBox1->Items->Add("Контактный телефон");
    Form4->ComboBox1->Items->Add("Адрес фирмы");
    Form4->ComboBox2->Items->Add("Фамилия");
    Form4->ComboBox2->Items->Add("Имя");
    Form4->ComboBox2->Items->Add("Отчество");
    Form4->ComboBox2->Items->Add("Контактный телефон");
    Form4->ComboBox2->Items->Add("Адрес фирмы");
    }
 Form4->ShowModal();
}


//_________________ Добавление строк _______________________________________
void __fastcall TForm1::N1Click(TObject *Sender)
{
 //в зависимости от индекса открытой вкладки
 //открывается определенная форма
 if (PageControl1->ActivePageIndex==0) {Form3->ShowModal();}
 if (PageControl1->ActivePageIndex==1) {Form6->ShowModal();}
 if (PageControl1->ActivePageIndex==2) {Form7->ShowModal();}
}


//_________________ Удаление строк _________________________________________
void __fastcall TForm1::N11Click(TObject *Sender)
{
 Form8->ShowModal();
}


//_________________ Редактирование строк ___________________________________
void __fastcall TForm1::N12Click(TObject *Sender)
{
 if (PageControl1->ActivePageIndex==0)
    {
    int upd_id = StringGrid1->Row; // индекс выделенной строки
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
    int upd_id = StringGrid2->Row; // индекс выделенной строки
    Form10->Edit1->Text = StringGrid2->Cells[0][upd_id];
    Form10->Edit2->Text = StringGrid2->Cells[1][upd_id];
    Form10->Edit3->Text = StringGrid2->Cells[2][upd_id];
    Form10->DateTimePicker1->Date = DateToStr(StringGrid2->Cells[3][upd_id]);
    Form10->ShowModal();
    }

 if (PageControl1->ActivePageIndex==2)
    {
    int upd_id = StringGrid3->Row; // индекс выделенной строки
    Form11->Edit1->Text = StringGrid3->Cells[0][upd_id];
    Form11->Edit2->Text = StringGrid3->Cells[1][upd_id];
    Form11->Edit3->Text = StringGrid3->Cells[2][upd_id];
    Form11->Edit4->Text = StringGrid3->Cells[3][upd_id];
    Form11->Edit5->Text = StringGrid3->Cells[4][upd_id];
    Form11->ShowModal();
    }
}


//_________________ Отмена филитрации ______________________________________
void __fastcall TForm1::N13Click(TObject *Sender)
{
 if (PageControl1->ActivePageIndex==0)
    {
    // запрос на выборку всех данных у сервера
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


//_________________ Открытие руководства пользователя ______________________
void __fastcall TForm1::N3Click(TObject *Sender)
{
 AnsiString ss =  GetCurrentDir()+"\\Doc\\ReadMe.doc";
 char* str = new char[(GetCurrentDir().Length())];
 strcpy(str, ss.c_str());
 ShellExecute(Form1->Handle, "open", str, NULL, NULL, SW_SHOWNORMAL);
}


//_________________ Открытие отчета ________________________________________
void __fastcall TForm1::N4Click(TObject *Sender)
{
 AnsiString ss =  GetCurrentDir()+"\\Doc\\Report.doc";
 char* str = new char[(GetCurrentDir().Length())];
 strcpy(str, ss.c_str());
 ShellExecute(Form1->Handle, "open", str, NULL, NULL, SW_SHOWNORMAL);
}


//_________________ О программе ________________________________________
void __fastcall TForm1::N5Click(TObject *Sender)
{
 MessageBox(NULL,"Клиентское приложение \nВыполнила Афанасьева К. В. \n28 Октября 2010г.","О программе", MB_OK);
}


void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
 //ClientSocket1->Close();
}

