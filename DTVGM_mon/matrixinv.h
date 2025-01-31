//************************************************************************//
//                              ��������	                          //
//************************************************************************//
#include "math.h"
#include "stdio.h"   //printf
int  MatrixINV(double **a,int n)
  {int i,j,k;
  int *is=new int[n];
  int *js=new int[n];
  double t,d;

  for (k=0;k<n;k++)
  {
        d=0.0;
        for (i=k;i<n;i++)
        	for (j=k;j<n;j++)
          {
          	if (fabs(a[i][j])>d)
            {
           		d=fabs(a[i][j]);
              is[k]=i;
              js[k]=j;
            }
          }//end i,j
        
        if (d+1.0==1.0)
          { free(is); free(js); printf("err**not inv\n");
            return(0);
          }
        
        if(is[k]!=k)
        for (j=0;j<n;j++)
        {
                t=a[k][j];
                a[k][j]=a[is[k]][j];
                a[is[k]][j]=t;
        }
        if(js[k]!=k)
        for (i=0;i<n;i++)
        {
                t=a[i][k];
                a[i][k]=a[i][js[k]];
                a[i][js[k]]=t;
        }
        
        
        a[k][k]=1.0/a[k][k];
        
        for (j=0;j<n;j++)
        {
                if(j!=k)
                a[k][j]=a[k][j]*a[k][k];
        }

        for (i=0;i<n;i++)
        {
        	if(i!=k)
        	{
          	for (j=0;j<n;j++)
            {
            	if(j!=k)
              {
              	a[i][j]=a[i][j]-a[i][k]*a[k][j];
              }
            }
          }
        }

        for (i=0;i<n;i++)
        {
        	if(i!=k)
          	a[i][k]=-a[i][k]*a[k][k];
        }
  } //end k
  
  for (k=n-1;k>=0;k--)
  {
  	if(js[k]!=k)
        for (j=0;j<n;j++)
        {
        	t=a[k][j];
          a[k][j]=a[js[k]][j];
          a[js[k]][j]=t;
        }
    if(is[k]!=k)
        for (i=0;i<n;i++)
        {
          t=a[i][k];
          a[i][k]=a[i][is[k]];
          a[i][is[k]]=t;
        }

  }// end k
  
 	free(is);
 	free(js);
 	return(1);

}//end MatrixINV

//==============================================================================
double HessianXY(double Xh, double Yh, double ZXY, double ZXhY, double ZXYh, double ZXhYh)
{//Calculate non-diagonal element value of Hessian Matrix by Difference Quotients
        return (ZXhYh - ZXYh - ZXhY + ZXY)/(Xh*Yh);
}//end
//==============================================================================

double HessianXY(double Xh, double ZX, double ZXh, double ZXhh)
{//Calculate diagonal element value of Hessian Matrix by Difference Quotients
        return (ZXhh - 2*ZXh + ZX)/(Xh*Xh);
}//end
//==============================================================================



