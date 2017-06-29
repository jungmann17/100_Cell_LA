/* Created by Language version: 6.2.0 */
/* VECTORIZED */
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
 
#define _threadargscomma_ _p, _ppvar, _thread, _nt,
#define _threadargs_ _p, _ppvar, _thread, _nt
 
#define _threadargsprotocomma_ double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt,
#define _threadargsproto_ double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 /* Thread safe. No static _p or _ppvar. */
 
#define t _nt->_t
#define dt _nt->_dt
#define Cdur_nmda _p[0]
#define AlphaTmax_nmda _p[1]
#define Beta_nmda _p[2]
#define Erev_nmda _p[3]
#define gbar_nmda _p[4]
#define Cdur_ampa _p[5]
#define AlphaTmax_ampa _p[6]
#define Beta_ampa _p[7]
#define Erev_ampa _p[8]
#define gbar_ampa _p[9]
#define Cainf _p[10]
#define pooldiam _p[11]
#define z _p[12]
#define neuroM _p[13]
#define tauCa _p[14]
#define P0 _p[15]
#define fCa _p[16]
#define initW _p[17]
#define lambda1 _p[18]
#define lambda2 _p[19]
#define threshold1 _p[20]
#define threshold2 _p[21]
#define fmax _p[22]
#define fmin _p[23]
#define inmda _p[24]
#define g_nmda _p[25]
#define on_nmda _p[26]
#define W_nmda _p[27]
#define iampa _p[28]
#define g_ampa _p[29]
#define on_ampa _p[30]
#define limitW _p[31]
#define ICa _p[32]
#define iCatotal _p[33]
#define Wmax _p[34]
#define Wmin _p[35]
#define maxChange _p[36]
#define normW _p[37]
#define scaleW _p[38]
#define pregid _p[39]
#define postgid _p[40]
#define r_nmda _p[41]
#define r_ampa _p[42]
#define capoolcon _p[43]
#define W _p[44]
#define eca _p[45]
#define t0 _p[46]
#define Afactor _p[47]
#define dW_ampa _p[48]
#define Dr_nmda _p[49]
#define Dr_ampa _p[50]
#define Dcapoolcon _p[51]
#define DW _p[52]
#define v _p[53]
#define _g _p[54]
#define _tsav _p[55]
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
 static Datum* _extcall_thread;
 static Prop* _extcall_prop;
 /* external NEURON variables */
 /* declaration of user functions */
 static double _hoc_NE2();
 static double _hoc_NEn();
 static double _hoc_eta();
 static double _hoc_omega();
 static double _hoc_sfunc();
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
 _extcall_prop = _prop;
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
 "NE2", _hoc_NE2,
 "NEn", _hoc_NEn,
 "eta", _hoc_eta,
 "omega", _hoc_omega,
 "sfunc", _hoc_sfunc,
 0, 0
};
#define NE2 NE2_tone2pyrD
#define NEn NEn_tone2pyrD
#define eta eta_tone2pyrD
#define omega omega_tone2pyrD
#define sfunc sfunc_tone2pyrD
 extern double NE2( _threadargsprotocomma_ double , double );
 extern double NEn( _threadargsprotocomma_ double , double );
 extern double eta( _threadargsprotocomma_ double );
 extern double omega( _threadargsprotocomma_ double , double , double );
 extern double sfunc( _threadargsprotocomma_ double );
 /* declare global and static user variables */
#define Beta2 Beta2_tone2pyrD
 double Beta2 = 0.0001;
#define Beta1 Beta1_tone2pyrD
 double Beta1 = 0.001;
#define NE_S NE_S_tone2pyrD
 double NE_S = 1.3;
#define NE_t3 NE_t3_tone2pyrD
 double NE_t3 = 0.95;
#define NE_t2 NE_t2_tone2pyrD
 double NE_t2 = 0.9;
#define NE_t1 NE_t1_tone2pyrD
 double NE_t1 = 1;
#define NEstop2 NEstop2_tone2pyrD
 double NEstop2 = 36000;
#define NEstart2 NEstart2_tone2pyrD
 double NEstart2 = 35900;
#define NEstop1 NEstop1_tone2pyrD
 double NEstop1 = 40000;
