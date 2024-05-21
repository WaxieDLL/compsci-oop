#include "imgui.h"
#include "../widgets.hpp"
#include "../../memassets/logo.hpp"

void Widgets::Navbar(const std::string& title, const std::vector<std::string>& items, std::string* selected_item, float height)
{
	const bool image_exists = Loaders::image_storage.contains("ul_logo");
	if (!image_exists)
	{
		//@TODO: buffer overflow might occur, i gotta fix it in my "non-lazy" time
		Loaders::LoadImageFromMemory("ul_logo", logoMemory, sizeof logoMemory);
		return;
	}

	ImGui::BeginChild(title.c_str(), ImVec2(ImGui::GetWindowSize().x, height));
	{
		if (image_exists)
		{
			ImGui::Image(Loaders::image_storage.at("ul_logo"), {32,32});
			ImGui::SameLine();
		}

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