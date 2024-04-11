#ifndef SARDELKA_LOGGER_H
#define SARDELKA_LOGGER_H

#include <include/core/proto-core.h>
#include <include/core/utils/time.h>
#include <external/utf8.h>

namespace SARDELKA
{
	typedef std::basic_stringstream<char32_t> u32stringstream;
	
	class Logger
	{
	public:
		static void Flush(int mode = 0, int color = -1);
		
		template<typename... Args>
		inline static void Text(Args... args)
		{
			m_u8stream.str(std::string()); // clear utf8 buffer
			m_u32string = U""; // clear utf32 string
			
			// add args to utf8 string stream
			m_u8stream << "[" << SARDELKA::GetDateAndTime() << "] ";
			(u8add(std::forward<Args>(args)), ...);
			m_u8stream << "\n";
			m_u8string = m_u8stream.str();
			
			// convert it to utf32
			utf8::utf8to32(m_u8string.begin(), m_u8string.end(), std::back_inserter(m_u32string));
			
			m_u32stream << m_u32string << "\n";
		}
		
		template<typename... Args>
		inline static void Message(Args... args)
		{
			m_u8stream.str(std::string()); // clear utf8 buffer
			m_u32string = U""; // clear utf32 string
			
			// add args to utf8 string stream
			// m_u8stream << "[" << Utils::GetDateAndTime() << "] ";
			(u8add(std::forward<Args>(args)), ...);
			m_u8stream << "\n";
			m_u8string = m_u8stream.str();
			
			// convert it to utf32
			utf8::utf8to32(m_u8string.begin(), m_u8string.end(), std::back_inserter(m_u32string));
			
			m_u32stream << m_u32string << "\n";
		}
		
	private:
		inline static void Reset()
		{
			m_u8string = "";
			m_u32string = U"";
			m_u8stream.str(std::string());
			m_u32stream.str(std::u32string());
		}
		
		template <typename T>
		inline static void u8add(T t) { m_u8stream << t; }
		
		template <typename T>
		inline static void u32add(T t) { m_u32stream << t; }
		
		static std::stringstream m_u8stream;
		static std::string m_u8string;
		static std::u32string m_u32string;
		static u32stringstream m_u32stream;
	};
	
	#define SARDELKA_CONSOLE_GREY(...)				::SARDELKA::Logger::Message(__VA_ARGS__); ::SARDELKA::Logger::Flush(0, -1);
	#define SARDELKA_CONSOLE_YELLOW(...)			::SARDELKA::Logger::Message(__VA_ARGS__); ::SARDELKA::Logger::Flush(0, 0);
	#define SARDELKA_CONSOLE_WHITE(...)			::SARDELKA::Logger::Message(__VA_ARGS__); ::SARDELKA::Logger::Flush(0, 1);
	#define SARDELKA_CONSOLE_DARKRED(...)			::SARDELKA::Logger::Message(__VA_ARGS__); ::SARDELKA::Logger::Flush(0, 2);
	#define SARDELKA_CONSOLE_RED(...)				::SARDELKA::Logger::Message(__VA_ARGS__); ::SARDELKA::Logger::Flush(0, 3);
	#define SARDELKA_CONSOLE_TEAL(...)				::SARDELKA::Logger::Message(__VA_ARGS__); ::SARDELKA::Logger::Flush(0, 4);
	#define SARDELKA_CONSOLE_CYAN(...)				::SARDELKA::Logger::Message(__VA_ARGS__); ::SARDELKA::Logger::Flush(0, 5);
	#define SARDELKA_CONSOLE_BLUE(...)				::SARDELKA::Logger::Message(__VA_ARGS__); ::SARDELKA::Logger::Flush(0, 6);
	#define SARDELKA_CONSOLE_MAGENTA(...)			::SARDELKA::Logger::Message(__VA_ARGS__); ::SARDELKA::Logger::Flush(0, 7);
	#define SARDELKA_CONSOLE_GREEN(...)			::SARDELKA::Logger::Message(__VA_ARGS__); ::SARDELKA::Logger::Flush(0, 8);
	#define SARDELKA_CONSOLE_CAPTION_BLACK(...)	::SARDELKA::Logger::Message(__VA_ARGS__); ::SARDELKA::Logger::Flush(0, 9);
	
	#define SARDELKA_CONSOLE_LOG(...)				::SARDELKA::Logger::Text("SARDELKA: ", __VA_ARGS__); ::SARDELKA::Logger::Flush(0, 1);
	#define SARDELKA_CONSOLE_ERROR(...)			::SARDELKA::Logger::Text("SARDELKA: ", __VA_ARGS__); ::SARDELKA::Logger::Flush(0, 3);
	#define SARDELKA_CONSOLE_DEBUG(...)			::SARDELKA::Logger::Text("SARDELKA: ", __VA_ARGS__); ::SARDELKA::Logger::Flush(1, 1);
	#define SARDELKA_CONSOLE_ASSERT(x, ...)		{ if (!(x)) { SARDELKA_CORE_ERROR(__VA_ARGS__); std::exit(-4); } }
	
	#define SARDELKA_TRACE(...)					SARDELKA_CONSOLE_GREY("Trace: ", __VA_ARGS__)
	#define SARDELKA_INFO(...)						SARDELKA_CONSOLE_GREY("Info: ", __VA_ARGS__)
	#define SARDELKA_WARN(...)						SARDELKA_CONSOLE_YELLOW("Warning: ", __VA_ARGS__)
	#define SARDELKA_ERROR(...)					SARDELKA_CONSOLE_RED("Error: ", __VA_ARGS__)
	#define SARDELKA_CRITICAL(...)					SARDELKA_CONSOLE_RED("Critical Error: ", __VA_ARGS__)
}

#endif