#define NEstart1 NEstart1_tone2pyrD
 double NEstart1 = 39500;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "Beta1_tone2pyrD", "/ms",
 "Beta2_tone2pyrD", "/ms",
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
 "inmda", "nA",
 "g_nmda", "uS",
 "iampa", "nA",
 "g_ampa", "uS",
 "ICa", "nA",
 "iCatotal", "nA",
 0,0
};
 static double W0 = 0;
 static double capoolcon0 = 0;
 static double delta_t = 0.01;
 static double r_ampa0 = 0;
 static double r_nmda0 = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "NEstart1_tone2pyrD", &NEstart1_tone2pyrD,
 "NEstop1_tone2pyrD", &NEstop1_tone2pyrD,
 "NEstart2_tone2pyrD", &NEstart2_tone2pyrD,
 "NEstop2_tone2pyrD", &NEstop2_tone2pyrD,
 "NE_t1_tone2pyrD", &NE_t1_tone2pyrD,
 "NE_t2_tone2pyrD", &NE_t2_tone2pyrD,
 "NE_t3_tone2pyrD", &NE_t3_tone2pyrD,
 "NE_S_tone2pyrD", &NE_S_tone2pyrD,
 "Beta1_tone2pyrD", &Beta1_tone2pyrD,
 "Beta2_tone2pyrD", &Beta2_tone2pyrD,
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
"tone2pyrD",
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
 "initW",
 "lambda1",
 "lambda2",
 "threshold1",
 "threshold2",
 "fmax",
 "fmin",
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
 "pregid",
 "postgid",
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
 	_p = nrn_prop_data_alloc(_mechtype, 56, _prop);
 	/*initialize range parameters*/
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
 	initW = 1.11;
 	lambda1 = 40;
 	lambda2 = 0.04;
 	threshold1 = 0.3;
 	threshold2 = 0.4;
 	fmax = 3;
 	fmin = 0.8;
  }
 	_prop->param = _p;
 	_prop->param_size = 56;
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

 void _tone2pyrD_new_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("ca", -10000.);
 	_ca_sym = hoc_lookup("ca_ion");
 	_pointtype = point_register_mech(_mechanism,
	 nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init,
	 hoc_nrnpointerindex, 1,
	 _hoc_create_pnt, _hoc_destroy_pnt, _member_func);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
  hoc_register_prop_size(_mechtype, 56, 5);
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 pnt_receive[_mechtype] = _net_receive;
 pnt_receive_size[_mechtype] = 1;
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 tone2pyrD /data/latimerb/netpyne/100_Cell/x86_64/tone2pyrD_new.mod\n");
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
 static int _ode_spec1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset = 0; {
   DW = limitW * eta ( _threadargscomma_ capoolcon ) * ( lambda1 * omega ( _threadargscomma_ capoolcon , threshold1 , threshold2 ) - lambda2 * W ) ;
   Dr_nmda = AlphaTmax_nmda * on_nmda * ( 1.0 - r_nmda ) - Beta_nmda * r_nmda ;
   Dr_ampa = AlphaTmax_ampa * on_ampa * ( 1.0 - r_ampa ) - Beta_ampa * r_ampa ;
   Dcapoolcon = - fCa * Afactor * ICa + ( Cainf - capoolcon ) / tauCa ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
 DW = DW  / (1. - dt*( (limitW * eta ( _threadargscomma_ capoolcon ))*(( ( - (lambda2)*(1.0) ) )) )) ;
 Dr_nmda = Dr_nmda  / (1. - dt*( (AlphaTmax_nmda * on_nmda)*(( ( - 1.0 ) )) - (Beta_nmda)*(1.0) )) ;
 Dr_ampa = Dr_ampa  / (1. - dt*( (AlphaTmax_ampa * on_ampa)*(( ( - 1.0 ) )) - (Beta_ampa)*(1.0) )) ;
 Dcapoolcon = Dcapoolcon  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tauCa )) ;
 return 0;
}
 /*END CVODE*/
 static int release (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) { {
    W = W + (1. - exp(dt*((limitW * eta ( _threadargscomma_ capoolcon ))*(( ( - (lambda2)*(1.0) ) )))))*(- ( ((limitW)*(eta ( _threadargscomma_ capoolcon )))*(( (lambda1)*(omega ( _threadargscomma_ capoolcon , threshold1 , threshold2 )) )) ) / ( ((limitW)*(eta ( _threadargscomma_ capoolcon )))*(( ( - (lambda2)*(1.0)) )) ) - W) ;
    r_nmda = r_nmda + (1. - exp(dt*((AlphaTmax_nmda * on_nmda)*(( ( - 1.0 ) )) - (Beta_nmda)*(1.0))))*(- ( ((AlphaTmax_nmda)*(on_nmda))*(( 1.0 )) ) / ( ((AlphaTmax_nmda)*(on_nmda))*(( ( - 1.0) )) - (Beta_nmda)*(1.0) ) - r_nmda) ;
    r_ampa = r_ampa + (1. - exp(dt*((AlphaTmax_ampa * on_ampa)*(( ( - 1.0 ) )) - (Beta_ampa)*(1.0))))*(- ( ((AlphaTmax_ampa)*(on_ampa))*(( 1.0 )) ) / ( ((AlphaTmax_ampa)*(on_ampa))*(( ( - 1.0) )) - (Beta_ampa)*(1.0) ) - r_ampa) ;
    capoolcon = capoolcon + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / tauCa)))*(- ( ((- fCa)*(Afactor))*(ICa) + ( ( Cainf ) ) / tauCa ) / ( ( ( ( - 1.0) ) ) / tauCa ) - capoolcon) ;
   }
  return 0;
}
 
static void _net_receive (_pnt, _args, _lflag) Point_process* _pnt; double* _args; double _lflag; 
{  double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   _thread = (Datum*)0; _nt = (_NrnThread*)_pnt->_vnt;   _p = _pnt->_prop->param; _ppvar = _pnt->_prop->dparam;
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
   } }
 
double sfunc ( _threadargsprotocomma_ double _lv ) {
   double _lsfunc;
  _lsfunc = 1.0 / ( 1.0 + 0.33 * exp ( - 0.06 * _lv ) ) ;
    
return _lsfunc;
 }
 
