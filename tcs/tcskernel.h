#ifndef __tcs_h
#define __tcs_h

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS 1
#endif

/* tcs: transient computation simulator 
   (c) nrel, 2011,  author: aron dobos */
   
#include <string>
#include <vector>

#include <unordered_map>
using std::unordered_map;
#pragma warning(disable: 4290)  // ignore warning: 'C++ exception specification ignored except to indicate a function is not __declspec(nothrow)'
/*
#ifdef _MSC_VER
#include <unordered_map>
using std::tr1::unordered_map;
#else

//#ifdef _LIBCPP_VERSION
//using libc++
#include <unordered_map>
using std::unordered_map;
//#else
// using libstdc++
//#include <tr1/unordered_map>
//using std::tr1::unordered_map;
//#endif

#endif
*/
#include "tcstype.h"

class tcstypeprovider
{
public:
	tcstypeprovider();
	~tcstypeprovider();
	
	struct dyndata {		
		std::string path;
		void *dynlib;
		tcstypeinfo **types;
	};

	struct typedata	{
		std::string type;
		tcstypeinfo *info;
		dyndata *dyn;
	};
	
	void add_search_path( const std::string &path );
	void clear_search_paths();
	
	void register_type( const std::string &type, tcstypeinfo *ti );

	int load_library( const std::string &type );
	void unload_libraries();	

	std::vector<tcstypeprovider::typedata> types();

	tcstypeinfo *find_type( const std::string &type );

	std::vector<std::string> messages();

private:
	std::vector<typedata> m_types;	
	std::vector<dyndata> m_libraries;
	std::vector<std::string> m_pathList;
	std::vector<std::string> m_messages;
};

class tcskernel
{
public:
	tcskernel( tcstypeprovider *prov );
	virtual ~tcskernel();
	
	int copy( tcskernel &tk );
	
	virtual void message( const std::string & text, int msgtype );
	virtual bool progress( float perecent, const std::string &text );
	virtual bool converged( double time );
	virtual int simulate( double start, double end, double step );

	std::string netlist();

	int version();
	void set_max_iterations( int iter, bool proceed_anyway );

	double current_time();
	double time_step();
		
	int add_unit( const std::string &type, const std::string &name = "" );
	void clear_units();
	void set_unit_name( int id, const std::string &name );
	void set_unit_value( int id, int idx, double val );
	void set_unit_value( int id, int idx, double *p, int len );
	void set_unit_value( int id, int idx, double *p, int nr, int nc );
	void set_unit_value( int id, int idx, const char *s );
		
	void set_unit_value( int id, const char *name, double val );
	void set_unit_value( int id, const char *name, double *p, int len );
	void set_unit_value( int id, const char *name, double *p, int nr, int nc );
	void set_unit_value( int id, const char *name, const char *s );

	double get_unit_value_number( int id, const char *name );
	const char *get_unit_value_string( int id, const char *name );
	double *get_unit_value( int id, const char *name, int *len );
	double *get_unit_value( int id, const char *name, int *nr, int *nc );

	bool parse_unit_value( int id, const char *name, const char *value );
	static bool parse_unit_value( tcsvalue *v, int type, const char *value );


	bool connect( int unit1, int output, 
			int unit2, int input,
			double tol = 0.1, // default convergence tolerance 0.1%
			int arridx = -1 ); // index of value to propagate, in case a ARRAY feeds a NUMBER
	
	bool connect( int unit1, const char *var1,
			int unit2, const char *var2,
			double tol = 0.1,
			int arridx = -1 );
	
	void message( int msgtype, const char *fmt, ... );
	void message( int unit, int msgtype, const char *message );
	
	static bool check_tolerance( double val1, double val2, double ftol );

			
	int solve( double time, double step );
	
	void create_instances();
	void free_instances();
	
	struct connection {
		int target_unit;
		int target_index;
		double ftol;
		int arridx;
	};
	
	struct unit {
		int id;
		std::string name;
		tcstypeinfo *type;
		std::vector<tcsvalue> values;
		std::vector< std::vector<connection> > conn;
		int ncall;
		bool mustcall;
		void *instance;
		tcscontext context;
	};

			
protected:
	int find_var( int unit, const char *name );
	bool m_proceedAnyway;
	int m_maxIterations;
	double m_currentTime;
	double m_timeStep;
	double m_startTime;
	double m_endTime;
	std::vector<unit> m_units;
	
	tcstypeprovider *m_provider;
};

#endif
