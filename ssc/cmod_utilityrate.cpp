#include "core.h"


static var_info vtab_utility_rate[] = {

/*   VARTYPE           DATATYPE         NAME                         LABEL                                           UNITS     META                      GROUP          REQUIRED_IF                 CONSTRAINTS                      UI_HINTS*/
	{ SSC_INPUT,        SSC_NUMBER,     "analysis_years",           "Number of years in analysis",                   "years",  "",                      "",             "*",                         "INTEGER,POSITIVE",              "" },
	{ SSC_INPUT,        SSC_ARRAY,      "e_with_system",            "Net energy at grid with system",                "kWh",    "",                      "",             "*",                         "LENGTH=8760",                   "" },
	{ SSC_INPUT,        SSC_ARRAY,      "p_with_system",            "Max power at grid with system",                 "kW",     "",                      "",             "?",                         "LENGTH=8760",                   "" },
	{ SSC_INPUT,        SSC_ARRAY,      "e_without_system",            "Net energy at grid without system (load only)", "kWh",    "",                      "",             "?",                         "LENGTH=8760",                   "" },
	{ SSC_INPUT,        SSC_ARRAY,      "p_without_system",         "Max power at grid without system (load only)",  "kW",     "",                      "",             "?",                         "LENGTH=8760",                   "" },

	{ SSC_INPUT,        SSC_ARRAY,      "system_availability",       "Annual availability of system",    "%/year", "",                      "",             "?=100",                       "",                              "" },
	{ SSC_INPUT,        SSC_ARRAY,      "system_degradation",       "Annual degradation of system",    "%/year", "",                      "",             "?=0",                       "",                              "" },
	{ SSC_INPUT,        SSC_ARRAY,      "load_escalation",          "Annual load escalation",          "%/year", "",                      "",             "?=0",                       "",                              "" },
	{ SSC_INPUT,        SSC_ARRAY,      "rate_escalation",          "Annual utility rate escalation",  "%/year", "",                      "",             "?=0",                       "",                              "" },
	
	{ SSC_INPUT,        SSC_NUMBER,     "ur_sell_eq_buy",           "Force sell rate equal to buy",    "0/1",    "Enforce net metering",  "",             "?=1",                       "BOOLEAN",                       "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_monthly_fixed_charge",  "Monthly fixed charge",            "$",      "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_flat_buy_rate",         "Flat rate (buy)",                 "$/kWh",  "",                      "",             "*",                         "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_flat_sell_rate",        "Flat rate (sell)",                "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	
	// Energy Charge Inputs
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_enable",            "Enable energy charge",        "0/1",    "",                      "",             "?=0",                       "BOOLEAN",                       "" },

	{ SSC_INPUT,        SSC_STRING,     "ur_ec_sched_weekday",     "Energy Charge Weekday Schedule",            "",       "288 digits 1-12, 24x12", "",             "ur_ec_enable=1",           "TOUSCHED",                      "" },
	{ SSC_INPUT,        SSC_STRING,     "ur_ec_sched_weekend",     "Energy Charge Weekend Schedule",            "",       "288 digits 1-12, 24x12", "",             "ur_ec_enable=1",           "TOUSCHED",                      "" },
	
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p1_t1_br",       "Period 1 Tier 1 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p1_t1_sr",       "Period 1 Tier 1 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p1_t1_ub",       "Period 1 Tier 1 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p1_t2_br",       "Period 1 Tier 2 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p1_t2_sr",       "Period 1 Tier 2 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p1_t2_ub",       "Period 1 Tier 2 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p1_t3_br",       "Period 1 Tier 3 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p1_t3_sr",       "Period 1 Tier 3 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p1_t3_ub",       "Period 1 Tier 3 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p1_t4_br",       "Period 1 Tier 4 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p1_t4_sr",       "Period 1 Tier 4 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p1_t4_ub",       "Period 1 Tier 4 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p1_t5_br",       "Period 1 Tier 5 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p1_t5_sr",       "Period 1 Tier 5 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p1_t5_ub",       "Period 1 Tier 5 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p1_t6_br",       "Period 1 Tier 6 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p1_t6_sr",       "Period 1 Tier 6 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p1_t6_ub",       "Period 1 Tier 6 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },

	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p2_t1_br",       "Period 2 Tier 1 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p2_t1_sr",       "Period 2 Tier 1 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p2_t1_ub",       "Period 2 Tier 1 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p2_t2_br",       "Period 2 Tier 2 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p2_t2_sr",       "Period 2 Tier 2 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p2_t2_ub",       "Period 2 Tier 2 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p2_t3_br",       "Period 2 Tier 3 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p2_t3_sr",       "Period 2 Tier 3 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p2_t3_ub",       "Period 2 Tier 3 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p2_t4_br",       "Period 2 Tier 4 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p2_t4_sr",       "Period 2 Tier 4 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p2_t4_ub",       "Period 2 Tier 4 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p2_t5_br",       "Period 2 Tier 5 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p2_t5_sr",       "Period 2 Tier 5 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p2_t5_ub",       "Period 2 Tier 5 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p2_t6_br",       "Period 2 Tier 6 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p2_t6_sr",       "Period 2 Tier 6 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p2_t6_ub",       "Period 2 Tier 6 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },

	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p3_t1_br",       "Period 3 Tier 1 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p3_t1_sr",       "Period 3 Tier 1 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p3_t1_ub",       "Period 3 Tier 1 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p3_t2_br",       "Period 3 Tier 2 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p3_t2_sr",       "Period 3 Tier 2 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p3_t2_ub",       "Period 3 Tier 2 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p3_t3_br",       "Period 3 Tier 3 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p3_t3_sr",       "Period 3 Tier 3 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p3_t3_ub",       "Period 3 Tier 3 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p3_t4_br",       "Period 3 Tier 4 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p3_t4_sr",       "Period 3 Tier 4 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p3_t4_ub",       "Period 3 Tier 4 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p3_t5_br",       "Period 3 Tier 5 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p3_t5_sr",       "Period 3 Tier 5 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p3_t5_ub",       "Period 3 Tier 5 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p3_t6_br",       "Period 3 Tier 6 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p3_t6_sr",       "Period 3 Tier 6 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p3_t6_ub",       "Period 3 Tier 6 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },

	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p4_t1_br",       "Period 4 Tier 1 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p4_t1_sr",       "Period 4 Tier 1 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p4_t1_ub",       "Period 4 Tier 1 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p4_t2_br",       "Period 4 Tier 2 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p4_t2_sr",       "Period 4 Tier 2 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p4_t2_ub",       "Period 4 Tier 2 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p4_t3_br",       "Period 4 Tier 3 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p4_t3_sr",       "Period 4 Tier 3 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p4_t3_ub",       "Period 4 Tier 3 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p4_t4_br",       "Period 4 Tier 4 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p4_t4_sr",       "Period 4 Tier 4 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p4_t4_ub",       "Period 4 Tier 4 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p4_t5_br",       "Period 4 Tier 5 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p4_t5_sr",       "Period 4 Tier 5 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p4_t5_ub",       "Period 4 Tier 5 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p4_t6_br",       "Period 4 Tier 6 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p4_t6_sr",       "Period 4 Tier 6 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p4_t6_ub",       "Period 4 Tier 6 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },

	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p5_t1_br",       "Period 5 Tier 1 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p5_t1_sr",       "Period 5 Tier 1 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p5_t1_ub",       "Period 5 Tier 1 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p5_t2_br",       "Period 5 Tier 2 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p5_t2_sr",       "Period 5 Tier 2 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p5_t2_ub",       "Period 5 Tier 2 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p5_t3_br",       "Period 5 Tier 3 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p5_t3_sr",       "Period 5 Tier 3 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p5_t3_ub",       "Period 5 Tier 3 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p5_t4_br",       "Period 5 Tier 4 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p5_t4_sr",       "Period 5 Tier 4 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p5_t4_ub",       "Period 5 Tier 4 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p5_t5_br",       "Period 5 Tier 5 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p5_t5_sr",       "Period 5 Tier 5 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p5_t5_ub",       "Period 5 Tier 5 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p5_t6_br",       "Period 5 Tier 6 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p5_t6_sr",       "Period 5 Tier 6 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p5_t6_ub",       "Period 5 Tier 6 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },

	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p6_t1_br",       "Period 6 Tier 1 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p6_t1_sr",       "Period 6 Tier 1 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p6_t1_ub",       "Period 6 Tier 1 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p6_t2_br",       "Period 6 Tier 2 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p6_t2_sr",       "Period 6 Tier 2 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p6_t2_ub",       "Period 6 Tier 2 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p6_t3_br",       "Period 6 Tier 3 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p6_t3_sr",       "Period 6 Tier 3 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p6_t3_ub",       "Period 6 Tier 3 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p6_t4_br",       "Period 6 Tier 4 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p6_t4_sr",       "Period 6 Tier 4 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p6_t4_ub",       "Period 6 Tier 4 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p6_t5_br",       "Period 6 Tier 5 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p6_t5_sr",       "Period 6 Tier 5 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p6_t5_ub",       "Period 6 Tier 5 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p6_t6_br",       "Period 6 Tier 6 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p6_t6_sr",       "Period 6 Tier 6 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p6_t6_ub",       "Period 6 Tier 6 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },

	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p7_t1_br",       "Period 7 Tier 1 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p7_t1_sr",       "Period 7 Tier 1 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p7_t1_ub",       "Period 7 Tier 1 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p7_t2_br",       "Period 7 Tier 2 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p7_t2_sr",       "Period 7 Tier 2 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p7_t2_ub",       "Period 7 Tier 2 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p7_t3_br",       "Period 7 Tier 3 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p7_t3_sr",       "Period 7 Tier 3 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p7_t3_ub",       "Period 7 Tier 3 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p7_t4_br",       "Period 7 Tier 4 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p7_t4_sr",       "Period 7 Tier 4 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p7_t4_ub",       "Period 7 Tier 4 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p7_t5_br",       "Period 7 Tier 5 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p7_t5_sr",       "Period 7 Tier 5 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p7_t5_ub",       "Period 7 Tier 5 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p7_t6_br",       "Period 7 Tier 6 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p7_t6_sr",       "Period 7 Tier 6 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p7_t6_ub",       "Period 7 Tier 6 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },

	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p8_t1_br",       "Period 8 Tier 1 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p8_t1_sr",       "Period 8 Tier 1 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p8_t1_ub",       "Period 8 Tier 1 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p8_t2_br",       "Period 8 Tier 2 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p8_t2_sr",       "Period 8 Tier 2 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p8_t2_ub",       "Period 8 Tier 2 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p8_t3_br",       "Period 8 Tier 3 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p8_t3_sr",       "Period 8 Tier 3 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p8_t3_ub",       "Period 8 Tier 3 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p8_t4_br",       "Period 8 Tier 4 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p8_t4_sr",       "Period 8 Tier 4 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p8_t4_ub",       "Period 8 Tier 4 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p8_t5_br",       "Period 8 Tier 5 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p8_t5_sr",       "Period 8 Tier 5 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p8_t5_ub",       "Period 8 Tier 5 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p8_t6_br",       "Period 8 Tier 6 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p8_t6_sr",       "Period 8 Tier 6 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p8_t6_ub",       "Period 8 Tier 6 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },

	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p9_t1_br",       "Period 9 Tier 1 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p9_t1_sr",       "Period 9 Tier 1 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p9_t1_ub",       "Period 9 Tier 1 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p9_t2_br",       "Period 9 Tier 2 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p9_t2_sr",       "Period 9 Tier 2 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p9_t2_ub",       "Period 9 Tier 2 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p9_t3_br",       "Period 9 Tier 3 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p9_t3_sr",       "Period 9 Tier 3 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p9_t3_ub",       "Period 9 Tier 3 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p9_t4_br",       "Period 9 Tier 4 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p9_t4_sr",       "Period 9 Tier 4 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p9_t4_ub",       "Period 9 Tier 4 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p9_t5_br",       "Period 9 Tier 5 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p9_t5_sr",       "Period 9 Tier 5 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p9_t5_ub",       "Period 9 Tier 5 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p9_t6_br",       "Period 9 Tier 6 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p9_t6_sr",       "Period 9 Tier 6 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p9_t6_ub",       "Period 9 Tier 6 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },

	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p10_t1_br",       "Period 10 Tier 1 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p10_t1_sr",       "Period 10 Tier 1 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p10_t1_ub",       "Period 10 Tier 1 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p10_t2_br",       "Period 10 Tier 2 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p10_t2_sr",       "Period 10 Tier 2 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p10_t2_ub",       "Period 10 Tier 2 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p10_t3_br",       "Period 10 Tier 3 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p10_t3_sr",       "Period 10 Tier 3 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p10_t3_ub",       "Period 10 Tier 3 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p10_t4_br",       "Period 10 Tier 4 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p10_t4_sr",       "Period 10 Tier 4 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p10_t4_ub",       "Period 10 Tier 4 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p10_t5_br",       "Period 10 Tier 5 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p10_t5_sr",       "Period 10 Tier 5 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p10_t5_ub",       "Period 10 Tier 5 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p10_t6_br",       "Period 10 Tier 6 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p10_t6_sr",       "Period 10 Tier 6 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p10_t6_ub",       "Period 10 Tier 6 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },

	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p11_t1_br",       "Period 11 Tier 1 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p11_t1_sr",       "Period 11 Tier 1 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p11_t1_ub",       "Period 11 Tier 1 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p11_t2_br",       "Period 11 Tier 2 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p11_t2_sr",       "Period 11 Tier 2 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p11_t2_ub",       "Period 11 Tier 2 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p11_t3_br",       "Period 11 Tier 3 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p11_t3_sr",       "Period 11 Tier 3 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p11_t3_ub",       "Period 11 Tier 3 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p11_t4_br",       "Period 11 Tier 4 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p11_t4_sr",       "Period 11 Tier 4 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p11_t4_ub",       "Period 11 Tier 4 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p11_t5_br",       "Period 11 Tier 5 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p11_t5_sr",       "Period 11 Tier 5 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p11_t5_ub",       "Period 11 Tier 5 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p11_t6_br",       "Period 11 Tier 6 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p11_t6_sr",       "Period 11 Tier 6 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p11_t6_ub",       "Period 11 Tier 6 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },

	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p12_t1_br",       "Period 12 Tier 1 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p12_t1_sr",       "Period 12 Tier 1 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p12_t1_ub",       "Period 12 Tier 1 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p12_t2_br",       "Period 12 Tier 2 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p12_t2_sr",       "Period 12 Tier 2 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p12_t2_ub",       "Period 12 Tier 2 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p12_t3_br",       "Period 12 Tier 3 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p12_t3_sr",       "Period 12 Tier 3 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p12_t3_ub",       "Period 12 Tier 3 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p12_t4_br",       "Period 12 Tier 4 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p12_t4_sr",       "Period 12 Tier 4 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p12_t4_ub",       "Period 12 Tier 4 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p12_t5_br",       "Period 12 Tier 5 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p12_t5_sr",       "Period 12 Tier 5 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p12_t5_ub",       "Period 12 Tier 5 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p12_t6_br",       "Period 12 Tier 6 Energy Buy Rate",         "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p12_t6_sr",       "Period 12 Tier 6 Energy Sell Rate",        "$/kWh",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_ec_p12_t6_ub",       "Period 12 Tier 6 Maximum Energy Usage",         "kWh",  "",                      "",             "?=0.0",                     "",                              "" },



	// Demand Charge Inputs
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_enable",            "Enable Demand Charge",        "0/1",    "",                      "",             "?=0",                       "BOOLEAN",                       "" },

	{ SSC_INPUT,        SSC_STRING,     "ur_dc_sched_weekday",     "Demand Charge Weekday Schedule",            "",       "288 digits 1-12, 24x12", "",             "ur_ec_enable=1",           "TOUSCHED",                      "" },
	{ SSC_INPUT,        SSC_STRING,     "ur_dc_sched_weekend",     "Demend Charge Weekend Schedule",            "",       "288 digits 1-12, 24x12", "",             "ur_ec_enable=1",           "TOUSCHED",                      "" },

	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p1_t1_dc",       "Period 1 Tier 1 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p1_t1_ub",       "Period 1 Tier 1 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p1_t2_dc",       "Period 1 Tier 2 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p1_t2_ub",       "Period 1 Tier 2 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p1_t3_dc",       "Period 1 Tier 3 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p1_t3_ub",       "Period 1 Tier 3 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p1_t4_dc",       "Period 1 Tier 4 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p1_t4_ub",       "Period 1 Tier 4 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p1_t5_dc",       "Period 1 Tier 5 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p1_t5_ub",       "Period 1 Tier 5 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p1_t6_dc",       "Period 1 Tier 6 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p1_t6_ub",       "Period 1 Tier 6 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },

	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p2_t1_dc",       "Period 2 Tier 1 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p2_t1_ub",       "Period 2 Tier 1 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p2_t2_dc",       "Period 2 Tier 2 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p2_t2_ub",       "Period 2 Tier 2 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p2_t3_dc",       "Period 2 Tier 3 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p2_t3_ub",       "Period 2 Tier 3 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p2_t4_dc",       "Period 2 Tier 4 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p2_t4_ub",       "Period 2 Tier 4 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p2_t5_dc",       "Period 2 Tier 5 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p2_t5_ub",       "Period 2 Tier 5 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p2_t6_dc",       "Period 2 Tier 6 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p2_t6_ub",       "Period 2 Tier 6 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },

	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p3_t1_dc",       "Period 3 Tier 1 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p3_t1_ub",       "Period 3 Tier 1 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p3_t2_dc",       "Period 3 Tier 2 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p3_t2_ub",       "Period 3 Tier 2 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p3_t3_dc",       "Period 3 Tier 3 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p3_t3_ub",       "Period 3 Tier 3 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p3_t4_dc",       "Period 3 Tier 4 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p3_t4_ub",       "Period 3 Tier 4 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p3_t5_dc",       "Period 3 Tier 5 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p3_t5_ub",       "Period 3 Tier 5 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p3_t6_dc",       "Period 3 Tier 6 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p3_t6_ub",       "Period 3 Tier 6 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },

	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p4_t1_dc",       "Period 4 Tier 1 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p4_t1_ub",       "Period 4 Tier 1 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p4_t2_dc",       "Period 4 Tier 2 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p4_t2_ub",       "Period 4 Tier 2 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p4_t3_dc",       "Period 4 Tier 3 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p4_t3_ub",       "Period 4 Tier 3 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p4_t4_dc",       "Period 4 Tier 4 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p4_t4_ub",       "Period 4 Tier 4 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p4_t5_dc",       "Period 4 Tier 5 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p4_t5_ub",       "Period 4 Tier 5 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p4_t6_dc",       "Period 4 Tier 6 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p4_t6_ub",       "Period 4 Tier 6 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },

	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p5_t1_dc",       "Period 5 Tier 1 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p5_t1_ub",       "Period 5 Tier 1 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p5_t2_dc",       "Period 5 Tier 2 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p5_t2_ub",       "Period 5 Tier 2 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p5_t3_dc",       "Period 5 Tier 3 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p5_t3_ub",       "Period 5 Tier 3 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p5_t4_dc",       "Period 5 Tier 4 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p5_t4_ub",       "Period 5 Tier 4 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p5_t5_dc",       "Period 5 Tier 5 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p5_t5_ub",       "Period 5 Tier 5 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p5_t6_dc",       "Period 5 Tier 6 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p5_t6_ub",       "Period 5 Tier 6 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },

	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p6_t1_dc",       "Period 6 Tier 1 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p6_t1_ub",       "Period 6 Tier 1 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p6_t2_dc",       "Period 6 Tier 2 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p6_t2_ub",       "Period 6 Tier 2 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p6_t3_dc",       "Period 6 Tier 3 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p6_t3_ub",       "Period 6 Tier 3 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p6_t4_dc",       "Period 6 Tier 4 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p6_t4_ub",       "Period 6 Tier 4 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p6_t5_dc",       "Period 6 Tier 5 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p6_t5_ub",       "Period 6 Tier 5 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p6_t6_dc",       "Period 6 Tier 6 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p6_t6_ub",       "Period 6 Tier 6 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },

	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p7_t1_dc",       "Period 7 Tier 1 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p7_t1_ub",       "Period 7 Tier 1 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p7_t2_dc",       "Period 7 Tier 2 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p7_t2_ub",       "Period 7 Tier 2 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p7_t3_dc",       "Period 7 Tier 3 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p7_t3_ub",       "Period 7 Tier 3 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p7_t4_dc",       "Period 7 Tier 4 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p7_t4_ub",       "Period 7 Tier 4 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p7_t5_dc",       "Period 7 Tier 5 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p7_t5_ub",       "Period 7 Tier 5 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p7_t6_dc",       "Period 7 Tier 6 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p7_t6_ub",       "Period 7 Tier 6 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },

	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p8_t1_dc",       "Period 8 Tier 1 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p8_t1_ub",       "Period 8 Tier 1 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p8_t2_dc",       "Period 8 Tier 2 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p8_t2_ub",       "Period 8 Tier 2 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p8_t3_dc",       "Period 8 Tier 3 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p8_t3_ub",       "Period 8 Tier 3 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p8_t4_dc",       "Period 8 Tier 4 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p8_t4_ub",       "Period 8 Tier 4 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p8_t5_dc",       "Period 8 Tier 5 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p8_t5_ub",       "Period 8 Tier 5 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p8_t6_dc",       "Period 8 Tier 6 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p8_t6_ub",       "Period 8 Tier 6 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },

	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p9_t1_dc",       "Period 9 Tier 1 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p9_t1_ub",       "Period 9 Tier 1 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p9_t2_dc",       "Period 9 Tier 2 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p9_t2_ub",       "Period 9 Tier 2 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p9_t3_dc",       "Period 9 Tier 3 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p9_t3_ub",       "Period 9 Tier 3 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p9_t4_dc",       "Period 9 Tier 4 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p9_t4_ub",       "Period 9 Tier 4 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p9_t5_dc",       "Period 9 Tier 5 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p9_t5_ub",       "Period 9 Tier 5 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p9_t6_dc",       "Period 9 Tier 6 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p9_t6_ub",       "Period 9 Tier 6 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },

	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p10_t1_dc",       "Period 10 Tier 1 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p10_t1_ub",       "Period 10 Tier 1 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p10_t2_dc",       "Period 10 Tier 2 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p10_t2_ub",       "Period 10 Tier 2 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p10_t3_dc",       "Period 10 Tier 3 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p10_t3_ub",       "Period 10 Tier 3 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p10_t4_dc",       "Period 10 Tier 4 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p10_t4_ub",       "Period 10 Tier 4 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p10_t5_dc",       "Period 10 Tier 5 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p10_t5_ub",       "Period 10 Tier 5 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p10_t6_dc",       "Period 10 Tier 6 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p10_t6_ub",       "Period 10 Tier 6 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },

	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p11_t1_dc",       "Period 11 Tier 1 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p11_t1_ub",       "Period 11 Tier 1 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p11_t2_dc",       "Period 11 Tier 2 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p11_t2_ub",       "Period 11 Tier 2 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p11_t3_dc",       "Period 11 Tier 3 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p11_t3_ub",       "Period 11 Tier 3 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p11_t4_dc",       "Period 11 Tier 4 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p11_t4_ub",       "Period 11 Tier 4 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p11_t5_dc",       "Period 11 Tier 5 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p11_t5_ub",       "Period 11 Tier 5 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p11_t6_dc",       "Period 11 Tier 6 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p11_t6_ub",       "Period 11 Tier 6 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },

	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p12_t1_dc",       "Period 12 Tier 1 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p12_t1_ub",       "Period 12 Tier 1 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p12_t2_dc",       "Period 12 Tier 2 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p12_t2_ub",       "Period 12 Tier 2 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p12_t3_dc",       "Period 12 Tier 3 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p12_t3_ub",       "Period 12 Tier 3 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p12_t4_dc",       "Period 12 Tier 4 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p12_t4_ub",       "Period 12 Tier 4 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p12_t5_dc",       "Period 12 Tier 5 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p12_t5_ub",       "Period 12 Tier 5 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p12_t6_dc",       "Period 12 Tier 6 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_p12_t6_ub",       "Period 12 Tier 6 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },

	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_jan_t1_dc",       "January Tier 1 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_jan_t1_ub",       "January Tier 1 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_jan_t2_dc",       "January Tier 2 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_jan_t2_ub",       "January Tier 2 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_jan_t3_dc",       "January Tier 3 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_jan_t3_ub",       "January Tier 3 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_jan_t4_dc",       "January Tier 4 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_jan_t4_ub",       "January Tier 4 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_jan_t5_dc",       "January Tier 5 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_jan_t5_ub",       "January Tier 5 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_jan_t6_dc",       "January Tier 6 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_jan_t6_ub",       "January Tier 6 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },

	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_feb_t1_dc",       "February Tier 1 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_feb_t1_ub",       "February Tier 1 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_feb_t2_dc",       "February Tier 2 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_feb_t2_ub",       "February Tier 2 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_feb_t3_dc",       "February Tier 3 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_feb_t3_ub",       "February Tier 3 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_feb_t4_dc",       "February Tier 4 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_feb_t4_ub",       "February Tier 4 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_feb_t5_dc",       "February Tier 5 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_feb_t5_ub",       "February Tier 5 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_feb_t6_dc",       "February Tier 6 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_feb_t6_ub",       "February Tier 6 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },

	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_mar_t1_dc",       "March Tier 1 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_mar_t1_ub",       "March Tier 1 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_mar_t2_dc",       "March Tier 2 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_mar_t2_ub",       "March Tier 2 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_mar_t3_dc",       "March Tier 3 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_mar_t3_ub",       "March Tier 3 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_mar_t4_dc",       "March Tier 4 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_mar_t4_ub",       "March Tier 4 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_mar_t5_dc",       "March Tier 5 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_mar_t5_ub",       "March Tier 5 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_mar_t6_dc",       "March Tier 6 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_mar_t6_ub",       "March Tier 6 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },

	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_apr_t1_dc",       "April Tier 1 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_apr_t1_ub",       "April Tier 1 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_apr_t2_dc",       "April Tier 2 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_apr_t2_ub",       "April Tier 2 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_apr_t3_dc",       "April Tier 3 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_apr_t3_ub",       "April Tier 3 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_apr_t4_dc",       "April Tier 4 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_apr_t4_ub",       "April Tier 4 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_apr_t5_dc",       "April Tier 5 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_apr_t5_ub",       "April Tier 5 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_apr_t6_dc",       "April Tier 6 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_apr_t6_ub",       "April Tier 6 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },

	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_may_t1_dc",       "May Tier 1 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_may_t1_ub",       "May Tier 1 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_may_t2_dc",       "May Tier 2 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_may_t2_ub",       "May Tier 2 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_may_t3_dc",       "May Tier 3 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_may_t3_ub",       "May Tier 3 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_may_t4_dc",       "May Tier 4 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_may_t4_ub",       "May Tier 4 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_may_t5_dc",       "May Tier 5 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_may_t5_ub",       "May Tier 5 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_may_t6_dc",       "May Tier 6 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_may_t6_ub",       "May Tier 6 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },

	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_jun_t1_dc",       "June Tier 1 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_jun_t1_ub",       "June Tier 1 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_jun_t2_dc",       "June Tier 2 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_jun_t2_ub",       "June Tier 2 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_jun_t3_dc",       "June Tier 3 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_jun_t3_ub",       "June Tier 3 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_jun_t4_dc",       "June Tier 4 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_jun_t4_ub",       "June Tier 4 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_jun_t5_dc",       "June Tier 5 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_jun_t5_ub",       "June Tier 5 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_jun_t6_dc",       "June Tier 6 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_jun_t6_ub",       "June Tier 6 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },

	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_jul_t1_dc",       "July Tier 1 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_jul_t1_ub",       "July Tier 1 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_jul_t2_dc",       "July Tier 2 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_jul_t2_ub",       "July Tier 2 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_jul_t3_dc",       "July Tier 3 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_jul_t3_ub",       "July Tier 3 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_jul_t4_dc",       "July Tier 4 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_jul_t4_ub",       "July Tier 4 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_jul_t5_dc",       "July Tier 5 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_jul_t5_ub",       "July Tier 5 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_jul_t6_dc",       "July Tier 6 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_jul_t6_ub",       "July Tier 6 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },

	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_aug_t1_dc",       "August Tier 1 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_aug_t1_ub",       "August Tier 1 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_aug_t2_dc",       "August Tier 2 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_aug_t2_ub",       "August Tier 2 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_aug_t3_dc",       "August Tier 3 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_aug_t3_ub",       "August Tier 3 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_aug_t4_dc",       "August Tier 4 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_aug_t4_ub",       "August Tier 4 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_aug_t5_dc",       "August Tier 5 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_aug_t5_ub",       "August Tier 5 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_aug_t6_dc",       "August Tier 6 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_aug_t6_ub",       "August Tier 6 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },

	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_sep_t1_dc",       "September Tier 1 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_sep_t1_ub",       "September Tier 1 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_sep_t2_dc",       "September Tier 2 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_sep_t2_ub",       "September Tier 2 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_sep_t3_dc",       "September Tier 3 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_sep_t3_ub",       "September Tier 3 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_sep_t4_dc",       "September Tier 4 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_sep_t4_ub",       "September Tier 4 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_sep_t5_dc",       "September Tier 5 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_sep_t5_ub",       "September Tier 5 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_sep_t6_dc",       "September Tier 6 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_sep_t6_ub",       "September Tier 6 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },

	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_oct_t1_dc",       "October Tier 1 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_oct_t1_ub",       "October Tier 1 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_oct_t2_dc",       "October Tier 2 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_oct_t2_ub",       "October Tier 2 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_oct_t3_dc",       "October Tier 3 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_oct_t3_ub",       "October Tier 3 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_oct_t4_dc",       "October Tier 4 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_oct_t4_ub",       "October Tier 4 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_oct_t5_dc",       "October Tier 5 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_oct_t5_ub",       "October Tier 5 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_oct_t6_dc",       "October Tier 6 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_oct_t6_ub",       "October Tier 6 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },

	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_nov_t1_dc",       "November Tier 1 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_nov_t1_ub",       "November Tier 1 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_nov_t2_dc",       "November Tier 2 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_nov_t2_ub",       "November Tier 2 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_nov_t3_dc",       "November Tier 3 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_nov_t3_ub",       "November Tier 3 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_nov_t4_dc",       "November Tier 4 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_nov_t4_ub",       "November Tier 4 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_nov_t5_dc",       "November Tier 5 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_nov_t5_ub",       "November Tier 5 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_nov_t6_dc",       "November Tier 6 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_nov_t6_ub",       "November Tier 6 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },

	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_dec_t1_dc",       "December Tier 1 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_dec_t1_ub",       "December Tier 1 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_dec_t2_dc",       "December Tier 2 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_dec_t2_ub",       "December Tier 2 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_dec_t3_dc",       "December Tier 3 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_dec_t3_ub",       "December Tier 3 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_dec_t4_dc",       "December Tier 4 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_dec_t4_ub",       "December Tier 4 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_dec_t5_dc",       "December Tier 5 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_dec_t5_ub",       "December Tier 5 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_dec_t6_dc",       "December Tier 6 Demand Charge",         "$/kW",  "",                      "",             "?=0.0",                     "",                              "" },
	{ SSC_INPUT,        SSC_NUMBER,     "ur_dc_dec_t6_ub",       "December Tier 6 Peak Demand",         "kW",  "",                      "",             "?=0.0",                     "",                              "" },





	
	// outputs
	{ SSC_OUTPUT,       SSC_ARRAY,      "energy_value",             "Net energy value in each year",     "$",    "",                      "",             "*",                         "LENGTH_EQUAL=analysis_years",   "" },
	{ SSC_OUTPUT,       SSC_ARRAY,      "energy_net",               "Net energy in each year",           "kW",   "",                      "",             "*",                         "LENGTH_EQUAL=analysis_years",   "" },
	{ SSC_OUTPUT,       SSC_ARRAY,      "revenue_with_system",      "Total revenue with system",         "$",    "",                      "",             "*",                         "LENGTH_EQUAL=analysis_years",   "" },
	{ SSC_OUTPUT,       SSC_ARRAY,      "revenue_without_system",   "Total revenue without system",      "$",    "",                      "",             "*",                         "LENGTH_EQUAL=analysis_years",   "" },
	
	{ SSC_OUTPUT,       SSC_ARRAY,      "year1_hourly_e_grid",         "Year 1 hourly electricity at grid",       "kWh", "",                      "",             "*",                         "LENGTH=8760",                   "" },
	{ SSC_OUTPUT,       SSC_ARRAY,      "year1_hourly_system_output",  "Year 1 hourly electricity from system",     "kWh", "",                      "",             "*",                         "LENGTH=8760",                   "" },
	{ SSC_OUTPUT,       SSC_ARRAY,      "year1_hourly_e_demand",       "Year 1 hourly electricity from grid",     "kWh", "",                      "",             "*",                         "LENGTH=8760",                   "" },
	
	{ SSC_OUTPUT,       SSC_ARRAY,      "year1_hourly_system_to_grid",    "Year 1 hourly electricity to grid",     "kWh", "",                      "",             "*",                         "LENGTH=8760",                   "" },
	{ SSC_OUTPUT,       SSC_ARRAY,      "year1_hourly_system_to_load",    "Year 1 hourly electricity to load",     "kWh", "",                      "",             "*",                         "LENGTH=8760",                   "" },

	{ SSC_OUTPUT,       SSC_ARRAY,      "year1_hourly_p_grid",         "Year 1 subhourly peak at grid ", "kW",  "",                      "",             "*",                         "LENGTH=8760",                   "" },
	{ SSC_OUTPUT,       SSC_ARRAY,      "year1_hourly_p_demand",       "Year 1 subhourly peak from grid", "kW",  "",                      "",             "*",                         "LENGTH=8760",                   "" },
	
	{ SSC_OUTPUT,       SSC_ARRAY,      "year1_hourly_p_system_to_load",         "Year 1 subhourly peak to load ", "kW",  "",                      "",             "*",                         "LENGTH=8760",                   "" },
	

	{ SSC_OUTPUT,       SSC_ARRAY,      "year1_hourly_revenue_with_system",     "Year 1 Hourly revenue with system",    "$", "",          "",             "*",                         "LENGTH=8760",                   "" },
	{ SSC_OUTPUT,       SSC_ARRAY,      "year1_hourly_payment_with_system",     "Year 1 Hourly payment with system",    "$", "",          "",             "*",                         "LENGTH=8760",                   "" },
	{ SSC_OUTPUT,       SSC_ARRAY,      "year1_hourly_income_with_system",      "Year 1 Hourly income with system",     "$", "",          "",             "*",                         "LENGTH=8760",                   "" },
	{ SSC_OUTPUT,       SSC_ARRAY,      "year1_hourly_price_with_system",       "Year 1 Hourly price with system",      "$", "",          "",             "*",                         "LENGTH=8760",                   "" },
	
	{ SSC_OUTPUT,       SSC_ARRAY,      "year1_hourly_revenue_without_system",  "Year 1 Hourly revenue without system", "$", "",          "",             "*",                         "LENGTH=8760",                   "" },
	{ SSC_OUTPUT,       SSC_ARRAY,      "year1_hourly_payment_without_system",  "Year 1 Hourly payment without system", "$", "",          "",             "*",                         "LENGTH=8760",                   "" },
	{ SSC_OUTPUT,       SSC_ARRAY,      "year1_hourly_income_without_system",   "Year 1 Hourly income without system",  "$", "",          "",             "*",                         "LENGTH=8760",                   "" },
	{ SSC_OUTPUT,       SSC_ARRAY,      "year1_hourly_price_without_system",    "Year 1 Hourly price without system",   "$", "",          "",             "*",                         "LENGTH=8760",                   "" },
	
	{ SSC_OUTPUT,       SSC_ARRAY,      "year1_monthly_dc_fixed_with_system",      "Year 1 monthly demand charge (Fixed) with system",    "$", "", "",          "*",                         "LENGTH=12",                     "" },
	{ SSC_OUTPUT,       SSC_ARRAY,      "year1_monthly_dc_tou_with_system",        "Year 1 monthly demand charge (TOU) with system",      "$", "", "",          "*",                         "LENGTH=12",                     "" },
	{ SSC_OUTPUT,       SSC_ARRAY,      "year1_monthly_tr_charge_with_system",     "Year 1 monthly tiered charge with system",            "$", "", "",          "*",                         "LENGTH=12",                     "" },
	{ SSC_OUTPUT,       SSC_ARRAY,      "year1_monthly_tr_rate_with_system",       "Year 1 monthly tiered rate with system",              "$", "", "",          "*",                         "LENGTH=12",                     "" },
	
	{ SSC_OUTPUT,       SSC_ARRAY,      "year1_monthly_dc_fixed_without_system",   "Year 1 monthly demand charge (Fixed) without system", "$", "", "",          "*",                         "LENGTH=12",                     "" },
	{ SSC_OUTPUT,       SSC_ARRAY,      "year1_monthly_dc_tou_without_system",     "Year 1 monthly demand charge (TOU) without system",   "$", "", "",          "*",                         "LENGTH=12",                     "" },
	{ SSC_OUTPUT,       SSC_ARRAY,      "year1_monthly_tr_charge_without_system",  "Year 1 monthly tiered charge without system",         "$", "", "",          "*",                         "LENGTH=12",                     "" },
	{ SSC_OUTPUT,       SSC_ARRAY,      "year1_monthly_tr_rate_without_system",    "Year 1 monthly tiered rate without system",           "$", "", "",          "*",                         "LENGTH=12",                     "" },
	
	{ SSC_OUTPUT,       SSC_ARRAY,      "charge_dc_fixed_jan",      "Demand Charge (Fixed) in Jan",    "$",      "",                      "",             "*",                         "LENGTH_EQUAL=analysis_years",   "" },
	{ SSC_OUTPUT,       SSC_ARRAY,      "charge_dc_fixed_feb",      "Demand Charge (Fixed) in Feb",    "$",      "",                      "",             "*",                         "LENGTH_EQUAL=analysis_years",   "" },
	{ SSC_OUTPUT,       SSC_ARRAY,      "charge_dc_fixed_mar",      "Demand Charge (Fixed) in Mar",    "$",      "",                      "",             "*",                         "LENGTH_EQUAL=analysis_years",   "" },
	{ SSC_OUTPUT,       SSC_ARRAY,      "charge_dc_fixed_apr",      "Demand Charge (Fixed) in Apr",    "$",      "",                      "",             "*",                         "LENGTH_EQUAL=analysis_years",   "" },
	{ SSC_OUTPUT,       SSC_ARRAY,      "charge_dc_fixed_may",      "Demand Charge (Fixed) in May",    "$",      "",                      "",             "*",                         "LENGTH_EQUAL=analysis_years",   "" },
	{ SSC_OUTPUT,       SSC_ARRAY,      "charge_dc_fixed_jun",      "Demand Charge (Fixed) in Jun",    "$",      "",                      "",             "*",                         "LENGTH_EQUAL=analysis_years",   "" },
	{ SSC_OUTPUT,       SSC_ARRAY,      "charge_dc_fixed_jul",      "Demand Charge (Fixed) in Jul",    "$",      "",                      "",             "*",                         "LENGTH_EQUAL=analysis_years",   "" },
	{ SSC_OUTPUT,       SSC_ARRAY,      "charge_dc_fixed_aug",      "Demand Charge (Fixed) in Aug",    "$",      "",                      "",             "*",                         "LENGTH_EQUAL=analysis_years",   "" },
	{ SSC_OUTPUT,       SSC_ARRAY,      "charge_dc_fixed_sep",      "Demand Charge (Fixed) in Sep",    "$",      "",                      "",             "*",                         "LENGTH_EQUAL=analysis_years",   "" },
	{ SSC_OUTPUT,       SSC_ARRAY,      "charge_dc_fixed_oct",      "Demand Charge (Fixed) in Oct",    "$",      "",                      "",             "*",                         "LENGTH_EQUAL=analysis_years",   "" },
	{ SSC_OUTPUT,       SSC_ARRAY,      "charge_dc_fixed_nov",      "Demand Charge (Fixed) in Nov",    "$",      "",                      "",             "*",                         "LENGTH_EQUAL=analysis_years",   "" },
	{ SSC_OUTPUT,       SSC_ARRAY,      "charge_dc_fixed_dec",      "Demand Charge (Fixed) in Dec",    "$",      "",                      "",             "*",                         "LENGTH_EQUAL=analysis_years",   "" },

		
	{ SSC_OUTPUT,       SSC_ARRAY,      "charge_dc_tou_jan",        "Demand Charge (TOU) in Jan",      "$",      "",                      "",             "*",                         "LENGTH_EQUAL=analysis_years",   "" },
	{ SSC_OUTPUT,       SSC_ARRAY,      "charge_dc_tou_feb",        "Demand Charge (TOU) in Feb",      "$",      "",                      "",             "*",                         "LENGTH_EQUAL=analysis_years",   "" },
	{ SSC_OUTPUT,       SSC_ARRAY,      "charge_dc_tou_mar",        "Demand Charge (TOU) in Mar",      "$",      "",                      "",             "*",                         "LENGTH_EQUAL=analysis_years",   "" },
	{ SSC_OUTPUT,       SSC_ARRAY,      "charge_dc_tou_apr",        "Demand Charge (TOU) in Apr",      "$",      "",                      "",             "*",                         "LENGTH_EQUAL=analysis_years",   "" },
	{ SSC_OUTPUT,       SSC_ARRAY,      "charge_dc_tou_may",        "Demand Charge (TOU) in May",      "$",      "",                      "",             "*",                         "LENGTH_EQUAL=analysis_years",   "" },
	{ SSC_OUTPUT,       SSC_ARRAY,      "charge_dc_tou_jun",        "Demand Charge (TOU) in Jun",      "$",      "",                      "",             "*",                         "LENGTH_EQUAL=analysis_years",   "" },
	{ SSC_OUTPUT,       SSC_ARRAY,      "charge_dc_tou_jul",        "Demand Charge (TOU) in Jul",      "$",      "",                      "",             "*",                         "LENGTH_EQUAL=analysis_years",   "" },
	{ SSC_OUTPUT,       SSC_ARRAY,      "charge_dc_tou_aug",        "Demand Charge (TOU) in Aug",      "$",      "",                      "",             "*",                         "LENGTH_EQUAL=analysis_years",   "" },
	{ SSC_OUTPUT,       SSC_ARRAY,      "charge_dc_tou_sep",        "Demand Charge (TOU) in Sep",      "$",      "",                      "",             "*",                         "LENGTH_EQUAL=analysis_years",   "" },
	{ SSC_OUTPUT,       SSC_ARRAY,      "charge_dc_tou_oct",        "Demand Charge (TOU) in Oct",      "$",      "",                      "",             "*",                         "LENGTH_EQUAL=analysis_years",   "" },
	{ SSC_OUTPUT,       SSC_ARRAY,      "charge_dc_tou_nov",        "Demand Charge (TOU) in Nov",      "$",      "",                      "",             "*",                         "LENGTH_EQUAL=analysis_years",   "" },
	{ SSC_OUTPUT,       SSC_ARRAY,      "charge_dc_tou_dec",        "Demand Charge (TOU) in Dec",      "$",      "",                      "",             "*",                         "LENGTH_EQUAL=analysis_years",   "" },

	{ SSC_OUTPUT,       SSC_ARRAY,      "charge_ec_jan",            "Energy Charge in Jan",       "$",      "",                      "",             "*",                         "LENGTH_EQUAL=analysis_years",   "" },
	{ SSC_OUTPUT,       SSC_ARRAY,      "charge_ec_feb",            "Energy Rate Charge in Feb",       "$",      "",                      "",             "*",                         "LENGTH_EQUAL=analysis_years",   "" },
	{ SSC_OUTPUT,       SSC_ARRAY,      "charge_ec_mar",            "Energy Rate Charge in Mar",       "$",      "",                      "",             "*",                         "LENGTH_EQUAL=analysis_years",   "" },
	{ SSC_OUTPUT,       SSC_ARRAY,      "charge_ec_apr",            "Energy Rate Charge in Apr",       "$",      "",                      "",             "*",                         "LENGTH_EQUAL=analysis_years",   "" },
	{ SSC_OUTPUT,       SSC_ARRAY,      "charge_ec_may",            "Energy Rate Charge in May",       "$",      "",                      "",             "*",                         "LENGTH_EQUAL=analysis_years",   "" },
	{ SSC_OUTPUT,       SSC_ARRAY,      "charge_ec_jun",            "Energy Rate Charge in Jun",       "$",      "",                      "",             "*",                         "LENGTH_EQUAL=analysis_years",   "" },
	{ SSC_OUTPUT,       SSC_ARRAY,      "charge_ec_jul",            "Energy Rate Charge in Jul",       "$",      "",                      "",             "*",                         "LENGTH_EQUAL=analysis_years",   "" },
	{ SSC_OUTPUT,       SSC_ARRAY,      "charge_ec_aug",            "Energy Rate Charge in Aug",       "$",      "",                      "",             "*",                         "LENGTH_EQUAL=analysis_years",   "" },
	{ SSC_OUTPUT,       SSC_ARRAY,      "charge_ec_sep",            "Energy Rate Charge in Sep",       "$",      "",                      "",             "*",                         "LENGTH_EQUAL=analysis_years",   "" },
	{ SSC_OUTPUT,       SSC_ARRAY,      "charge_ec_oct",            "Energy Rate Charge in Oct",       "$",      "",                      "",             "*",                         "LENGTH_EQUAL=analysis_years",   "" },
	{ SSC_OUTPUT,       SSC_ARRAY,      "charge_ec_nov",            "Energy Rate Charge in Nov",       "$",      "",                      "",             "*",                         "LENGTH_EQUAL=analysis_years",   "" },
	{ SSC_OUTPUT,       SSC_ARRAY,      "charge_ec_dec",            "Energy Rate Charge in Dec",       "$",      "",                      "",             "*",                         "LENGTH_EQUAL=analysis_years",   "" },
	