static double _hoc_sfunc(void* _vptr) {
 double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   _p = ((Point_process*)_vptr)->_prop->param;
  _ppvar = ((Point_process*)_vptr)->_prop->dparam;
  _thread = _extcall_thread;
  _nt = (_NrnThread*)((Point_process*)_vptr)->_vnt;
 _r =  sfunc ( _p, _ppvar, _thread, _nt, *getarg(1) );
 return(_r);
}
 
double eta ( _threadargsprotocomma_ double _lCani ) {
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
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   _p = ((Point_process*)_vptr)->_prop->param;
  _ppvar = ((Point_process*)_vptr)->_prop->dparam;
  _thread = _extcall_thread;
  _nt = (_NrnThread*)((Point_process*)_vptr)->_vnt;
 _r =  eta ( _p, _ppvar, _thread, _nt, *getarg(1) );
 return(_r);
}
 
double omega ( _threadargsprotocomma_ double _lCani , double _lthreshold1 , double _lthreshold2 ) {
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
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   _p = ((Point_process*)_vptr)->_prop->param;
  _ppvar = ((Point_process*)_vptr)->_prop->dparam;
  _thread = _extcall_thread;
  _nt = (_NrnThread*)((Point_process*)_vptr)->_vnt;
 _r =  omega ( _p, _ppvar, _thread, _nt, *getarg(1) , *getarg(2) , *getarg(3) );
 return(_r);
}
 
