#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>

#include "app.hpp"

#include <ranges>



#include "gui/window.hpp"
#define WINDOW_SIZE ImVec2(1280, 720)

CAppManager::CAppManager()
{
	if (!glfwInit())
		return;

	const char* glsl_version = "#version 130";
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

	//c++ casts makes me hate my life
	m_pWindowGLFW = glfwCreateWindow(static_cast<int>(WINDOW_SIZE.x), static_cast<int>(WINDOW_SIZE.y), "OOP Project", nullptr, nullptr);
	if (m_pWindowGLFW == nullptr)
		return;

	glfwMakeContextCurrent(m_pWindowGLFW);
	glfwSwapInterval(1); // Enable vsync

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

	ImGui::StyleColorsDark();

	ImGui_ImplGlfw_InitForOpenGL(m_pWindowGLFW, true);
	ImGui_ImplOpenGL3_Init(glsl_version);

	m_bInitialized = true;
}

CAppManager::~CAppManager()
{
	for (const auto& val : m_windows | std::views::values)
		delete val;
	m_windows.clear();

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwDestroyWindow(m_pWindowGLFW);
	glfwTerminate();
}

std::optional<CWindow*> CAppManager::AddWindow(const std::string& name)
{
	if (name.empty())
		return std::nullopt;

	if (m_windows.contains(name))
		return std::nullopt;

	m_windows[name] = new CWindow({ name, {0.f, 0.f},  WINDOW_SIZE, true });

	return m_windows[name];
}

std::optional<CWindow*> CAppManager::GetWindow(const std::string& name)
{
	if (name.empty())
		return std::nullopt;

	if (!m_windows.contains(name))
		return std::nullopt;

	return m_windows.at(name);
}

bool CAppManager::SetActiveWindow(const std::string& name)
{
	auto window = GetWindow(name);
	if (!window.has_value())
		return false;

	m_pActiveWindow = window.value();

	return m_pActiveWindow != nullptr;
}

bool CAppManager::SetActiveWindow(CWindow* window)
{
	if (!window)
		return false;

	m_pActiveWindow = window;

	return true;
}

void CAppManager::MainLoop()
{
	static uint8_t tabidx = 0;
	while (!glfwWindowShouldClose(m_pWindowGLFW))
	{
		glfwPollEvents();
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		if (m_pActiveWindow)
			m_pActiveWindow->OnMainLoop();

		// Rendering
		ImGui::Render();
		int display_w, display_h;
		glfwGetFramebufferSize(m_pWindowGLFW, &display_w, &display_h);
		glViewport(0, 0, display_w, display_h);
		glClearColor(0,0,0,1.f);
		glClear(GL_COLOR_BUFFER_BIT);
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		glfwSwapBuffers(m_pWindowGLFW);
	}
}