var_info_invalid };

class cm_utilityrate : public compute_module
{
private:
public:
	cm_utilityrate()
	{
		add_var_info( vtab_utility_rate );
	}

	void exec( ) throw( general_error )
	{
		ssc_number_t *parr = 0;
		size_t count, i, j;

		size_t nyears = (size_t)as_integer("analysis_years");

		// compute annual system output degradation multipliers
		std::vector<ssc_number_t> sys_scale(nyears);
		parr = as_array("system_degradation", &count);
		if (count == 1)
		{
			for (i=0;i<nyears;i++)
				sys_scale[i] = (ssc_number_t) pow( (double)(1-parr[0]*0.01), (double)i );
		}
		else
		{
			for (i=0;i<nyears && i<count;i++)
				sys_scale[i] = (ssc_number_t)(1.0 - parr[i]*0.01);
		}

		// annual availability multipliers
		parr = as_array("system_availability", &count);
		if (count == 1)
		{
			for (i=0;i<nyears;i++)
				sys_scale[i] *= (ssc_number_t) ( parr[0]*0.01 ) ;
		}
		else
		{
			for (i=0;i<nyears && i<count;i++)
				sys_scale[i] *= (ssc_number_t)( parr[i]*0.01 );
		}

		// compute load (electric demand) annual escalation multipliers
		std::vector<ssc_number_t> load_scale(nyears);
		parr = as_array("load_escalation", &count);
		if (count == 1)
		{
			// add in inflation rate - added in interop layer
			for (i=0;i<nyears;i++)
				load_scale[i] = (ssc_number_t)pow( (double)(/*inflation_rate+*/1+parr[0]*0.01), (double)i );
		}
		else
		{
			for (i=0;i<nyears;i++)
				load_scale[i] = (ssc_number_t)(1 + parr[i]*0.01);
		}

		// compute utility rate out-years escalation multipliers
		std::vector<ssc_number_t> rate_scale(nyears);
		parr = as_array("rate_escalation", &count);
		if (count == 1)
		{
			for (i=0;i<nyears;i++)
				rate_scale[i] = (ssc_number_t)pow( (double)(/*inflation_rate+*/1+parr[0]*0.01), (double)i );
		}
		else
		{
			for (i=0;i<nyears;i++)
				rate_scale[i] = (ssc_number_t)(1 + parr[i]*0.01);
		}


		// prepare 8760 arrays for load and grid values
		std::vector<ssc_number_t> e_sys(8760), p_sys(8760), 
			e_load(8760), p_load(8760),
			e_grid(8760), p_grid(8760),
			e_load_cy(8760), p_load_cy(8760); // current year load (accounts for escal)
		
		parr = as_array("e_with_system", &count);
		for (i=0;i<8760;i++)
		{
			e_sys[i] = p_sys[i] = parr[i]; // by default p_sys = e_sys (since it's hourly)
			// others are 0.0
			e_grid[i] = p_grid[i] = e_load[i] = p_load[i] = e_load_cy[i] = p_load_cy[i] = 0.0;
		}

		if (is_assigned("p_with_system"))
		{
			parr = as_array("p_with_system", &count);
			if (count != 8760) throw general_error("p_with_system must have 8760 values");
			for (i=0;i<8760;i++)
				p_sys[i] = parr[i];
		}

		if (is_assigned("e_without_system"))
		{
			parr = as_array("e_without_system", &count);
			if (count != 8760) throw general_error("e_without_system must have 8760 values");
			for (i=0;i<8760;i++)
			{
				e_load[i] = parr[i];
				p_load[i] = parr[i]; // by default p_load = e_load
			}
		}

		if (is_assigned("p_without_system"))
		{
			parr = as_array("p_without_system", &count);
			if (count != 8760) throw general_error("p_without_system must have 8760 values");
			for (i=0;i<8760;i++)
				p_load[i] = parr[i];
		}

		/* allocate intermediate data arrays */
		std::vector<ssc_number_t> revenue_w_sys(8760), revenue_wo_sys(8760),
			payment(8760), income(8760), price(8760);
		std::vector<ssc_number_t> monthly_revenue_w_sys(12), monthly_revenue_wo_sys(12),
			monthly_fixed_charges(12),
			monthly_dc_fixed(12), monthly_dc_tou(12),
			monthly_tr_charges(12), monthly_tr_rates(12);

		/* allocate outputs */		
		ssc_number_t *annual_net_revenue = allocate("energy_value", nyears);
		ssc_number_t *energy_net = allocate("energy_net", nyears);
		ssc_number_t *annual_revenue_w_sys = allocate("revenue_with_system", nyears);
		ssc_number_t *annual_revenue_wo_sys = allocate("revenue_without_system", nyears);

		ssc_number_t *ch_dc_fixed_jan = allocate("charge_dc_fixed_jan", nyears );
		ssc_number_t *ch_dc_fixed_feb = allocate("charge_dc_fixed_feb", nyears );
		ssc_number_t *ch_dc_fixed_mar = allocate("charge_dc_fixed_mar", nyears );
		ssc_number_t *ch_dc_fixed_apr = allocate("charge_dc_fixed_apr", nyears );
		ssc_number_t *ch_dc_fixed_may = allocate("charge_dc_fixed_may", nyears );
		ssc_number_t *ch_dc_fixed_jun = allocate("charge_dc_fixed_jun", nyears );
		ssc_number_t *ch_dc_fixed_jul = allocate("charge_dc_fixed_jul", nyears );
		ssc_number_t *ch_dc_fixed_aug = allocate("charge_dc_fixed_aug", nyears );
		ssc_number_t *ch_dc_fixed_sep = allocate("charge_dc_fixed_sep", nyears );
		ssc_number_t *ch_dc_fixed_oct = allocate("charge_dc_fixed_oct", nyears );
		ssc_number_t *ch_dc_fixed_nov = allocate("charge_dc_fixed_nov", nyears );
		ssc_number_t *ch_dc_fixed_dec = allocate("charge_dc_fixed_dec", nyears );
		
		ssc_number_t *ch_dc_tou_jan = allocate("charge_dc_tou_jan", nyears );
		ssc_number_t *ch_dc_tou_feb = allocate("charge_dc_tou_feb", nyears );
		ssc_number_t *ch_dc_tou_mar = allocate("charge_dc_tou_mar", nyears );
		ssc_number_t *ch_dc_tou_apr = allocate("charge_dc_tou_apr", nyears );
		ssc_number_t *ch_dc_tou_may = allocate("charge_dc_tou_may", nyears );
		ssc_number_t *ch_dc_tou_jun = allocate("charge_dc_tou_jun", nyears );
		ssc_number_t *ch_dc_tou_jul = allocate("charge_dc_tou_jul", nyears );
		ssc_number_t *ch_dc_tou_aug = allocate("charge_dc_tou_aug", nyears );
		ssc_number_t *ch_dc_tou_sep = allocate("charge_dc_tou_sep", nyears );
		ssc_number_t *ch_dc_tou_oct = allocate("charge_dc_tou_oct", nyears );
		ssc_number_t *ch_dc_tou_nov = allocate("charge_dc_tou_nov", nyears );
		ssc_number_t *ch_dc_tou_dec = allocate("charge_dc_tou_dec", nyears );
		
		ssc_number_t *ch_tr_jan = allocate("charge_tr_jan", nyears );
		ssc_number_t *ch_tr_feb = allocate("charge_tr_feb", nyears );
		ssc_number_t *ch_tr_mar = allocate("charge_tr_mar", nyears );
		ssc_number_t *ch_tr_apr = allocate("charge_tr_apr", nyears );
		ssc_number_t *ch_tr_may = allocate("charge_tr_may", nyears );
		ssc_number_t *ch_tr_jun = allocate("charge_tr_jun", nyears );
		ssc_number_t *ch_tr_jul = allocate("charge_tr_jul", nyears );
		ssc_number_t *ch_tr_aug = allocate("charge_tr_aug", nyears );
		ssc_number_t *ch_tr_sep = allocate("charge_tr_sep", nyears );
		ssc_number_t *ch_tr_oct = allocate("charge_tr_oct", nyears );
		ssc_number_t *ch_tr_nov = allocate("charge_tr_nov", nyears );
		ssc_number_t *ch_tr_dec = allocate("charge_tr_dec", nyears );

		for (i=0;i<nyears;i++)
		{
			for (j=0;j<8760;j++)
			{
				// apply load escalation appropriate for current year
				e_load_cy[j] = e_load[j] * load_scale[i];
				p_load_cy[j] = p_load[j] * load_scale[i];

				// calculate e_grid value (e_sys + e_load)
				// note: load is assumed to have negative sign

				e_grid[j] = e_sys[j]*sys_scale[i] + e_load_cy[j];
				p_grid[j] = p_sys[j]*sys_scale[i] + p_load_cy[j];
			}

			// calculate revenue with solar system (using net grid energy & maxpower)
			ur_calc( &e_grid[0], &p_grid[0],
				&revenue_w_sys[0], &payment[0], &income[0], &price[0],
				&monthly_fixed_charges[0],
				&monthly_dc_fixed[0], &monthly_dc_tou[0],
				&monthly_tr_charges[0], &monthly_tr_rates[0] );

			if (i == 0)
			{
				assign( "year1_hourly_revenue_with_system", var_data( &revenue_w_sys[0], 8760 ) );
				assign( "year1_hourly_payment_with_system", var_data( &payment[0], 8760 ) );
				assign( "year1_hourly_income_with_system", var_data( &income[0], 8760 ) );
				assign( "year1_hourly_price_with_system", var_data( &price[0], 8760 ) );
				assign( "year1_hourly_e_grid", var_data( &e_grid[0], 8760 ) );
				assign( "year1_hourly_p_grid", var_data( &p_grid[0], 8760 ) );
				
				// output and demand per Paul's email 9/10/10
				// positive demand indicates system does not produce enough electricity to meet load
				// zero if the system produces more than the demand
				std::vector<ssc_number_t> output(8760), edemand(8760), pdemand(8760), e_sys_to_grid(8760), e_sys_to_load(8760), p_sys_to_load(8760);
				for (j=0;j<8760;j++)
				{
					output[j] = e_sys[j] * sys_scale[i];
					edemand[j] = e_grid[j] < 0.0 ? -e_grid[j] : (ssc_number_t)0.0;
					pdemand[j] = p_grid[j] < 0.0 ? -p_grid[j] : (ssc_number_t)0.0;

					ssc_number_t sys_e_net = output[j] + e_load[j];// loads are assumed negative
					e_sys_to_grid[j] = sys_e_net > 0 ? sys_e_net : (ssc_number_t)0.0;
					e_sys_to_load[j] = sys_e_net > 0 ? -e_load[j] : output[j];

					ssc_number_t sys_p_net = output[j] + p_load[j];// loads are assumed negative
					p_sys_to_load[j] = sys_p_net > 0 ? -p_load[j] : output[j];
				}

				assign( "year1_hourly_system_output", var_data(&output[0], 8760) );
				assign( "year1_hourly_e_demand", var_data(&edemand[0], 8760) );
				assign( "year1_hourly_p_demand", var_data(&pdemand[0], 8760) );

				assign( "year1_hourly_system_to_grid", var_data(&e_sys_to_grid[0], 8760) ); 
				assign( "year1_hourly_system_to_load", var_data(&e_sys_to_load[0], 8760) ); 
				assign( "year1_hourly_p_system_to_load", var_data(&p_sys_to_load[0], 8760) );
				
				assign( "year1_monthly_dc_fixed_with_system", var_data(&monthly_dc_fixed[0], 12) );
				assign( "year1_monthly_dc_tou_with_system", var_data(&monthly_dc_tou[0], 12) );
				assign( "year1_monthly_tr_charge_with_system", var_data(&monthly_tr_charges[0], 12) );
				assign( "year1_monthly_tr_rate_with_system", var_data(&monthly_tr_rates[0], 12) );
			}

			// now recalculate revenue without solar system (using load only)
			ur_calc( &e_load_cy[0], &p_load_cy[0],
				&revenue_wo_sys[0], &payment[0], &income[0], &price[0],
				&monthly_fixed_charges[0],
				&monthly_dc_fixed[0], &monthly_dc_tou[0],
				&monthly_tr_charges[0], &monthly_tr_rates[0] );

			if (i == 0)
			{
				assign( "year1_hourly_revenue_without_system", var_data( &revenue_wo_sys[0], 8760 ) );
				assign( "year1_hourly_payment_without_system", var_data( &payment[0], 8760 ) );
				assign( "year1_hourly_income_without_system", var_data( &income[0], 8760 ) );
				assign( "year1_hourly_price_without_system", var_data( &price[0], 8760 ) );
								
				assign( "year1_monthly_dc_fixed_without_system", var_data(&monthly_dc_fixed[0], 12) );
				assign( "year1_monthly_dc_tou_without_system", var_data(&monthly_dc_tou[0], 12) );
				assign( "year1_monthly_tr_charge_without_system", var_data(&monthly_tr_charges[0], 12) );
				assign( "year1_monthly_tr_rate_without_system", var_data(&monthly_tr_rates[0], 12) );
			}

			// determine net-revenue benefit due to solar for year 'i'
			
			annual_net_revenue[i] = 0.0;
			energy_net[i] = 0.0;
			annual_revenue_w_sys[i] = 0.0;
			annual_revenue_wo_sys[i] = 0.0;

			for(j=0;j<8760;j++)
			{
				energy_net[i] +=  e_sys[j]*sys_scale[i];
				annual_net_revenue[i] += revenue_w_sys[j] - revenue_wo_sys[j];
				annual_revenue_w_sys[i] += revenue_w_sys[j];
				annual_revenue_wo_sys[i] += revenue_wo_sys[j];
			}

			annual_net_revenue[i] *= rate_scale[i];
			annual_revenue_w_sys[i] *= rate_scale[i];
			annual_revenue_wo_sys[i] *= rate_scale[i];

			ch_dc_fixed_jan[i] = monthly_dc_fixed[0] * rate_scale[i];
			ch_dc_fixed_feb[i] = monthly_dc_fixed[1] * rate_scale[i];
			ch_dc_fixed_mar[i] = monthly_dc_fixed[2] * rate_scale[i];
			ch_dc_fixed_apr[i] = monthly_dc_fixed[3] * rate_scale[i];
			ch_dc_fixed_may[i] = monthly_dc_fixed[4] * rate_scale[i];
			ch_dc_fixed_jun[i] = monthly_dc_fixed[5] * rate_scale[i];
			ch_dc_fixed_jul[i] = monthly_dc_fixed[6] * rate_scale[i];
			ch_dc_fixed_aug[i] = monthly_dc_fixed[7] * rate_scale[i];
			ch_dc_fixed_sep[i] = monthly_dc_fixed[8] * rate_scale[i];
			ch_dc_fixed_oct[i] = monthly_dc_fixed[9] * rate_scale[i];
			ch_dc_fixed_nov[i] = monthly_dc_fixed[10] * rate_scale[i];
			ch_dc_fixed_dec[i] = monthly_dc_fixed[11] * rate_scale[i];
		
			ch_dc_tou_jan[i] = monthly_dc_tou[0] * rate_scale[i];
			ch_dc_tou_feb[i] = monthly_dc_tou[1] * rate_scale[i];
			ch_dc_tou_mar[i] = monthly_dc_tou[2] * rate_scale[i];
			ch_dc_tou_apr[i] = monthly_dc_tou[3] * rate_scale[i];
			ch_dc_tou_may[i] = monthly_dc_tou[4] * rate_scale[i];
			ch_dc_tou_jun[i] = monthly_dc_tou[5] * rate_scale[i];
			ch_dc_tou_jul[i] = monthly_dc_tou[6] * rate_scale[i];
			ch_dc_tou_aug[i] = monthly_dc_tou[7] * rate_scale[i];
			ch_dc_tou_sep[i] = monthly_dc_tou[8] * rate_scale[i];
			ch_dc_tou_oct[i] = monthly_dc_tou[9] * rate_scale[i];
			ch_dc_tou_nov[i] = monthly_dc_tou[10] * rate_scale[i];
			ch_dc_tou_dec[i] = monthly_dc_tou[11] * rate_scale[i];
		
			ch_tr_jan[i] = monthly_tr_charges[0] * rate_scale[i];
			ch_tr_feb[i] = monthly_tr_charges[1] * rate_scale[i];
			ch_tr_mar[i] = monthly_tr_charges[2] * rate_scale[i];
			ch_tr_apr[i] = monthly_tr_charges[3] * rate_scale[i];
			ch_tr_may[i] = monthly_tr_charges[4] * rate_scale[i];
			ch_tr_jun[i] = monthly_tr_charges[5] * rate_scale[i];
			ch_tr_jul[i] = monthly_tr_charges[6] * rate_scale[i];
			ch_tr_aug[i] = monthly_tr_charges[7] * rate_scale[i];
			ch_tr_sep[i] = monthly_tr_charges[8] * rate_scale[i];
			ch_tr_oct[i] = monthly_tr_charges[9] * rate_scale[i];
			ch_tr_nov[i] = monthly_tr_charges[10] * rate_scale[i];
			ch_tr_dec[i] = monthly_tr_charges[11] * rate_scale[i];			
		}
	
	}

