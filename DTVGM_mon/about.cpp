//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "About.h"
#include <Math.hpp> //RandG
//#include <system.hpp>
#include <stdio.h>  //fprintf
#include <iostream.h>  //max(a,b),min(a,b)

//#include "wgsSCEUA.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
TAboutBox *AboutBox;

//Global Variants
//int iff;
//double r[97];
//int ix1,ix2,ix3;
//Global Variants

//---------------------------------------------------------------------
__fastcall TAboutBox::TAboutBox(TComponent *Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------

//---------------------------------------------------------------------------


void __fastcall TAboutBox::Button1Click(TObject *Sender)
{
/*
const int n = 11;
double arrin[n] = {46,55,13,42,94,5,17,70,3,2,1};

sort1(n,arrin);
for(int j=0;j<n;j++)
        //ShowMessage(String(indx[j]));
        ShowMessage(String(arrin[j]));
*/
}
//---------------------------------------------------------------------------

void __fastcall TAboutBox::Button2Click(TObject *Sender)
{
/*
const int n = 11;
double arrin[n] = {2,3,1,6,5,10,7,9,4,8,11};
int indx[n];
indexx(n, arrin, indx);

for(int j=0;j<n;j++)
        ShowMessage(String(indx[j]));
*/

}
//---------------------------------------------------------------------------

void __fastcall TAboutBox::Button3Click(TObject *Sender)
{
/*
        int iseed = 10;
//        ShowMessage("ran1 = " + String(ran1(iseed)));
        ShowMessage("random = " + String(random(1e8)/1.e8));
//        ShowMessage("gasdev =" +  String(gasdev(5)));
*/
}
//---------------------------------------------------------------------------


void __fastcall TAboutBox::Button4Click(TObject *Sender)
{
/*
//c  THIS IS THE MAIN PROGRAM CALLING SUBROUTINES SCEIN AND SCEUA
//      implicit real*8 (a-h,o-z)
//      dimension a(16), bl(16), bu(16), jseed(10)


const int npar = 16;   //���16���Ż�����
int maxn,kstop,nopt,ngs,iseed;//ideflt;
double pcento;
int npg,nps,nspl,mings,iniflg,iprint;
double a[npar], bl[npar], bu[npar];

//      iff = 0;
      int jseed[] = {2,3,5,7,11,13,17,19,23,29};
      int nrun;
      ShowMessage(" >>> ENTER THE MAIN PROGRAM <<< ");

      FunctSet();
      scein(a,bl,bu,nopt,maxn,kstop,pcento,iseed,ngs,npg,nps,nspl,mings,iniflg,iprint);

//      ShowMessage(" scein Finished --- ");
      if (iseed > 0)
        nrun = min(iseed,10);
      else
        nrun = 1;

      for(int i=0;i<nrun;i++)
      {
        if (nrun != 1) iseed = jseed[i];
        ShowMessage("@ SCE-UA Run Number = " + String(i) + "\n Random Seed Value = " +  String(iseed));
        sceua(a,bl,bu,nopt,maxn,kstop,pcento,iseed,ngs,npg,nps,nspl,mings,iniflg,iprint);
      }//end do i
      fclose(ipr);
*/
}
//---------------------------------------------------------------------------

void __fastcall TAboutBox::Button5Click(TObject *Sender)
{
/*
//������Question: Ϊʲô���ֺ������÷�ʽ�õ��Ľ��һ��������
        double rfunctn0,rfunctn1,rfunctn2;
        int nopt = 2;
        double x2[2] = {1,1};
        functn = &functn3;

        rfunctn0 = functn3(nopt,x2);
        rfunctn1 = (functn)(nopt,x2);
        rfunctn2 = (*functn)(nopt,x2);
        ShowMessage("rfunctn0 = " + String(rfunctn0));
        ShowMessage("*rfunctn1 = " + String(rfunctn2));
        ShowMessage("������Question: Ϊʲô���ֺ������÷�ʽ�õ��Ľ��һ��������");
*/
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

