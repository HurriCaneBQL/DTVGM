//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop


#include <stdio.h>  //FILE *fpdata;
#include "HydroGraph.h"
#include "iostream.h"  //max(a,b),min(a,b)
//#include "DM1.h"
//#include "struct.h"  //MAX(a,b),MIN(a,b)

typedef char char50[50]; //长度为50的char
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmHydroGraph *frmHydroGraph;
//---------------------------------------------------------------------------
__fastcall TfrmHydroGraph::TfrmHydroGraph(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TfrmHydroGraph::FormCreate(TObject *Sender)
{

/*
        String strTable,strQuery,strFieldName,strSaveFile;
        char *sFile;
        int nRows;
        strTable = "MonFlow";
        strQuery = "Select * FROM " + strTable + " WHERE station = 'station'"; //只需要得到字段名
        DM->ADOQuery1->SQL->Clear();
        DM->ADOQuery1->SQL->Add(strQuery);
        DM->ADOQuery1->Prepared;  //大大加快查询速度
        DM->ADOQuery1->Active=true;

        TStringList *TempList = new TStringList; // declare the list
        try{
                DM->ADOQuery1->GetFieldNames(TempList);
                StringGrid1->ColCount = TempList->Count + 1;
                StringGrid1->Cells[0][0] = "ID";
                for(int i=0;i<TempList->Count;i++)
                {
                        StringGrid1->Cells[i + 1][0] = TempList->Strings[i];   //Cells[col][row]
                }
        }
        __finally{
        delete TempList; // destroy the list object
        }

        //读取表DTVGMlog最后一条记录，导入该条记录的数据文件
        strQuery = "Select TOP 1 SaveFile from DTVGMlog ORDER by RunEnd DESC"; //只需要得到字段名
        DM->ADOQuery1->SQL->Clear();
        DM->ADOQuery1->SQL->Add(strQuery);
        DM->ADOQuery1->Prepared;  //大大加快查询速度
        DM->ADOQuery1->Active=true;
        strSaveFile = DM->ADOQuery1->FieldValues["SaveFile"];
        nRows = ImportFile(StringGrid1,strSaveFile.c_str());
        Label1->Caption = IntToStr(nRows) + ": " + strSaveFile;
*/
        //RadioButton1->Checked = true;//HydroGraph(0);
        RadioButton1Click(Sender);

        StringGrid1->Width = this->Width - 10;
        Notebook1->Width = this->Width - 10;
        Chart1->Width = Notebook1->Width;
        Chart2->Width = Notebook1->Width;

}
//---------------------------------------------------------------------------

void __fastcall TfrmHydroGraph::BitBtn1Click(TObject *Sender)
{
/*
     int nRows;
     char* sFile;
     DM->OpenDialog->DefaultExt="txt";
     DM->OpenDialog->FileName="*.txt";
     DM->OpenDialog->Filter="Text Files(*.txt)|*.txt";
     DM->OpenDialog->InitialDir=Application->ExeName;
     DM->OpenDialog->Title="选择导入数据文件";
     DM->OpenDialog->Options.Clear();
     DM->OpenDialog->Options<<ofFileMustExist
                         <<ofHideReadOnly
                         <<ofNoChangeDir
                         <<ofCreatePrompt;
     if(DM->OpenDialog->Execute())
     {
        sFile=DM->OpenDialog->FileName.c_str(); //AnsiString转为char
       // Label1->Caption = sFile;
        nRows = ImportFile(StringGrid1,sFile);
        Label1->Caption = IntToStr(nRows) + ": " + sFile;
        RadioButton1Click(Sender);//RadioButton1->Checked = true;//HydroGraph(0);
     }
*/
}
//---------------------------------------------------------------------------

extern int __fastcall ImportFile(TStringGrid *StringGrid,char *txtFileName)
{//然后导入文本数据到 StringGrid
int nFieldCount,FieldDataType,i;
int k=0;
FILE *fpdata;

StringGrid->RowCount = 2;
nFieldCount = StringGrid->ColCount - 1;

 if(FileExists(txtFileName))
 {
   if((fpdata=fopen(txtFileName,"r"))==NULL)
   {
     fprintf(stderr,"Cannot open input file.\n");
     return -2;
   }
 }
 else
 {
  ShowMessage(AnsiString("Couldnot find the file:")+txtFileName+".");
  return -1;
 }


char50* chdata = new char50[nFieldCount];  //生成nFieldCount个长度为50的char类型

while(!feof(fpdata))//for(;!feof(fpdata);)
{
        k += 1;
        StringGrid->RowCount = k + 1;
        StringGrid->Cells[0][k] = IntToStr(k);  //Cells[Acol][Arow]
        for(i = 0; i < nFieldCount; i++)
        { //读取数据，写入表中
                fscanf(fpdata,"%s",&chdata[i]);
                StringGrid->Cells[i + 1][k] = chdata[i];
        }//for(i = 0; i < nFieldCount; i++)
        //ShowMessage((String)chdata[1] + "-" + (String)chdata[2]);
}//for(;!feof(fpdata);)

if(StringGrid->Cells[2][k]==StringGrid->Cells[2][k - 1]&&StringGrid->Cells[3][k]==StringGrid->Cells[3][k - 1])
{
        StringGrid->RowCount -= 1;
        k -= 1;
}

fclose(fpdata);
delete[] chdata;
return k;
}  //importfile

void __fastcall TfrmHydroGraph::HydroGraph()
{
/*
        int i,j; //i:col,j:row
        int iqobs,iqcal,iMeanGridRain,iAWmean,iSurfaceRunoff,iSubsurfaceRunoff,iRunoff,iETa;

        //Chart1->RemoveSeries(Series1);
        for(i=1;i<StringGrid1->ColCount;i++)
        {
                if(LowerCase(StringGrid1->Cells[i][0]) == "qobs") iqobs = i;
                else if(LowerCase(StringGrid1->Cells[i][0]) == "qcal") iqcal = i;
                else if(LowerCase(StringGrid1->Cells[i][0]) == "meangridrain") iMeanGridRain = i;
                else if(LowerCase(StringGrid1->Cells[i][0]) == "awmean") iAWmean = i;
                else if(LowerCase(StringGrid1->Cells[i][0]) == "surfacerunoff") iSurfaceRunoff = i;
                else if(LowerCase(StringGrid1->Cells[i][0]) == "subsurfacerunoff") iSubsurfaceRunoff = i;
                else if(LowerCase(StringGrid1->Cells[i][0]) == "runoff") iRunoff = i;
                else if(LowerCase(StringGrid1->Cells[i][0]) == "eta") iETa = i;
        }

        switch(iGraph)
        {
         case 0:
                //TLineSeries *LineSeries1;
                //LineSeries1->ParentChart = Chart1;
                //Chart1->AddSeries(TLineSeries *LineSeries1);
                Notebook1->PageIndex = 0;
                Series_qobs->Clear();
                Series_qcal->Clear();
                Series_P->Clear();
                Series_sm->Clear();

                //Chart1->Title->Text->Clear();
                //Chart1->Title->Text->Add("降水－径流过程线");
                //Series1->Style<<tssDenyChangeType; //不出错，但是没有看到作用

                for(j=1;j<StringGrid1->RowCount;j++)
                {
                        Series_qobs->AddXY(StringGrid1->Cells[0][j].ToInt(),StringGrid1->Cells[iqobs][j].ToDouble(),"",clBlack);
                        Series_qcal->AddXY(StringGrid1->Cells[0][j].ToInt(),StringGrid1->Cells[iqcal][j].ToDouble(),"",clRed);
                        Series_P->AddXY(StringGrid1->Cells[0][j].ToInt(),StringGrid1->Cells[iMeanGridRain][j].ToDouble(),"",clGreen);
                        Series_sm->AddXY(StringGrid1->Cells[0][j].ToInt(),StringGrid1->Cells[iAWmean][j].ToDouble(),"",clBlue);
                }
                Chart1->LeftAxis->Maximum = int(max(Series_qobs->MaxYValue(),Series_qcal->MaxYValue())*1.5);
                Chart1->RightAxis->Maximum = int(max(Series_P->MaxYValue(),Series_sm->MaxYValue())*1.5);
                break;
         case 1:
                Notebook1->PageIndex = 1;
                Series_Rd->Clear();
                Series_Rs->Clear();
                Series_R->Clear();
                Series_ETa->Clear();

                //Chart1->Title->Text->Clear();
                //Chart1->Title->Text->Add("地表/地下径流/蒸散发");
                for(j=1;j<StringGrid1->RowCount;j++)
                {
                        Series_R->AddXY(StringGrid1->Cells[0][j].ToInt(),StringGrid1->Cells[iRunoff][j].ToDouble(),"",clTeeColor);
                        Series_ETa->AddXY(StringGrid1->Cells[0][j].ToInt(),StringGrid1->Cells[iETa][j].ToDouble(),"",clTeeColor);
                        Series_Rd->AddXY(StringGrid1->Cells[0][j].ToInt(),StringGrid1->Cells[iSurfaceRunoff][j].ToDouble(),"",clTeeColor);
                        Series_Rs->AddXY(StringGrid1->Cells[0][j].ToInt(),StringGrid1->Cells[iSubsurfaceRunoff][j].ToDouble(),"",clTeeColor);
                }
                Chart2->LeftAxis->Maximum = int(Series_R->MaxYValue()*1.5);
                Chart2->RightAxis->Maximum = int(Series_ETa->MaxYValue()*1.5);
                Chart2->Repaint();
                break;
        }//switch
*/

float pcp,qobs,qcal,sm,ep,eta,tavg,tmax,tmin;
float etau,etad,awd,rud,rgg;
char sgauge[20],sdate[20];
char *s_graphfile;

  FILE *fpgraph;
  s_graphfile = "\dtvgmgraph.txt";
  if (FileExists(s_graphfile))
        {
        if((fpgraph=fopen(s_graphfile,"r"))==NULL)
        {
        fprintf(stderr, "Cannot open input file.\n");
        return ;
        }
        }

  else
        {
        ShowMessage(AnsiString("Couldn't find the file: ")+ s_graphfile + "." );
        return;
        }

   Notebook1->PageIndex = 0;
   Series_qobs->Clear();
   Series_qcal->Clear();
   Series_P->Clear();
   Series_sm->Clear();

  for(;!feof(fpgraph);)
  {

   fscanf(fpgraph,"%s%s%f%f%f%f%f%f%f%f%f%f%f%f%f%f" ,&sgauge,&sdate,&qobs,&qcal,&pcp,&sm,&ep,&eta,&tavg,&tmax,&tmin,&etau,&etad,&awd,&rud,&rgg);

   Series_P->AddXY(StrToDate(sdate),pcp,"",clTeeColor);
   Series_qobs->AddXY(StrToDate(sdate),qobs,"",clTeeColor);
   Series_qcal->AddXY(StrToDate(sdate),qcal,"",clTeeColor);
   Series_sm->AddXY(StrToDate(sdate),sm,"",clTeeColor);
  }
  fclose(fpgraph);


  //Chart1->RightAxis->Maximum = int(Series4->MaxYValue()*3.5);
   Chart1->LeftAxis->Maximum = int(max(Series_qobs->MaxYValue(),Series_qcal->MaxYValue())*1.5);
   Chart1->RightAxis->Maximum = int(max(Series_P->MaxYValue(),Series_sm->MaxYValue())*1.5);

}
void __fastcall TfrmHydroGraph::RadioButton1Click(TObject *Sender)
{

        HydroGraph();
       // HydroGraph(0); //实测流量，模拟流量，降水量，土壤湿度
}
//---------------------------------------------------------------------------

void __fastcall TfrmHydroGraph::RadioButton2Click(TObject *Sender)
{

       // HydroGraph(1); //地表径流，地下径流，总径流，蒸发
}
//---------------------------------------------------------------------------