	void ur_calc( ssc_number_t e_in[8760], ssc_number_t p_in[8760],

		ssc_number_t revenue[8760], ssc_number_t payment[8760], ssc_number_t income[8760], ssc_number_t price[8760],
		ssc_number_t monthly_fixed_charges[12],
		ssc_number_t monthly_dc_fixed[12], ssc_number_t monthly_dc_tou[12],
		ssc_number_t monthly_tr_charges[12], ssc_number_t monthly_tr_rates[12] ) throw(general_error)
	{
		int i;

		for (i=0;i<8760;i++)
			revenue[i] = payment[i] = income[i] = price[i] = 0.0;

		for (i=0;i<12;i++)
		{
			monthly_fixed_charges[i] 
				= monthly_dc_fixed[i] = monthly_dc_tou[i] 
				= monthly_tr_charges[i] = monthly_tr_rates[i] = 0.0;
		}

		// process basic flat rate
		process_flat_rate( e_in, payment, income, price );

		// process monthly fixed charges
		process_monthly_charge( payment, monthly_fixed_charges );

		// process time of use charges
		if (as_boolean("ur_tou_enable"))
			process_tou_rate( e_in, payment, income, price );

		// process demand charges
		if (as_boolean("ur_dc_enable"))
			process_demand_charge( p_in, payment, monthly_dc_fixed, monthly_dc_tou );

		// process tiered rate charges
		if (as_boolean("ur_tr_enable"))
			process_tiered_rate( e_in, payment, income, monthly_tr_charges, monthly_tr_rates );

		// compute revenue ( = income - payment )
		for (i=0;i<8760;i++)
			revenue[i] = income[i] - payment[i];
	}

