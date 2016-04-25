/*
#include "Fit/Chi2FCN.h"

class MyFCN: public ROOT::Fit::Chi2Function{
  public:
    MyFCN(const ROOT::Fit::BinData&  data, const ROOT::Fit::Chi2Function::IModelFunction&  func): ROOT::Fit::Chi2Function(data,func) {}
    ~MyFCN(){}

    private:
    virtual double	DoEval(const double* x) const{
        double ret = ROOT::Fit::Chi2Function::DoEval(x);
        std::cout << "MyFCN::DoEval" << ret << endl;
        assert(0);
        return ret;
    }
};

*/
#include "Fit/Fitter.h"
#include "Fit/BinData.h"
#include "Fit/Chi2FCN.h"
#include "TH1.h"
#include "TList.h"
#include "Math/WrappedMultiTF1.h"
#include "Math/FitMethodFunction.h"
#include "HFitInterface.h"
#include "TCanvas.h"
#include "TStyle.h"


// definition of shared parameter
// background function 
int iparB[2] = { 0,      // exp amplitude in B histo
                 2    // exp common parameter 
};

// signal + background function 
int iparSB[5] = { 1, // exp amplitude in S+B histo
                  2, // exp common parameter
                  3, // gaussian amplitude
                  4, // gaussian mean
                  5  // gaussian sigma
};

class MyFCN : public ROOT::Math::FitMethodFunction { 

public:
   MyFCN( int dim, int npoints, ROOT::Math::FitMethodFunction & f1,  ROOT::Math::FitMethodFunction & f2) :
      ROOT::Math::FitMethodFunction(dim,npoints),
      fChi2_1(&f1), fChi2_2(&f2) {}


   ROOT::Math::IMultiGenFunction * Clone() const { 
      // copy using default copy-ctor
      // i.e. function pointer will be copied (and not the functions)
      return new MyFCN(*this);   
   }

   double  DataElement(const double *par, unsigned int ipoint, double *g = 0) const { 
      // implement evaluation of single chi2 element
      double p1[2];
      for (int i = 0; i < 2; ++i) p1[i] = par[iparB[i] ];

      double p2[5]; 
      for (int i = 0; i < 5; ++i) p2[i] = par[iparSB[i] ];

      double g1[2]; 
      double g2[5];
      double value = 0; 
      if (g != 0) { 
         for (int i = 0; i < 6; ++i) g[i] = 0; 
      }

      if (ipoint < fChi2_1->NPoints() ) {
         if (g != 0) { 
            value = fChi2_1->DataElement(p1, ipoint, g1);
            // update gradient values
            for (int i= 0; i < 2; ++i) g[iparB[i]] = g1[i];         
         }
         else 
            // no need to compute gradient in this case
            value = fChi2_1->DataElement(p1, ipoint);
      }
      else { 
         unsigned int jpoint = ipoint- fChi2_1->NPoints();
         assert (jpoint < fChi2_2->NPoints() );
         if ( g != 0) { 
            value =  fChi2_2->DataElement(p2, jpoint, g2);
            // update gradient values
            for (int i= 0; i < 5; ++i) g[iparSB[i]] = g2[i];
         }
         else 
            // no need to compute gradient in this case
            value =  fChi2_2->DataElement(p2, jpoint);
      }
        
      return value; 
      
   }


   // needed if want to use Fumili or Fumili2
   virtual Type_t Type() const { return ROOT::Math::FitMethodFunction::kLeastSquare; }

private:
   // parameter vector is first background (in common 1 and 2) and then is signal (only in 2)
   virtual double DoEval (const double *par) const {
      double p1[2];
      for (int i = 0; i < 2; ++i) p1[i] = par[iparB[i] ];

      double p2[5]; 
      for (int i = 0; i < 5; ++i) p2[i] = par[iparSB[i] ];

      return (*fChi2_1)(p1) + (*fChi2_2)(p2);
   } 

   const  ROOT::Math::FitMethodFunction * fChi2_1;
   const  ROOT::Math::FitMethodFunction * fChi2_2;
};
