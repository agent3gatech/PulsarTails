#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <TMath.h>
#include <string>
#include <iostream>

void LuminosityUL()
{

Double_t FDiff = 4.98e-12;  //cm^-2 s^-1 TeV^-1

Double_t EThresh = 0.316; //TeV

Double_t DistancePC = 1730; //pc 

Double_t Edot = 5.2e+34; //ergs

string PSRJ = "PSRJ0030+0451";

string CUT = "SOFT";

Double_t EMin = 1;
Double_t EMax = 10;
Double_t gamma = 3.8;
Double_t EnergyNorm = pow(EThresh,gamma);

Double_t EMaxMax = 30; //TeV
Double_t SpecInt;
Double_t SpecInt2;
Double_t SpecInt3;
Double_t ergtoTeV = 0.62415;
Double_t PCtoCM = 3.0857e+18;
Double_t Distance = DistancePC*PCtoCM;
Double_t LumGamma; 
Double_t fourpi = 12.5663706144;

//-----

cout << " --- " << PSRJ << " --- " << endl ;
cout << " Distance = " << DistancePC << " pc  " << endl ;
cout << " Edot = " << Edot << " ergs  " << endl ;
cout << " Gamma = " << gamma << " " << endl ;
cout << " EThresh = " << EThresh << " Tev " << endl ;
cout << " EMaxMax = " << EMaxMax << " TeV " << endl ;
cout << " EMin = " << EMin << " TeV " << endl ;
cout << " EMax = " << EMax << " TeV" << endl ;
cout << " CUT = " << CUT << " " << endl ;
cout << " FDiff_UL = " << FDiff << " cm^-2 s^-1 TeV^-1 " << endl ;
cout << " --------------------------------------- " << endl ;

//-----

Spectrum = new TF1("Spectrum", "[0]*[1]*TMath::Power(x,[2])", 0.01, 100);
Spectrum->SetParameters(FDiff,EnergyNorm,-1*gamma);

SpecInt = Spectrum->Integral(EMin,EMax);
SpecInt2 = Spectrum->Integral(EThresh,EMaxMax);

cout << "Flux_UL From " << EThresh << " to " << EMaxMax << "  = " << SpecInt2 << " cm^-2 s^-1"  << endl;
cout << "Flux_UL From " << EMin << " to " << EMax << "  = " << SpecInt << " cm^-2 s^-1"  <<endl;

Spectrum2 = new TF1("Spectrum2", "[0]*[1]*TMath::Power(x,[2])", 0.01, 100);
Spectrum2->SetParameters(FDiff,EnergyNorm,-1*gamma +1);

SpecInt3 = Spectrum2->Integral(EMin,EMax);

cout << "E_Flux_UL From " << EMin << " to " << EMax << "  = " << SpecInt3 << " TeV cm^-2 s^-1"  << endl;

LumGamma = SpecInt3*(1/ergtoTeV)*fourpi*Distance*Distance;
cout << "Lum_UL From " << EMin << " to " << EMax << "  = " << LumGamma << " erg  s^-1"  <<  endl;

Efficiency = LumGamma/Edot;
cout << "Gamma_Efficiency_UL From " << EMin << " to " << EMax << "  = " << Efficiency  << endl;

}
