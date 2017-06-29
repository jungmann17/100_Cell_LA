/* Created by Language version: 6.2.0 */
/* NOT VECTORIZED */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "scoplib_ansi.h"
#undef PI
#define nil 0
#include "md1redef.h"
#include "section.h"
#include "nrniv_mf.h"
#include "md2redef.h"
 
#if METHOD3
extern int _method3;
#endif

#if !NRNGPU
#undef exp
#define exp hoc_Exp
extern double hoc_Exp(double);
#endif
 
#define _threadargscomma_ /**/
#define _threadargs_ /**/
 
#define _threadargsprotocomma_ /**/
#define _threadargsproto_ /**/
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 static double *_p; static Datum *_ppvar;
 
#define t nrn_threads->_t
#define dt nrn_threads->_dt
#define srcid _p[0]
#define destid _p[1]
#define Cdur_nmda _p[2]
#define AlphaTmax_nmda _p[3]
#define Beta_nmda _p[4]
#define Erev_nmda _p[5]
#define gbar_nmda _p[6]
#define Cdur_ampa _p[7]
#define AlphaTmax_ampa _p[8]
#define Beta_ampa _p[9]
#define Erev_ampa _p[10]
#define gbar_ampa _p[11]
#define Cainf _p[12]
#define pooldiam _p[13]
#define z _p[14]
#define neuroM _p[15]
#define tauCa _p[16]
#define P0 _p[17]
#define fCa _p[18]
#define lambda1 _p[19]
#define lambda2 _p[20]
#define threshold1 _p[21]
#define threshold2 _p[22]
#define initW _p[23]
#define fmax _p[24]
#define fmin _p[25]
#define thr_rp _p[26]
#define facfactor _p[27]
#define f _p[28]
#define tauF _p[29]
#define d1 _p[30]
#define tauD1 _p[31]
#define d2 _p[32]
#define tauD2 _p[33]
#define inmda _p[34]
#define g_nmda _p[35]
#define on_nmda _p[36]
#define W_nmda _p[37]
#define iampa _p[38]
#define g_ampa _p[39]
#define on_ampa _p[40]
#define limitW _p[41]
#define ICa _p[42]
#define iCatotal _p[43]
#define Wmax _p[44]
#define Wmin _p[45]
#define maxChange _p[46]
#define normW _p[47]
#define scaleW _p[48]
#define tempW _p[49]
#define pregid _p[50]
#define postgid _p[51]
#define F _p[52]
#define D1 _p[53]
#define D2 _p[54]
#define r_nmda _p[55]
#define r_ampa _p[56]
#define capoolcon _p[57]
#define W _p[58]
#define eca _p[59]
#define t0 _p[60]
#define Afactor _p[61]
#define dW_ampa _p[62]
#define rp _p[63]
#define tsyn _p[64]
#define fa _p[65]
#define Dr_nmda _p[66]
#define Dr_ampa _p[67]
#define Dcapoolcon _p[68]
#define DW _p[69]
#define _g _p[70]
#define _tsav _p[71]
#define _nd_area  *_ppvar[0]._pval
#define _ion_eca	*_ppvar[2]._pval
 
#if MAC
#if !defined(v)
#define v _mlhv
#endif
#if !defined(h)
#define h _mlhh
#endif
#endif
 
#if defined(__cplusplus)
extern "C" {
#endif
 static int hoc_nrnpointerindex =  -1;
 /* external NEURON variables */
 /* declaration of user functions */
 static double _hoc_DA2();
 static double _hoc_DA1();
 static double _hoc_eta();
 static double _hoc_omega();
 static double _hoc_sfunc();
 static double _hoc_unirand();
 static int _mechtype;
extern void _nrn_cacheloop_reg(int, int);
extern void hoc_register_prop_size(int, int, int);
extern void hoc_register_limits(int, HocParmLimits*);
extern void hoc_register_units(int, HocParmUnits*);
extern void nrn_promote(Prop*, int, int);
extern Memb_func* memb_func;
 extern Prop* nrn_point_prop_;
 static int _pointtype;
 static void* _hoc_create_pnt(_ho) Object* _ho; { void* create_point_process();
 return create_point_process(_pointtype, _ho);
}
 static void _hoc_destroy_pnt();
 static double _hoc_loc_pnt(_vptr) void* _vptr; {double loc_point_process();
 return loc_point_process(_pointtype, _vptr);
}
 static double _hoc_has_loc(_vptr) void* _vptr; {double has_loc_point();
 return has_loc_point(_vptr);
}
 static double _hoc_get_loc_pnt(_vptr)void* _vptr; {
 double get_loc_point_process(); return (get_loc_point_process(_vptr));
}
 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _p = _prop->param; _ppvar = _prop->dparam;
 }
 static void _hoc_setdata(void* _vptr) { Prop* _prop;
 _prop = ((Point_process*)_vptr)->_prop;
   _setdata(_prop);
 }
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 0,0
};
 static Member_func _member_func[] = {
 "loc", _hoc_loc_pnt,
 "has_loc", _hoc_has_loc,
 "get_loc", _hoc_get_loc_pnt,
 "DA2", _hoc_DA2,
 "DA1", _hoc_DA1,
 "eta", _hoc_eta,
 "omega", _hoc_omega,
 "sfunc", _hoc_sfunc,
 "unirand", _hoc_unirand,
 0, 0
};
#define DA2 DA2_pyrD2pyrD_STFD
#define DA1 DA1_pyrD2pyrD_STFD
#define eta eta_pyrD2pyrD_STFD
#define omega omega_pyrD2pyrD_STFD
#define sfunc sfunc_pyrD2pyrD_STFD
#define unirand unirand_pyrD2pyrD_STFD
 extern double DA2( double , double );
 extern double DA1( double , double );
 extern double eta( double );
 extern double omega( double , double , double );
 extern double sfunc( double );
 extern double unirand( );
 /* declare global and static user variables */
#define Beta2 Beta2_pyrD2pyrD_STFD
 double Beta2 = 0.0001;
#define Beta1 Beta1_pyrD2pyrD_STFD
 double Beta1 = 0.001;
#define DA_S DA_S_pyrD2pyrD_STFD
 double DA_S = 1.3;
#define DA_t3 DA_t3_pyrD2pyrD_STFD
 double DA_t3 = 0.9;
#define DA_t2 DA_t2_pyrD2pyrD_STFD
 double DA_t2 = 0.8;
#define DA_t1 DA_t1_pyrD2pyrD_STFD
 double DA_t1 = 1.2;
#define DAstop2 DAstop2_pyrD2pyrD_STFD
 double DAstop2 = 36000;
#define DAstart2 DAstart2_pyrD2pyrD_STFD
 double DAstart2 = 35900;
