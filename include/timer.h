#pragma once
#ifndef TIMER_H
#define TIMER_H
#include<ctime>

//namespace QUANTAPLUS {
class ElapsedTime{
	public:
		void Start(){
			start = std::clock();
		}
		void End(){ std::cout<<"------------------------------------------"<<std::endl;
			duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
			if (duration < 60.0) {
				std::cout << "Elapsed time: " << duration << " seconds" << std::endl;
			}
			else {
				std::cout << "Elapsed time: " << duration/60.0 << " mins" << std::endl;
			}
		}
	private:
		std::clock_t start;
		double duration;
};
//} //end of QUANTAPLUS namesapce
#endif
