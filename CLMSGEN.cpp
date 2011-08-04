// CLMSGEN.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <stdio.h>
#include <time.h>
#include "boost/date_time/posix_time/posix_time.hpp"
using namespace boost::posix_time;
using namespace boost::gregorian;
using namespace std;
int main()
{
	ofstream outStream;
	outStream.open("output.txt");

	std::string ts("00:56:00");
	time_duration initial_time(duration_from_string(ts));
	time_duration time_step = seconds (60);
		
	int JS_value = 50;
	int JS_step = -5;

	for (int i = 1; i < 11 ;i++)
	{
		//outStream	<<  "CH" << j << "_PRN_LOS        = <OVERRIDE> GTS_DATA::G-LOS" << i << "::CHAN_STAT_WORD_1_2  	<BITS>  10 	<TO> 15 <SCALE> 1.0  <END_OVERRIDE>\n"
		//			<<	"CH" << j << "_CODE_LOS       = <OVERRIDE> GTS_DATA::G-LOS" << i << "::CHAN_STAT_WORD_1_2  	<BITS>  5	<TO> 6	<SCALE> 1.0  <END_OVERRIDE>\n"
		//			<<	"CH" << j << "_C_N_LOS        = <OVERRIDE> GTS_DATA::G-LOS" << i << "::CHAN_STAT_WORD_2_2  	<BITS>  6 	<TO>  11 <SCALE> 1.0  <END_OVERRIDE>\n"
		//			<<	"CH" << j << "_FREQ_LOS       = <OVERRIDE> GTS_DATA::G-LOS" << i << "::CHAN_STAT_WORD_1_2  	<BIT>   8 			 <SCALE> 1.0  <END_OVERRIDE>\n"
		//			<<	"CH" << j << "_STATE_LOS      = <OVERRIDE> GTS_DATA::G-LOS" << i << "::CHAN_STAT_WORD_2_2  	<BITS>  12 	<TO>  15 <SCALE> 1.0  <END_OVERRIDE>\n"
		//			<<	"\n";

		outStream <<	"<EVENT>\n"
			<<		"	<TIME>"<< initial_time  <<"</TIME>\n"
			<<		"	<SIGNAL_GENERATOR>\n"
			<<		"	<ID>1</ID>\n"
			<<		"		<DEFINE>RT_NOISE</DEFINE>\n"
			<<		"		<J_S_VALUE>\n"
			<<		"			<VALUE>"<<	JS_value	<<"</VALUE>\n"
			<<		"			<UNIT>DBM</UNIT>\n"
			<<		"		</J_S_VALUE>\n"
			<<		"		<RF_OUTPUT>ON</RF_OUTPUT>\n"
			<<		"	</SIGNAL_GENERATOR>\n"
			<<		"</EVENT>\n"
			<<		"<EVENT>\n"
			<<		"	<TIME>"<< initial_time  <<"</TIME>\n"
			<<		"	<SIGNAL_GENERATOR>\n"
			<<		"	<ID>2</ID>\n"
			<<		"		<DEFINE>RT_NOISE</DEFINE>\n"
			<<		"		<J_S_VALUE>\n"
			<<		"			<VALUE>"<<	JS_value	<<"</VALUE>\n"
			<<		"			<UNIT>DBM</UNIT>\n"
			<<		"		</J_S_VALUE>\n"
			<<		"		<RF_OUTPUT>ON</RF_OUTPUT>\n"
			<<		"	</SIGNAL_GENERATOR>\n"
			<<		"</EVENT>\n"
			<<		"\n";

		initial_time = initial_time + time_step;
		JS_value = JS_value + JS_step;
	}
	outStream.close();
	return 0;
}