#define DAstop1 DAstop1_pyrD2pyrD_STFD
 double DAstop1 = 40000;
#define DAstart1 DAstart1_pyrD2pyrD_STFD
 double DAstart1 = 39500;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 "d2", 0, 1,
 "d1", 0, 1,
 "f", 0, 1e+09,
 "tauD2", 1e-09, 1e+09,
 "tauD1", 1e-09, 1e+09,
 "tauF", 1e-09, 1e+09,
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "Beta1_pyrD2pyrD_STFD", "/ms",
 "Beta2_pyrD2pyrD_STFD", "/ms",
 "srcid", "1",
 "destid", "1",
 "Cdur_nmda", "ms",
 "AlphaTmax_nmda", "/ms",
 "Beta_nmda", "/ms",
 "Erev_nmda", "mV",
 "gbar_nmda", "uS",
 "Cdur_ampa", "ms",
 "AlphaTmax_ampa", "/ms",
 "Beta_ampa", "/ms",
 "Erev_ampa", "mV",
 "gbar_ampa", "uS",
 "Cainf", "mM",
 "pooldiam", "micrometer",
 "tauCa", "ms",
 "f", "1",
 "tauF", "ms",
 "d1", "1",
 "tauD1", "ms",
 "d2", "1",
 "tauD2", "ms",
 "inmda", "nA",
 "g_nmda", "uS",
 "iampa", "nA",
 "g_ampa", "uS",
 "ICa", "mA",
 "iCatotal", "mA",
 0,0
};
 static double W0 = 0;
 static double capoolcon0 = 0;
 static double delta_t = 0.01;
 static double r_ampa0 = 0;
 static double r_nmda0 = 0;
 static double v = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "DAstart1_pyrD2pyrD_STFD", &DAstart1_pyrD2pyrD_STFD,
 "DAstop1_pyrD2pyrD_STFD", &DAstop1_pyrD2pyrD_STFD,
 "DAstart2_pyrD2pyrD_STFD", &DAstart2_pyrD2pyrD_STFD,
 "DAstop2_pyrD2pyrD_STFD", &DAstop2_pyrD2pyrD_STFD,
 "DA_t1_pyrD2pyrD_STFD", &DA_t1_pyrD2pyrD_STFD,
 "DA_t2_pyrD2pyrD_STFD", &DA_t2_pyrD2pyrD_STFD,
 "DA_t3_pyrD2pyrD_STFD", &DA_t3_pyrD2pyrD_STFD,
 "DA_S_pyrD2pyrD_STFD", &DA_S_pyrD2pyrD_STFD,
 "Beta1_pyrD2pyrD_STFD", &Beta1_pyrD2pyrD_STFD,
 "Beta2_pyrD2pyrD_STFD", &Beta2_pyrD2pyrD_STFD,
 0,0
};
 static DoubVec hoc_vdoub[] = {
 0,0,0
};
 static double _sav_indep;
 static void nrn_alloc(Prop*);
static void  nrn_init(_NrnThread*, _Memb_list*, int);
static void nrn_state(_NrnThread*, _Memb_list*, int);
 static void nrn_cur(_NrnThread*, _Memb_list*, int);
static void  nrn_jacob(_NrnThread*, _Memb_list*, int);
 static void _hoc_destroy_pnt(_vptr) void* _vptr; {
   destroy_point_process(_vptr);
}
 
static int _ode_count(int);
static void _ode_map(int, double**, double**, double*, Datum*, double*, int);
static void _ode_spec(_NrnThread*, _Memb_list*, int);
static void _ode_matsol(_NrnThread*, _Memb_list*, int);
 
#define _cvode_ieq _ppvar[4]._i
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "6.2.0",
"pyrD2pyrD_STFD",
 "srcid",
 "destid",
 "Cdur_nmda",
 "AlphaTmax_nmda",
 "Beta_nmda",
 "Erev_nmda",
 "gbar_nmda",
 "Cdur_ampa",
 "AlphaTmax_ampa",
 "Beta_ampa",
 "Erev_ampa",
 "gbar_ampa",
 "Cainf",
 "pooldiam",
 "z",
 "neuroM",
 "tauCa",
 "P0",
 "fCa",
 "lambda1",
 "lambda2",
 "threshold1",
 "threshold2",
 "initW",
 "fmax",
 "fmin",
 "thr_rp",
 "facfactor",
 "f",
 "tauF",
 "d1",
 "tauD1",
 "d2",
 "tauD2",
 0,
 "inmda",
 "g_nmda",
 "on_nmda",
 "W_nmda",
 "iampa",
 "g_ampa",
 "on_ampa",
 "limitW",
 "ICa",
 "iCatotal",
 "Wmax",
 "Wmin",
 "maxChange",
 "normW",
 "scaleW",
 "tempW",
 "pregid",
 "postgid",
 "F",
 "D1",
 "D2",
 0,
 "r_nmda",
 "r_ampa",
 "capoolcon",
 "W",
 0,
 0};
 static Symbol* _ca_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
  if (nrn_point_prop_) {
	_prop->_alloc_seq = nrn_point_prop_->_alloc_seq;
	_p = nrn_point_prop_->param;
	_ppvar = nrn_point_prop_->dparam;
 }else{
 	_p = nrn_prop_data_alloc(_mechtype, 72, _prop);
 	/*initialize range parameters*/
 	srcid = -1;
 	destid = -1;
 	Cdur_nmda = 16.765;
 	AlphaTmax_nmda = 0.2659;
 	Beta_nmda = 0.008;
 	Erev_nmda = 0;
 	gbar_nmda = 0.0005;
 	Cdur_ampa = 1.421;
 	AlphaTmax_ampa = 3.8142;
 	Beta_ampa = 0.1429;
 	Erev_ampa = 0;
 	gbar_ampa = 0.001;
 	Cainf = 5e-05;
 	pooldiam = 1.8172;
 	z = 2;
 	neuroM = 0;
 	tauCa = 50;
 	P0 = 0.015;
 	fCa = 0.024;
 	lambda1 = 20;
 	lambda2 = 0.03;
 	threshold1 = 0.3;
 	threshold2 = 0.4;
 	initW = 0.667;
 	fmax = 3;
 	fmin = 0.8;
 	thr_rp = 1;
 	facfactor = 1;
 	f = 0;
 	tauF = 20;
 	d1 = 0.95;
 	tauD1 = 40;
 	d2 = 0.9;
 	tauD2 = 70;
  }
 	_prop->param = _p;
 	_prop->param_size = 72;
  if (!nrn_point_prop_) {
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 5, _prop);
  }
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_ca_sym);
 nrn_promote(prop_ion, 0, 1);
 	_ppvar[2]._pval = &prop_ion->param[0]; /* eca */
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 0,0
};
 
