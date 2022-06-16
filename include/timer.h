#pragma once
#include<ctime>

class ElapsedTime{
	public:
		void Start(){
			start = std::clock();
		}
		void End(){
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
