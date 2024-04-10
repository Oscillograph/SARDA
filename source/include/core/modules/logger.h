#ifndef SARDA_LOGGER_H
#define SARDA_LOGGER_H

#include <include/core/proto-core.h>
#include <include/core/utils/time.h>
#include <external/utf8.h>

namespace sarda
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
			m_u8stream << "[" << sarda::GetDateAndTime() << "] ";
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
	
	#define SARDA_CONSOLE_GREY(...)				::sarda::Logger::Message(__VA_ARGS__); ::sarda::Logger::Flush(0, -1);
	#define SARDA_CONSOLE_YELLOW(...)			::sarda::Logger::Message(__VA_ARGS__); ::sarda::Logger::Flush(0, 0);
	#define SARDA_CONSOLE_WHITE(...)			::sarda::Logger::Message(__VA_ARGS__); ::sarda::Logger::Flush(0, 1);
	#define SARDA_CONSOLE_DARKRED(...)			::sarda::Logger::Message(__VA_ARGS__); ::sarda::Logger::Flush(0, 2);
	#define SARDA_CONSOLE_RED(...)				::sarda::Logger::Message(__VA_ARGS__); ::sarda::Logger::Flush(0, 3);
	#define SARDA_CONSOLE_TEAL(...)				::sarda::Logger::Message(__VA_ARGS__); ::sarda::Logger::Flush(0, 4);
	#define SARDA_CONSOLE_CYAN(...)				::sarda::Logger::Message(__VA_ARGS__); ::sarda::Logger::Flush(0, 5);
	#define SARDA_CONSOLE_BLUE(...)				::sarda::Logger::Message(__VA_ARGS__); ::sarda::Logger::Flush(0, 6);
	#define SARDA_CONSOLE_MAGENTA(...)			::sarda::Logger::Message(__VA_ARGS__); ::sarda::Logger::Flush(0, 7);
	#define SARDA_CONSOLE_GREEN(...)			::sarda::Logger::Message(__VA_ARGS__); ::sarda::Logger::Flush(0, 8);
	#define SARDA_CONSOLE_CAPTION_BLACK(...)	::sarda::Logger::Message(__VA_ARGS__); ::sarda::Logger::Flush(0, 9);
	
	#define SARDA_CONSOLE_LOG(...)				::sarda::Logger::Text("SARDA: ", __VA_ARGS__); ::sarda::Logger::Flush(0, 1);
	#define SARDA_CONSOLE_ERROR(...)			::sarda::Logger::Text("SARDA: ", __VA_ARGS__); ::sarda::Logger::Flush(0, 3);
	#define SARDA_CONSOLE_DEBUG(...)			::sarda::Logger::Text("SARDA: ", __VA_ARGS__); ::sarda::Logger::Flush(1, 1);
	#define SARDA_CONSOLE_ASSERT(x, ...)		{ if (!(x)) { SARDA_CORE_ERROR(__VA_ARGS__); std::exit(-4); } }
	
	#define SARDA_TRACE(...)					SARDA_CONSOLE_GREY("Trace: ", __VA_ARGS__)
	#define SARDA_INFO(...)						SARDA_CONSOLE_GREY("Info: ", __VA_ARGS__)
	#define SARDA_WARN(...)						SARDA_CONSOLE_YELLOW("Warning: ", __VA_ARGS__)
	#define SARDA_ERROR(...)					SARDA_CONSOLE_RED("Error: ", __VA_ARGS__)
	#define SARDA_CRITICAL(...)					SARDA_CONSOLE_RED("Critical Error: ", __VA_ARGS__)
}

#endif