#define _tqitem &(_ppvar[3]._pvoid)
 static void _net_receive(Point_process*, double*, double);
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*f)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _pyrD2pyrD_STFD_new_reg() {
	int _vectorized = 0;
  _initlists();
 	ion_reg("ca", -10000.);
 	_ca_sym = hoc_lookup("ca_ion");
 	_pointtype = point_register_mech(_mechanism,
	 nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init,
	 hoc_nrnpointerindex, 0,
	 _hoc_create_pnt, _hoc_destroy_pnt, _member_func);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
  hoc_register_prop_size(_mechtype, 72, 5);
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 pnt_receive[_mechtype] = _net_receive;
 pnt_receive_size[_mechtype] = 1;
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 pyrD2pyrD_STFD /data/latimerb/netpyne/100_Cell/x86_64/pyrD2pyrD_STFD_new.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
 static double FARADAY = 96485.0;
 static double pi = 3.141592;
static int _reset;
static char *modelname = "";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist1[4], _dlist1[4];
 static int release(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 () {_reset=0;
 {
   DW = limitW * eta ( _threadargscomma_ capoolcon ) * ( lambda1 * omega ( _threadargscomma_ capoolcon , threshold1 , threshold2 ) - lambda2 * W ) ;
   Dr_nmda = AlphaTmax_nmda * on_nmda * ( 1.0 - r_nmda ) - Beta_nmda * r_nmda ;
   Dr_ampa = AlphaTmax_ampa * on_ampa * ( 1.0 - r_ampa ) - Beta_ampa * r_ampa ;
   Dcapoolcon = - fCa * Afactor * ICa + ( Cainf - capoolcon ) / tauCa ;
   }
 return _reset;
}
 static int _ode_matsol1 () {
 DW = DW  / (1. - dt*( (limitW * eta ( _threadargscomma_ capoolcon ))*(( ( - (lambda2)*(1.0) ) )) )) ;
 Dr_nmda = Dr_nmda  / (1. - dt*( (AlphaTmax_nmda * on_nmda)*(( ( - 1.0 ) )) - (Beta_nmda)*(1.0) )) ;
 Dr_ampa = Dr_ampa  / (1. - dt*( (AlphaTmax_ampa * on_ampa)*(( ( - 1.0 ) )) - (Beta_ampa)*(1.0) )) ;
 Dcapoolcon = Dcapoolcon  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tauCa )) ;
 return 0;
}
 /*END CVODE*/
 static int release () {_reset=0;
 {
    W = W + (1. - exp(dt*((limitW * eta ( _threadargscomma_ capoolcon ))*(( ( - (lambda2)*(1.0) ) )))))*(- ( ((limitW)*(eta ( _threadargscomma_ capoolcon )))*(( (lambda1)*(omega ( _threadargscomma_ capoolcon , threshold1 , threshold2 )) )) ) / ( ((limitW)*(eta ( _threadargscomma_ capoolcon )))*(( ( - (lambda2)*(1.0)) )) ) - W) ;
    r_nmda = r_nmda + (1. - exp(dt*((AlphaTmax_nmda * on_nmda)*(( ( - 1.0 ) )) - (Beta_nmda)*(1.0))))*(- ( ((AlphaTmax_nmda)*(on_nmda))*(( 1.0 )) ) / ( ((AlphaTmax_nmda)*(on_nmda))*(( ( - 1.0) )) - (Beta_nmda)*(1.0) ) - r_nmda) ;
    r_ampa = r_ampa + (1. - exp(dt*((AlphaTmax_ampa * on_ampa)*(( ( - 1.0 ) )) - (Beta_ampa)*(1.0))))*(- ( ((AlphaTmax_ampa)*(on_ampa))*(( 1.0 )) ) / ( ((AlphaTmax_ampa)*(on_ampa))*(( ( - 1.0) )) - (Beta_ampa)*(1.0) ) - r_ampa) ;
    capoolcon = capoolcon + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / tauCa)))*(- ( ((- fCa)*(Afactor))*(ICa) + ( ( Cainf ) ) / tauCa ) / ( ( ( ( - 1.0) ) ) / tauCa ) - capoolcon) ;
   }
  return 0;
}
 
static void _net_receive (_pnt, _args, _lflag) Point_process* _pnt; double* _args; double _lflag; 
{    _p = _pnt->_prop->param; _ppvar = _pnt->_prop->dparam;
  if (_tsav > t){ extern char* hoc_object_name(); hoc_execerror(hoc_object_name(_pnt->ob), ":Event arrived out of order. Must call ParallelContext.set_maxstep AFTER assigning minimum NetCon.delay");}
 _tsav = t;   if (_lflag == 1. ) {*(_tqitem) = 0;}
 {
   if ( _lflag  == 0.0 ) {
     if ( (  ! on_nmda ) ) {
       t0 = t ;
       on_nmda = 1.0 ;
       net_send ( _tqitem, _args, _pnt, t +  Cdur_nmda , 1.0 ) ;
       }
     else if ( on_nmda  == 1.0 ) {
       net_move ( _tqitem, _pnt, t + Cdur_nmda ) ;
       t0 = t ;
       }
     }
   if ( _lflag  == 1.0 ) {
     on_nmda = 0.0 ;
     }
   if ( _lflag  == 0.0 ) {
     D1 = 1.0 - ( 1.0 - D1 ) * exp ( - ( t - tsyn ) / tauD1 ) ;
     D2 = 1.0 - ( 1.0 - D2 ) * exp ( - ( t - tsyn ) / tauD2 ) ;
     tsyn = t ;
     facfactor = F * D1 * D2 ;
     if ( F > 3.0 ) {
       F = 3.0 ;
       }
     if ( facfactor < 0.5 ) {
       facfactor = 0.5 ;
       }
     D1 = D1 * d1 ;
     D2 = D2 * d2 ;
     }
   } }
 
double sfunc (  double _lv ) {
   double _lsfunc;
  _lsfunc = 1.0 / ( 1.0 + 0.33 * exp ( - 0.06 * _lv ) ) ;
    
return _lsfunc;
 }
 
static double _hoc_sfunc(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  sfunc (  *getarg(1) );
 return(_r);
}
 
double eta (  double _lCani ) {
   double _leta;
 double _ltaulearn , _lP1 , _lP2 , _lP4 , _lCacon ;
 _lP1 = 0.1 ;
   _lP2 = _lP1 * 1e-4 ;
   _lP4 = 1.0 ;
   _lCacon = _lCani * 1e3 ;
   _ltaulearn = _lP1 / ( _lP2 + _lCacon * _lCacon * _lCacon ) + _lP4 ;
   _leta = 1.0 / _ltaulearn * 0.001 ;
   
return _leta;
 }
 
