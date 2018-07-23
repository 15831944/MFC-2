#pragma once
class CMyTime
{
public:

	static CMyTime GetCurrentTime();

	static BOOL IsValidFILETIME(_In_ const FILETIME& ft) throw();

	CMyTime();
	CMyTime(_In_ __time64_t time);
	CMyTime(int nYear, int nMonth, int nDay, int nHour, int nMin, int nSec, int nDST = -1);

	__time64_t GetTime();

	int GetYear();
	int GetMonth();
	int GetDay();
	int GetHour();
	int GetMinute();
	int GetSecond();
	int GetDayOfWeek();

	

	bool operator==(_In_ CMyTime time);
	bool operator!=(_In_ CMyTime time);
	bool operator<(_In_ CMyTime time);
	bool operator>(_In_ CMyTime time);
	bool operator<=(_In_ CMyTime time);
	bool operator>=(_In_ CMyTime time);




private:
	__time64_t m_time;
};

inline CMyTime CMyTime::GetCurrentTime()
{
	return time(NULL);
}
inline CMyTime::CMyTime()
{
	m_time = 0;
}
inline CMyTime::CMyTime(_In_ __time64_t time)
{
	m_time = time;
}
inline CMyTime::CMyTime(int nYear,int nMonth,int nDay, int nHour, int nMin, int nSec, int nDST)
{
	tm tms = { nSec, nMin, nHour, nDay, nMonth - 1, nYear - 1900};
	m_time = mktime(&tms);
}



inline __time64_t CMyTime::GetTime()
{
	return m_time;
}
inline int CMyTime::GetYear()
{
	tm tms;
	localtime_s(&tms, &m_time);
	return tms.tm_year + 1900;
}
inline int CMyTime::GetMonth()
{
	tm tms;
	localtime_s(&tms, &m_time);
	return tms.tm_mon + 1;
}
inline int CMyTime::GetDay() 
{
	tm tms;
	localtime_s(&tms, &m_time);
	return tms.tm_mday;
}
inline int CMyTime::GetHour()
{
	tm tms;
	localtime_s(&tms, &m_time);
	return tms.tm_hour;
}
inline int CMyTime::GetMinute()
{
	tm tms;
	localtime_s(&tms, &m_time);
	return tms.tm_min;
}
inline int CMyTime::GetSecond()
{
	tm tms;
	localtime_s(&tms, &m_time);
	return tms.tm_sec;
}
inline int CMyTime::GetDayOfWeek()
{
	tm tms;
	localtime_s(&tms, &m_time);
	return tms.tm_wday + 1;
}




inline bool CMyTime::operator==(_In_ CMyTime time)
{
	return m_time == time.m_time;
}
inline bool CMyTime::operator!=(_In_ CMyTime time) 
{
	return m_time != time.m_time;
}
inline bool CMyTime::operator<(_In_ CMyTime time) 
{
	return m_time < time.m_time;
}
inline bool CMyTime::operator>(_In_ CMyTime time) 
{
	return m_time > time.m_time;
}
inline bool CMyTime::operator<=(_In_ CMyTime time)
{
	return m_time <= time.m_time;
}
inline bool CMyTime::operator>=(_In_ CMyTime time) 
{
	return m_time >= time.m_time;
}