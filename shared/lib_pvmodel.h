/*******************************************************************************************************
*  Copyright 2017 Alliance for Sustainable Energy, LLC
*
*  NOTICE: This software was developed at least in part by Alliance for Sustainable Energy, LLC
*  (�Alliance�) under Contract No. DE-AC36-08GO28308 with the U.S. Department of Energy and the U.S.
*  The Government retains for itself and others acting on its behalf a nonexclusive, paid-up,
*  irrevocable worldwide license in the software to reproduce, prepare derivative works, distribute
*  copies to the public, perform publicly and display publicly, and to permit others to do so.
*
*  Redistribution and use in source and binary forms, with or without modification, are permitted
*  provided that the following conditions are met:
*
*  1. Redistributions of source code must retain the above copyright notice, the above government
*  rights notice, this list of conditions and the following disclaimer.
*
*  2. Redistributions in binary form must reproduce the above copyright notice, the above government
*  rights notice, this list of conditions and the following disclaimer in the documentation and/or
*  other materials provided with the distribution.
*
*  3. The entire corresponding source code of any redistribution, with or without modification, by a
*  research entity, including but not limited to any contracting manager/operator of a United States
*  National Laboratory, any institution of higher learning, and any non-profit organization, must be
*  made publicly available under this license for as long as the redistribution is made available by
*  the research entity.
*
*  4. Redistribution of this software, without modification, must refer to the software by the same
*  designation. Redistribution of a modified version of this software (i) may not refer to the modified
*  version by the same designation, or by any confusingly similar designation, and (ii) must refer to
*  the underlying software originally provided by Alliance as �System Advisor Model� or �SAM�. Except
*  to comply with the foregoing, the terms �System Advisor Model�, �SAM�, or any confusingly similar
*  designation may not be used to refer to any modified version of this software or any modified
*  version of the underlying software originally provided by Alliance without the prior written consent
*  of Alliance.
*
*  5. The name of the copyright holder, contributors, the United States Government, the United States
*  Department of Energy, or any of their employees may not be used to endorse or promote products
*  derived from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
*  IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
*  FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER,
*  CONTRIBUTORS, UNITED STATES GOVERNMENT OR UNITED STATES DEPARTMENT OF ENERGY, NOR ANY OF THEIR
*  EMPLOYEES, BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
*  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
*  IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
*  THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************************************/

#ifndef __pvmodulemodel_h
#define __pvmodulemodel_h

#include <string>

class pvcelltemp_t;
class pvpower_t;

class pvinput_t
{
public:
	pvinput_t();
	pvinput_t( double ib, double id, double ig, double ip, 
		double ta, double td, double ws, double wd, double patm,
		double zen, double inc, 
		double elv, double tlt, double azi,
		double hrday, int rmode , bool up);

	double Ibeam; // beam irradiance, W/m2
	double Idiff; // sky diffuse irradiance, W/m2
	double Ignd; // ground reflected irradiance, W/m2
	double poaIrr; // plane of array irradiance, W/m2
	double Tdry; // dry bulb temp, C
	double Tdew; // dew point temp, C
	double Wspd; // wind speed, m/s
	double Wdir; // wind direction, deg +from north
	double Patm; // atmospheric pressure, millibar
	double Zenith; // zenith angle, deg
	double IncAng; // incidence angle on surface, deg
	double Elev; // site elevation, m
	double Tilt; // surface tilt angle, deg +from horizontal
	double Azimuth; // surface azimuth angle, deg +from north (E=90,S=180)
	double HourOfDay; // hour of the day 0=12am, 23=11pm
	int radmode; //radiation mode
	bool usePOAFromWF; // use poa directly flag
};

class pvoutput_t
{
public:
	pvoutput_t();
	pvoutput_t( double p, double v,
		double c, double e, 
		double voc, double isc, double t );

	double Power; // output power, Watts
	double Voltage; // operating voltage, V
	double Current; // operating current, A
	double Efficiency; // operating efficiency, fraction (0..1)
	double Voc_oper; // open circuit voltage at operating condition, V
	double Isc_oper; // short circuit current at operating condition, A
	double CellTemp; // cell temperature, 'C
};

class pvmodule_t; // forward decl

class pvcelltemp_t
{
protected:
	std::string m_err;
public:
	
	virtual bool operator() ( pvinput_t &input, pvmodule_t &module, double opvoltage, double &Tcell ) = 0;
	std::string error();
};

class pvmodule_t
{
protected:
	std::string m_err;
public:

	virtual double AreaRef() = 0;
	virtual double VmpRef() = 0;
	virtual double ImpRef() = 0;
	virtual double VocRef() = 0;
	virtual double IscRef() = 0;

	virtual bool operator() ( pvinput_t &input, double TcellC, double opvoltage, pvoutput_t &output ) = 0;
	std::string error();
};



class spe_module_t : public pvmodule_t
{
public:
	double VmpNominal;
	double VocNominal;
	double Area; // m2
	double Gamma; // temp coefficient %/'C
	int Reference; // specification of reference condition.  valid values: 0..4
	double fd; // diffuse fraction
	double Eff[5]; // as fractions
	double Rad[5]; // W/m2

	spe_module_t( );	
	static double eff_interpolate( double irrad, double rad[5], double eff[5] );
	
	double WattsStc() { return Eff[Reference] * Rad[Reference] * Area; }

	virtual double AreaRef() { return Area; }
	virtual double VmpRef() { return VmpNominal; }
	virtual double ImpRef() { return WattsStc()/VmpRef(); }
	virtual double VocRef() { return VocNominal; }
	virtual double IscRef() { return ImpRef()*1.3; }
	virtual bool operator() ( pvinput_t &input, double TcellC, double opvoltage, pvoutput_t &output);
};

#define AOI_MIN 0.5
#define AOI_MAX 89.5

double current_5par( double V, double IMR, double A, double IL, double IO, double RS, double RSH );
double openvoltage_5par( double Voc0, double a, double IL, double IO, double Rsh );
double maxpower_5par( double Voc_ubound, double a, double Il, double Io, double Rs, double Rsh, double *Vmp=0, double *Imp=0 );
double air_mass_modifier( double Zenith_deg, double Elev_m, double a[5] );
double transmittance( double theta1_deg, /* incidence angle of incoming radiation (deg) */
		double n_cover,  /* refractive index of cover material, n_glass = 1.586 */
		double n_incoming, /* refractive index of incoming material, typically n_air = 1.0 */
		double k,        /* proportionality constant assumed to be 4 (1/m) for derivation of Bouguer's law (set to zero to skip bougeur's law */
		double l_thick,  /* material thickness (set to zero to skip Bouguer's law */
		double *_theta2_deg = 0 ); /* thickness of cover material (m), usually 2 mm for typical module */
double iam( double theta_deg, bool ar_glass ); // incidence angle modifier factor relative to normal incidence
double iam_nonorm( double theta_deg, bool ar_glass );  // non-normalized cover loss (typically use one above!)


#endif