static double _hoc_eta(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  eta (  *getarg(1) );
 return(_r);
}
 
double omega (  double _lCani , double _lthreshold1 , double _lthreshold2 ) {
   double _lomega;
 double _lr , _lmid , _lCacon ;
 _lCacon = _lCani * 1e3 ;
   _lr = ( _lthreshold2 - _lthreshold1 ) / 2.0 ;
   _lmid = ( _lthreshold1 + _lthreshold2 ) / 2.0 ;
   if ( _lCacon <= _lthreshold1 ) {
     _lomega = 0.0 ;
     }
   else if ( _lCacon >= _lthreshold2 ) {
     _lomega = 1.0 / ( 1.0 + 50.0 * exp ( - 50.0 * ( _lCacon - _lthreshold2 ) ) ) ;
     }
   else {
     _lomega = - sqrt ( _lr * _lr - ( _lCacon - _lmid ) * ( _lCacon - _lmid ) ) ;
     }
   
return _lomega;
 }
 
static double _hoc_omega(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  omega (  *getarg(1) , *getarg(2) , *getarg(3) );
 return(_r);
}
 
double DA1 (  double _lDAstart1 , double _lDAstop1 ) {
   double _lDA1;
 double _lDAtemp1 , _lDAtemp2 , _lDAtemp3 , _lDAtemp4 , _lDAtemp5 , _lDAtemp6 , _lDAtemp7 , _lDAtemp8 , _lDAtemp9 , _lDAtemp10 , _lDAtemp11 , _lDAtemp12 , _lDAtemp13 , _lDAtemp14 , _lDAtemp15 , _lDAtemp16 , _lDAtemp17 , _lDAtemp18 , _lDAtemp19 , _lDAtemp20 , _lDAtemp21 , _lDAtemp22 , _lDAtemp23 , _lDAtemp24 , _lDAtemp25 , _lDAtemp26 , _lDAtemp27 , _lDAtemp28 , _lDAtemp29 , _lDAtemp30 , _lDAtemp31 , _lDAtemp32 , _lDAtemp33 , _lDAtemp34 , _ls ;
 _lDAtemp1 = _lDAstart1 + 4000.0 ;
   _lDAtemp2 = _lDAtemp1 + 4000.0 ;
   _lDAtemp3 = _lDAtemp2 + 4000.0 ;
   _lDAtemp4 = _lDAtemp3 + 4000.0 ;
   _lDAtemp5 = _lDAtemp4 + 4000.0 ;
   _lDAtemp6 = _lDAtemp5 + 4000.0 ;
   _lDAtemp7 = _lDAtemp6 + 4000.0 ;
   _lDAtemp8 = _lDAtemp7 + 4000.0 ;
   _lDAtemp9 = _lDAtemp8 + 4000.0 ;
   _lDAtemp10 = _lDAtemp9 + 4000.0 ;
   _lDAtemp11 = _lDAtemp10 + 4000.0 ;
   _lDAtemp12 = _lDAtemp11 + 4000.0 ;
   _lDAtemp13 = _lDAtemp12 + 4000.0 ;
   _lDAtemp14 = _lDAtemp13 + 4000.0 ;
   _lDAtemp15 = _lDAtemp14 + 4000.0 + 100000.0 ;
   _lDAtemp16 = _lDAtemp15 + 4000.0 ;
   _lDAtemp17 = _lDAtemp16 + 4000.0 ;
   _lDAtemp18 = _lDAtemp17 + 4000.0 ;
   _lDAtemp19 = _lDAtemp18 + 4000.0 ;
   _lDAtemp20 = _lDAtemp19 + 4000.0 ;
   _lDAtemp21 = _lDAtemp20 + 4000.0 ;
   _lDAtemp22 = _lDAtemp21 + 4000.0 ;
   _lDAtemp23 = _lDAtemp22 + 4000.0 ;
   _lDAtemp24 = _lDAtemp23 + 4000.0 ;
   _lDAtemp25 = _lDAtemp24 + 4000.0 ;
   _lDAtemp26 = _lDAtemp25 + 4000.0 ;
   _lDAtemp27 = _lDAtemp26 + 4000.0 ;
   _lDAtemp28 = _lDAtemp27 + 4000.0 ;
   _lDAtemp29 = _lDAtemp28 + 4000.0 ;
   _lDAtemp30 = _lDAtemp29 + 4000.0 ;
   _lDAtemp31 = _lDAtemp30 + 4000.0 ;
   _lDAtemp32 = _lDAtemp31 + 4000.0 ;
   _lDAtemp33 = _lDAtemp32 + 4000.0 ;
   _lDAtemp34 = _lDAtemp33 + 4000.0 ;
   if ( t <= _lDAstart1 ) {
     _lDA1 = 1.0 ;
     }
   else if ( t >= _lDAstart1  && t <= _lDAstop1 ) {
     _lDA1 = DA_t1 ;
     }
   else if ( t > _lDAstop1  && t < _lDAtemp1 ) {
     _lDA1 = 1.0 + ( DA_t1 - 1.0 ) * exp ( - Beta1 * ( t - _lDAstop1 ) ) ;
     }
   else if ( t >= _lDAtemp1  && t <= _lDAtemp1 + 500.0 ) {
     _lDA1 = DA_t1 ;
     }
   else if ( t > _lDAtemp1 + 500.0  && t < _lDAtemp2 ) {
     _lDA1 = 1.0 + ( DA_t1 - 1.0 ) * exp ( - Beta1 * ( t - ( _lDAtemp1 + 500.0 ) ) ) ;
     }
   else if ( t >= _lDAtemp2  && t <= _lDAtemp2 + 500.0 ) {
     _lDA1 = DA_t1 ;
     }
   else if ( t > _lDAtemp2 + 500.0  && t < _lDAtemp3 ) {
     _lDA1 = 1.0 + ( DA_t1 - 1.0 ) * exp ( - Beta1 * ( t - ( _lDAtemp2 + 500.0 ) ) ) ;
     }
   else if ( t >= _lDAtemp3  && t <= _lDAtemp3 + 500.0 ) {
     _lDA1 = DA_t1 ;
     }
   else if ( t > _lDAtemp3 + 500.0  && t < _lDAtemp4 ) {
     _lDA1 = 1.0 + ( DA_t1 - 1.0 ) * exp ( - Beta1 * ( t - ( _lDAtemp3 + 500.0 ) ) ) ;
     }
   else if ( t >= _lDAtemp4  && t <= _lDAtemp4 + 500.0 ) {
     _lDA1 = DA_t1 ;
     }
   else if ( t > _lDAtemp4 + 500.0  && t < _lDAtemp5 ) {
     _lDA1 = 1.0 + ( DA_t1 - 1.0 ) * exp ( - Beta1 * ( t - ( _lDAtemp4 + 500.0 ) ) ) ;
     }
   else if ( t >= _lDAtemp5  && t <= _lDAtemp5 + 500.0 ) {
     _lDA1 = DA_t1 ;
     }
   else if ( t > _lDAtemp5 + 500.0  && t < _lDAtemp6 ) {
     _lDA1 = 1.0 + ( DA_t1 - 1.0 ) * exp ( - Beta1 * ( t - ( _lDAtemp5 + 500.0 ) ) ) ;
     }
   else if ( t >= _lDAtemp6  && t <= _lDAtemp6 + 500.0 ) {
     _lDA1 = DA_t1 ;
     }
   else if ( t > _lDAtemp6 + 500.0  && t < _lDAtemp7 ) {
     _lDA1 = 1.0 + ( DA_t1 - 1.0 ) * exp ( - Beta1 * ( t - ( _lDAtemp6 + 500.0 ) ) ) ;
     }
   else if ( t >= _lDAtemp7  && t <= _lDAtemp7 + 500.0 ) {
     _lDA1 = DA_t1 ;
     }
   else if ( t > _lDAtemp7 + 500.0  && t < _lDAtemp8 ) {
     _lDA1 = 1.0 + ( DA_t1 - 1.0 ) * exp ( - Beta1 * ( t - ( _lDAtemp7 + 500.0 ) ) ) ;
     }
   else if ( t >= _lDAtemp8  && t <= _lDAtemp8 + 500.0 ) {
     _lDA1 = DA_t1 ;
     }
   else if ( t > _lDAtemp8 + 500.0  && t < _lDAtemp9 ) {
     _lDA1 = 1.0 + ( DA_t1 - 1.0 ) * exp ( - Beta1 * ( t - ( _lDAtemp8 + 500.0 ) ) ) ;
     }
   else if ( t >= _lDAtemp9  && t <= _lDAtemp9 + 500.0 ) {
     _lDA1 = DA_t2 ;
     }
   else if ( t > _lDAtemp9 + 500.0  && t < _lDAtemp10 ) {
     _lDA1 = 1.0 + ( DA_t2 - 1.0 ) * exp ( - Beta2 * ( t - ( _lDAtemp9 + 500.0 ) ) ) ;
     }
   else if ( t >= _lDAtemp10  && t <= _lDAtemp10 + 500.0 ) {
     _lDA1 = DA_t2 ;
     }
   else if ( t > _lDAtemp10 + 500.0  && t < _lDAtemp11 ) {
     _lDA1 = 1.0 + ( DA_t2 - 1.0 ) * exp ( - Beta2 * ( t - ( _lDAtemp10 + 500.0 ) ) ) ;
     }
   else if ( t >= _lDAtemp11  && t <= _lDAtemp11 + 500.0 ) {
     _lDA1 = DA_t2 ;
     }
   else if ( t > _lDAtemp11 + 500.0  && t < _lDAtemp12 ) {
     _lDA1 = 1.0 + ( DA_t2 - 1.0 ) * exp ( - Beta2 * ( t - ( _lDAtemp11 + 500.0 ) ) ) ;
     }
   else if ( t >= _lDAtemp12  && t <= _lDAtemp12 + 500.0 ) {
     _lDA1 = DA_t2 ;
     }
   else if ( t > _lDAtemp12 + 500.0  && t < _lDAtemp13 ) {
     _lDA1 = 1.0 + ( DA_t2 - 1.0 ) * exp ( - Beta2 * ( t - ( _lDAtemp12 + 500.0 ) ) ) ;
     }
   else if ( t >= _lDAtemp13  && t <= _lDAtemp13 + 500.0 ) {
     _lDA1 = DA_t2 ;
     }
   else if ( t > _lDAtemp13 + 500.0  && t < _lDAtemp14 ) {
     _lDA1 = 1.0 + ( DA_t2 - 1.0 ) * exp ( - Beta2 * ( t - ( _lDAtemp13 + 500.0 ) ) ) ;
     }
   else if ( t >= _lDAtemp14  && t <= _lDAtemp14 + 500.0 ) {
     _lDA1 = DA_t2 ;
     }
   else if ( t > _lDAtemp14 + 500.0  && t < _lDAtemp15 ) {
     _lDA1 = 1.0 + ( DA_t2 - 1.0 ) * exp ( - Beta2 * ( t - ( _lDAtemp14 + 500.0 ) ) ) ;
     }
   else if ( t >= _lDAtemp15  && t <= _lDAtemp15 + 500.0 ) {
     _lDA1 = DA_t2 ;
     }
   else if ( t > _lDAtemp15 + 500.0  && t < _lDAtemp16 ) {
     _lDA1 = 1.0 + ( DA_t2 - 1.0 ) * exp ( - Beta2 * ( t - ( _lDAtemp15 + 500.0 ) ) ) ;
     }
   else if ( t >= _lDAtemp16  && t <= _lDAtemp16 + 500.0 ) {
     _lDA1 = DA_t2 ;
     }
   else if ( t > _lDAtemp16 + 500.0  && t < _lDAtemp17 ) {
     _lDA1 = 1.0 + ( DA_t2 - 1.0 ) * exp ( - Beta2 * ( t - ( _lDAtemp16 + 500.0 ) ) ) ;
     }
   else if ( t >= _lDAtemp17  && t <= _lDAtemp17 + 500.0 ) {
     _lDA1 = DA_t2 ;
     }
   else if ( t > _lDAtemp17 + 500.0  && t < _lDAtemp18 ) {
     _lDA1 = 1.0 + ( DA_t2 - 1.0 ) * exp ( - Beta2 * ( t - ( _lDAtemp17 + 500.0 ) ) ) ;
     }
   else if ( t >= _lDAtemp18  && t <= _lDAtemp18 + 500.0 ) {
     _lDA1 = DA_t2 ;
     }
   else if ( t > _lDAtemp18 + 500.0  && t < _lDAtemp19 ) {
     _lDA1 = 1.0 + ( DA_t2 - 1.0 ) * exp ( - Beta2 * ( t - ( _lDAtemp18 + 500.0 ) ) ) ;
     }
   else if ( t >= _lDAtemp19  && t <= _lDAtemp19 + 500.0 ) {
     _lDA1 = DA_t3 ;
     }
   else if ( t > _lDAtemp19 + 500.0  && t < _lDAtemp20 ) {
     _lDA1 = 1.0 + ( DA_t2 - 1.0 ) * exp ( - Beta2 * ( t - ( _lDAtemp19 + 500.0 ) ) ) ;
     }
   else if ( t >= _lDAtemp20  && t <= _lDAtemp20 + 500.0 ) {
     _lDA1 = DA_t3 ;
     }
   else if ( t > _lDAtemp20 + 500.0  && t < _lDAtemp21 ) {
     _lDA1 = 1.0 + ( DA_t2 - 1.0 ) * exp ( - Beta2 * ( t - ( _lDAtemp20 + 500.0 ) ) ) ;
     }
   else if ( t >= _lDAtemp21  && t <= _lDAtemp21 + 500.0 ) {
     _lDA1 = DA_t3 ;
     }
   else if ( t > _lDAtemp21 + 500.0  && t < _lDAtemp22 ) {
     _lDA1 = 1.0 + ( DA_t2 - 1.0 ) * exp ( - Beta2 * ( t - ( _lDAtemp21 + 500.0 ) ) ) ;
     }
   else if ( t >= _lDAtemp22  && t <= _lDAtemp22 + 500.0 ) {
     _lDA1 = DA_t3 ;
     }
   else if ( t > _lDAtemp22 + 500.0  && t < _lDAtemp23 ) {
     _lDA1 = 1.0 + ( DA_t2 - 1.0 ) * exp ( - Beta2 * ( t - ( _lDAtemp22 + 500.0 ) ) ) ;
     }
   else if ( t >= _lDAtemp23  && t <= _lDAtemp23 + 500.0 ) {
     _lDA1 = DA_t3 ;
     }
   else if ( t > _lDAtemp23 + 500.0  && t < _lDAtemp24 ) {
     _lDA1 = 1.0 + ( DA_t2 - 1.0 ) * exp ( - Beta2 * ( t - ( _lDAtemp23 + 500.0 ) ) ) ;
     }
   else if ( t >= _lDAtemp24  && t <= _lDAtemp24 + 500.0 ) {
     _lDA1 = DA_t3 ;
     }
   else if ( t > _lDAtemp24 + 500.0  && t < _lDAtemp25 ) {
     _lDA1 = 1.0 + ( DA_t2 - 1.0 ) * exp ( - Beta2 * ( t - ( _lDAtemp24 + 500.0 ) ) ) ;
     }
   else if ( t >= _lDAtemp25  && t <= _lDAtemp25 + 500.0 ) {
     _lDA1 = DA_t3 ;
     }
   else if ( t > _lDAtemp25 + 500.0  && t < _lDAtemp26 ) {
     _lDA1 = 1.0 + ( DA_t2 - 1.0 ) * exp ( - Beta2 * ( t - ( _lDAtemp25 + 500.0 ) ) ) ;
     }
   else if ( t >= _lDAtemp26  && t <= _lDAtemp26 + 500.0 ) {
     _lDA1 = DA_t3 ;
     }
   else if ( t > _lDAtemp26 + 500.0  && t < _lDAtemp27 ) {
     _lDA1 = 1.0 + ( DA_t2 - 1.0 ) * exp ( - Beta2 * ( t - ( _lDAtemp26 + 500.0 ) ) ) ;
     }
   else if ( t >= _lDAtemp27  && t <= _lDAtemp27 + 500.0 ) {
     _lDA1 = DA_t3 ;
     }
   else if ( t > _lDAtemp27 + 500.0  && t < _lDAtemp28 ) {
     _lDA1 = 1.0 + ( DA_t2 - 1.0 ) * exp ( - Beta2 * ( t - ( _lDAtemp27 + 500.0 ) ) ) ;
     }
   else if ( t >= _lDAtemp28  && t <= _lDAtemp28 + 500.0 ) {
     _lDA1 = DA_t3 ;
     }
   else if ( t > _lDAtemp28 + 500.0  && t < _lDAtemp29 ) {
     _lDA1 = 1.0 + ( DA_t2 - 1.0 ) * exp ( - Beta2 * ( t - ( _lDAtemp28 + 500.0 ) ) ) ;
     }
   else if ( t >= _lDAtemp29  && t <= _lDAtemp29 + 500.0 ) {
     _lDA1 = DA_t3 ;
     }
   else if ( t > _lDAtemp29 + 500.0  && t < _lDAtemp30 ) {
     _lDA1 = 1.0 + ( DA_t2 - 1.0 ) * exp ( - Beta2 * ( t - ( _lDAtemp29 + 500.0 ) ) ) ;
     }
   else if ( t >= _lDAtemp30  && t <= _lDAtemp30 + 500.0 ) {
     _lDA1 = DA_t3 ;
     }
   else if ( t > _lDAtemp30 + 500.0  && t < _lDAtemp31 ) {
     _lDA1 = 1.0 + ( DA_t2 - 1.0 ) * exp ( - Beta2 * ( t - ( _lDAtemp30 + 500.0 ) ) ) ;
     }
   else if ( t >= _lDAtemp31  && t <= _lDAtemp31 + 500.0 ) {
     _lDA1 = DA_t3 ;
     }
   else if ( t > _lDAtemp31 + 500.0  && t < _lDAtemp32 ) {
     _lDA1 = 1.0 + ( DA_t2 - 1.0 ) * exp ( - Beta2 * ( t - ( _lDAtemp31 + 500.0 ) ) ) ;
     }
   else if ( t >= _lDAtemp32  && t <= _lDAtemp32 + 500.0 ) {
     _lDA1 = DA_t3 ;
     }
   else if ( t > _lDAtemp32 + 500.0  && t < _lDAtemp33 ) {
     _lDA1 = 1.0 + ( DA_t2 - 1.0 ) * exp ( - Beta2 * ( t - ( _lDAtemp32 + 500.0 ) ) ) ;
     }
   else if ( t >= _lDAtemp33  && t <= _lDAtemp33 + 500.0 ) {
     _lDA1 = DA_t3 ;
     }
   else if ( t > _lDAtemp33 + 500.0  && t < _lDAtemp34 ) {
     _lDA1 = 1.0 + ( DA_t2 - 1.0 ) * exp ( - Beta2 * ( t - ( _lDAtemp33 + 500.0 ) ) ) ;
     }
   else if ( t >= _lDAtemp34  && t <= _lDAtemp34 + 500.0 ) {
     _lDA1 = DA_t3 ;
     }
   else {
     _lDA1 = 1.0 ;
     }
   
return _lDA1;
 }
 
