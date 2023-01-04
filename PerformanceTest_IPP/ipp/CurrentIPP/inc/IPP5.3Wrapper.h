#include<ippi.h>
#include<ipps.h>
#include<ippcv.h>
#include<ippvm.h>
#include<ippcore.h>
#include<string>
#include <iostream>

#ifdef _WIN32
#if defined(IPP_API_EXPORTS)
#define IPP_API __declspec(dllexport)
#else
#define IPP_API __declspec(dllimport)
#endif
#else
#define IPP_API
#endif

typedef double DOUBLE_T;
typedef unsigned char Ipp8u;
typedef signed int SINT32_T;

namespace currentIPP
{
	class Profiler
	{
	public:
		unsigned int m_nCallCount;
		unsigned int m_nMin, m_nSec, m_nMilliSec;
		double m_dNanoSec;
		Profiler()
		{
			m_nMin = 0;
			m_nSec = 0;
			m_nMilliSec = 0;
			m_dNanoSec = 0;
			m_nCallCount = 0;
		}
		static IPP_API Profiler* GetInstance();
		IPP_API std::string GetTime();
		IPP_API unsigned int GetCallCount();
		void AddToTime(double nanoSec);
	};

	IPP_API int Mean_StdDev_8u_C1R_IPP5(Ipp8u *pDst, SINT32_T srcStep, DOUBLE_T* pMean, DOUBLE_T* pStdDev, SINT32_T Width, SINT32_T Height, Profiler *profiler);
}
