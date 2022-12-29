auto& WheelPivotTranslationAmount = *(float*)0xA72FFC;
auto& DrawCars = *(bool*)0xA73008;
auto& DrawCarsReflections = *(bool*)0xA7300C;
auto& DrawCarShadow = *(bool*)0xA73010;
auto& DrawLightFlares = *(bool*)0xA6C088;
auto& EnableSky = *(bool*)0xA73358;
auto& DrawSky = *(bool*)0xA7335C;
auto& DrawSkyEnvMap = *(bool*)0xA73360;
auto& MainSkyScale = *(float*)0xA732AC;
auto& SkydomeModel = *(eModel*)0xB77910;
auto& CarScaleMatrix = *(UMath::Matrix4*)0xB778D0;
auto& LeftTireRotateZMatrix = *(UMath::Matrix4*)0xB75000;
auto& LeftTireMirrorMatrix = *(UMath::Matrix4*)0xB74EC0;

auto& bJustChangedGraphics = *(bool*)0xAB0B25;
auto& g_FSAALevel = *(int*)0xA6537C;

void Render_EnableCrashVisualTreatment(bool on)
{
	((void(__cdecl*)(bool))0x64CA00)(on);
}