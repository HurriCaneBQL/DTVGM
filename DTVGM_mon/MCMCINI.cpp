//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MCMCINI.h"
#include "DM1.h"
#include "DTVGM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "DateDialog"
#pragma resource "*.dfm"
TDlgMCMCINI *DlgMCMCINI;
//---------------------------------------------------------------------------
__fastcall TDlgMCMCINI::TDlgMCMCINI(TComponent* Owner)
        : TDateDlg(Owner)
{
}
//---------------------------------------------------------------------------






void __fastcall TDlgMCMCINI::OKBtnClick(TObject *Sender)
{
        String strParaEn;
        if(DM->ADOTable0->Filtered) DM->ADOTable0->Filtered = false;
        DM->ADOTable0->Active = false;
        DM->ADOTable0->TableName = "MCMCini";
        DM->ADOTable0->Active = true;
        DM->ADOTable0->First();
        
              for(int i=0;i<DM->ADOTable0->RecordCount;i++)
                {DM->ADOTable0->Edit();
                 strParaEn = DM->ADOTable0->FieldValues["ITEM"];
                 if(strParaEn == "g1")
                        DM->ADOTable0->FieldValues["Value"] = BoolToStr(CBox_g1->Checked,true);
                 else if (strParaEn == "g2")
                        DM->ADOTable0->FieldValues["Value"] = BoolToStr(CBox_g2->Checked,true);
                 else if (strParaEn == "Kr")
                        DM->ADOTable0->FieldValues["Value"] = BoolToStr(CBox_Kr->Checked,true);
                 else if (strParaEn == "KAW")
                        DM->ADOTable0->FieldValues["Value"] = BoolToStr(CBox_KAW->Checked,true);
                 else if (strParaEn == "AW0")
                        DM->ADOTable0->FieldValues["Value"] = BoolToStr(CBox_AW0->Checked,true);
                 else if (strParaEn == "ProposalDistribution")
                        DM->ADOTable0->FieldValues["Value"] = IntToStr(RadioGroup2->ItemIndex);
                 else if (strParaEn == "Samples")
                        DM->ADOTable0->FieldValues["Value"] = MaskEdit_Samples->Text;
                 else if(strParaEn == "Sigma")
                        DM->ADOTable0->FieldValues["Value"] = MaskEdit_Sigma->Text;
                 else if(strParaEn == "DateBegin")
                        DM->ADOTable0->FieldValues["Value"] = MaskEdit1->Text+"-"+IntToStrF(ComboBox1->Text.ToInt(),2)+"-"+IntToStrF(ComboBox2->Text.ToInt(),2);
                 else if(strParaEn == "DateEnd")
                        DM->ADOTable0->FieldValues["Value"] = MaskEdit2->Text+"-"+IntToStrF(ComboBox3->Text.ToInt(),2)+"-"+IntToStrF(ComboBox4->Text.ToInt(),2);

                 DM->ADOTable0->Next();
                }

        gdateBegin = StrToDate(MaskEdit1->Text + "-" + ComboBox1->Text + "-" + ComboBox2->Text);
        gdateEnd   = StrToDate(MaskEdit2->Text + "-" + ComboBox3->Text + "-" + ComboBox4->Text);
        if(gdateBegin > gdateEnd)
                {ShowMessage("Begin Date ("+ DateToStr(gdateBegin) + ") > End Date ("+ DateToStr(gdateEnd) + "), Pls Check!");
                 ModalResult = mrCancel;
                 return;
                }

}
//---------------------------------------------------------------------------

void __fastcall TDlgMCMCINI::RadioGroup2Click(TObject *Sender)
{
        switch (RadioGroup2->ItemIndex)
        {
                case 0:
                        MaskEdit_Sigma->Text = 0.05;
                        break;
                case 1:
                        MaskEdit_Sigma->Text = 0.05;
                        break;
                case 2:
                        MaskEdit_Sigma->Text = 3;
                        break;
                case 3:
                        MaskEdit_Sigma->Text = 3;
                        break;

        }
}
//---------------------------------------------------------------------------