static double _hoc_DA1(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  DA1 (  *getarg(1) , *getarg(2) );
 return(_r);
}
 
double DA2 (  double _lDAstart2 , double _lDAstop2 ) {
   double _lDA2;
 double _lDA2temp1 , _lDA2temp2 , _lDA2temp3 , _lDA2temp4 , _lDA2temp5 , _lDA2temp6 , _lDA2temp7 , _lDA2temp8 , _lDA2temp9 , _lDA2temp10 , _lDA2temp11 , _lDA2temp12 , _lDA2temp13 , _lDA2temp14 , _lDA2temp15 , _lDA2temp16 , _ls ;
 _lDA2temp1 = _lDAstart2 + 4000.0 ;
   _lDA2temp2 = _lDA2temp1 + 4000.0 ;
   _lDA2temp3 = _lDA2temp2 + 4000.0 ;
   _lDA2temp4 = _lDA2temp3 + 4000.0 ;
   _lDA2temp5 = _lDA2temp4 + 4000.0 ;
   _lDA2temp6 = _lDA2temp5 + 4000.0 ;
   _lDA2temp7 = _lDA2temp6 + 4000.0 ;
   _lDA2temp8 = _lDA2temp7 + 4000.0 ;
   _lDA2temp9 = _lDA2temp8 + 4000.0 ;
   _lDA2temp10 = _lDA2temp9 + 4000.0 ;
   _lDA2temp11 = _lDA2temp10 + 4000.0 ;
   _lDA2temp12 = _lDA2temp11 + 4000.0 ;
   _lDA2temp13 = _lDA2temp12 + 4000.0 ;
   _lDA2temp14 = _lDA2temp13 + 4000.0 ;
   _lDA2temp15 = _lDA2temp14 + 4000.0 ;
   if ( t <= _lDAstart2 ) {
     _lDA2 = 1.0 ;
     }
   else if ( t >= _lDAstart2  && t <= _lDAstop2 ) {
     _lDA2 = DA_S ;
     }
   else if ( t > _lDAstop2  && t < _lDA2temp1 ) {
     _lDA2 = 1.0 + ( DA_S - 1.0 ) * exp ( - Beta2 * ( t - ( _lDAstop2 + 500.0 ) ) ) ;
     }
   else if ( t >= _lDA2temp1  && t <= _lDA2temp1 + 100.0 ) {
     _lDA2 = DA_S ;
     }
   else if ( t > _lDA2temp1 + 100.0  && t < _lDA2temp2 ) {
     _lDA2 = 1.0 + ( DA_S - 1.0 ) * exp ( - Beta2 * ( t - ( _lDA2temp1 + 100.0 ) ) ) ;
     }
   else if ( t >= _lDA2temp2  && t <= _lDA2temp2 + 100.0 ) {
     _lDA2 = DA_S ;
     }
   else if ( t > _lDA2temp2 + 100.0  && t < _lDA2temp3 ) {
     _lDA2 = 1.0 + ( DA_S - 1.0 ) * exp ( - Beta2 * ( t - ( _lDA2temp2 + 100.0 ) ) ) ;
     }
   else if ( t >= _lDA2temp3  && t <= _lDA2temp3 + 100.0 ) {
     _lDA2 = DA_S ;
     }
   else if ( t > _lDA2temp3 + 100.0  && t < _lDA2temp4 ) {
     _lDA2 = 1.0 + ( DA_S - 1.0 ) * exp ( - Beta2 * ( t - ( _lDA2temp3 + 100.0 ) ) ) ;
     }
   else if ( t >= _lDA2temp4  && t <= _lDA2temp4 + 100.0 ) {
     _lDA2 = DA_S ;
     }
   else if ( t > _lDA2temp4 + 100.0  && t < _lDA2temp5 ) {
     _lDA2 = 1.0 + ( DA_S - 1.0 ) * exp ( - Beta2 * ( t - ( _lDA2temp4 + 100.0 ) ) ) ;
     }
   else if ( t >= _lDA2temp5  && t <= _lDA2temp5 + 100.0 ) {
     _lDA2 = DA_S ;
     }
   else if ( t > _lDA2temp5 + 100.0  && t < _lDA2temp6 ) {
     _lDA2 = 1.0 + ( DA_S - 1.0 ) * exp ( - Beta2 * ( t - ( _lDA2temp5 + 100.0 ) ) ) ;
     }
   else if ( t >= _lDA2temp6  && t <= _lDA2temp6 + 100.0 ) {
     _lDA2 = DA_S ;
     }
   else if ( t > _lDA2temp6 + 100.0  && t < _lDA2temp7 ) {
     _lDA2 = 1.0 + ( DA_S - 1.0 ) * exp ( - Beta2 * ( t - ( _lDA2temp6 + 100.0 ) ) ) ;
     }
   else if ( t >= _lDA2temp7  && t <= _lDA2temp7 + 100.0 ) {
     _lDA2 = DA_S ;
     }
   else if ( t > _lDA2temp7 + 100.0  && t < _lDA2temp8 ) {
     _lDA2 = 1.0 + ( DA_S - 1.0 ) * exp ( - Beta2 * ( t - ( _lDA2temp7 + 100.0 ) ) ) ;
     }
   else if ( t >= _lDA2temp8  && t <= _lDA2temp8 + 100.0 ) {
     _lDA2 = DA_S ;
     }
   else if ( t > _lDA2temp8 + 100.0  && t < _lDA2temp9 ) {
     _lDA2 = 1.0 + ( DA_S - 1.0 ) * exp ( - Beta2 * ( t - ( _lDA2temp8 + 100.0 ) ) ) ;
     }
   else if ( t >= _lDA2temp9  && t <= _lDA2temp9 + 100.0 ) {
     _lDA2 = DA_S ;
     }
   else if ( t > _lDA2temp9 + 100.0  && t < _lDA2temp10 ) {
     _lDA2 = 1.0 + ( DA_S - 1.0 ) * exp ( - Beta2 * ( t - ( _lDA2temp9 + 100.0 ) ) ) ;
     }
   else if ( t >= _lDA2temp10  && t <= _lDA2temp10 + 100.0 ) {
     _lDA2 = DA_S ;
     }
   else if ( t > _lDA2temp10 + 100.0  && t < _lDA2temp11 ) {
     _lDA2 = 1.0 + ( DA_S - 1.0 ) * exp ( - Beta2 * ( t - ( _lDA2temp10 + 100.0 ) ) ) ;
     }
   else if ( t >= _lDA2temp11  && t <= _lDA2temp11 + 100.0 ) {
     _lDA2 = DA_S ;
     }
   else if ( t > _lDA2temp11 + 100.0  && t < _lDA2temp12 ) {
     _lDA2 = 1.0 + ( DA_S - 1.0 ) * exp ( - Beta2 * ( t - ( _lDA2temp11 + 100.0 ) ) ) ;
     }
   else if ( t >= _lDA2temp12  && t <= _lDA2temp12 + 100.0 ) {
     _lDA2 = DA_S ;
     }
   else if ( t > _lDA2temp12 + 100.0  && t < _lDA2temp13 ) {
     _lDA2 = 1.0 + ( DA_S - 1.0 ) * exp ( - Beta2 * ( t - ( _lDA2temp12 + 100.0 ) ) ) ;
     }
   else if ( t >= _lDA2temp13  && t <= _lDA2temp13 + 100.0 ) {
     _lDA2 = DA_S ;
     }
   else if ( t > _lDA2temp13 + 100.0  && t < _lDA2temp14 ) {
     _lDA2 = 1.0 + ( DA_S - 1.0 ) * exp ( - Beta2 * ( t - ( _lDA2temp13 + 100.0 ) ) ) ;
     }
   else if ( t >= _lDA2temp14  && t <= _lDA2temp14 + 100.0 ) {
     _lDA2 = DA_S ;
     }
   else if ( t > _lDA2temp14 + 100.0  && t < _lDA2temp15 ) {
     _lDA2 = 1.0 + ( DA_S - 1.0 ) * exp ( - Beta2 * ( t - ( _lDA2temp14 + 100.0 ) ) ) ;
     }
   else if ( t >= _lDA2temp15  && t <= _lDA2temp15 + 100.0 ) {
     _lDA2 = DA_S ;
     }
   else {
     _lDA2 = 1.0 ;
     }
   
return _lDA2;
 }
 
