//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
#include <IBDatabase.hpp>
#include <IBCustomDataSet.hpp>
#include <IBTable.hpp>
#include <IBQuery.hpp>
#include <ScktComp.hpp>



//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TComboBox *ComboBox1;
        TIBDatabase *IBDatabase1;
        TIBTransaction *IBTransaction1;
        TDataSource *DataSource2;
        TDataSource *DataSource3;
        TIBQuery *IBQuery1;
        TIBQuery *IBQuery2;
        TIBQuery *IBQuery3;
        TDataSource *DataSource1;
        TIBQuery *IBQuery4;
        TServerSocket *ServerSocket1;
        TMemo *Memo1;
        TDataSource *DataSource4;
        TIBQuery *IBQuery5;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ServerSocket1ClientRead(TObject *Sender,
          TCustomWinSocket *Socket);
        void __fastcall ServerSocket1ClientConnect(TObject *Sender,
          TCustomWinSocket *Socket);

private:	// User declarations
public:		// User declarations

        void OpenTable1();
        void OpenTable2();
        void OpenTable3();
        void Select(String s);
        void Sort(String s);
        void Add(String s);
        void Del(String s);
        void Upd(String s);
        void Fen(String s);
        void Fnd(String s);
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
