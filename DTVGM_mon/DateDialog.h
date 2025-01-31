//----------------------------------------------------------------------------
#ifndef DateDialogH
#define DateDialogH
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
#include <ComCtrls.hpp>
#include <Mask.hpp>
//----------------------------------------------------------------------------
class TDateDlg : public TForm
{
__published:        
	TButton *OKBtn;
	TButton *CancelBtn;
	TBevel *Bevel1;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label1;
        TMaskEdit *MaskEdit1;
        TUpDown *UpDown1;
        TComboBox *ComboBox1;
        TComboBox *ComboBox2;
        TLabel *Label2;
        TMaskEdit *MaskEdit2;
        TUpDown *UpDown2;
        TComboBox *ComboBox3;
        TComboBox *ComboBox4;
        void __fastcall ComboBox1Change(TObject *Sender);
        void __fastcall ComboBox3Change(TObject *Sender);
        void __fastcall OKBtnClick(TObject *Sender);
        void __fastcall UpDown1Click(TObject *Sender, TUDBtnType Button);
        void __fastcall UpDown2Click(TObject *Sender, TUDBtnType Button);
        void __fastcall FormCreate(TObject *Sender);
private:
public:
	virtual __fastcall TDateDlg(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TDateDlg *DateDlg;
//----------------------------------------------------------------------------
#endif    
