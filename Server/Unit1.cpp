//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"

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

void TForm1::OpenTable1()
{
 IBQuery1->Active = false;
 IBQuery1->SQL->Clear();
 IBQuery1->SQL->Add("SELECT * FROM "+ComboBox1->Items->Strings[2]);
 IBQuery1->Active = true;
}


void TForm1::OpenTable2()
{
 IBQuery2->Active = false;
 IBQuery2->SQL->Clear();
 IBQuery2->SQL->Add("SELECT * FROM "+ComboBox1->Items->Strings[1]);
 IBQuery2->Active = true;
}


void TForm1::OpenTable3()
{
 IBQuery3->Active = false;
 IBQuery3->SQL->Clear();
 IBQuery3->SQL->Add("SELECT * FROM "+ComboBox1->Items->Strings[0]);
 IBQuery3->Active = true;
}




//_________________ Сортировка _____________________________________________
void TForm1::Sort(String s)
{
 String c = s.SubString(1,4); // команда
 s.Delete(1, s.Pos(';'));     // удаление подстроки с командой из запроса

 if (c == "Srt1")
    {
    Form1->IBQuery1->Active = false;
    Form1->IBQuery1->SQL->Clear();
    Form1->IBQuery1->SQL->Add(s);
    Form1->IBQuery1->Active = true;
    }

 if (c == "Srt2")
    {
    Form1->IBQuery2->Active = false;
    Form1->IBQuery2->SQL->Clear();
    Form1->IBQuery2->SQL->Add(s);
    Form1->IBQuery2->Active = true;
    }

 if (c == "Srt3")
    {
    Form1->IBQuery3->Active = false;
    Form1->IBQuery3->SQL->Clear();
    Form1->IBQuery3->SQL->Add(s);
    Form1->IBQuery3->Active = true;
    }
}


//_________________ Добавление записи ______________________________________
void TForm1::Add(String s)
{
 String c = s.SubString(1,4); // присланная строка
 s.Delete(1, s.Pos(';'));     // удаление команды из списка параметров

 if (c == "Add1")
    {
    IBQuery1->Active = false;
    IBQuery1->SQL->Clear();
    IBQuery1->SQL->Add("INSERT INTO PROJECTS (PROJECT_NAME, DATE_BEG, DATE_END, DISTINATION, CUSTOMER_ID, COMPLETENESS, MOD_AND_LIB_ID_LIST)");
    IBQuery1->SQL->Add("VALUES ( :Param2, :Param3, :Param4, :Param5, :Param6, :Param7, :Param8)");
    IBQuery1->Params->ParamByName("Param2")->Value = s.SubString(1, s.Pos(';')-1); s.Delete(1, s.Pos(';'));
    IBQuery1->Params->ParamByName("Param3")->Value = s.SubString(1, s.Pos(';')-1); s.Delete(1, s.Pos(';'));
    IBQuery1->Params->ParamByName("Param4")->Value = s.SubString(1, s.Pos(';')-1); s.Delete(1, s.Pos(';'));
    IBQuery1->Params->ParamByName("Param5")->Value = s.SubString(1, s.Pos(';')-1); s.Delete(1, s.Pos(';'));
    IBQuery1->Params->ParamByName("Param6")->Value = s.SubString(1, s.Pos(';')-1); s.Delete(1, s.Pos(';'));
    IBQuery1->Params->ParamByName("Param7")->Value = s.SubString(1, s.Pos(';')-1); s.Delete(1, s.Pos(';'));
    IBQuery1->Params->ParamByName("Param8")->Value = s.SubString(1, s.Pos(';')-1); s.Delete(1, s.Pos(';'));
    IBQuery1->ExecSQL();
    OpenTable1();
    }
 if (c == "Add2")
    {
    IBQuery2->Active = false;
    IBQuery2->SQL->Clear();
    IBQuery2->SQL->Add("INSERT INTO MODULES_AND_LIBRARIES (MOD_OR_LIB_NAME, DISTINATION, PROCEDURE_LIST, DATE_CREATE)");
    IBQuery2->SQL->Add("VALUES (:Param2, :Param3, :Param4, :Param5)");
    IBQuery2->Params->ParamByName("Param2")->Value = s.SubString(1, s.Pos(';')-1); s.Delete(1, s.Pos(';'));
    IBQuery2->Params->ParamByName("Param3")->Value = s.SubString(1, s.Pos(';')-1); s.Delete(1, s.Pos(';'));
    IBQuery2->Params->ParamByName("Param4")->Value = s.SubString(1, s.Pos(';')-1); s.Delete(1, s.Pos(';'));
    IBQuery2->Params->ParamByName("Param5")->Value = s.SubString(1, s.Pos(';')-1); s.Delete(1, s.Pos(';'));
    IBQuery2->ExecSQL();
    OpenTable2();
    }
 if (c == "Add3")
    {
    IBQuery3->Active = false;
    IBQuery3->SQL->Clear();
    IBQuery3->SQL->Add("INSERT INTO CUSTOMERS (SURNAME, NAME, PATRONUMIC, TELEPHONE, ADDRESS)");
    IBQuery3->SQL->Add("VALUES ( :Param2, :Param3, :Param4, :Param5, :Param6)");
    IBQuery3->Params->ParamByName("Param2")->Value = s.SubString(1, s.Pos(';')-1); s.Delete(1, s.Pos(';'));
    IBQuery3->Params->ParamByName("Param3")->Value = s.SubString(1, s.Pos(';')-1); s.Delete(1, s.Pos(';'));
    IBQuery3->Params->ParamByName("Param4")->Value = s.SubString(1, s.Pos(';')-1); s.Delete(1, s.Pos(';'));
    IBQuery3->Params->ParamByName("Param5")->Value = s.SubString(1, s.Pos(';')-1); s.Delete(1, s.Pos(';'));
    IBQuery3->Params->ParamByName("Param6")->Value = s.SubString(1, s.Pos(';')-1); s.Delete(1, s.Pos(';'));
    IBQuery3->ExecSQL();
    OpenTable3();
    }
}


