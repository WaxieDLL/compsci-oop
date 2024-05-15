//I'd normally use #pragma once instead of the common include guard but there is no guarantee of pragma once to work.
#ifndef INCLUDE_WINDOW_H
#define INCLUDE_WINDOW_H

#include <string>
#include <functional>
#include "imgui.h"
#include <optional>

struct WindowConfig_t {
	std::string name;
	ImVec2 position;
	ImVec2 size;
	bool fullscreen;
};

class CWindow {
public:
	CWindow(WindowConfig_t config) : m_config(std::move(config)) {}
	void SetCallback(std::function<void()> callback)
	{
		m_callback = std::move(callback);
	}
	void OnMainLoop();
	WindowConfig_t* GetConfigPtr() { return &m_config; }
private:
	WindowConfig_t m_config;
	std::function<void()> m_callback;
};

#endif