static double _hoc_DA2(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  DA2 (  *getarg(1) , *getarg(2) );
 return(_r);
}
 
double unirand (  ) {
   double _lunirand;
 _lunirand = scop_random ( ) ;
   
return _lunirand;
 }
 
static double _hoc_unirand(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  unirand (  );
 return(_r);
}
 
static int _ode_count(int _type){ return 4;}
 
static void _ode_spec(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  eca = _ion_eca;
     _ode_spec1 ();
 }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 4; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 
static void _ode_matsol(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  eca = _ion_eca;
 _ode_matsol1 ();
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_ca_sym, _ppvar, 2, 0);
 }

static void initmodel() {
  int _i; double _save;_ninits++;
 _save = t;
 t = 0.0;
{
  W = W0;
  capoolcon = capoolcon0;
  r_ampa = r_ampa0;
  r_nmda = r_nmda0;
 {
   on_nmda = 0.0 ;
   r_nmda = 0.0 ;
   W_nmda = initW ;
   on_ampa = 0.0 ;
   r_ampa = 0.0 ;
   W = initW ;
   limitW = 1.0 ;
   tempW = initW ;
   t0 = - 1.0 ;
   Wmax = fmax * initW ;
   Wmin = fmin * initW ;
   maxChange = ( Wmax - Wmin ) / 10.0 ;
   dW_ampa = 0.0 ;
   capoolcon = Cainf ;
   Afactor = 1.0 / ( z * FARADAY * 4.0 / 3.0 * pi * pow( ( pooldiam / 2.0 ) , 3.0 ) ) * ( 1e6 ) ;
   fa = 0.0 ;
   F = 1.0 ;
   D1 = 1.0 ;
   D2 = 1.0 ;
   }
  _sav_indep = t; t = _save;

}
}