//_________________ Удаление записи ______________________________________
void TForm1::Del(String s)
{
 String c = s.SubString(1,4); // присланная строка
 s.Delete(1, s.Pos(';'));     // удаление команды из списка параметров

 if (c == "Del1")
    {
    IBQuery1->Active = false;
    IBQuery1->SQL->Clear();
    IBQuery1->SQL->Add("DELETE FROM PROJECTS");
    IBQuery1->SQL->Add("WHERE PROJECT_NAME=:Param2 AND DATE_BEG=:Param3 AND DATE_END=:Param4 AND DISTINATION=:Param5 AND CUSTOMER_ID=:Param6 AND COMPLETENESS=:Param7 AND MOD_AND_LIB_ID_LIST=:Param8");
    IBQuery1->Params->ParamByName("Param2")->Value = s.SubString(1, s.Pos(';')-1); s.Delete(1, s.Pos(';'));
    IBQuery1->Params->ParamByName("Param3")->Value = s.SubString(1, s.Pos(';')-1); s.Delete(1, s.Pos(';'));
    IBQuery1->Params->ParamByName("Param4")->Value = s.SubString(1, s.Pos(';')-1); s.Delete(1, s.Pos(';'));
    IBQuery1->Params->ParamByName("Param5")->Value = s.SubString(1, s.Pos(';')-1); s.Delete(1, s.Pos(';'));
    IBQuery1->Params->ParamByName("Param6")->Value = s.SubString(1, s.Pos(';')-1); s.Delete(1, s.Pos(';'));
    IBQuery1->Params->ParamByName("Param7")->Value = s.SubString(1, s.Pos(';')-1); s.Delete(1, s.Pos(';'));
    IBQuery1->Params->ParamByName("Param8")->Value = s.SubString(1, s.Pos(';')-1); s.Delete(1, s.Pos(';'));
    IBQuery1->ExecSQL();
    OpenTable1();
    }
 if (c == "Del2")
    {
    IBQuery2->Active = false;
    IBQuery2->SQL->Clear();
    IBQuery2->SQL->Add("DELETE FROM MODULES_AND_LIBRARIES");
    IBQuery2->SQL->Add("WHERE MOD_OR_LIB_NAME=:Param2 AND DISTINATION=:Param3 AND PROCEDURE_LIST=:Param4 AND DATE_CREATE=:Param5");
    IBQuery2->Params->ParamByName("Param2")->Value = s.SubString(1, s.Pos(';')-1); s.Delete(1, s.Pos(';'));
    IBQuery2->Params->ParamByName("Param3")->Value = s.SubString(1, s.Pos(';')-1); s.Delete(1, s.Pos(';'));
    IBQuery2->Params->ParamByName("Param4")->Value = s.SubString(1, s.Pos(';')-1); s.Delete(1, s.Pos(';'));
    IBQuery2->Params->ParamByName("Param5")->Value = s.SubString(1, s.Pos(';')-1); s.Delete(1, s.Pos(';'));
    IBQuery2->ExecSQL();
    OpenTable2();
    }
 if (c == "Del3")
    {
    IBQuery3->Active = false;
    IBQuery3->SQL->Clear();
    IBQuery3->SQL->Add("DELETE FROM CUSTOMERS");
    IBQuery3->SQL->Add("WHERE SURNAME=:Param2 AND NAME=:Param3 AND PATRONUMIC=:Param4 AND TELEPHONE=:Param5 AND ADDRESS=:Param6");
    IBQuery3->Params->ParamByName("Param2")->Value = s.SubString(1, s.Pos(';')-1); s.Delete(1, s.Pos(';'));
    IBQuery3->Params->ParamByName("Param3")->Value = s.SubString(1, s.Pos(';')-1); s.Delete(1, s.Pos(';'));
    IBQuery3->Params->ParamByName("Param4")->Value = s.SubString(1, s.Pos(';')-1); s.Delete(1, s.Pos(';'));
    IBQuery3->Params->ParamByName("Param5")->Value = s.SubString(1, s.Pos(';')-1); s.Delete(1, s.Pos(';'));
    IBQuery3->Params->ParamByName("Param6")->Value = s.SubString(1, s.Pos(';')-1); s.Delete(1, s.Pos(';'));
    IBQuery3->ExecSQL();
    OpenTable3();
    }
}


