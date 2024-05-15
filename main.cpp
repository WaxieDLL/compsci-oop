#include "app.hpp"
#include "gui/window.hpp"

int main()
{
	CAppManager app;
	const auto pHomeWindow = app.AddWindow("Home Window");
	if (pHomeWindow.has_value())
	{
		pHomeWindow.value()->SetCallback([&]
			{
				if (ImGui::Button("->"))
					app.SetActiveWindow("Dispatch Window");

				ImGui::TextUnformatted("Home Window");
			});
	}

	const auto pDispatchWindow = app.AddWindow("Dispatch Window");
	if (pDispatchWindow.has_value())
	{
		pDispatchWindow.value()->SetCallback([&]
			{
				if (ImGui::Button("<-"))
					app.SetActiveWindow("Home Window");

				ImGui::TextUnformatted("Dispatch Window");
			});
	}

	app.SetActiveWindow("Home Window");

	app.MainLoop();
	return 0;
}