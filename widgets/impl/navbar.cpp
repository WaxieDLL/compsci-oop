#include "imgui.h"
#include "../widgets.hpp"

void Widgets::Navbar(const std::string& title, const std::vector<std::string>& items, std::string* selected_item, float height)
{
	ImGui::BeginChild(title.c_str(), ImVec2(ImGui::GetWindowSize().x, height));
	{
		ImGui::TextUnformatted(title.c_str());

		for(const auto& item : items)
		{
			ImGui::SameLine();
			if (ImGui::Button(item.c_str()))
				*selected_item = item;
		}
	}
	ImGui::EndChild();
}