static void nrn_init(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _tsav = -1e20;
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v = _v;
  eca = _ion_eca;
 initmodel();
}}

static double _nrn_current(double _v){double _current=0.;v=_v;{ {
   if ( ( eta ( _threadargscomma_ capoolcon ) * ( lambda1 * omega ( _threadargscomma_ capoolcon , threshold1 , threshold2 ) - lambda2 * W ) ) > 0.0  && W >= Wmax ) {
     limitW = 1e-12 ;
     }
   else if ( ( eta ( _threadargscomma_ capoolcon ) * ( lambda1 * omega ( _threadargscomma_ capoolcon , threshold1 , threshold2 ) - lambda2 * W ) ) < 0.0  && W <= Wmin ) {
     limitW = 1e-12 ;
     }
   else {
     limitW = 1.0 ;
     }
   if ( t0 > 0.0 ) {
     if ( rp < thr_rp ) {
       if ( t - t0 < Cdur_ampa ) {
         on_ampa = 1.0 ;
         }
       else {
         on_ampa = 0.0 ;
         }
       }
     else {
       on_ampa = 0.0 ;
       }
     }
   if ( neuroM  == 1.0 ) {
     g_nmda = gbar_nmda * r_nmda * facfactor * DA1 ( _threadargscomma_ DAstart1 , DAstop1 ) * DA2 ( _threadargscomma_ DAstart2 , DAstop2 ) ;
     }
   else {
     g_nmda = gbar_nmda * r_nmda * facfactor ;
     }
   inmda = W_nmda * g_nmda * ( v - Erev_nmda ) * sfunc ( _threadargscomma_ v ) ;
   g_ampa = gbar_ampa * r_ampa * facfactor ;
   iampa = W * g_ampa * ( v - Erev_ampa ) ;
   ICa = P0 * g_nmda * ( v - eca ) * sfunc ( _threadargscomma_ v ) ;
   }
 _current += inmda;
 _current += iampa;

} return _current;
}

