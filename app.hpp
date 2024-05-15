//I'd normally use #pragma once instead of the common include guard but there is no guarantee of pragma once to work.
#ifndef INCLUDE_APP_H
#define INCLUDE_APP_H
#include <optional>
#include <string>
#include <unordered_map>

class CWindow;
class GLFWwindow;

class CAppManager {
public:
	CAppManager();
	~CAppManager();
	std::optional<CWindow*> AddWindow(const std::string& name); //returns created window pointer or std::nullopt if it fails.
	std::optional<CWindow*> GetWindow(const std::string& name); //returns window that matches with name you provided.
	bool SetActiveWindow(const std::string& name); //returns true if window successfully activated.
	bool SetActiveWindow(CWindow* window); //returns true if window successfully activated.
	void MainLoop();

	bool IsValid() const
	{
		return m_bInitialized;
	}
private:
	bool m_bInitialized{ false };
	GLFWwindow* m_pWindowGLFW{ nullptr };
	CWindow* m_pActiveWindow{nullptr};
	std::unordered_map<std::string, CWindow*> m_windows{};
};

#endif