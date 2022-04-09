float& WheelPivotTranslationAmount = *(float*)0xA72FFC;
bool& DrawCars = *(bool*)0xA73008;
bool& DrawCarsReflections = *(bool*)0xA7300C;
bool& DrawCarShadow = *(bool*)0xA73010;
bool& DrawLightFlares = *(bool*)0xA6C088;
bool& EnableSky = *(bool*)0xA73358;
bool& DrawSky = *(bool*)0xA7335C;
bool& DrawSkyEnvMap = *(bool*)0xA73360;
float& MainSkyScale = *(float*)0xA732AC;
eModel& SkydomeModel = *(eModel*)0xB77910;
UMath::Matrix4& CarScaleMatrix = *(UMath::Matrix4*)0xB778D0;
UMath::Matrix4& LeftTireRotateZMatrix = *(UMath::Matrix4*)0xB75000;
UMath::Matrix4& LeftTireMirrorMatrix = *(UMath::Matrix4*)0xB74EC0;

void Render_EnableCrashVisualTreatment(bool on)
{
	((void(__cdecl*)(bool))0x64CA00)(on);
}