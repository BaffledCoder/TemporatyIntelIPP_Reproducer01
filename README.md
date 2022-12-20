# TemporatyIntelIPP_Reproducer01
It contains reproducer for intel communities issue "ippiMorphOpenBorder_8u_C1R is slower than older IPP version"

## How to Build
### Would have to make same kind of project for IPP5.3 folder   
First run Build.py in IPP2021.6.2 folder
Build LatestIntelIPP vs2017 project in IPP2021.6.2\IPP_Release_x64
Then copy the lib and dll from both projects into PerformanceTest_IPP\ipp\CurrentIPP\Release and PerformanceTest_IPP\ipp\LatestIPP\Release respectively
I have already copied them.

## Run Build.py in PerformanceTest_IPP folder and build PerformanceTestIPP vs2017 project present in IPP5.3\IPP_Release_x64
On running you will find latest IPP2021.6 takes more time than IPP5.3

I have already tried on my machine which support AVX2 having Windows 10 Pro version: 22H2
