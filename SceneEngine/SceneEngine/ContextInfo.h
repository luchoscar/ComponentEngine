#pragma once

namespace Core
{
	class ContextInfo
	{
	public:
		ContextInfo();
		ContextInfo(int majorVersion, int minorVersion, bool core);
		~ContextInfo() {}

		int GetMajorVersion() { return _majorVersion; }
		int GetMinorVersion() { return _minorVersion; }
		bool IsCore() { return _core; }

	private:
		int _majorVersion, _minorVersion;
		bool _core;
	};
}