double NEn ( _threadargsprotocomma_ double _lNEstart1 , double _lNEstop1 ) {
   double _lNEn;
 double _lNEtemp1 , _lNEtemp2 , _lNEtemp3 , _lNEtemp4 , _lNEtemp5 , _lNEtemp6 , _lNEtemp7 , _lNEtemp8 , _lNEtemp9 , _lNEtemp10 , _lNEtemp11 , _lNEtemp12 , _lNEtemp13 , _lNEtemp14 , _lNEtemp15 , _lNEtemp16 , _lNEtemp17 , _lNEtemp18 , _lNEtemp19 , _lNEtemp20 , _lNEtemp21 , _lNEtemp22 , _lNEtemp23 , _lNEtemp24 , _lNEtemp25 , _lNEtemp26 , _lNEtemp27 , _lNEtemp28 , _lNEtemp29 , _lNEtemp30 , _lNEtemp31 , _lNEtemp32 , _lNEtemp33 , _lNEtemp34 , _ls ;
 _lNEtemp1 = _lNEstart1 + 4000.0 ;
   _lNEtemp2 = _lNEtemp1 + 4000.0 ;
   _lNEtemp3 = _lNEtemp2 + 4000.0 ;
   _lNEtemp4 = _lNEtemp3 + 4000.0 ;
   _lNEtemp5 = _lNEtemp4 + 4000.0 ;
   _lNEtemp6 = _lNEtemp5 + 4000.0 ;
   _lNEtemp7 = _lNEtemp6 + 4000.0 ;
   _lNEtemp8 = _lNEtemp7 + 4000.0 ;
   _lNEtemp9 = _lNEtemp8 + 4000.0 ;
   _lNEtemp10 = _lNEtemp9 + 4000.0 ;
   _lNEtemp11 = _lNEtemp10 + 4000.0 ;
   _lNEtemp12 = _lNEtemp11 + 4000.0 ;
   _lNEtemp13 = _lNEtemp12 + 4000.0 ;
   _lNEtemp14 = _lNEtemp13 + 4000.0 ;
   _lNEtemp15 = _lNEtemp14 + 4000.0 + 100000.0 ;
   _lNEtemp16 = _lNEtemp15 + 4000.0 ;
   _lNEtemp17 = _lNEtemp16 + 4000.0 ;
   _lNEtemp18 = _lNEtemp17 + 4000.0 ;
   _lNEtemp19 = _lNEtemp18 + 4000.0 ;
   _lNEtemp20 = _lNEtemp19 + 4000.0 ;
   _lNEtemp21 = _lNEtemp20 + 4000.0 ;
   _lNEtemp22 = _lNEtemp21 + 4000.0 ;
   _lNEtemp23 = _lNEtemp22 + 4000.0 ;
   _lNEtemp24 = _lNEtemp23 + 4000.0 ;
   _lNEtemp25 = _lNEtemp24 + 4000.0 ;
   _lNEtemp26 = _lNEtemp25 + 4000.0 ;
   _lNEtemp27 = _lNEtemp26 + 4000.0 ;
   _lNEtemp28 = _lNEtemp27 + 4000.0 ;
   _lNEtemp29 = _lNEtemp28 + 4000.0 ;
   _lNEtemp30 = _lNEtemp29 + 4000.0 ;
   _lNEtemp31 = _lNEtemp30 + 4000.0 ;
   _lNEtemp32 = _lNEtemp31 + 4000.0 ;
   _lNEtemp33 = _lNEtemp32 + 4000.0 ;
   _lNEtemp34 = _lNEtemp33 + 4000.0 ;
   if ( t <= _lNEstart1 ) {
     _lNEn = 1.0 ;
     }
   else if ( t >= _lNEstart1  && t <= _lNEstop1 ) {
     _lNEn = NE_t1 ;
     }
   else if ( t > _lNEstop1  && t < _lNEtemp1 ) {
     _lNEn = 1.0 + ( NE_t1 - 1.0 ) * exp ( - Beta1 * ( t - _lNEstop1 ) ) ;
     }
   else if ( t >= _lNEtemp1  && t <= _lNEtemp1 + 500.0 ) {
     _lNEn = NE_t1 ;
     }
   else if ( t > _lNEtemp1 + 500.0  && t < _lNEtemp2 ) {
     _lNEn = 1.0 + ( NE_t1 - 1.0 ) * exp ( - Beta1 * ( t - _lNEstop1 ) ) ;
     }
   else if ( t >= _lNEtemp2  && t <= _lNEtemp2 + 500.0 ) {
     _lNEn = NE_t1 ;
     }
   else if ( t > _lNEtemp2 + 500.0  && t < _lNEtemp3 ) {
     _lNEn = 1.0 + ( NE_t1 - 1.0 ) * exp ( - Beta1 * ( t - ( _lNEtemp2 + 500.0 ) ) ) ;
     }
   else if ( t >= _lNEtemp3  && t <= _lNEtemp3 + 500.0 ) {
     _lNEn = NE_t1 ;
     }
   else if ( t > _lNEtemp3 + 500.0  && t < _lNEtemp4 ) {
     _lNEn = 1.0 + ( NE_t1 - 1.0 ) * exp ( - Beta1 * ( t - ( _lNEtemp3 + 500.0 ) ) ) ;
     }
   else if ( t >= _lNEtemp4  && t <= _lNEtemp4 + 500.0 ) {
     _lNEn = NE_t1 ;
     }
   else if ( t > _lNEtemp4 + 500.0  && t < _lNEtemp5 ) {
     _lNEn = 1.0 + ( NE_t1 - 1.0 ) * exp ( - Beta1 * ( t - ( _lNEtemp4 + 500.0 ) ) ) ;
     }
   else if ( t >= _lNEtemp5  && t <= _lNEtemp5 + 500.0 ) {
     _lNEn = NE_t1 ;
     }
   else if ( t > _lNEtemp5 + 500.0  && t < _lNEtemp6 ) {
     _lNEn = 1.0 + ( NE_t1 - 1.0 ) * exp ( - Beta1 * ( t - ( _lNEtemp5 + 500.0 ) ) ) ;
     }
   else if ( t >= _lNEtemp6  && t <= _lNEtemp6 + 500.0 ) {
     _lNEn = NE_t1 ;
     }
   else if ( t > _lNEtemp6 + 500.0  && t < _lNEtemp7 ) {
     _lNEn = 1.0 + ( NE_t1 - 1.0 ) * exp ( - Beta1 * ( t - ( _lNEtemp6 + 500.0 ) ) ) ;
     }
   else if ( t >= _lNEtemp7  && t <= _lNEtemp7 + 500.0 ) {
     _lNEn = NE_t2 ;
     }
   else if ( t > _lNEtemp7 + 500.0  && t < _lNEtemp8 ) {
     _lNEn = 1.0 + ( NE_t2 - 1.0 ) * exp ( - Beta2 * ( t - ( _lNEtemp7 + 500.0 ) ) ) ;
     }
   else if ( t >= _lNEtemp8  && t <= _lNEtemp8 + 500.0 ) {
     _lNEn = NE_t2 ;
     }
   else if ( t > _lNEtemp8 + 500.0  && t < _lNEtemp9 ) {
     _lNEn = 1.0 + ( NE_t2 - 1.0 ) * exp ( - Beta2 * ( t - ( _lNEtemp8 + 500.0 ) ) ) ;
     }
   else if ( t >= _lNEtemp9  && t <= _lNEtemp9 + 500.0 ) {
     _lNEn = NE_t2 ;
     }
   else if ( t > _lNEtemp9 + 500.0  && t < _lNEtemp10 ) {
     _lNEn = 1.0 + ( NE_t2 - 1.0 ) * exp ( - Beta2 * ( t - ( _lNEtemp9 + 500.0 ) ) ) ;
     }
   else if ( t >= _lNEtemp10  && t <= _lNEtemp10 + 500.0 ) {
     _lNEn = NE_t2 ;
     }
   else if ( t > _lNEtemp10 + 500.0  && t < _lNEtemp11 ) {
     _lNEn = 1.0 + ( NE_t2 - 1.0 ) * exp ( - Beta2 * ( t - ( _lNEtemp10 + 500.0 ) ) ) ;
     }
   else if ( t >= _lNEtemp11  && t <= _lNEtemp11 + 500.0 ) {
     _lNEn = NE_t2 ;
     }
   else if ( t > _lNEtemp11 + 500.0  && t < _lNEtemp12 ) {
     _lNEn = 1.0 + ( NE_t2 - 1.0 ) * exp ( - Beta2 * ( t - ( _lNEtemp11 + 500.0 ) ) ) ;
     }
   else if ( t >= _lNEtemp12  && t <= _lNEtemp12 + 500.0 ) {
     _lNEn = NE_t2 ;
     }
   else if ( t > _lNEtemp12 + 500.0  && t < _lNEtemp13 ) {
     _lNEn = 1.0 + ( NE_t2 - 1.0 ) * exp ( - Beta2 * ( t - ( _lNEtemp12 + 500.0 ) ) ) ;
     }
   else if ( t >= _lNEtemp13  && t <= _lNEtemp13 + 500.0 ) {
     _lNEn = NE_t2 ;
     }
   else if ( t > _lNEtemp13 + 500.0  && t < _lNEtemp14 ) {
     _lNEn = 1.0 + ( NE_t2 - 1.0 ) * exp ( - Beta2 * ( t - ( _lNEtemp13 + 500.0 ) ) ) ;
     }
   else if ( t >= _lNEtemp14  && t <= _lNEtemp14 + 500.0 ) {
     _lNEn = NE_t2 ;
     }
   else if ( t > _lNEtemp14 + 500.0  && t < _lNEtemp15 ) {
     _lNEn = 1.0 + ( NE_t2 - 1.0 ) * exp ( - Beta2 * ( t - ( _lNEtemp14 + 500.0 ) ) ) ;
     }
   else if ( t >= _lNEtemp15  && t <= _lNEtemp15 + 500.0 ) {
     _lNEn = NE_t2 ;
     }
   else if ( t > _lNEtemp15 + 500.0  && t < _lNEtemp16 ) {
     _lNEn = 1.0 + ( NE_t2 - 1.0 ) * exp ( - Beta2 * ( t - ( _lNEtemp15 + 500.0 ) ) ) ;
     }
   else if ( t >= _lNEtemp16  && t <= _lNEtemp16 + 500.0 ) {
     _lNEn = NE_t2 ;
     }
   else if ( t > _lNEtemp16 + 500.0  && t < _lNEtemp17 ) {
     _lNEn = 1.0 + ( NE_t2 - 1.0 ) * exp ( - Beta2 * ( t - ( _lNEtemp16 + 500.0 ) ) ) ;
     }
   else if ( t >= _lNEtemp17  && t <= _lNEtemp17 + 500.0 ) {
     _lNEn = NE_t2 ;
     }
   else if ( t > _lNEtemp17 + 500.0  && t < _lNEtemp18 ) {
     _lNEn = 1.0 + ( NE_t2 - 1.0 ) * exp ( - Beta2 * ( t - ( _lNEtemp17 + 500.0 ) ) ) ;
     }
   else if ( t >= _lNEtemp18  && t <= _lNEtemp18 + 500.0 ) {
     _lNEn = NE_t2 ;
     }
   else if ( t > _lNEtemp18 + 500.0  && t < _lNEtemp19 ) {
     _lNEn = 1.0 + ( NE_t2 - 1.0 ) * exp ( - Beta2 * ( t - ( _lNEtemp18 + 500.0 ) ) ) ;
     }
   else if ( t >= _lNEtemp19  && t <= _lNEtemp19 + 500.0 ) {
     _lNEn = NE_t3 ;
     }
   else if ( t > _lNEtemp19 + 500.0  && t < _lNEtemp20 ) {
     _lNEn = 1.0 + ( NE_t2 - 1.0 ) * exp ( - Beta2 * ( t - ( _lNEtemp19 + 500.0 ) ) ) ;
     }
   else if ( t >= _lNEtemp20  && t <= _lNEtemp20 + 500.0 ) {
     _lNEn = NE_t3 ;
     }
   else if ( t > _lNEtemp20 + 500.0  && t < _lNEtemp21 ) {
     _lNEn = 1.0 + ( NE_t2 - 1.0 ) * exp ( - Beta2 * ( t - ( _lNEtemp20 + 500.0 ) ) ) ;
     }
   else if ( t >= _lNEtemp21  && t <= _lNEtemp21 + 500.0 ) {
     _lNEn = NE_t3 ;
     }
   else if ( t > _lNEtemp21 + 500.0  && t < _lNEtemp22 ) {
     _lNEn = 1.0 + ( NE_t2 - 1.0 ) * exp ( - Beta2 * ( t - ( _lNEtemp21 + 500.0 ) ) ) ;
     }
   else if ( t >= _lNEtemp22  && t <= _lNEtemp22 + 500.0 ) {
     _lNEn = NE_t3 ;
     }
   else if ( t > _lNEtemp22 + 500.0  && t < _lNEtemp23 ) {
     _lNEn = 1.0 + ( NE_t2 - 1.0 ) * exp ( - Beta2 * ( t - ( _lNEtemp22 + 500.0 ) ) ) ;
     }
   else if ( t >= _lNEtemp23  && t <= _lNEtemp23 + 500.0 ) {
     _lNEn = NE_t3 ;
     }
   else if ( t > _lNEtemp23 + 500.0  && t < _lNEtemp24 ) {
     _lNEn = 1.0 + ( NE_t2 - 1.0 ) * exp ( - Beta2 * ( t - ( _lNEtemp23 + 500.0 ) ) ) ;
     }
   else if ( t >= _lNEtemp24  && t <= _lNEtemp24 + 500.0 ) {
     _lNEn = NE_t3 ;
     }
   else if ( t > _lNEtemp24 + 500.0  && t < _lNEtemp25 ) {
     _lNEn = 1.0 + ( NE_t2 - 1.0 ) * exp ( - Beta2 * ( t - ( _lNEtemp24 + 500.0 ) ) ) ;
     }
   else if ( t >= _lNEtemp25  && t <= _lNEtemp25 + 500.0 ) {
     _lNEn = NE_t3 ;
     }
   else if ( t > _lNEtemp25 + 500.0  && t < _lNEtemp26 ) {
     _lNEn = 1.0 + ( NE_t2 - 1.0 ) * exp ( - Beta2 * ( t - ( _lNEtemp25 + 500.0 ) ) ) ;
     }
   else if ( t >= _lNEtemp26  && t <= _lNEtemp26 + 500.0 ) {
     _lNEn = NE_t3 ;
     }
   else if ( t > _lNEtemp26 + 500.0  && t < _lNEtemp27 ) {
     _lNEn = 1.0 + ( NE_t2 - 1.0 ) * exp ( - Beta2 * ( t - ( _lNEtemp26 + 500.0 ) ) ) ;
     }
   else if ( t >= _lNEtemp27  && t <= _lNEtemp27 + 500.0 ) {
     _lNEn = NE_t3 ;
     }
   else if ( t > _lNEtemp27 + 500.0  && t < _lNEtemp28 ) {
     _lNEn = 1.0 + ( NE_t2 - 1.0 ) * exp ( - Beta2 * ( t - ( _lNEtemp27 + 500.0 ) ) ) ;
     }
   else if ( t >= _lNEtemp28  && t <= _lNEtemp28 + 500.0 ) {
     _lNEn = NE_t3 ;
     }
   else if ( t > _lNEtemp28 + 500.0  && t < _lNEtemp29 ) {
     _lNEn = 1.0 + ( NE_t2 - 1.0 ) * exp ( - Beta2 * ( t - ( _lNEtemp28 + 500.0 ) ) ) ;
     }
   else if ( t >= _lNEtemp29  && t <= _lNEtemp29 + 500.0 ) {
     _lNEn = NE_t3 ;
     }
   else if ( t > _lNEtemp29 + 500.0  && t < _lNEtemp30 ) {
     _lNEn = 1.0 + ( NE_t2 - 1.0 ) * exp ( - Beta2 * ( t - ( _lNEtemp29 + 500.0 ) ) ) ;
     }
   else if ( t >= _lNEtemp30  && t <= _lNEtemp30 + 500.0 ) {
     _lNEn = NE_t3 ;
     }
   else if ( t > _lNEtemp30 + 500.0  && t < _lNEtemp31 ) {
     _lNEn = 1.0 + ( NE_t2 - 1.0 ) * exp ( - Beta2 * ( t - ( _lNEtemp30 + 500.0 ) ) ) ;
     }
   else if ( t >= _lNEtemp31  && t <= _lNEtemp31 + 500.0 ) {
     _lNEn = NE_t3 ;
     }
   else if ( t > _lNEtemp31 + 500.0  && t < _lNEtemp32 ) {
     _lNEn = 1.0 + ( NE_t2 - 1.0 ) * exp ( - Beta2 * ( t - ( _lNEtemp31 + 500.0 ) ) ) ;
     }
   else if ( t >= _lNEtemp32  && t <= _lNEtemp32 + 500.0 ) {
     _lNEn = NE_t3 ;
     }
   else if ( t > _lNEtemp32 + 500.0  && t < _lNEtemp33 ) {
     _lNEn = 1.0 + ( NE_t2 - 1.0 ) * exp ( - Beta2 * ( t - ( _lNEtemp32 + 500.0 ) ) ) ;
     }
   else if ( t >= _lNEtemp33  && t <= _lNEtemp33 + 500.0 ) {
     _lNEn = NE_t3 ;
     }
   else if ( t > _lNEtemp33 + 500.0  && t < _lNEtemp34 ) {
     _lNEn = 1.0 + ( NE_t2 - 1.0 ) * exp ( - Beta2 * ( t - ( _lNEtemp33 + 500.0 ) ) ) ;
     }
   else if ( t >= _lNEtemp34  && t <= _lNEtemp34 + 500.0 ) {
     _lNEn = NE_t3 ;
     }
   else {
     _lNEn = 1.0 ;
     }
   
return _lNEn;
 }
 