//_________________ Обновление записи ______________________________________
void TForm1::Upd(String s)
{
 String c = s.SubString(1,4); // присланная строка
 s.Delete(1, s.Pos(';'));     // удаление команды из списка параметров

 if (c == "Upd1")
    {
    //----- определение индекса строки -------------------------------------
    int k = StrToInt (s.SubString(1, s.Pos(';')-1));
    s.Delete(1, s.Pos(';'));
    int upd_id;

    //переход к этой строке в таблице
    IBQuery1->First();
    for (int i=0; i<=k; i++)
        {
        if(i==k-1)
          {
          upd_id = IBQuery1->Fields->Fields[0]->AsInteger; //значение поля ID
          ShowMessage(IBQuery1->Fields->Fields[1]->AsString);// 
          break;
          }
        IBQuery1->Next();
        }
    IBQuery1->Active = false;
    IBQuery1->SQL->Clear();
    IBQuery1->SQL->Add("UPDATE PROJECTS SET PROJECT_NAME=:Param2, DATE_BEG=:Param3, DATE_END=:Param4, DISTINATION=:Param5, CUSTOMER_ID=:Param6, COMPLETENESS=:Param7, MOD_AND_LIB_ID_LIST=:Param8 WHERE ID="+IntToStr(upd_id));
    IBQuery1->Params->ParamByName("Param2")->Value = s.SubString(1, s.Pos(';')-1); s.Delete(1, s.Pos(';'));
    IBQuery1->Params->ParamByName("Param3")->Value = s.SubString(1, s.Pos(';')-1); s.Delete(1, s.Pos(';'));
    IBQuery1->Params->ParamByName("Param4")->Value = s.SubString(1, s.Pos(';')-1); s.Delete(1, s.Pos(';'));
    IBQuery1->Params->ParamByName("Param5")->Value = s.SubString(1, s.Pos(';')-1); s.Delete(1, s.Pos(';'));
    IBQuery1->Params->ParamByName("Param6")->Value = s.SubString(1, s.Pos(';')-1); s.Delete(1, s.Pos(';'));
    IBQuery1->Params->ParamByName("Param7")->Value = s.SubString(1, s.Pos(';')-1); s.Delete(1, s.Pos(';'));
    IBQuery1->Params->ParamByName("Param8")->Value = s.SubString(1, s.Pos(';')-1); s.Delete(1, s.Pos(';'));
    IBQuery1->ExecSQL();
    OpenTable1();
    }

 if (c == "Upd2")
    {
    //----- определение индекса строки -------------------------------------
    int k = StrToInt (s.SubString(1, s.Pos(';')-1));
    s.Delete(1, s.Pos(';'));
    int upd_id;

    //переход к этой строке в таблице
    IBQuery2->First();
    for (int i=0; i<k; i++)
        {
        if(i==k-1)
          {
          upd_id = IBQuery2->Fields->Fields[0]->AsInteger; //значение поля ID
          break;
          }
        IBQuery2->Next();
        }
    IBQuery2->Active = false;
    IBQuery2->SQL->Clear();
    IBQuery1->SQL->Add("UPDATE MODULES_AND_LIBRARIES SET MOD_OR_LIB_NAME=:Param2, DISTINATION=:Param3, PROCEDURE_LIST=:Param4, DATE_CREATE=:Param5 WHERE ID="+IntToStr(upd_id));
    IBQuery2->Params->ParamByName("Param2")->Value = s.SubString(1, s.Pos(';')-1); s.Delete(1, s.Pos(';'));
    IBQuery2->Params->ParamByName("Param3")->Value = s.SubString(1, s.Pos(';')-1); s.Delete(1, s.Pos(';'));
    IBQuery2->Params->ParamByName("Param4")->Value = s.SubString(1, s.Pos(';')-1); s.Delete(1, s.Pos(';'));
    IBQuery2->Params->ParamByName("Param5")->Value = s.SubString(1, s.Pos(';')-1); s.Delete(1, s.Pos(';'));
    IBQuery2->ExecSQL();
    OpenTable2();
    }

 if (c == "Upd3")
    {
    //----- определение индекса строки -------------------------------------
    int k = StrToInt (s.SubString(1, s.Pos(';')-1));
    s.Delete(1, s.Pos(';'));
    int upd_id;

    //переход к этой строке в таблице
    IBQuery3->First();
    for (int i=0; i<k; i++)
        {
        if(i==k-1)
          {
          upd_id = IBQuery3->Fields->Fields[0]->AsInteger; //значение поля ID
          break;
          }
        IBQuery3->Next();
        }
    IBQuery3->Active = false;
    IBQuery3->SQL->Clear();
    IBQuery1->SQL->Add("UPDATE CUSTOMERS SET SURNAME=:Param2, NAME=:Param3, PATRONUMIC=:Param4, TELEPHONE=:Param5, ADDRESSWHERE=:Param6 ID="+IntToStr(upd_id));
    IBQuery3->Params->ParamByName("Param2")->Value = s.SubString(1, s.Pos(';')-1); s.Delete(1, s.Pos(';'));
    IBQuery3->Params->ParamByName("Param3")->Value = s.SubString(1, s.Pos(';')-1); s.Delete(1, s.Pos(';'));
    IBQuery3->Params->ParamByName("Param4")->Value = s.SubString(1, s.Pos(';')-1); s.Delete(1, s.Pos(';'));
    IBQuery3->Params->ParamByName("Param5")->Value = s.SubString(1, s.Pos(';')-1); s.Delete(1, s.Pos(';'));
    IBQuery3->Params->ParamByName("Param6")->Value = s.SubString(1, s.Pos(';')-1); s.Delete(1, s.Pos(';'));
    IBQuery3->ExecSQL();
    OpenTable3();
    }
}


