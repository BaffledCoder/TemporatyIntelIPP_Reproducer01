#include <string>
#include <iostream>
#include <IPP5.3Wrapper.h>
#include<IPP2021Wrapper.h>

int main()
{
			// small values
	/*Ipp8u *pSrc = new Ipp8u[64];
	memset(pSrc, '7', 64);
	DOUBLE_T* pMean1 = 0, *pStdDev1 = 0;
	DOUBLE_T* pMean2 = 0, *pStdDev2 = 0;
	currentIPP::Profiler *curProfiler = currentIPP::Profiler::GetInstance();
	latestIPP::Profiler *latestProfiler = latestIPP::Profiler::GetInstance();

	for (int i = 0; i < 100000000; i++)
	{
		currentIPP::Mean_StdDev_8u_C1R_IPP5(pSrc, 1, pMean1, pStdDev1, 1, 64, curProfiler);
		latestIPP::Mean_StdDev_8u_C1R_IPP2021(pSrc, 1, pMean2, pStdDev2, 1, 64, latestProfiler);
	}

	std::cout << "CurrentIPP Time: "<< curProfiler->GetTime() <<"		No. of calls: " << curProfiler->GetCallCount()<<std::endl;
	std::cout << "LatestIPP Time: "<< latestProfiler->GetTime() <<"		No. of calls: " << latestProfiler->GetCallCount()<<std::endl;
	return 0;*/

			//large values
	Ipp8u *pSrc = new Ipp8u[1024];
	memset(pSrc, '7', 1024);
	DOUBLE_T Mean1 = 0, StdDev1 = 0;
	DOUBLE_T Mean2 = 0, StdDev2 = 0;
	currentIPP::Profiler *curProfiler = currentIPP::Profiler::GetInstance();
	latestIPP::Profiler *latestProfiler = latestIPP::Profiler::GetInstance();

	for (int i = 0; i < 10000000; i++)
	{
		currentIPP::Mean_StdDev_8u_C1R_IPP5(pSrc, 1, &Mean1, &StdDev1, 1, 1024, curProfiler);
		latestIPP::Mean_StdDev_8u_C1R_IPP2021(pSrc, 1, &Mean2, &StdDev2, 1, 1024, latestProfiler);
	}

	std::cout << "CurrentIPP Time: " << curProfiler->GetTime() << "		No. of calls: " << curProfiler->GetCallCount() << std::endl;
	std::cout << "LatestIPP Time: " << latestProfiler->GetTime() << "		No. of calls: " << latestProfiler->GetCallCount() << std::endl;
	return 0;
}