static double _hoc_NEn(void* _vptr) {
 double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   _p = ((Point_process*)_vptr)->_prop->param;
  _ppvar = ((Point_process*)_vptr)->_prop->dparam;
  _thread = _extcall_thread;
  _nt = (_NrnThread*)((Point_process*)_vptr)->_vnt;
 _r =  NEn ( _p, _ppvar, _thread, _nt, *getarg(1) , *getarg(2) );
 return(_r);
}
 
double NE2 ( _threadargsprotocomma_ double _lNEstart2 , double _lNEstop2 ) {
   double _lNE2;
 double _lNE2temp1 , _lNE2temp2 , _lNE2temp3 , _lNE2temp4 , _lNE2temp5 , _lNE2temp6 , _lNE2temp7 , _lNE2temp8 , _lNE2temp9 , _lNE2temp10 , _lNE2temp11 , _lNE2temp12 , _lNE2temp13 , _lNE2temp14 , _lNE2temp15 , _lNE2temp16 , _ls ;
 _lNE2temp1 = _lNEstart2 + 4000.0 ;
   _lNE2temp2 = _lNE2temp1 + 4000.0 ;
   _lNE2temp3 = _lNE2temp2 + 4000.0 ;
   _lNE2temp4 = _lNE2temp3 + 4000.0 ;
   _lNE2temp5 = _lNE2temp4 + 4000.0 ;
   _lNE2temp6 = _lNE2temp5 + 4000.0 ;
   _lNE2temp7 = _lNE2temp6 + 4000.0 ;
   _lNE2temp8 = _lNE2temp7 + 4000.0 ;
   _lNE2temp9 = _lNE2temp8 + 4000.0 ;
   _lNE2temp10 = _lNE2temp9 + 4000.0 ;
   _lNE2temp11 = _lNE2temp10 + 4000.0 ;
   _lNE2temp12 = _lNE2temp11 + 4000.0 ;
   _lNE2temp13 = _lNE2temp12 + 4000.0 ;
   _lNE2temp14 = _lNE2temp13 + 4000.0 ;
   _lNE2temp15 = _lNE2temp14 + 4000.0 ;
   if ( t <= _lNEstart2 ) {
     _lNE2 = 1.0 ;
     }
   else if ( t >= _lNEstart2  && t <= _lNEstop2 ) {
     _lNE2 = NE_S ;
     }
   else if ( t > _lNEstop2  && t < _lNE2temp1 ) {
     _lNE2 = 1.0 + ( NE_S - 1.0 ) * exp ( - Beta2 * ( t - ( _lNEstop2 + 500.0 ) ) ) ;
     }
   else if ( t >= _lNE2temp1  && t <= _lNE2temp1 + 100.0 ) {
     _lNE2 = NE_S ;
     }
   else if ( t > _lNE2temp1 + 100.0  && t < _lNE2temp2 ) {
     _lNE2 = 1.0 + ( NE_S - 1.0 ) * exp ( - Beta2 * ( t - ( _lNE2temp1 + 100.0 ) ) ) ;
     }
   else if ( t >= _lNE2temp2  && t <= _lNE2temp2 + 100.0 ) {
     _lNE2 = NE_S ;
     }
   else if ( t > _lNE2temp2 + 100.0  && t < _lNE2temp3 ) {
     _lNE2 = 1.0 + ( NE_S - 1.0 ) * exp ( - Beta2 * ( t - ( _lNE2temp2 + 100.0 ) ) ) ;
     }
   else if ( t >= _lNE2temp3  && t <= _lNE2temp3 + 100.0 ) {
     _lNE2 = NE_S ;
     }
   else if ( t > _lNE2temp3 + 100.0  && t < _lNE2temp4 ) {
     _lNE2 = 1.0 + ( NE_S - 1.0 ) * exp ( - Beta2 * ( t - ( _lNE2temp3 + 100.0 ) ) ) ;
     }
   else if ( t >= _lNE2temp4  && t <= _lNE2temp4 + 100.0 ) {
     _lNE2 = NE_S ;
     }
   else if ( t > _lNE2temp4 + 100.0  && t < _lNE2temp5 ) {
     _lNE2 = 1.0 + ( NE_S - 1.0 ) * exp ( - Beta2 * ( t - ( _lNE2temp4 + 100.0 ) ) ) ;
     }
   else if ( t >= _lNE2temp5  && t <= _lNE2temp5 + 100.0 ) {
     _lNE2 = NE_S ;
     }
   else if ( t > _lNE2temp5 + 100.0  && t < _lNE2temp6 ) {
     _lNE2 = 1.0 + ( NE_S - 1.0 ) * exp ( - Beta2 * ( t - ( _lNE2temp5 + 100.0 ) ) ) ;
     }
   else if ( t >= _lNE2temp6  && t <= _lNE2temp6 + 100.0 ) {
     _lNE2 = NE_S ;
     }
   else if ( t > _lNE2temp6 + 100.0  && t < _lNE2temp7 ) {
     _lNE2 = 1.0 + ( NE_S - 1.0 ) * exp ( - Beta2 * ( t - ( _lNE2temp6 + 100.0 ) ) ) ;
     }
   else if ( t >= _lNE2temp7  && t <= _lNE2temp7 + 100.0 ) {
     _lNE2 = NE_S ;
     }
   else if ( t > _lNE2temp7 + 100.0  && t < _lNE2temp8 ) {
     _lNE2 = 1.0 + ( NE_S - 1.0 ) * exp ( - Beta2 * ( t - ( _lNE2temp7 + 100.0 ) ) ) ;
     }
   else if ( t >= _lNE2temp8  && t <= _lNE2temp8 + 100.0 ) {
     _lNE2 = NE_S ;
     }
   else if ( t > _lNE2temp8 + 100.0  && t < _lNE2temp9 ) {
     _lNE2 = 1.0 + ( NE_S - 1.0 ) * exp ( - Beta2 * ( t - ( _lNE2temp8 + 100.0 ) ) ) ;
     }
   else if ( t >= _lNE2temp9  && t <= _lNE2temp9 + 100.0 ) {
     _lNE2 = NE_S ;
     }
   else if ( t > _lNE2temp9 + 100.0  && t < _lNE2temp10 ) {
     _lNE2 = 1.0 + ( NE_S - 1.0 ) * exp ( - Beta2 * ( t - ( _lNE2temp9 + 100.0 ) ) ) ;
     }
   else if ( t >= _lNE2temp10  && t <= _lNE2temp10 + 100.0 ) {
     _lNE2 = NE_S ;
     }
   else if ( t > _lNE2temp10 + 100.0  && t < _lNE2temp11 ) {
     _lNE2 = 1.0 + ( NE_S - 1.0 ) * exp ( - Beta2 * ( t - ( _lNE2temp10 + 100.0 ) ) ) ;
     }
   else if ( t >= _lNE2temp11  && t <= _lNE2temp11 + 100.0 ) {
     _lNE2 = NE_S ;
     }
   else if ( t > _lNE2temp11 + 100.0  && t < _lNE2temp12 ) {
     _lNE2 = 1.0 + ( NE_S - 1.0 ) * exp ( - Beta2 * ( t - ( _lNE2temp11 + 100.0 ) ) ) ;
     }
   else if ( t >= _lNE2temp12  && t <= _lNE2temp12 + 100.0 ) {
     _lNE2 = NE_S ;
     }
   else if ( t > _lNE2temp12 + 100.0  && t < _lNE2temp13 ) {
     _lNE2 = 1.0 + ( NE_S - 1.0 ) * exp ( - Beta2 * ( t - ( _lNE2temp12 + 100.0 ) ) ) ;
     }
   else if ( t >= _lNE2temp13  && t <= _lNE2temp13 + 100.0 ) {
     _lNE2 = NE_S ;
     }
   else if ( t > _lNE2temp13 + 100.0  && t < _lNE2temp14 ) {
     _lNE2 = 1.0 + ( NE_S - 1.0 ) * exp ( - Beta2 * ( t - ( _lNE2temp13 + 100.0 ) ) ) ;
     }
   else if ( t >= _lNE2temp14  && t <= _lNE2temp14 + 100.0 ) {
     _lNE2 = NE_S ;
     }
   else if ( t > _lNE2temp14 + 100.0  && t < _lNE2temp15 ) {
     _lNE2 = 1.0 + ( NE_S - 1.0 ) * exp ( - Beta2 * ( t - ( _lNE2temp14 + 100.0 ) ) ) ;
     }
   else if ( t >= _lNE2temp15  && t <= _lNE2temp15 + 100.0 ) {
     _lNE2 = NE_S ;
     }
   else {
     _lNE2 = 1.0 ;
     }
   
return _lNE2;
 }
 