	void process_flat_rate( ssc_number_t e[8760],
			ssc_number_t payment[8760],
			ssc_number_t income[8760],
			ssc_number_t price[8760] )
	{
		int i;
		ssc_number_t buy = as_number("ur_flat_buy_rate");
		ssc_number_t sell = as_number("ur_flat_sell_rate");

		if (as_boolean("ur_sell_eq_buy")) sell = buy;

		for (i=0;i<8760;i++)
		{
			if (e[i] < 0) // must buy from grid
			{
				payment[i] += -1.0f*e[i]*buy;
				price[i] += buy;
			}
			else
			{
				income[i] += e[i]*sell;
				price[i] += sell;
			}
		}
	}

	void process_monthly_charge( ssc_number_t payment[8760], ssc_number_t charges[12] )
	{
		int m,d,h,c;

		ssc_number_t fixed = as_number("ur_monthly_fixed_charge");
		c=0;
		for (m=0;m<12;m++)
		{
			for (d=0;d<util::nday[m];d++)
			{
				for (h=0;h<24;h++)
				{
					if ( d==util::nday[m]-1 && h == 23)
					{
						charges[m] = fixed;
						payment[c] += fixed;
					}
					c++;
				}
			}
		}
	}

	void process_tou_rate( ssc_number_t e[8760],
			ssc_number_t payment[8760],
			ssc_number_t income[8760],
			ssc_number_t price[8760] )
	{
		ssc_number_t rates[9][2];

		const char *schedwkday = as_string("ur_tou_sched_weekday");
		const char *schedwkend = as_string("ur_tou_sched_weekend");

		int tod[8760];

		if (!util::translate_schedule( tod, schedwkday, schedwkend, 0, 8))
			throw general_error("could not translate weekday and weekend schedules for time-of-use rate");

		bool sell_eq_buy = as_boolean("ur_sell_eq_buy");

		for (int i=0;i<9;i++)
		{
			std::string nstr = util::to_string( i+1 );
			rates[i][0] = as_number("ur_tou_p" + nstr + "_buy_rate");
			rates[i][1] = sell_eq_buy ? rates[i][0] : as_number("ur_tou_p" + nstr + "_sell_rate");
		}

		for (int i=0;i<8760;i++)
		{
			int tod_p = tod[i];
			ssc_number_t buy = rates[tod_p][0];
			ssc_number_t sell = rates[tod_p][1];

			if (e[i] < 0)
			{
				payment[i] += -1.0f*e[i]*buy;
				price[i] += buy;
			}
			else
			{
				income[i] += e[i]*sell;
				price[i] += sell;
			}
		}
	}

