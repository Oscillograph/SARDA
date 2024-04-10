#ifndef SARDA_TIME_H
#define SARDA_TIME_H

#include <include/core/proto-core.h>

namespace sarda
{
	class Timestep {
	public:
		Timestep(float time = 0.0f){
			m_Time = time;
		}
		
		operator float() const { return m_Time; }
		
		float GetSeconds() const { return m_Time; }
		float GetMilliseconds() const { return m_Time * 1000.0f; }
	private:
		float m_Time = 0.0f; // time in seconds
	};
	
	
	struct TimerResult {
		std::string Name;
		float Time;
		
		TimerResult(std::string name, float time)
		: Name(name), Time(time)
		{}
	};
	
//	// Usage of this timer:
//	// 		Timer timer("Timer::Name", [&](TimerResult result){ my_Results.push_back(result); });
//	// where my_Results is a vector of results.
//	// OR
//	// much more convenient is to use a macro here:
//	// 		#define BSE_PROFILER(name)	Timer timer##__LINE__(name, [&](TimerResult result){ my_Results.push_back(result); });
//	// so that you only need to call BSE_PROFILER("Timer::Name"), for example.
//	// After the scope gets to vanish, the timer destroyer is called, and lambda function is processed.
//	// You might want to use BSE_PROFILER collector as a global variable, as OnImGuiLayer callbacks work good only in
//	// ImGuiLayers, and they don't know about the app calling them.
//	template <typename Func>
//	class Timer {
//	public:
//		Timer(std::string name, Func&& func)
//		: m_Name(name), m_Stopped(false), m_Func(func)
//		{
//			m_StartTimePoint = std::chrono::high_resolution_clock::now();
//		}
//		
//		~Timer(){
//			if (!m_Stopped){
//				Stop();
//			}
//		}
//		
//		void Stop(){
//			auto endTimePoint = std::chrono::high_resolution_clock::now();
//			long long start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimePoint).time_since_epoch().count();
//			long long end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint).time_since_epoch().count();
//			m_Stopped = true;
//			
//			float duration = (end - start) * 0.001f;
//			
//			// BSE_CORE_INFO("{1} operation took: {0} ms", duration, m_Name);
//			// return new TimerResult(m_Name, duration);
//			m_Func({m_Name, duration});
//		}
//		
//	private:
//		std::string m_Name;
//		//std::chrono::time_point<std::chrono::steady_clock> m_StartTimePoint;
//		std::chrono::high_resolution_clock::time_point m_StartTimePoint;
//		bool m_Stopped;
//		Func m_Func;
//	};
	
	static std::string GetDateAndTime() 
	{
		time_t 		timeNow = time(0);
		tm  		timeStruct;
		char 		charBuffer[80];
		
		// get current time
		timeStruct = *localtime(&timeNow);
		// convert it to a string
		strftime(charBuffer, sizeof(charBuffer), "%Y.%m.%d - %X", &timeStruct);
		
		return charBuffer;
	};
}

#endif 