static double _hoc_NE2(void* _vptr) {
 double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   _p = ((Point_process*)_vptr)->_prop->param;
  _ppvar = ((Point_process*)_vptr)->_prop->dparam;
  _thread = _extcall_thread;
  _nt = (_NrnThread*)((Point_process*)_vptr)->_vnt;
 _r =  NE2 ( _p, _ppvar, _thread, _nt, *getarg(1) , *getarg(2) );
 return(_r);
}
 
static int _ode_count(int _type){ return 4;}
 
static void _ode_spec(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  eca = _ion_eca;
     _ode_spec1 (_p, _ppvar, _thread, _nt);
 }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
	double* _p; Datum* _ppvar;
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 4; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 
static void _ode_matsol(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  eca = _ion_eca;
 _ode_matsol1 (_p, _ppvar, _thread, _nt);
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_ca_sym, _ppvar, 2, 0);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
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
   t0 = - 1.0 ;
   Wmax = fmax * initW ;
   Wmin = fmin * initW ;
   maxChange = ( Wmax - Wmin ) / 10.0 ;
   dW_ampa = 0.0 ;
   capoolcon = Cainf ;
   Afactor = 1.0 / ( z * FARADAY * 4.0 / 3.0 * pi * pow( ( pooldiam / 2.0 ) , 3.0 ) ) * ( 1e6 ) ;
   }
 
}
}