	void process_demand_charge( ssc_number_t p[8760],
			ssc_number_t payment[8760],
			ssc_number_t dc_fixed[12],
			ssc_number_t dc_tou[12] )
	{
		int i,m,d,h,c;


		// compute fixed monthly demand charges
		c=0;
		for (m=0;m<12;m++)
		{
			ssc_number_t charge = 0.0;
			ssc_number_t mpeak = 0.0;
			for (d=0;d<util::nday[m];d++)
			{
				for (h=0;h<24;h++)
				{
					if (p[c] < 0 && p[c] < mpeak)
						mpeak = p[c];

					if (d==util::nday[m]-1 && h==23)
					{
						charge = as_number(util::format("ur_dc_fixed_m%d", m+1));
						dc_fixed[m] = -mpeak*charge;
						payment[c] += dc_fixed[m];
					}

					c++;
				}
			}
		}


		// compute time-of-use based demand charge
		// for each month:
		// 1. find peak demand in each period (1-9)
		// 2. multiply each period's peak demand by period price and add to payment for that month

		// extract schedules
		const char *schedwkday = as_string("ur_dc_sched_weekday");
		const char *schedwkend = as_string("ur_dc_sched_weekend");
		int tod[8760];
		if (!util::translate_schedule( tod, schedwkday, schedwkend, 0, 8))
			throw general_error("could not translate weekday and weekend schedules for demand charge time-of-use rate");

		// extract rate info
		ssc_number_t period_price[9];
		for (i=0;i<9;i++)
			period_price[i] = as_number(util::format("ur_dc_p%d", i+1));

		ssc_number_t ppeaks[9];
		c=0;
		for (m=0;m<12;m++)
		{
			for (i=0;i<9;i++) ppeaks[i] = 0;

			for (d=0;d<util::nday[m];d++)
			{
				for(h=0;h<24;h++)
				{
					int todp = tod[c];
					if (p[c] < 0 && p[c] < ppeaks[todp])
						ppeaks[todp] = p[c];

					if (d==util::nday[m]-1 && h==23)
					{
						// sum up all peak demand charges at end of month
						ssc_number_t charge=0;
						for (i=0;i<9;i++)
							charge += -ppeaks[i]*period_price[i];

						// add to payments
						dc_tou[m] = charge;
						payment[c] += charge;
					}

					c++;
				}
			}
		}

	}

