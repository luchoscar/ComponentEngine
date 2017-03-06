#pragma once

namespace Core
{
	class GraphicsInfo
	{
	public:
		GraphicsInfo();
		GraphicsInfo(int majorVersion, int minorVersion, bool core);
		~GraphicsInfo() {}

		int GetMajorVersion() { return _majorVersion; }
		int GetMinorVersion() { return _minorVersion; }
		bool IsCore() { return _core; }

	private:
		int _majorVersion, _minorVersion;
		bool _core;
	};
}
