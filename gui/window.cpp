#include "window.hpp"
#include <ranges>
#include "imgui.h"

void CWindow::OnMainLoop()
{
	ImGui::SetNextWindowPos(m_config.position, ImGuiCond_Always);
	ImGui::SetNextWindowSize(m_config.fullscreen ? ImGui::GetIO().DisplaySize : m_config.size, ImGuiCond_Always);
	ImGui::Begin(m_config.name.c_str(), nullptr, ImGuiWindowFlags_NoDecoration);
	{
		if (m_callback)
			m_callback();
	}
	ImGui::End();
}