	void process_tiered_rate( ssc_number_t e[8760],
			ssc_number_t payment[8760],
			ssc_number_t income[8760],
			ssc_number_t tr_charge[12],
			ssc_number_t tr_rate[12] )
	{
		int i,m,d,h,c;

		ssc_number_t energy_ub[6];
		ssc_number_t rates[6];
		ssc_number_t sell_rate=0, tier_rate=0;

		c=0;
		for (m=0;m<12;m++)
		{
			// compute total monthly energy use (net)
			ssc_number_t energy_use = 0;
			for (d=0;d<util::nday[m];d++)
			{
				for (h=0;h<24;h++)
				{
					energy_use += -1.0f*e[c]; // add up total energy use
					c++;
				}
			}


			int period = as_integer(util::format("ur_tr_sched_m%d",m+1)); // 0..5
			if (period < 0) period = 0;
			if (period > 5) period = 5;

			if (energy_use > 0)
			{

				for (i=0;i<6;i++)
				{
					energy_ub[i] = as_number(util::format("ur_tr_s%d_energy_ub%d", period+1, i+1));
					rates[i] = as_number(util::format("ur_tr_s%d_rate%d", period+1, i+1));
				}
				
				ssc_number_t charge_amt = 0;
				i=0;
				while (i<6)
				{
					// add up the charge amount for this block
					ssc_number_t e_upper = energy_ub[i];
					ssc_number_t e_lower = i > 0 ? energy_ub[i-1] : (ssc_number_t)0.0;
	
					if (energy_use > e_upper)
						charge_amt += (e_upper-e_lower)*rates[i];
					else
						charge_amt += (energy_use-e_lower)*rates[i];
	
					if ( energy_use < e_upper )
						break;
	
					i++;
				}
	
				tr_rate[m] = energy_use > 0 ? charge_amt/energy_use : (ssc_number_t)0.0;
				tr_charge[m] = charge_amt;
				payment[c-1] += charge_amt;
			}
			else // sell excess
			{
				tr_rate[m] = 0;
				tr_charge[m] = 0;
				sell_rate = 0;
				switch (as_integer("ur_tr_sell_mode"))
				{
				case 0: // flat tiered sell rate
					sell_rate = as_number("ur_tr_sell_rate");
					break;
				case 1: // Tier 1 rate
					sell_rate = as_number(util::format("ur_tr_s%d_rate1", period+1));
					break;
				case 2: // cheapest rate for tier structure
					sell_rate = as_number(util::format("ur_tr_s%d_rate1", period+1));
					for (int j=1; j<6; j++)
					{
						tier_rate = as_number(util::format("ur_tr_s%d_rate%d", period+1, j+1));
						if (tier_rate < sell_rate) sell_rate = tier_rate;
					}
					break;
				default:
					throw general_error("invalid sell rate mode. must be 0, 1, or 2");
					break;
				}

				income[c-1] -= sell_rate * energy_use;
			}
		}
	
	}


};

DEFINE_MODULE_ENTRY( utilityrate, "Complex utility rate structure net revenue calculator", 3 );