static void nrn_cur(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
  eca = _ion_eca;
 _g = _nrn_current(_v + .001);
 	{ _rhs = _nrn_current(_v);
 	}
 _g = (_g - _rhs)/.001;
 _g *=  1.e2/(_nd_area);
 _rhs *= 1.e2/(_nd_area);
#if CACHEVEC
  if (use_cachevec) {
	VEC_RHS(_ni[_iml]) -= _rhs;
  }else
#endif
  {
	NODERHS(_nd) -= _rhs;
  }
 
}}

static void nrn_jacob(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml];
#if CACHEVEC
  if (use_cachevec) {
	VEC_D(_ni[_iml]) += _g;
  }else
#endif
  {
     _nd = _ml->_nodelist[_iml];
	NODED(_nd) += _g;
  }
 
}}

static void nrn_state(_NrnThread* _nt, _Memb_list* _ml, int _type){
 double _break, _save;
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _nd = _ml->_nodelist[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 _break = t + .5*dt; _save = t;
 v=_v;
{
  eca = _ion_eca;
 { {
 for (; t < _break; t += dt) {
 error =  release();
 if(error){fprintf(stderr,"at line 166 in file pyrD2pyrD_STFD_new.mod:\n	SOLVE release METHOD cnexp\n"); nrn_complain(_p); abort_run(error);}
 
}}
 t = _save;
 }}}

}

static void terminal(){}

static void _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(W) - _p;  _dlist1[0] = &(DW) - _p;
 _slist1[1] = &(r_nmda) - _p;  _dlist1[1] = &(Dr_nmda) - _p;
 _slist1[2] = &(r_ampa) - _p;  _dlist1[2] = &(Dr_ampa) - _p;
 _slist1[3] = &(capoolcon) - _p;  _dlist1[3] = &(Dcapoolcon) - _p;
_first = 0;
}
