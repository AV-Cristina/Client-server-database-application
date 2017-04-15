//---------------------------------------------------------------------------

#ifndef Unit4H
#define Unit4H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <ExtCtrls.hpp>
#include <IBCustomDataSet.hpp>
#include <IBQuery.hpp>
//---------------------------------------------------------------------------
class TForm4 : public TForm
{
__published:	// IDE-managed Components
        TButton *Button1;
        TGroupBox *GroupBox1;
        TLabel *Label1;
        TLabel *Label2;
        TComboBox *ComboBox1;
        TGroupBox *GroupBox3;
        TRadioGroup *RadioGroup1;
        TEdit *Edit1;
        TComboBox *ComboBox2;
        TEdit *Edit2;
        TLabel *Label3;
        TLabel *Label4;
        TCheckBox *CheckBox1;
        TCheckBox *CheckBox2;
        TStringGrid *StringGrid1;
        void __fastcall Button1Click(TObject *Sender);

private:	// User declarations
public:		// User declarations
        __fastcall TForm4(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif
