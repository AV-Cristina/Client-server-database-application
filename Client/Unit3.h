//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "TOOLEDIT.hpp"
#include <Mask.hpp>
#include "ToolEdit.hpp"
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label2;
        TGroupBox *GroupBox1;
        TLabel *Label6;
        TLabel *Label17;
        TEdit *Edit5;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TButton *Button1;
        TEdit *Edit1;
        TEdit *Edit3;
        TEdit *Edit4;
        TEdit *Edit2;
        TLabel *Label1;
        TButton *Button2;
        TDateTimePicker *DateTimePicker1;
        TDateTimePicker *DateTimePicker2;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Edit3KeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
        __fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
 