static void nrn_init(_NrnThread* _nt, _Memb_list* _ml, int _type){
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
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
 initmodel(_p, _ppvar, _thread, _nt);
}}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _v){double _current=0.;v=_v;{ {
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
     if ( t - t0 < Cdur_ampa ) {
       on_ampa = 1.0 ;
       }
     else {
       on_ampa = 0.0 ;
       }
     }
   if ( neuroM >= 2.0 ) {
     g_nmda = gbar_nmda * r_nmda * NEn ( _threadargscomma_ NEstart1 , NEstop1 ) * NE2 ( _threadargscomma_ NEstart2 , NEstop2 ) ;
     }
   else {
     g_nmda = gbar_nmda * r_nmda ;
     }
   inmda = W_nmda * g_nmda * ( v - Erev_nmda ) * sfunc ( _threadargscomma_ v ) ;
   g_ampa = gbar_ampa * r_ampa ;
   iampa = W * g_ampa * ( v - Erev_ampa ) ;
   ICa = P0 * g_nmda * ( v - eca ) * sfunc ( _threadargscomma_ v ) ;
   }
 _current += inmda;
 _current += iampa;

} return _current;
}

static void nrn_cur(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
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
 _g = _nrn_current(_p, _ppvar, _thread, _nt, _v + .001);
 	{ _rhs = _nrn_current(_p, _ppvar, _thread, _nt, _v);
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

static void nrn_jacob(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
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

static void nrn_state(_NrnThread* _nt, _Memb_list* _ml, int _type) {
 double _break, _save;
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
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
   release(_p, _ppvar, _thread, _nt);
  
}}
 t = _save;
 }}}

}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(W) - _p;  _dlist1[0] = &(DW) - _p;
 _slist1[1] = &(r_nmda) - _p;  _dlist1[1] = &(Dr_nmda) - _p;
 _slist1[2] = &(r_ampa) - _p;  _dlist1[2] = &(Dr_ampa) - _p;
 _slist1[3] = &(capoolcon) - _p;  _dlist1[3] = &(Dcapoolcon) - _p;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