//_________________ Фильтр записей _________________________________________
void TForm1::Fen(String s)
{
 String c = s.SubString(1,4); // присланная строка
 s.Delete(1, s.Pos(';'));     // удаление команды из списка параметров

 if (c == "Fen1")
    {
    Memo1->Lines->Add(s);
    IBQuery1->Active = false;
    IBQuery1->SQL->Clear();
    IBQuery1->SQL->Add(s);
    IBQuery1->Active = true;
    }
 if (c == "Fen2")
    {
    IBQuery2->Active = false;
    IBQuery2->SQL->Clear();
    IBQuery2->SQL->Add(s);
    IBQuery2->Active = true;
    }
 if (c == "Fen3")
    {
    IBQuery3->Active = false;
    IBQuery3->SQL->Clear();
    IBQuery3->SQL->Add(s);
    IBQuery3->Active = true;
    }
}


//_________________ Отмена фильтра _________________________________________
void TForm1::Select(String s)
{
 String c = s.SubString(1,4); // присланная строка
 s.Delete(1, s.Pos(';'));     // удаление команды из списка параметров

 if (c == "AlS1") {OpenTable1();}
 if (c == "AlS2") {OpenTable2();}
 if (c == "AlS3") {OpenTable3();}
}


//_________________ Поиск записей __________________________________________
void TForm1::Fnd(String s)
{
 String AndOr;
 String And_Or;
 String AllWord;

 IBQuery5->Active = false;
 IBQuery5->SQL->Clear();

 String tab = s.SubString(1,4); // присланная команда из 4х симолов
 s.Delete(1, s.Pos(';'));

 if (tab == "Fnd1")
    {IBQuery5->SQL->Add("SELECT * FROM PROJECTS");}

 if (tab == "Fnd2")
    {IBQuery5->SQL->Add("SELECT * FROM MODULES_AND_LIBRARIES");}

 if (tab == "Fnd3")
    {IBQuery5->SQL->Add("SELECT * FROM CUSTOMERS");}

 // число параметров
 String ParamCount = s.SubString(1, s.Pos(';')-1);
 s.Delete(1, s.Pos(';'));

 //----------- 2 критерия ------------------------------------------------
 if (ParamCount == 2)
    {
    And_Or= s.SubString(1, s.Pos(';')-1);;
    s.Delete(1, s.Pos(';'));

    if (And_Or==1) {AndOr = " AND ";}
    else {AndOr = " OR ";}
    //слово целиком или цастисное совпадение
    AllWord = s.SubString(1, s.Pos(';')-1);
    s.Delete(1, s.Pos(';'));
    //имена полей таблицы
    String f1= s.SubString(1, s.Pos(';')-1);;
    s.Delete(1, s.Pos(';'));
    String f2= s.SubString(1, s.Pos(';')-1);;
    s.Delete(1, s.Pos(';'));
    //значения полей таблицы
    String t1= s.SubString(1, s.Pos(';')-1);;
    s.Delete(1, s.Pos(';'));
    String t2= s.SubString(1, s.Pos(';')-1);;
    s.Delete(1, s.Pos(';'));


    //----- только слово целиком -----------------------------------------
    if (AllWord==1)
       {
       IBQuery5->SQL->Add("WHERE "+f1+"=:Param1"+AndOr+f2+"=:Param2");
       IBQuery5->Params->ParamByName("Param1")->Value = t1;
       IBQuery5->Params->ParamByName("Param2")->Value = t2;
       }
    //----- может включать искомое слово ---------------------------------
    if (AllWord==0)
       {IBQuery5->SQL->Add("WHERE "+f1+" LIKE '"+t1+"%'"+AndOr+f2+" LIKE '"+t2+"%'");}
    }

    //----------- если ттолько 1й или 2й критерий --------------------------
    if (ParamCount == 1)
       {
       AllWord = s.SubString(1, s.Pos(';')-1);
       s.Delete(1, s.Pos(';'));
       //имя поля таблицы
       String f= s.SubString(1, s.Pos(';')-1);;
       s.Delete(1, s.Pos(';'));
       //значение поля таблицы
       String t= s.SubString(1, s.Pos(';')-1);;
       s.Delete(1, s.Pos(';'));

       //----- только слово целиком -----------------------------------------
       if (AllWord==1)
          {
          IBQuery5->SQL->Add("WHERE "+f+"=:Param1");
          IBQuery5->Params->ParamByName("Param1")->Value = t;
          }
       //----- может включать искомое слово ---------------------------------
       if (AllWord==0)
          {IBQuery5->SQL->Add("WHERE "+f+" LIKE '"+t+"%'");}
       }

    //----------- выполнение -------------------------------------------------
    IBQuery5->Active = true;
 }


