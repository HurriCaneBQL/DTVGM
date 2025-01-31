//----------------------------------------------------------------------------
#ifndef ModelParaDialogH
#define ModelParaDialogH
//----------------------------------------------------------------------------
#include <vcl\System.hpp>
#include <vcl\Windows.hpp>
#include <vcl\SysUtils.hpp>
#include <vcl\Classes.hpp>
#include <vcl\Graphics.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Controls.hpp>
#include <vcl\Buttons.hpp>
#include <vcl\ExtCtrls.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <DBCtrls.hpp>
#include <jpeg.hpp>
//----------------------------------------------------------------------------
class TModelParaDlg : public TForm
{
__published:        
	TButton *OKBtn;
	TButton *CancelBtn;
	TBevel *Bevel1;
        TDBGrid *DBGrid1;
        TDBNavigator *DBNavigator1;
        TButton *Button1;
        TComboBox *ComboBox1;
        TImage *Image1;
        TDBGrid *DBGrid2;
        TDBNavigator *DBNavigator2;
        TLabel *Label1;
        TCheckBox *CheckBox1;
        void __fastcall FormShow(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall DBGrid1DblClick(TObject *Sender);
        void __fastcall ComboBox1Change(TObject *Sender);
        void __fastcall OKBtnClick(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
private:
public:
	virtual __fastcall TModelParaDlg(TComponent* AOwner);
        void __fastcall TModelParaDlg::ShowTable_ModelParameters();
        void __fastcall TModelParaDlg::RegionCCFilter(String Outlet);
};
//----------------------------------------------------------------------------
extern PACKAGE TModelParaDlg *ModelParaDlg;
//----------------------------------------------------------------------------
#endif    