//__________ Подключение  __________________________________________________
void __fastcall TForm1::FormCreate(TObject *Sender)
{
 ServerSocket1->Port=2000;
 ServerSocket1->Open();

 IBDatabase1->Close();
 IBDatabase1->DatabaseName = GetCurrentDir()+"\\DB\\Software.gdb";
 IBDatabase1->Params->Clear();
 IBDatabase1->Params->Add("User_name=SYSDBA");
 IBDatabase1->Params->Add("Password=masterkey");
 IBDatabase1->Params->Add("lc_ctype=WIN1251");
 IBDatabase1->LoginPrompt =  false;
 IBDatabase1->Connected = true;

//получение списка имен таблиц БД
 IBDatabase1->GetTableNames(ComboBox1->Items, false);

//----------------- Таблица "Программные проекты" --------------------------
  OpenTable1();       // выборка всех записей из таблицы

//----------------- Таблица "Модули и библиотеки" --------------------------
  OpenTable2();


//----------------- Таблица "Заказчики" --------------------------
  OpenTable3();
}


//__________ Обработка команд ______________________________________________
void __fastcall TForm1::ServerSocket1ClientRead(TObject *Sender,TCustomWinSocket *Socket)
{
 String s = Socket->ReceiveText();  //присланная строка
 String c = s.SubString(1,3);       //присланная команда
 String a;                          //отправляемая клиенту строка
                         
//------- Если запрос на сортировку ----------------------------------------
 if (c == "Srt")
    {
    Memo1->Lines->Add("Запрос на сортировку записей");
    Sort(s);
    Memo1->Lines->Add("Записи отсортированы");
    a = "upd";
    Socket->SendText(a);
    }
//------- Если запрос на добавление ----------------------------------------
 if (c == "Add")
    {
    Memo1->Lines->Add("Запрос на добавление записи");
    Add(s);
    Memo1->Lines->Add("Запись добавлена");
    a = "upd";
    Socket->SendText(a);
    }
//------- Если запрос на удаление ------------------------------------------
 if (c == "Del")
    {
    Memo1->Lines->Add("Запрос на удаление записи");
    Del(s);
    Memo1->Lines->Add("Запись удалена");
    a = "upd";
    Socket->SendText(a);
    }
//------- Если запрос на изменение ------------------------------------------
 if (c == "Upd")
    {
    Memo1->Lines->Add("Запрос на изменение записи");
    Upd(s);
    Memo1->Lines->Add("Запись изменена");
    a = "upd";
    Socket->SendText(a);
    }
//------- Если запрос на фильтрацию ----------------------------------------
 if (c == "Fen")
    {
    Memo1->Lines->Add("Запрос на фильтрацию");
    Fen(s);
    Memo1->Lines->Add("Записи отфильтрованы");
    a = "upd";
    Socket->SendText(a);
    }
//------- Если запрос на отмену фильтрации -----AlS1-----------------------------
 if (c == "AlS")
    {
    Memo1->Lines->Add("Запрос на отмену фильтрации");
    Select(s);
    Memo1->Lines->Add("Фильтр отменен");
    a = "upd";
    Socket->SendText(a);
    }

//------- Если запрос на поиск ---------------------------------------------
 if (c == "Fnd")
    {
    String l = s.SubString(1,4);
    Memo1->Lines->Add("Запрос на поиск");
    Fnd(s);
    Memo1->Lines->Add("Поиск выполнен");
    if (IBQuery5->RecordCount != 0)
       {
       if (l == "Fnd1"){a = "#I1";}
       if (l == "Fnd2"){a = "#I2";}
       if (l == "Fnd3"){a = "#I3";}
       IBQuery5->First();
       for (int j=1; j<IBQuery5->FieldCount; j++)
           {a = a + IBQuery5->Fields->Fields[j]->AsString + ';';}
       }
    // если поиск не дал результатов
    else {a = "000";}
    Socket->SendText(a);          // отправка 1й строки
    }


 if (c == "Inp")
    {
    // если не конец таблицы
    IBQuery5->Next();
    if (!IBQuery5->Eof)
       {
       a = "Inp";
       //запись в а всех полей строки
       for (int j=1; j<IBQuery5->FieldCount; j++)
           {a = a + IBQuery5->Fields->Fields[j]->AsString + ';';}
       Socket->SendText(a);
       }
    }


//------- Если запрос всех даных БД ----------------------------------------
 if (c == "All")
    {
    c = s.SubString(1,4); // команда

 // Если запрос всех даных БД
 if (c == "All0")
    {
    Memo1->Lines->Add("Запрос БД");
    //сначала отправляем данные 1й таблицы
    IBQuery1->First();
    a = "#A1";  // говорит о том, что данные из 1й таблицы
    for (int j=1; j<IBQuery1->FieldCount; j++)
        {a = a + IBQuery1->Fields->Fields[j]->AsString + ';';}
    Socket->SendText(a);
    }

// Если пришло подтверждение того
// что предыдущая строка получена клиентом
// отправляется следующая строка

//отправление данных 1й таблицы если от клиента пришло "#A1"

 if (c == "All1")
    {
    // если не конец таблицы
    IBQuery1->Next();
    if (!IBQuery1->Eof)
       {
       a = "#A1";  // говорит о том, что данные из 1й таблицы
       //запись в а всех полей строки
       for (int j=1; j<IBQuery1->FieldCount; j++)
           {a = a + IBQuery1->Fields->Fields[j]->AsString + ';';}
       Socket->SendText(a);
       }
    // если конец таблицы - переход на 1ю запись сл. таблицы
    if (IBQuery1->Eof)
       {
       IBQuery2->First();
       a = "#A2";  // говорит о том, что данные из 2й таблицы
       for (int j=1; j<IBQuery2->FieldCount; j++)
           {a = a + IBQuery2->Fields->Fields[j]->AsString + ';';}
       Socket->SendText(a);
       }
    }

//отправление данных 2й таблицы
 if (c == "All2")
    {
    IBQuery2->Next();
    if (!IBQuery2->Eof)
       {
       a = "#A2";
       for (int j=1; j<IBQuery2->FieldCount; j++)
           {a = a + IBQuery2->Fields->Fields[j]->AsString + ';';}
       Socket->SendText(a);
       }
    if (IBQuery2->Eof)
       {
       IBQuery3->First();
       a = "#A3";
       for (int j=1; j<IBQuery3->FieldCount; j++)
           {a = a + IBQuery3->Fields->Fields[j]->AsString + ';';}
       Socket->SendText(a);
       }
    }

//отправление данных 3й таблицы
 if (c == "All3")
    {
    IBQuery3->Next();
    if (!IBQuery3->Eof)
       {
       a = "#A3";
       for (int j=1; j<IBQuery3->FieldCount; j++)
           {a = a + IBQuery3->Fields->Fields[j]->AsString + ';';}
       Socket->SendText(a);
       }
    if (IBQuery3->Eof)
       {
       Memo1->Lines->Add("БД отправлена");
       } /**/
    }
 }
}


//__________ Отключение сервера ____________________________________________
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
 if (ServerSocket1->Active==true) {ServerSocket1->Close();}
}



void __fastcall TForm1::ServerSocket1ClientConnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
 Memo1->Lines->Add("Подключился клиент - IP: " + Socket->RemoteAddress + ", Socket: " + IntToStr(Socket->SocketHandle));
}
//---------------------------------------------------------------------------

